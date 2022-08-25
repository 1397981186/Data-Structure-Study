/**
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。 

 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。 

 返回容器可以储存的最大水量。 

 说明：你不能倾斜容器。 

 

 示例 1： 

 

 
输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。 

 示例 2： 

 
输入：height = [1,1]
输出：1
 

 

 提示： 

 
 n == height.length 
 2 <= n <= 10⁵ 
 0 <= height[i] <= 10⁴ 
 

 Related Topics 贪心 数组 双指针 👍 3728 👎 0

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
    //理解
    //垂线--宽度无限接近于0

    //贪心？
    //建议直接看题解学习
public:
    int maxArea(vector<int>& height) {
        /**
        	执行耗时:72 ms,击败了67.36% 的C++用户
	        内存消耗:57.5 MB,击败了93.81% 的C++用户
        */
        int res =0 ;
        int leftP = 0;
        int rightP = height.size()-1;

        while (leftP!=rightP){ // 贪心：每次都找比当前大的面积，如果左边低就移动左边的墙向右
            // 因为如果此时移动右边的墙，面积必定比刚才的小
            res = max(res, min(height[leftP],height[rightP])*(rightP-leftP));
            if (height[leftP]<height[rightP]){
                leftP++;
            } else{
                rightP--;
            }
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
