#include <iostream>
#include "listNode.h"
#include <string>
#include <vector>
using namespace std;

/* -------------------------------------------
 * 完全背包问题
 * 外层target
 * 内层遍历所有num
 * ------------------------------------------*/

bool wordBreak(string s,const vector<string>&wordDict)
{
	vector<bool>dp(s.size()+1,false);
	dp[0] = true;// 空字符的情况是成立的
	for(int i = 1;i<=s.size();i++)
	{
		for(auto word:wordDict)
		{
			int length = word.size();
			if((i-length)>=0 && s.substring(i-length,i)==word)
			{
				dp[i] = dp[i] || dp[i-length];
			}
		}
	}
	return dp[s.size()];
}


int main()
{
   string s = "leetcode";
   vector<string>wordDict{"leet","code"};
   wordBreak(s,wordDict);
   return 0;
}
