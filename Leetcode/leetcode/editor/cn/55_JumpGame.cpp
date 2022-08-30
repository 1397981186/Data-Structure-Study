/**
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。 

 数组中的每个元素代表你在该位置可以跳跃的最大长度。 

 判断你是否能够到达最后一个下标。 

 

 示例 1： 

 
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
 

 示例 2： 

 
输入：nums = [3,2,1,0,4]
输出：false
解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
 

 

 提示： 

 
 1 <= nums.length <= 3 * 10⁴ 
 0 <= nums[i] <= 10⁵ 
 

 Related Topics 贪心 数组 动态规划 👍 1977 👎 0

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
    //贪心：每次跳，都跳到能跳区间的最大的点上，以保证续航--》[4,2,0,0,1,1,4,4,4,0,4,0]过不了
    //修改贪心策略：每次跳，都跳到 i+num[i]最远的点上，保证“延伸最长”

public:
    bool canJump1(vector<int>& nums) {
        /**
        	执行耗时:44 ms,击败了88.33% 的C++用户
	        内存消耗:47 MB,击败了93.83% 的C++用户
        */
        int len = 1;
        int step=nums[0];
        int tempIt=0;
        int tempStep=0;
        int numsLen = nums.size();
        while (len<numsLen){
            if (step+len>=numsLen){return true;}//用于第一次判断，往后满足的都会在len<numsLen循环中跳出

            for (int i = 1; i <= step; i++) {
                if (tempStep+tempIt<=nums[len+i-1]+i){//要有 “=” ，用来尽可能地往前走
                    tempStep=nums[len+i-1];
                    tempIt=i;
                }
            }
            if (tempStep==0){
                return false;
            }
            len+=tempIt;
            step=tempStep;
//            cout<<"len,step "<<len<<","<<step<<endl;
            tempStep=0;
            tempIt=0;
        }

        return true;
    }

    bool canJump(vector<int>& nums) {
    /**
    	执行耗时:56 ms,击败了40.43% 的C++用户
	    内存消耗:47.1 MB,击败了84.38% 的C++用户
    */
        int cover = 0;
        if (nums.size() == 1) return true; // 只有一个元素，就是能达到
        for (int i = 0; i <= cover; i++) { // 注意这里是小于等于cover
            cover = max(i + nums[i], cover);
            if (cover >= nums.size() - 1) return true; // 说明可以覆盖到终点了
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
