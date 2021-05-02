#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* -------------------------------------------
 * 根据一行或一列数字中同一数字出现频率来判断 用map hashmap.clear();
 * 难点在于搞清楚遍历的层次顺序
 * 3*3 就存在四层循环嵌套
 * ------------------------------------------*/

bool isValid(string s)
{
    return s>"0" && s<"9";
}

void isValidSudoku(vector<vector<string>>sudo)
{
    unordered_map<char,int>hashmap;

    // 横行遍历
    for(vector<string> H : sudo)
    {
        for(int i = 0;i<H.size();i++)
        {
            if(isValid(H[i]))
            {
                hashmap[H[i][0]] += 1;
                if(hashmap[H[i][0]] == 2) return;
            }
        }
        hashmap.clear();
    }

    // 竖行遍历
    for(int i = 0; i< sudo.size();i++)
    {
        for(int j = 0;j<sudo.size();j++)
        {
            if(isValid(sudo[j][i]))
            {
                hashmap[sudo[j][i][0]] += 1;
                if(hashmap[sudo[j][i][0]] == 2) return;
            }
        }
        hashmap.clear();
    }

    // 3*3遍历 横行套竖行
    // H
    for(int k = 0; k < 3; k++)
    {
        // Z
        for(int p = 0; p < 3; p++)
        {
            // i = 0,p = 0,1,2; i = 1,p = 0,1,2
            for(int i = k * 3; i < (k + 1) * 3; i++)
            {
                for(int j = p * 3; j < p * 3 + 3; j++)
                {
                    if(isValid(sudo[j][i]))
                    {
                        hashmap[sudo[j][i][0]] += 1;
                        if(hashmap[sudo[j][i][0]] == 2) return;
                    }
                }
            }
            hashmap.clear();
        }
    }




    return ;
}

int main()
{
    vector<vector<string>> sudoKu{
    {"5","3",".",".","7",".",".",".","."},
    {"6",".",".","1","9","5",".",".","."},
    {".","9","8",".",".",".",".","6","."},
    {"8",".",".",".","6",".",".",".","3"},
    {"4",".",".","8",".","3",".",".","1"},
    {"7",".",".",".","2",".",".",".","6"},
    {".","6",".",".",".",".","2","8","."},
    {".",".",".","4","1","9",".",".","5"},
    {".",".",".",".","8",".",".","7","9"}
    };

    isValidSudoku(sudoKu);

    return 0;
}