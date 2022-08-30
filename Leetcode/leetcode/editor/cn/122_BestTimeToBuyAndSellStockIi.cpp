/**
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。 

 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。 

 返回 你能获得的 最大 利润 。 

 

 示例 1： 

 
输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
     总利润为 4 + 3 = 7 。 

 示例 2： 

 
输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     总利润为 4 。 

 示例 3： 

 
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0 。 

 

 提示： 

 
 1 <= prices.length <= 3 * 10⁴ 
 0 <= prices[i] <= 10⁴ 
 

 Related Topics 贪心 数组 动态规划 👍 1818 👎 0

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
    //先做的714题，再做这个应该简单
    //贪心：只要比前一天高，我就卖。只要一直跌，我就买跌的最低点的
    //动态规划：两个数组

public:
    int maxProfit1(vector<int>& prices) {
        //贪心算法
        /**
        	执行耗时:4 ms,击败了90.79% 的C++用户
	        内存消耗:12.6 MB,击败了69.19% 的C++用户
        */
        int res=0;
        int minPri = prices[0];
        int priSize = prices.size();
        for (int i = 0; i <= priSize-1; i++) {
            if (minPri>prices[i]){
                minPri=prices[i];
            } else if (minPri<prices[i]){
                res += prices[i]-minPri;
                minPri= prices[i];
            }
        }
        return res;
    }

    int maxProfit(vector<int>& prices) {
        //动态规划
        /**
        	执行耗时:4 ms,击败了90.79% 的C++用户
	        内存消耗:14.8 MB,击败了6.35% 的C++用户
        */
        int priSize = prices.size();
        vector<vector<int>> myVec(priSize,vector<int>(2,0));
        myVec[0][0]= -prices[0];//hold shares
        myVec[0][1]=0;
        for (int i = 1; i <= priSize - 1; i++) {
            myVec[i][0]= max(myVec[i-1][0],myVec[i-1][1]-prices[i]);//hold shares
            myVec[i][1]= max(myVec[i-1][1],myVec[i-1][0]+prices[i]);//hold money
        }
        return myVec[priSize-1][1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
