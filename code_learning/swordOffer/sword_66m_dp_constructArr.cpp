
/*************************************************************************
 * 上三角与下三角进行存储
 * 超时
 * https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/solution/shang-san-jiao-xia-san-jiao-by-dan-che-c-fvpu/
*======================================================================*/

vector<int> constructArr(vector<int>& a) {
    int size = a.size();
    vector<vector<int>>dp(size,vector<int>(size,0));
    for(int i = 1;i<size;i++)// 最左列填充 a[0]
    {
        dp[i][0] = a[0];
    }
    for(int i = 0;i<size-1;i++)// 最右列上三角填充 a[size-1]
    {
        dp[i][size-1] = a[size-1];
    }
    // 左下三角填充
    for(int i = 1;i<size;i++)
    {
        for(int j = 1;j<i;j++)
        {
            dp[i][j] = a[j] * dp[i][j-1];
        }
    }
    for(int i = 0;i<size-1;i++)
    {
        for(int j = size-2;j>i;j--)
        {
            dp[i][j] = a[j] * dp[i][j+1];
        }
    }
    vector<int>output(size,0);
    for(int i = 0;i<size;i++)
    {
        if(i-1>=0 && i+1<size)
            output[i] = dp[i][i-1] * dp[i][i+1];
        else if(i-1>=0)
            output[i] = dp[i][i-1];
        else
            output[i] = dp[i][i+1];
    }
    return output;

}