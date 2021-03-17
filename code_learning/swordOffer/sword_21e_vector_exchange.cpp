vector<int> exchange(vector<int>& nums) {
    vector<int>oushu;
    vector<int>result;
    vector<int>::iterator ite = nums.begin();
    while(ite != nums.end())
    {
        if(*ite%2 == 0)
        {
            oushu.push_back(*ite);
            nums.erase(ite);
            continue;
        }
        ite+=1;
    }
    nums.insert(nums.end(),oushu.begin(),oushu.end());
    return nums;
}
// 涉及两vector组合拼接
// 迭代器遍历 erase操作容易产生迭代器的错位 循环操作不建议使用