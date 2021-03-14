class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>result;
        if(!nums.size())return result;

        for(int i = 0;i<nums.size()-k+1;i++)
        {
            compareMax(result,nums,i,k);
        }
        return result;
    }
    void compareMax(vector<int>&result,vector<int>nums,int i,int k)
    {
        vector<int>temp = nums;
        sort(temp.begin()+i,temp.begin()+i+k);
        result.push_back(temp[i+k-1]);
    }
};