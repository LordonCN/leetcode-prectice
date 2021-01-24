#ifndef DPAGENT_H
#define DPAGENT_H

#include "Agent.h"
//#include "Game.h"

// unit class 手动规则

class DPPolicyAgent : public AgentAbstract
{
public:
    int  choseAttackTarget(int _ID,float _observation[AgentsNumber])override;
	void move(float observation[], float pDouble[28][7]) override;
    float* getMoveDirection(int id,float* start_pos,float *targetslocation,int target_id)override;
    float* moveBasedOnTarget(int _ID, float _observation[AgentsNumber],float pDouble[28][7])override;

	void attack(int target_id)override;
	void fallback()override;


};


#endif