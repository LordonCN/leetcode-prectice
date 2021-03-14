class Solution {
public:
    bool isStraight(vector<int>& result) {
        sort(result.begin(),result.end());
        // 双指针 复杂度为n
        int left = 0,right = 4;
        while(left != right)
        {
            int temp = result[right]-result[right-1];//主要通过右侧移动来判断 左侧只用来辅助0的补偿
            //非0遇到重复 停止
            if(temp == 0 && result[right]!=0)
                return false;
                //中间差值过大左侧0能否弥补
            else if(temp > 1 && result[right-1]!=0)
            {
                while(temp>1)
                {
                    if(result[left] == 0)
                    {
                        left += 1; temp -= 1;
                    }
                    else return false;
                }
                right -= 1;
            }
                // 差值为1 继续
            else if(temp == 1)
                right-=1;
                // 到0了 直接停
            else return true;
        }
        return true;
    }
};