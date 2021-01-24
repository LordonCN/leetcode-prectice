#ifndef GAME_H
#define GAME_H

#include "Agent.h"
#include "DPAgent.h"
#include "DQNAgent.h"
#include <vector>
#include "Agents.h"
#include <string>

#define MAX_STEP 100

class Game
{
private:
 
	float time;
	float delta_time ;
	float time_step  ;
    // static const int max_step = 100 ;
	int actionSelectByDQN;
    int policyChoice;  // 0-dp 1-dqn


public:
	// 包含敌方 我方单位 使用vector 智能指针 条款16 17
    // Agents * agents;
    // std::shared_ptr<Agents> agents (new Agents(policyChoice)); //智能指针声明的时候就初始化完毕
	std::shared_ptr<Agents> agents; // 先声明

    float state[AgentsNumber][7];
    float observation[AgentsNumber][32]; // [id][id] 可以存储血量
    float gameRewardAndState[2] = {0};
    int action[AgentsNumber] = {0};
    static const int nactions = 28 + 1 + 1;
    static const int nunits = 28;
    float available_actions[nunits][nactions];
    bool gameStop ;


	Game(int plan);
	Game() = default;
	~Game();

	void resetState();                               // 置位所有单元状态
	void choseAndTakeAction(bool isDQNAgent);
	void takeDPPolicyAction();
	void takeDQNPolicyAction();
	void update_state();
	// 添加其他结束条件
	bool isEnd(int AllyNumber,int EnemyNumber,float time);
    void observe() ;
    void step(bool isDQNAgent);
    float getTimeStep() const;
    void saveQtDataFunction();

	// void step(DQNCraftAgent agent[]);
	// void observe(DQNCraftAgent agent[]);
	// void update_state(DQNCraftAgent agent[]);
	// void settlement(DQNCraftAgent agent[]);

    void setPolicyChoice(int policyChoiceNumber){policyChoice = policyChoiceNumber;};
    float* loadparameters(std::string str);
//	int getTimeStep() {return time_step;};
//	int getMaxStep() {return MAX_STEP;};
//	int getPolicyCHoice(){return policyChoice;};

};

// class DPGame:public Game
// {

#endif