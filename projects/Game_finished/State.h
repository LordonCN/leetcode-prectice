#ifndef STATE_H
#define STATE_H

#include "Params.h"
#include <iostream>
class State
{
private:
    int health  ;
    int ammo ;
	float slocation[2];
	int hight;
    int id ;
	float direction[2];
	double start_position[2];

	int movement;
	int unit_type;
	bool circle;
	float detection_range;
	float attack_range ;
	int direction_flag;
	int fire_channel;
	bool planenable ;
	bool is_attacked;
	int planNumber;



public:
    State();
    ~State(){};
	bool canMove = false;
    enum side { red, blue } side;
    // 这里可以加当前是否允许攻击
     enum {attack,noattack};
    // int state;
    // void setAttackMode(){state = (state==attack)?noattack:attack};

	void  setHealth(int);
	void  setState(int id_,float target_x,float target_y );
	void  setSlocation(int number,int x,int y,int height);
	void  setSlocation(float x,float y){ slocation[0]=x;slocation[1]=y;};
    void  setIncSlocation(float x,float y){ slocation[0]+=x;slocation[1]+=y;};
//	void  setObservation(int i ,int j,float distance);
	void  setDirection(float dire_x[2]){direction[0] = dire_x[0]; direction[1] = dire_x[1];};
    void  setDirection(float dire_x,float dire_y){direction[0] = dire_x; direction[1] = dire_y;};
	void  setAmmo(int);
	void  setAttackRange(int number){this->attack_range = number;};
	void  setID(int i ){this->id = i; };
	void  setPlanNumber(int i ){this->planNumber= i;};
	void  setMovement(int);
	void  setAttackState(int number ){this->is_attacked = number;};
	void  changeHealth(int);
	void  setAgentType(int i){this->unit_type = unit_type_list[i];};

	int   getHealth()  {return health;};
	float*getSloacation() {return (float*)slocation;};// 返回当前坐标数组
//	float*getObservation()  {return (float*)observation;};
	float getDirection(int axic)  {return direction[axic];};
    float getAttackRange()  {return attack_range;};
	float getStartPosition(int number,int position)  {return start_pos[number][position];};// 返回初始坐标
	int   getMovement() {return this->movement;};
	int   getAmmo()  {return ammo;};
	int   getId()const {return this->id;};
	int   getAttackState() {return this->is_attacked;};
    int   getAgentType() {return this->unit_type;};

	int unit_type_list[28] =
    {
        -1,	//雷达1
        -1,	//雷达2
        0,	//铁穹1　　　　无模型　坦克代替
        0,	//铁穹2　　　　无模型　坦克代替
        0,	//铁穹3　　　　无模型　坦克代替
        0,	//铁穹4　　　　无模型　坦克代替
        0,	//铁穹5　　　　无模型　坦克代替
        0,	//铁穹6　　　　无模型　坦克代替
        1,	//响尾蛇1　　　无模型　坦克代替
        1,	//响尾蛇2　　　无模型　坦克代替
        2,	//隐形战斗机1
        2,	//隐形战斗机2
        2,	//隐形战斗机3
        2,	//隐形战斗机4
        2,	//隐形战斗机5
        2,	//隐形战斗机6
        2,	//隐形战斗机7
        2,	//隐形战斗机8
        3,	//干扰机
        4,	//轰炸机1　	　无模型　F18代替
        4,	//轰炸机2　	　无模型　F18代替
        4,	//轰炸机3　	　无模型　F18代替
        4,	//轰炸机4　	　无模型　F18代替
        5,	//船坞登陆舰　
        6,	//两栖装甲车1
        6,	//两栖装甲车2
        6,	//两栖装甲车3
        6	//两栖装甲车4
    };
    float start_pos[28][3] =
    {
        {120.18, 24.79, 100},		//	雷达1
        {119.65, 23.77, 100},		//	雷达2
        {120.17, 24.79, 100},		//	铁穹1　　　　
        {120.16, 24.79, 100},		//	铁穹2　　　　
        {120.17, 24.78, 100},		//	铁穹3　　　　
        {119.64, 23.77, 100},		//	铁穹4　　　　
        {119.64, 23.76, 100},		//	铁穹5　　　　
        {119.64, 23.76, 100},		//	铁穹6　　　　
        {120.17, 24.78, 100},		//	响尾蛇1　　　
        {119.65, 23.76, 100},		//	响尾蛇2　　　
        {119.72, 25.65, 10000},		//	隐形战斗机1
        {119.72, 25.65, 10000},		//	隐形战斗机2
        {119.72, 25.65, 10000},		//	隐形战斗机3
        {119.72, 25.65, 10000},		//	隐形战斗机4
        {118.72, 25.65, 10000},		//	隐形战斗机5
        {118.72, 25.71, 10000},		//	隐形战斗机6
        {118.72, 25.71, 10000},		//	隐形战斗机7
        {118.72, 25.71, 10000},		//	隐形战斗机8
        {118.72, 25.71, 10000},		//	干扰机
        {118.72, 25.71, 15000},		//	轰炸机1　	　
        {118.72, 25.71, 15000},		//	轰炸机2　	　
        {118.72, 25.71, 15000},		//	轰炸机3　	　
        {118.72, 25.71, 15000},		//	轰炸机4　
        {118.79, 25.4, 100},		//	船坞登陆舰　
        {118.79, 25.4, 100},		//	两栖装甲车1
        {118.79, 25.4, 100},		//	两栖装甲车2
        {118.79, 25.4, 100},		//	两栖装甲车3
        {118.79, 25.4, 100},		//	两栖装甲车4
    };

};


#endif