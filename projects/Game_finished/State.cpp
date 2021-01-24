#include "State.h"
#include "params.h"
#include <string.h>

State::State()
{
	slocation[2] = SLOCATION;
	direction[2] = DIRECTION;
	start_position[2] = START_POSITION;
	memset(slocation, 0, sizeof(slocation));
	memset(direction, 0, sizeof(direction));
	memset(start_position, 0, sizeof(start_position));
	planNumber = 0;
    health = HEALTH;
	ammo = AMMO;
	hight = HEIGHT;
	id = ID;
	movement = MOVEMENT;
	unit_type = UNIT_TYPE;
	circle = CIRCLE;
	detection_range = DETECTION_RANGE;
	attack_range =ATTACK_RANGE;
	direction_flag = DIRECTION_FLAG;
	fire_channel = FIRE_CHANNEL;
	planenable = PLANENABLE;
	is_attacked = IS_ATTACKED;


}
/*************************************************************************
 * INPUT:   
 *                                                                                             *
 * OUTPUT:  None
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/13/2020 512tianjiaoworkstation : Created.                                              *
 *======================================================================*/
void  State::setHealth(int number)
{
	health = number;
}
void  State::changeHealth(int number)
{
	health -= number;
}

void  State::setAmmo(int number)
{
	ammo = number;
}


/*************************************************************************
 * INPUT:   number:which agent
 *          x:x-axis
 * 			y:y-axis                                                                           *
 * 			height
 * OUTPUT:  None
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/13/2020 512tianjiaoworkstation : Created.                                              *
 *======================================================================*/
void  State::setSlocation(int number, int x, int y,int height)
{
	// 每一个agent都有xy坐标
	slocation[0] = getStartPosition(number,x); 
	slocation[1] = getStartPosition(number,y);
	height = height;
}


void State::setMovement(int movement_)
{ 
	movement = movement_;
}

// void State::attack(int target_id)
// {
// 	movement = target_id;
// 	ammo--;
// }
