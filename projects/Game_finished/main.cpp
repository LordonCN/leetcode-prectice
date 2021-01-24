#include <iostream>
#include "Game.h"

using namespace std;
int max_step = MAX_STEP;
int dqnOK[1] = {0};
bool isDQNAgent = false;

int main()
{
/*************************************************************************
 *  DQN policy
 *======================================================================*/
//	Game game_dqn(1);
//	isDQNAgent = true;
//	// 这里完成初始化状态与游戏状态更新
//    Utils::writeCharDatatxt(writeGameStatePath, "0", true);
//    do
//    {
//        while(1)
//        {
//            Utils::readtxt(writeDQNStatePath, dqnOK);
//            if(dqnOK[0])
//                break;
//        }
////        Utils::writeCharDatatxt(writeDQNStatePath, "0", true);
//
//        game_dqn.step(isDQNAgent);
//
//        Utils::writeCharDatatxt(writeGameStatePath, "1", true);
//
//        if(game_dqn.gameStop)
//            break;
//    }
////    while(game_dp.getTimeStep()<max_step );
//    while(1);
//    game_dqn.saveQtDataFunction();

/*************************************************************************
 *  DQN policy
 *======================================================================*/
    Game game_dp(0);
    do
    {
        game_dp.step(isDQNAgent);

    }
    while(game_dp.getTimeStep()<max_step);
    game_dp.saveQtDataFunction();


}












