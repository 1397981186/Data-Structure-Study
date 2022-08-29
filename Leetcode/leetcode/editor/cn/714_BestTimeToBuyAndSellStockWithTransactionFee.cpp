/**
给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。 

 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。 

 返回获得利润的最大值。 

 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。 

 

 示例 1： 

 
输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
输出：8
解释：能够达到的最大利润:  
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8 

 示例 2： 

 
输入：prices = [1,3,7,5,10,3], fee = 3
输出：6
 

 

 提示： 

 
 1 <= prices.length <= 5 * 10⁴ 
 1 <= prices[i] < 5 * 10⁴ 
 0 <= fee < 5 * 10⁴ 
 

 Related Topics 贪心 数组 动态规划 👍 778 👎 0

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
    //? 看题解，找套路

    //贪心策略：只要当前价格大于（最低价格+手续费），就可以收获利润，
    // 至于准确的卖出日期，就是连续收获利润区间里的最后一天（并不需要计算是具体哪一天）。
    //计算最大利润，需要巧妙地利用数学
    //注意 模拟持有的方式
    //最后买入了没有卖出？ 无所谓，算的是利润，又不是净资产

    //动态规划
    //第i天持股票所剩最多现金 = max(第i-1天持股票所剩现金, 第i-1天持现金-买第i天的股票)
    //如果第 i 天手上有股票，要么是 i - 1 有股票，今天什么都不做。要么是 i - 1 手上没有股票，今天买了它。因此 dp[i][0] 就是这两种情况的利润最大值。
    //第i天持有最多现金 = max(第i-1天持有的最多现金，第i-1天持有股票的最多现金+第i天卖出股票)
    //如果第 i 天手上没有股票，要么是 i - 1 没股票，今天什么都不做。要么是 i - 1 手上有股票，今天卖了它。因此 dp[i][1] 就是这两种情况的利润最大值。
    //return max(dp[n - 1][0], dp[n - 1][1]); ---> dp[0][1]=0 , dp[0][0] -= prices[0]; 则最后的现金就是利润
    // holdMoney , holdShares
public:
    int maxProfit1(vector<int>& prices, int fee) {
        //贪心策略
        /**
        	执行耗时:72 ms,击败了94.93% 的C++用户
	        内存消耗:53.6 MB,击败了77.02% 的C++用户
        */
        int res = 0;
        int minPri = prices[0] ;
        for (int pri : prices) {
            if (minPri>pri){
                minPri=pri;//相当于买入
            }else if (minPri<pri-fee){
                res+=pri-fee- minPri;
                minPri=pri-fee;//保证最后卖出的日期是持续盈利的最后一日
            }
        }
        return res;
    }

    int maxProfit(vector<int>& prices, int fee) {
        //动态规划
/**
	执行耗时:188 ms,击败了17.92% 的C++用户
	内存消耗:88.6 MB,击败了41.21% 的C++用户
*/
        int priSize = prices.size();
        vector<vector<int>> myVec(priSize,vector<int>(2,0));//注意学习此处的初始化方式,多重的嵌套
        //myVex[i][0] for holdShares
        //myVec[i][1] for holdMoney
        myVec[0][0]= -prices[0];
        myVec[0][1]=0;//初始资金为0，最后所得值就是纯利润

        for (int i = 1; i <= priSize - 1; i++) {//动态规划,想当于考虑了所有可能的情况(买，或者卖或者不买)
            myVec[i][0]= max(myVec[i-1][0],myVec[i-1][1]-prices[i]);
            //持有股票的两种情况：继续持有i-1天的，或者 买第i天的
            //取max，有贪心思想在里面。如果我们决定现在持有，那么就看是之前买便宜还是今天买便宜。取max可以保证持有最低点
            myVec[i][1]= max(myVec[i-1][1],myVec[i-1][0]+prices[i]-fee);
            //持有现金的两种情况：继续持有i-1天的，或者 在第i天卖掉股票
            //取max，如果实际上是明天i+1天卖掉更好，那么计算i+1时会进行处理。取max可以保证卖出最高点
        }

        return myVec[priSize-1][1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
