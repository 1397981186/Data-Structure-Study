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
        int res=0;
        leftSmallIt.push_back(-1);
        for (int i = 1; i <= heights.size() - 1; i++) {
            if (heights[i]>heights[i-1]){
                leftSmallIt.push_back(i-1);
            } else if(heights[i]==heights[i-1]){
                leftSmallIt.push_back(leftSmallIt[i-1]);
            } else{
                //why so wawawawawawwawawwwwwwwwwawaawawawawawawawawawawawawawawaw
                smallTemp=i-1;
                while (heights[i]<=heights[smallTemp]&&smallTemp>0){
                    smallTemp=leftSmallIt[smallTemp];
                }
                leftSmallIt.push_back(smallTemp);
            }
        }
        for (int i = 0; i <= leftSmallIt.size() - 1; i++) {
            cout<<leftSmallIt[i]<<" ";
        }

        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
    vector<int> nums1={1,2,3,3,4,5,4,3,2,1};
//    vector<int> nums2={3};
    int res;
    res=solution.largestRectangleArea(nums1);
    cout<<"---sre---"<<res<<endl;
    return 0;
}