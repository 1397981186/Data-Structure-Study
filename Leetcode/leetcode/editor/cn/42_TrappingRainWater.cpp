/**
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 

 

 示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 

 示例 2：
输入：height = [4,2,0,3,2,5]
输出：9
 

 

 提示：
 
 n == height.length 
 1 <= n <= 2 * 10⁴ 
 0 <= height[i] <= 10⁵ 
 
 Related Topics 栈 数组 双指针 动态规划 单调栈 👍 3489 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> pool;
        int pre=0;
        int firstIt=0;
        int lastIt=0;
        int res=0;
        int i=0;
        while (true){
            if (height[i]>=pre&&firstIt==0){//
                pre=height[i];
            }else if (height[i]<pre&&firstIt==0){

            }



            if (i==height.size()-1){
                break;
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
