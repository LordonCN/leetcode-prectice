#include "Agent.h"
using namespace std;

AgentAbstract::AgentAbstract()
{

}

AgentAbstract::~AgentAbstract()
{

}



/*************************************************************************
 * INPUT:   target_id
 *                                                                                             *
 * OUTPUT: 
 *                                                                                             *
 * WARNINGS:   This the default attack way, use inline + virtusl methord
 *                                                                                             *
 * HISTORY:
 *   12/13/2020 JLB : Created.                                                                 *
 *======================================================================*/
void AgentAbstract::defaultAttack(int target_id)
{
    this->agentState.setMovement(target_id);
    this->agentState.setAmmo(-1);
}

/*************************************************************************
 * INPUT:   None
 *                                                                                             *
 * OUTPUT:  
 *                                                                                             *
 * WARNINGS:   默认返航函数 
 *                                                                                             *
 * HISTORY:
 *   12/13/2020 JLB : Created.                                                                 *
 *======================================================================*/
void AgentAbstract::defaultFallback()
{
    float speed = 0;
    this->agentState.setMovement(80);
    if (3 == agentState.getAgentType()) {
        speed = 0.035;
    }
    else if(5 == agentState.getAgentType())
    {
        speed = 0.025;
    }
    else if(7 == agentState.getAgentType())
    {
        speed = 0.003;
    }
    float dist = Utils::calculate_dist(this->agentState.getSloacation(),this->agentState.getSloacation());
    agentState.setDirection((119.77 - agentState.getSloacation()[0]) / dist * speed * 100 * 0.055,(25.41 - agentState.getSloacation()[1]) / dist * speed * 100 * 0.055) ;

    if (agentState.getDirection(0)>= 0) {
        agentState.setSlocation(119.770,25.420);
        return;
    }

    agentState.setIncSlocation(agentState.getDirection(0),agentState.getDirection(1));

    std::cout << agentState.getId()<< " fallback"<< std::endl;
    std::cout << agentState.getId() << " fallback"<< std::endl;
}