

// 参考 https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/nge-tou-zi-de-dian-shu-dong-tai-gui-hua-ji-qi-yo-3/
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<int>dp(70,0);
        // 初始化第一次投掷结果 所有可能性均为1
        for (int i = 1; i <= 6; i ++) {
            dp[i] = 1;
        }
        // 第二个骰子开始
        for (int i = 2; i <= n; i ++) {
            // 填充所有可能出现的可能性
            for (int j = 6*i; j >= i; j --) {// 在上一个骰子的基础上能够到达的最大值
                dp[j] = 0;
                for (int cur = 1; cur <= 6; cur ++) {
                    if (j - cur < i-1) {
                        break;
                    }
                    dp[j] += dp[j-cur];
                }
            }
        }
        // 能够出现的可能/所有可能性
        int all = pow(6,n);
        vector<double> ret;
        for (int i =n; i <= 6 * n; i ++) {
            ret.push_back(dp[i] * 1.0 / all);
        }
        return ret;
    }
};