int findRepeatNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int l = 0,r = nums.size()-1;
    while(l<r)
    {
        if(nums[l] == nums[l+1])return nums[l];
        else
            l += 1;
        if(nums[r] == nums[r-1])return nums[r];
        else
            r -= 1;
    }
    return -1;
}