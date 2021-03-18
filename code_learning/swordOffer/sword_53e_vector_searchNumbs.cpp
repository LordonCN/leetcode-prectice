int search(vector<int>& nums, int target) {
    if(nums.empty())return 0;
    int l = 0;
    unordered_map<int,int>store;

    while(l<nums.size())
    {
        if(nums[l]<target)l+=1;
        else if(nums[l]>target) break;
        else
        {
            store[target] += 1;
            l += 1;
        }
    }

    return store[target];
}
