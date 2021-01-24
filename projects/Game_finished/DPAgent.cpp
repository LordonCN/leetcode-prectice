#include "DPAgent.h"

void DPPolicyAgent::fallback()
{
	defaultFallback();
}

/*************************************************************************
 * INPUT:   observation-- calculate the distance between plane and target
 *                                                                                             *
 *          ID-- now which one is activate, Active attack
 *                                                                                             *
 * OUTPUT:  return the speed of x-axis and y-axis
 *                                                                                             *
 * WARNINGS:   距离最短
 *                                                                                             *
 * HISTORY:    
 *   12/13/2020 512tianjiaoworkstation : Created.                                                                 *
 *======================================================================*/
float* DPPolicyAgent::moveBasedOnTarget(int _ID, float _observation[AgentsNumber],float pDouble[28][7])
{
	// 状态转移策略更新
	int target_id = 0;
	static float direction[2] ;

	// 当前id下的最佳攻击目标
	target_id = choseAttackTarget(_ID,_observation);

	direction[0] = getMoveDirection(_ID,this->agentState.getSloacation(),pDouble[target_id],target_id)[0];
    direction[1] = getMoveDirection(_ID,this->agentState.getSloacation(),pDouble[target_id],target_id)[1];

	return direction; // speed

}
/*************************************************************************
 * INPUT:   target_id 
 *                                                                                             *
 * OUTPUT:  update the state
 *                                                                                             *
 * WARNINGS:  
 *                                                                                             *
 * HISTORY:   
 *   12/13/2020 512tianjiaoworkstation : Created.                                                                 *
 *======================================================================*/
void DPPolicyAgent::attack(int target_id)
{
	defaultAttack(target_id);
}

/*************************************************************************
 * INPUT:   observation-- calculate the distance between plane and target
 *                                                                                             *
 *          health-- the health of all target
 *                                                                                             *
 * OUTPUT:  return target ID
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/13/2020 512tianjiaoworkstation : Created.                                                                 *
 *======================================================================*/
int DPPolicyAgent::choseAttackTarget(int _ID,float _observation[AgentsNumber])
{
	// 目标id
	int target_id = 0;
	// 目标优先级
	double ladarPriority[10] = { 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, };
	// 目标血量
	int health[10] = { 0 };
	// 目标距离
	double dist[10] = { 0 };
	// 评判攻击权重
	double weight[10] = { 0.0 };
	double min_weight = 1000000;

	for (int i = 0; i < 10; i++)
	{
		health[i] = static_cast<int>(_observation[i]);   //先将敌方的血量保存一下
		dist[i] = _observation[i];   //与敌方的距离
		if (health[i] == 0){
			weight[i] = 1000000;//当目标的血量为零时，将该目标的权重设为最大值，即不考虑向该目标移动
		}
		else{
		weight[i] = health[i] * health[i] * dist[i] * ladarPriority[i];  //先将敌方的血量保存一下
		}
		if (min_weight > weight[i]){
			min_weight = weight[i];
			target_id = i;
		}
	}
	std::cout<<_ID<<"'s target is :"<<target_id<<std::endl;
	return target_id;
}
/*************************************************************************
 * INPUT:   observation-- calculate the distance between plane and target
 *                                                                                             *
 *          health-- the health of all target
 *                                                                                             *
 * OUTPUT:  return target ID
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/13/2020 512tianjiaoworkstation : Created.                                                                 *
 *======================================================================*/

float* DPPolicyAgent::getMoveDirection(int id,float* start_pos,float *targetslocation,int target_id)
{

    float agent_max_speed[28] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,   //敌方10个目标保持不动
                                  1200.0, 1200.0, 1200.0, 1200.0, 1200.0, 1200.0, 1200.0, 1200.0,    //8个隐形战斗机的最大移动速度
                                  1000.0, 1000.0, 1000.0, 1000.0, 1000.0, 120.0, 80.0, 80.0, 80.0, 80.0 };  //干扰机、轰炸机、装甲车的最大移动速度

    std::cout<<"id:"<< id <<" position is: "<<start_pos[0]<<"    "<<targetslocation[0]<<std::endl;

	static float pos_inc[2];
	float dist = 0;

	dist = Utils::calculate_dist(start_pos, targetslocation);
	// 传进来的state[7] 只用前两个
	pos_inc[0] = (targetslocation[0] - start_pos[0]) * (agent_max_speed[id] / dist) * 0.00036;
	pos_inc[1] = (targetslocation[1] - start_pos[1]) * (agent_max_speed[id] / dist) * 0.00036;
//    std::cout<<pos_inc[0]<<std::endl;
	return pos_inc;
}



/*************************************************************************
 * INPUT:   i j and the distance calculate by calcalate_dist
 *                                                                                             *
 * OUTPUT:  None
 *                                                                                             *
 * HISTORY: 使用引用方法对所有28个agent修改不方便 适合只针对一个修改的情况
 *                                                                                             *
 *   12/13/2020 512tianjiaoworkstation : Created.                                                                 *
 *======================================================================*/
void DPPolicyAgent::move(float observation[], float pDouble[28][7])
{
//    std::cout<<"I am in dpmove now , and every agent's movement can be changed"<<std::endl;
    std::cout<<"------------------------------"<<std::endl;
	agentState.setMovement(90);

	switch (agentState.getId()) {

	case 0: agentState.setMovement(50); break;
	case 1: agentState.setMovement(50); break;
	case 2: agentState.setMovement(50); break;
	case 3: agentState.setMovement(50); break;
	case 4: agentState.setMovement(50); break;
	case 5: agentState.setMovement(50); break;
	case 6: agentState.setMovement(50); break;
	case 7: agentState.setMovement(50); break;
	case 8: agentState.setMovement(50); break;
	case 9: agentState.setMovement(50); break;
	case 18:
        if (agentState.getSloacation()[0] < 120.6) {
            agentState.setDirection(0.003,-0.003);
            break;
        }
	case 23:
        if (agentState.getSloacation()[0] < 120.6) {
            agentState.setDirection(0.003,-0.003);
            break;
        }
        else
        {
            agentState.setDirection(0,0);
            agentState.setMovement(50);
            break;
        }
        default:
            agentState.setDirection(moveBasedOnTarget(agentState.getId(),observation,pDouble));
            // 状态转移更新
            agentState.setIncSlocation(agentState.getDirection(0),agentState.getDirection(1));
	}
}

