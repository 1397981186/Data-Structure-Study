/**
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。 

 求在该柱状图中，能够勾勒出来的矩形的最大面积。

 示例 1:
输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
 

 示例 2： 
输入： heights = [2,4]
输出： 4 


 提示：
 1 <= heights.length <=10⁵ 
 0 <= heights[i] <= 10⁴ 
 
 Related Topics 栈 数组 单调栈 👍 1966 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//先动态规划，再单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //动态规划写法
        vector<int> leftSmallIt;
        vector<int> rightSmallIt;
        int smallTemp=0;

        leftSmallIt[0]=-1;
        for (int i = 1; i <= heights.size() - 1; i++) {
            if (heights[i]>heights[i-1]){
                leftSmallIt[i]=i-1;
            } else if(heights[i]=heights[i-1]){
                leftSmallIt[i]=leftSmallIt[i-1];
            } else{
                smallTemp=leftSmallIt[i-1];
                while (heights[i]>=heights[smallTemp]){
                    smallTemp=leftSmallIt[smallTemp];
                }
                leftSmallIt[i]=smallTemp;
            }
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
    vector<int> nums1={1,2};
//    vector<int> nums2={3};
    double res;
    res=solution.largestRectangleArea(nums1);
    cout<<"---sre---"<<res<<endl;
    return 0;
}