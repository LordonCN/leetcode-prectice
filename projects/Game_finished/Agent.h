#ifndef AGENT_H
#define AGENT_H

#include "Utils.h"
#include <string>
#include "Params.h"
#include "State.h"

// #include "DPAgent.h"

// class Side
// {
// 	enum side { red, blue } side;
// };

class AgentAbstract
{
private:
        std::string unit_name_list[28] =
            {
                    "SF600-RADER-1",	//雷达1
                    "SF600-RADER-2",	//雷达2
                    "SF600-AAMB-1",	//铁穹1　　　　无模型　坦克代替
                    "SF600-AAMB-2",	//铁穹2　　　　无模型　坦克代替
                    "SF600-AAMB-3",	//铁穹3　　　　无模型　坦克代替
                    "SF600-AAMB-4",	//铁穹4　　　　无模型　坦克代替
                    "SF600-AAMB-5",	//铁穹5　　　　无模型　坦克代替
                    "SF600-AAMB-6",	//铁穹6　　　　无模型　坦克代替
                    "SF600-ATMB-1",	//响尾蛇1　　　无模型　坦克代替
                    "SF600-ATMB-2",	//响尾蛇2　　　无模型　坦克代替
                    "SF600-AIR-1",	//隐形战斗机1
                    "SF600-AIR-2",	//隐形战斗机2
                    "SF600-AIR-3",	//隐形战斗机3
                    "SF600-AIR-4",	//隐形战斗机4
                    "SF600-AIR-5",	//隐形战斗机5
                    "SF600-AIR-6",	//隐形战斗机6
                    "SF600-AIR-7",	//隐形战斗机7
                    "SF600-AIR-8",	//隐形战斗机8
                    "SF600-JAMMER-1",	//干扰机
                    "SF600-BOMBER-1",	//轰炸机1　	　无模型　F18代替
                    "SF600-BOMBER-2",	//轰炸机2　	　无模型　F18代替
                    "SF600-BOMBER-3",	//轰炸机3　	　无模型　F18代替
                    "SF600-BOMBER-4",	//轰炸机4　	　无模型　F18代替
                    "SF600-RADER-2",	//船坞登陆舰　
                    "SF600-TANK-1",	//两栖装甲车1
                    "SF600-TANK-2",	//两栖装甲车2
                    "SF600-TANK-3",	//两栖装甲车3
                    "SF600-TANK-4"		//两栖装甲车4
            };

protected:
        void defaultAttack(int target_id);
        void defaultFallback();

public:
        State agentState; // 每个agent的状态

        AgentAbstract() ;
        virtual ~AgentAbstract(); // 定义为virtual -> 基于多态动态绑定性 p163 181


        // 单元包含的动作功能 声明为纯虚函数为子类只提供继承接口 实现此处控制方案的选择
        virtual void attack(int target_id) = 0;  // 添加默认攻击方式  inline 函数方法 p165
        virtual void fallback() = 0;  // 添加默认攻击方式  inline 函数方法 p165
        virtual void move(float observation[], float pDouble[28][7]) = 0;
        virtual	float* moveBasedOnTarget(int _ID, float _observation[AgentsNumber],float pDouble[28][7]) = 0;
        virtual int   choseAttackTarget(int _ID,float _observationi[AgentsNumber])= 0 ;
        virtual float* getMoveDirection(int id,float* start_pos,float *targetslocation,int target_id)= 0;

};

#endif