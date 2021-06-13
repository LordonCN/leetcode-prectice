#include <iostream>
#include <vector>

using namespace std;

/* -------------------------------------------
 * 1 - 折半查找
 * 2 - vector 使用 iterator 进行查找 ac 100 50
 * 看看底层是怎么找的 总结一下
 * 普适性更强，查找速度应该比折半查找更快
 * 统计个数只需要迭代器之间做差即可
 * ------------------------------------------*/

vector<int> searchRange(vector<int> nums,int target)
{
    // 先二分法找到target所在下标 再对low high进行左右探索
    int low = 0;
    int high = nums.size()-1;
    int middle = (high+low)/2;
    bool sign = false; // 是否存在该目标

    // 找目标 是否存在target
    while(low<high)
    {
        int middle_ = (high+low)/2;
        if(nums[middle_] == target){
            sign = true;
            middle = middle_;
            break; // 进入到后面的左右探索
        }
        if(nums[middle_] < target){
            low = middle_ + 1;
        }
        else{
            high = middle_ - 1;
        }
    }

    high = middle + 1;
    low = middle - 1;
    // 找重复 确定该元素出现的频率
    while(sign)
    {
        if(nums[low] == nums[middle]) low -- ;
        if(nums[high] == nums[middle]) high++ ;
        if(nums[high] != nums[middle] && nums[low] != nums[middle] ) return vector<int>{low+1,high-1};
    }

    // 都没有
    return vector<int>{-1,-1};
}

vector<int> vectorFindIterator(const vector<int>& nums,const int & target)
{
    vector<int>result;
    result.push_back(-1);
    result.push_back(-1);
    // 使用迭代器进行查找
    vector<int>::iterator it = nums.begin();
    for(auto it = nums.begin();it != nums.end();it++)
        if(*it == target) break;// 找到了目标退出
        
    if(it == nums.end())return result;
    // 记录位置
    result[0] = it-nums.begin();
    while(it+1 != nums.end() && *it == *(it+1))
        it ++;
    result[1] = it-nums.begin();
    return result;
}

int main()
{
    // 首先准备好nums target
    vector<int> nums{0,1,2,3,7,8,8,9};

    int target = 8;
    vector<int>result;
    result = searchRange(nums,target);

    return 0;
}