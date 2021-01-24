#ifndef PARAMS_H
#define PARAMS_H

#include <string>

#define AgentsNumber 28
#define HEALTH 2
#define AMMO  2
#define SLOCATION {0}
#define HEIGHT  1500
#define STATE  {0}
#define OBSERVATION {0}// [id][id] 可以存储血量
#define ID 0
#define ACTION  {0}
#define START_POSITION  {0}
#define DIRECTION  {0}
#define MOVEMENT 0
#define UNIT_TYPE  0
#define CIRCLE  0
#define DETECTION_RANGE  100
#define ATTACK_RANGE  40
#define DIRECTION_FLAG  1
#define FIRE_CHANNEL  1
#define PLANENABLE  1
#define IS_ATTACKED 0
#define PLANNUMBER 0

#define writeDataPath  "../observation.txt"
#define writeActionDataPath  "../action.txt"
#define writeGameStatePath  "../gameOK.txt"
#define writeDQNStatePath  "../DQNOK.txt"
#define writeQTDataPath  "../QtData/"

// float start_pos[28][3];


#endif