#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include "cmath"
#include <fstream>
#include "sstream"
#include <string>
#include <time.h>

class Utils
{
public:
    static float calculate_dist(float pos1[2], float pos2[2]);
    static float calculate_dist(double pos1[2], float pos2[2]);

    static float stringToNum(const std::string &str);
    static void save_dqn_data(float observation[][32],float data[]);
    static void save_qt_data(std::string writeQtDataPath);
    static void writeDatatxt(std::string path, int data,bool bCover);
    static void writeCharDatatxt(std::string path, std::string data,bool bCover);

    static double relu(double x);
    static void readtxt(std::string name,int points_num[]);

};




#endif
