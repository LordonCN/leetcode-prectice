#include <sstream>
#include "Utils.h"
#include "string"
#include "Params.h"

float Utils::calculate_dist(float pos1[], float pos2[] )
{
    float diff[2];
	diff[0] = pos1[0] - pos2[0];
	diff[1] = pos1[1] - pos2[1];
    float dist = sqrt(pow(diff[0]*100.6, 2) + pow(diff[1]*111, 2));
	return float(dist);
}
float Utils::calculate_dist(double pos1[],float pos2[] ) 
{
	// 一纬度111km 一经度100.6k
	double diff[2];
	diff[0] = pos1[0] - pos2[0];
	diff[1] = pos1[1] - pos2[1];
	double dist = sqrt(pow(diff[0]*100.6, 2) + pow(diff[1]*111, 2));
	return float(dist);
}

float Utils::stringToNum(const std::string& str)
{
    std::istringstream iss(str);
    float num;
    iss >> num;
    return num;
}

void Utils::writeDatatxt(std::string path, int data,bool bCover)
{

    //fstream fout(path, ios::app);
    std::fstream fout;
    if (bCover)
    {
        fout.open(path);//默认是：ios_base::in | ios_base::out
    }
    else
    {
        fout.open(path, std::ios::app);//所有写入附加在文件末尾
    }
    //fstream fout(path);
    fout << data << std::endl;
    fout.flush();
    fout.close();
}

void Utils::save_dqn_data(float observation[][32],float data[])
{
    std::fstream fout;
    fout.open(writeDataPath, std::ios_base::out);//默认是：ios_base::in | ios_base::out
    fout.flush();
    fout.close();
    // readtxt("observation.txt", points_num);
    for (int i = 0; i < 28; ++i)
    {
        for (int j= 0; j < 32; ++j)
        {
            writeDatatxt(writeDataPath, observation[i][j], false);
        }
    }
    for (int i = 0; i < 2; ++i)
    {
        writeDatatxt(writeDataPath, data[i], false);
    }
}
void Utils::save_qt_data(std::string writeQtDatePath)
{
    std::fstream fout;
    fout.open(writeQtDatePath, std::ios_base::out);//默认是：ios_base::in | ios_base::out
    fout.flush();
    fout.close();

    std::ostringstream os;
    int axis_x = 0;
    int axis_y = 0;
    srand((unsigned)time(NULL));
    writeCharDatatxt(writeQtDatePath,"30,2" , false);
    for (int i = 0; i < 30; ++i)
    {
        int randNUmber =  (rand()% 10)/3;
//        std::cout<<"randnumber is :" <<randNUmber<<std::endl;
        if(2 == randNUmber) // 偶数
        {
            if(axis_x<11)
                axis_x++;
            else
                axis_x = axis_x;
        }
        else if(1 == randNUmber)
        {
            if(axis_y<10)
                axis_y++;
            else
                axis_y = axis_y;
        }
        else
        {
            axis_y = axis_y;
            axis_x = axis_x;
        }
        os<<axis_x;
        os<<",";
        os<<axis_y;
        writeCharDatatxt(writeQtDatePath,os.str(), false);
        os.str("");
    }
}
void Utils::writeCharDatatxt(std::string path, std::string data,bool bCover)
{

    //fstream fout(path, ios::app);
    std::fstream fout;
    if (bCover)
    {
        fout.open(path);//默认是：ios_base::in | ios_base::out
    }
    else
    {
        fout.open(path, std::ios::app);//所有写入附加在文件末尾
    }
    //fstream fout(path);
    fout << data << std::endl;
    fout.flush();
    fout.close();
}


double Utils::relu(double x) {
    if (x > 0)
        return x;
    else
        return 0;
}

void Utils::readtxt(std::string name,int points_num[])
{
    std::ifstream in(name);
    std::string line;
    std::string num[1000];
    int i_1 = 0;
    int i_2 = 0;
    if (in) // 有该文件
    {
        while (getline(in, line)) // line中不包括每行的换行符
        {
            num[i_1] = line;
            i_1++;
        }
    }
    else // 没有该文件
    {
        std::cout << "no such file" << std::endl;
    }
    //将序号字符串转换为整形
    for (i_2 = 0; i_2 < i_1; i_2++)
    {
        points_num[i_2] = stoi(num[i_2]);
    }
}
