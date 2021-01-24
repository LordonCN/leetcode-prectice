//
// Created by admin on 2020/12/24.
//

#ifndef AGENTS_H
#define AGENTS_H

#include "vector"
// 里面均包括agent.h
#include "DPAgent.h"
#include "DQNAgent.h"
#include <memory>

class Agents {
public:
    Agents(){};
    Agents(int plan);
    ~Agents();

    const std::vector<std::shared_ptr<AgentAbstract>> &getEnemy() const;

    const std::vector<std::shared_ptr<AgentAbstract>> &getAlly() const;

    const std::vector<std::shared_ptr<AgentAbstract>> &getAllAgents() const;

private:
    // TODO:21.1.2改用智能指针 这里指针类型为基类 cpp中再创建具体类型
    // 敌方单位i
    std::vector<std::shared_ptr<AgentAbstract>> enemy;
    // 我方单位i
    std::vector<std::shared_ptr<AgentAbstract>> ally;
    std::vector<std::shared_ptr<AgentAbstract>> all_agents;

};

//class Agents {
//public:
//    Agents(){};
//    Agents(int plan);
//    ~Agents();
//
//    const std::vector<AgentAbstract *> &getEnemy() const {
//        return enemy;
//    }
//    const std::vector<AgentAbstract *> &getAlly() const {
//        return ally;
//    }
//
//    void setEnemy(const std::vector<AgentAbstract *> &enemy);
//    void setAlly(const std::vector<AgentAbstract *> &ally);
//
//    const std::vector<AgentAbstract *> &getAllAgents()const;
//
//
//private:
//    // 敌方单位i
//    std::vector<AgentAbstract*> enemy;
//    // 我方单位i
//    std::vector<AgentAbstract*> ally;
//    std::vector<AgentAbstract*> all_agents;
//
//};


#endif //GAME_12_24_AGENTS_H
