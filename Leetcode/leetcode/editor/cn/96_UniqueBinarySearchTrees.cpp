/**
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。 

 

 示例 1： 
 
 
输入：n = 3
输出：5
 

 示例 2： 

 
输入：n = 1
输出：1
 

 

 提示： 

 
 1 <= n <= 19 
 

 Related Topics 树 二叉搜索树 数学 动态规划 二叉树 👍 1905 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    //思考
    //不会

    //这tm是一个数学问题
public:
    int numTrees(int n) {
        /**
        	执行耗时:0 ms,击败了100.00% 的C++用户
	        内存消耗:5.8 MB,击败了82.42% 的C++用户
        */
        vector<int> dp(n+1);
        dp[0]=1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i-1; j++) {
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }

        return dp[n];

    }
};
//leetcode submit region end(Prohibit modification and deletion)
