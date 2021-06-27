class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // vector<vector<int>>dp(nums.size(),vector<int>(2,0));
        // dp[0][0] = 0;
        // dp[0][1] = nums[0];
        // for(int i = 1;i<nums.size();i++)
        // {

        // }
        // return dp[][];
        if(nums.empty())return 0;
        vector<int>dp(nums.size(),0);
        dp[0] = nums[0];
        for(int i = 1;i<nums.size();i++)
        {
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
        }
        sort(dp.begin(),dp.end());
        return dp[nums.size()-1];

    }
};