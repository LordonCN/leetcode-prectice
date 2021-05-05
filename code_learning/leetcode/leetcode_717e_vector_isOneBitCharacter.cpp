#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/* -------------------------------------------
 * 没用到位操作 第一感觉就是数组遍历一下
 * 有点像DP
 * ------------------------------------------*/

bool isOneBitCharacter(vector<int>& bits) {
    // 如果最后一个为1 直接结束
    if(bits.back())return false;
    // 当前还有多少个字符
    int length = bits.size();
    if(length == 1)return true;
    else if(length == 2 && bits[0])return false;
    // 2个以上的时候 使用
    for(int i = 0;i<length-1;i++)
    {
        if(bits[i])// 如果当前位为1 那么下一位必须要存在 否则return false
        {
            if((i+1)<(length-1))
                i++;
            else
                return false;
        }
    }
    return true;
}

int main()
{
    vector<int>ans{1,1,1,0,0,1,0};
    isOneBitCharacter(ans);

    return 0;
}
