#include <fstream>
#include <cassert>
#include "Game.h"

/*************************************************************************
 * ClassInit:   Game class init function
 *
 * Details:     调用resetstate函数
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/13/2020 JLB : Created.                                                                 *
 *======================================================================*/
Game::Game(int plan)
{
    setPolicyChoice(plan);
    resetState();
}

Game::~Game()
{
    // agents 这里只new了一次
    delete agents;
}

/*************************************************************************
 * INPUT:   float slocation[2]
 *                                                                                             *
 * OUTPUT:  save to float observation[28][28]
 *                                                                                             *
 * WARNINGS:   子类中virtual的重构，agent通过该方法计算各个单元之间的距离
 *                                                                                             *
 * HISTORY:
 *   12/13/2020 JLB : Created.                                                                 *
 *======================================================================*/
void Game::observe()
{
    for (int i = 0; i < AgentsNumber; i++) {
        for(int j = 0;j < AgentsNumber;j++){
            observation[i][j] =Utils::calculate_dist(agents->getAllAgents()[i]->agentState.getSloacation(),agents->getAllAgents()[j]->agentState.getSloacation()) ;
        }
        observation[i][28] = agents->getAllAgents()[i]->agentState.getSloacation()[0];
        observation[i][29] = agents->getAllAgents()[i]->agentState.getSloacation()[1];
        observation[i][30] = agents->getAllAgents()[i]->agentState.getHealth();
        observation[i][31] = agents->getAllAgents()[i]->agentState.getAmmo();


        //更新可行动作
        if (agents->getAllAgents()[i]->agentState.getHealth() == 0) {
            available_actions[i][nactions - 1] = 1;	//只能选择null
            continue;
        }
        available_actions[i][nactions - 2] = 1;	//啥时候都能移动

        for (int j = 0; j < 28; j++) {
            //获取能够攻击的单位
            if ((agents->getAllAgents()[i]->agentState.side !=  agents->getAllAgents()[j]->agentState.side)
                && (agents->getAllAgents()[i]->agentState.getAmmo()!= 0)
                && (observation[i][j] < agents->getAllAgents()[i]->agentState.getAttackRange()
                    && agents->getAllAgents()[j]->agentState.getHealth()>0))
            {
                available_actions[i][j] = 1;
            }
        }
    }
    Utils::save_dqn_data(observation,gameRewardAndState);
}

/*************************************************************************
 * ClassInit:   Game class init function
 *
 * Details:      对所有单元的状态初始化
 *               控制策略的选择
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/13/2020 JLB : Created.                                                                 *
 *======================================================================*/
void Game::resetState()
{
    std::cout << "I am in game::resetstate" << std::endl;

    // agents = new Agents(policyChoice);
    agents.reset(new Agents(policyChoice)); // TODO:智能指针声明后初始化


    time = 0;
    delta_time = 0;
    time_step = 0;
    actionSelectByDQN = 0;
    policyChoice = 0;
    gameStop = false;

    int init_x_position_ = 0;
    int init_y_position_ = 1;
    int init_height_ = 100;


    // 设定初始状态
    for (int i = 0; i < AgentsNumber; i++)
    {
        // 所有单位基本状态设定
        agents->getAllAgents()[i]->agentState.setID(i);
        agents->getAllAgents()[i]->agentState.setMovement(40);
        action[i] = agents->getAllAgents()[i]->agentState.getMovement();
        agents->getAllAgents()[i]->agentState.setPlanNumber(PLANNUMBER);
        agents->getAllAgents()[i]->agentState.setSlocation(i, 0, 1, 2); // start_pos中变量位置
        agents->getAllAgents()[i]->agentState.setAgentType(i);

        // 个别单位攻击范围设定
        if (i > 23) {
            agents->getAlly()[i - 10]->agentState.setAttackRange(10);
        }
        agents->getAlly()[1]->agentState.setAttackRange(60);
        agents->getAlly()[10]->agentState.setAttackRange(60);
        agents->getAlly()[7]->agentState.setAttackRange(60);

        // 阵营设定
        if (i < 10)
            agents->getEnemy()[i]->agentState.side = State::side::blue;
        else {
            agents->getAlly()[i - 10]->agentState.side = State::side::red;
        }

        // 特殊单位弹药单位设定
        if (0 == i || 1 == i || 18 == i) {
            agents->getAllAgents()[i]->agentState.setAmmo(0);
        }
        // 血量设置
        if (i < 10) {
            agents->getEnemy()[i]->agentState.setHealth(4);
        }

        if (i > 1 && i < 10) {
            agents->getEnemy()[i]->agentState.setAmmo(2);
        }

    }
    observe();

    //加载网络参数
//    float *weight_b;
//    float *bias_b;
//    weight_b = loadparameters("./data/netParameter_weight.txt");
//    bias_b = loadparameters("./data/netParameter_bias.txt");
//    for (int j = 0; j < 25; ++j) {
//                cout<<*action++<<endl;//两种都可以
//        cout << action[i] << endl;//两种都可以
//        weights[i][j] = weight_b[j];
//        bias[j] = bias_b[j];

    update_state();
//    }

}

void Game::step(bool isDQNAgent)
{
    choseAndTakeAction(isDQNAgent);
    update_state();

    time_step++;
    delta_time = (time_step - time)*0.9;
    time = time_step;
}

bool Game::isEnd(int AllyNumber,int EnemyNumber,float time) {

    if(time>1200)
    {
        observation[27][31] = 1;
        return true;
    }
    if(0 == AllyNumber || 0 == EnemyNumber)
    {
        observation[27][31] = 1;
        return true;

    }

    observation[27][31] = 0;
    return false;
}

/*************************************************************************
 * if isDQNAgent is true
 *    cpp code will run together with python
 * else
 *    use dp policy to simulate the game
 *======================================================================*/
void Game::choseAndTakeAction(bool isDQNAgent) {
    if (isDQNAgent){
        std::cout<<time<<std::endl;

        takeDQNPolicyAction();
    }
    else{
        takeDPPolicyAction();
    }
}

/*************************************************************************
 *  DQN policy
 *======================================================================*/
void Game::takeDQNPolicyAction() {
    static int movements[28] = {0};
    float distanceReward  = 0;
    float timeReward  = 0;
    float healthReward  = 0;
    int aliveNumberAlly = 18;
    int aliveNumberEnemy= 10;
    float enemyEverageSlocation[2] = {0};
    float allyEverageSlocation[2] = {0};
    float distance;
    static float distanceTemp = 0; // 保存上一次距离
    float aliveReward = 0 ;

    int targetID;

    Utils::readtxt(writeActionDataPath, movements);

    for(int i = 0 ;i < AgentsNumber; i++)
    {

        std::cout<<"now is id:"<<i<<std::endl;
        agents->getAllAgents()[i]->agentState.setMovement(movements[i]);
        if(i>9){
            // 我方单位 采取动作 及回报计算
            // take action
            agents->getAllAgents()[i]->move(observation[i], state);

//            targetID = agents->getAllAgents()[i]->agentState.getMovement();// 第i个智能体的目标
//            std::cout<<"target is:"<<targetID<<std::endl;
//
//
//            std::cout<<"i is :"<<agents->getAllAgents()[i]->agentState.getSloacation()[0]<<std::endl;
//            std::cout<<"targetid is :"<<agents->getAllAgents()[targetID]->agentState.getSloacation()[0]<<std::endl;
//
//            distance = Utils::calculate_dist(agents->getAllAgents()[i]->agentState.getSloacation(),agents->getAllAgents()[targetID]->agentState.getSloacation());
//            distanceReward += distance/100.0;

            if(agents->getAllAgents()[i]->agentState.getHealth())
            {
                allyEverageSlocation[0] += agents->getAllAgents()[i]->agentState.getSloacation()[0];
                allyEverageSlocation[1] += agents->getAllAgents()[i]->agentState.getSloacation()[1];
            }
            healthReward += agents->getAllAgents()[i]->agentState.getHealth();

            if(0 == agents->getAllAgents()[i]->agentState.getHealth())
                {aliveNumberAlly -= 1;}
        }
        else{
            healthReward -= agents->getAllAgents()[i]->agentState.getHealth();

            if(0 == agents->getAllAgents()[i]->agentState.getHealth())
                aliveNumberEnemy-= 1;

            if(agents->getAllAgents()[i]->agentState.getHealth())
            {
                enemyEverageSlocation[0] += agents->getAllAgents()[i]->agentState.getSloacation()[0];
                enemyEverageSlocation[1] += agents->getAllAgents()[i]->agentState.getSloacation()[1];
            }
        }

    }

    // 距离奖励
    distance = Utils::calculate_dist(enemyEverageSlocation,allyEverageSlocation);

    // 存活奖励
    aliveReward = static_cast<float>((10-aliveNumberEnemy)-(18-aliveNumberAlly))*100;

    // 结束条件
    gameStop = isEnd(aliveNumberAlly,aliveNumberEnemy,time);
    std::cout<<gameStop<<std::endl;



    // 第一轮距离奖励不算
    if(0 == time)
        distance = 0;

    distanceReward = distanceTemp - distance;
    gameRewardAndState[0] = distanceReward
                            +healthReward
                            +aliveReward
                            -time;
    std::cout<<"distance is: "<<distanceReward<<" "
             <<"time is: "<<-time<<" "
             <<"healthreward is: "<<healthReward<<" "
             <<"alive reward is: "<<aliveReward;
    // 保存上一次的distance
    distanceTemp = Utils::calculate_dist(enemyEverageSlocation,allyEverageSlocation);



    if(gameStop)
    {
        if(0 == aliveNumberAlly)
            gameRewardAndState[0] -= 10000;
        if(0 == aliveNumberEnemy)
            gameRewardAndState[0] += 10000;
        // 游戏结束
        gameRewardAndState[1] = 1;
    }
    else
        gameRewardAndState[1] = 0;
}

/*************************************************************************
 *  DP policy
 *======================================================================*/
void Game::takeDPPolicyAction() {

    std::cout << "---------------This is in DP policy------------------" << std::endl;
    for (int i = 0; i < AgentsNumber; i++)
    {
        //单位存活情况分析
        if (agents->getAllAgents()[i]->agentState.getHealth() == 0) {
            agents->getAllAgents()[i]->agentState.setMovement(100);
            continue;
        }

        //如果没有弹药或者开过台湾了 则返航
        if (((agents->getAllAgents()[i]->agentState.getAmmo() == 0) ||
             (agents->getAllAgents()[i]->agentState.getSloacation()[0] > 121)) && (i > 9 && i != 23 && i != 18)) {
            agents->getAllAgents()[i]->agentState.setAmmo(0);
            agents->getAllAgents()[i]->fallback(); //movement == 80
            continue;
        }

        //如果不同队 有弹药 能打到 攻击
        for (int j = 0; j < AgentsNumber; j++) {
            if ((agents->getAllAgents()[i]->agentState.getAmmo() != 0)
                && agents->getAllAgents()[j]->agentState.getHealth() > 0
                && agents->getAllAgents()[i]->agentState.side !=  agents->getAllAgents()[j]->agentState.side
                && agents->getAllAgents()[i]->agentState.getAttackRange()>observation[i][j]){
                agents->getAllAgents()[i]->attack(j);  //movement = target_id;
                agents->getAllAgents()[j]->agentState.setAttackState(1);
                agents->getAllAgents()[i]->agentState.canMove = false;
                break;
            }
        }

        //否则 移动
        if (agents->getAllAgents()[i]->agentState.canMove) {
            agents->getAllAgents()[i]->move(observation[i], state);
        }
    }
}

void Game::saveQtDataFunction() {

    // 保存qtdata
    for(int i =1;i<4;i++){
        for(int j = 1; j <6;j++)
            Utils::save_qt_data(writeQTDataPath+std::to_string(i)+std::to_string(j)+".txt");
    }
}
/*************************************************************************
 * INPUT:   none
 *                                                                                             *
 * OUTPUT:  
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/13/2020 JLB : Created.                                                                 *
 *======================================================================*/
void Game::update_state() {
    std::cout<<"I am in Game update state"<<std::endl;

    for (int i = 0; i < AgentsNumber; i++) {
        float target_x, target_y;
        // 若采取攻击动作
        if (agents->getAllAgents()[i]->agentState.getMovement() < AgentsNumber) {
            target_x = (agents->getAllAgents()[agents->getAllAgents()[i]->agentState.getMovement()]->agentState.getSloacation())[0];
            target_y = (agents->getAllAgents()[agents->getAllAgents()[i]->agentState.getMovement()]->agentState.getSloacation())[1];
        } else {
            target_x = target_y = 1000;
        }

        state[i][0] = agents->getAllAgents()[i]->agentState.getSloacation()[0];
        state[i][1] = agents->getAllAgents()[i]->agentState.getSloacation()[1];
        state[i][2] = agents->getAllAgents()[i]->agentState.getHealth();
        state[i][3] = agents->getAllAgents()[i]->agentState.getMovement();
        state[i][4] = agents->getAllAgents()[i]->agentState.getAmmo();
        state[i][5] = target_x;
        state[i][6] = target_y;


        if (agents->getAllAgents()[i]->agentState.getAttackState() == 1) {
            agents->getAllAgents()[i]->agentState.setAttackState(0);
            agents->getAllAgents()[i]->agentState.changeHealth(-1);
        }
        if (i>=10){
            agents->getAllAgents()[i]->agentState.canMove = true;
        }
    }
    observe();
}


float *Game::loadparameters(std::string str) {
    float static action[25];

    std::ifstream loadparameter;
    loadparameter.open(str);
    assert(loadparameter.is_open());   //若失败,则输出错误消息,并终止程序运行
    std::string s;//临时字符串变量
    for (int i = 0; i < 32; ++i) {
        getline(loadparameter, s, '\n');//按每行读取
//        cout<<s<<endl;
//        istringstream iss(s);
//        float num;
//        iss>>num;
//        action[i] = num;//将字符串转化成浮点型并存进动作数组
        action[i] = Utils::stringToNum(s);//将字符串转化成浮点型并存进动作数组
    }
    loadparameter.close();

    return action;

}

float Game::getTimeStep() const {
    return time_step;
}



