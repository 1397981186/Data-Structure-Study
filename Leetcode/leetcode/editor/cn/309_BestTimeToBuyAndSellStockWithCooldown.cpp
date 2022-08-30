/**
给定一个整数数组
 prices，其中第 prices[i] 表示第 i 天的股票价格 。 

 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）: 

 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。 

 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 

 

 示例 1: 

 
输入: prices = [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出] 

 示例 2: 

 
输入: prices = [1]
输出: 0
 

 

 提示： 

 
 1 <= prices.length <= 5000 
 0 <= prices[i] <= 1000 
 

 Related Topics 数组 动态规划 👍 1304 👎 0

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
    //冷冻期：前一天卖掉股票会对今天的购买产生影响
    //贪心：？？ 每次利润最大的同时还要妥协在最低点买？
    //动态规划：三维，其中一维用于记录冻结期--》不可，迭代没有思路

    //题解
    //解决此题，需要用到状态机。股票题都有状态机思想
    //分成3个状态，再沿用之前的方法就可求解。

public:
    int maxProfit(vector<int>& prices) {

        /**
        	执行耗时:4 ms,击败了74.63% 的C++用户
	        内存消耗:11.5 MB,击败了14.57% 的C++用户
        */
        int priSize = prices.size();
        vector<vector<int>> myVec(priSize,vector<int>(3,0));
        myVec[0][0]=-prices[0];//hold Shares
        myVec[0][1]=0;//hold Money
        myVec[0][2]=0;//rest

        for (int i = 1; i <= priSize - 1; i++) {
            myVec[i][0]= max(myVec[i-1][0],myVec[i-1][1]-prices[i]);
            myVec[i][1]= max(myVec[i-1][1],myVec[i-1][2]);
            myVec[i][2]= myVec[i-1][0]+prices[i];
        }
        return max(myVec[priSize-1][1],myVec[priSize-1][2]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
