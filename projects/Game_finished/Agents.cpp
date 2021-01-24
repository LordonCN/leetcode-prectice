// Created by admin on 2020/12/24.
//

#include "Agents.h"


Agents::Agents(int plan)
{
    // 智能指针多态
    std::shared_ptr<DPPolicyAgent> DPPointer(new DPPolicyAgent);
    std::shared_ptr<DQNCraftAgent> DQNPointer(new DQNCraftAgent);

    switch (plan) {
        // dp策略
    case 0:
        for (int i = 0; i < 10; i++) {
            enemy.push_back(DPPointer);
        }
        for (int i = 0; i < 18; ++i) {
            ally.push_back(DPPointer);
        }
        break;
        // dqn策略
    case 1:
        for (int i = 0; i < 10; i++) {
            enemy.push_back(DQNPointer);
        }
        for (int i = 0; i < 18; ++i) {
            ally.push_back(DQNPointer);
        }
        break;
    default:

        break;
    }
    all_agents.insert(all_agents.end(),enemy.begin(),enemy.end());
    all_agents.insert(all_agents.end(),ally.begin(),ally.end());
}

Agents::~Agents()
{
    // 改用智能指针不用手动删除内存
//    for(int i = 0; i<10;i++){
//        delete enemy[i];
//    }
//    for(int i = 0; i<18;i++){
//        delete ally[i];
//    }
//    for(int i = 0; i<28;i++){
//        delete all_agents[i];
//    }
    // vector 内存释放
    enemy.clear();
    enemy.shrink_to_fit();
    ally.clear();
    ally.shrink_to_fit();
    all_agents.clear();
    all_agents.shrink_to_fit();

}

const std::vector<std::shared_ptr<AgentAbstract>> &Agents::getEnemy() const {
    return enemy;
}


const std::vector<std::shared_ptr<AgentAbstract>> &Agents::getAlly() const {
    return ally;
}

const std::vector<std::shared_ptr<AgentAbstract>> &Agents::getAllAgents() const {
    return all_agents;
}












