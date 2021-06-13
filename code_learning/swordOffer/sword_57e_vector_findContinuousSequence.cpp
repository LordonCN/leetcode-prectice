vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>>result;
    vector<int>temp;
    for(int i =1;i<=target/2;i++)
    {
        temp.push_back(i);
        for(int t = i+1;t<target;t++)
        {
            temp.push_back(t);
            int sum = accumulate(temp.begin(),temp.end(),0);
            if(sum>target)
            {
                temp.erase(temp.begin(),temp.end());
                temp.shrink_to_fit();
                break;
            }
            else if(sum == target)
            {
                result.push_back(temp);
                temp.erase(temp.begin(),temp.end());
                temp.shrink_to_fit();
                break;
            }
        }
    }
    return result;
}
