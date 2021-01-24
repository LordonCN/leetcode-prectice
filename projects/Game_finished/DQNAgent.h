#ifndef DQNAGENT_H
#define DQNAGENT_H

#include "Agent.h"
//#include "Game.h"

// 强化学习规则控制

class DQNCraftAgent: public AgentAbstract
{
    //Linear 参数
    static const int node_number = 25;
    static const int input_dim = 28;
    static const int output_dim = 30;
    float weights[node_number][input_dim];
    float bias[node_number];
    double hidden_output[node_number];
    float inputs[input_dim];
    float outputs[output_dim];
    float available_actions[output_dim];

public:
	void attack(int target_id)override;
	void fallback()override;
    float* moveBasedOnTarget(int _ID, float _observation[AgentsNumber],float pDouble[28][7])override;
    int   choseAttackTarget(int _ID,float _observation[AgentsNumber])override;
    float* getMoveDirection(int id,float* start_pos,float *targetslocation,int target_id)override;

//    int chooseAction(float* net_outputs);
    void move(float observation[], float pDouble[28][7]) override;

};


#endif