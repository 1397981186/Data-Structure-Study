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
/**
			执行耗时:20 ms,击败了11.55% 的C++用户
			内存消耗:19.7 MB,击败了13.87% 的C++用户
*/
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int midHeight=0;
        int res=0;
        int wall=0;
//        int mid=0;
        if (height.size()<=2){
            return 0;
        }

        for (int i = 0; i <= height.size()-1; i++) {
            if (st.empty()){
                st.push(i);
            }else{
                if (height[i]<height[st.top()]){
                    st.push(i);
                } else if (height[i]==height[st.top()]){
                    st.pop();
                    st.push(i);
                }else{
                    while (!st.empty()&&height[st.top()]<=height[i]){
//                    mid=height[st.top()];
                        midHeight=height[st.top()];
                        st.pop();
                        if (st.empty()){
                            break;//当stack里只有一个的情况
                        }
                        wall=min(height[st.top()],height[i]);
                        res+=(i-st.top()-1)*(wall-midHeight);
                    }

                    st.push(i);
                }

            }
        }
        return res;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
    vector<int> nums1={0,1,0,2,1,0,1,3,2,1,2,1};
//    vector<int> nums1={4,2,0,3,2,5};
//    vector<int> nums2={3};
    double res;
    res=solution.trap(nums1);
    cout<<"---sre---"<<res<<endl;
    return 0;
}
