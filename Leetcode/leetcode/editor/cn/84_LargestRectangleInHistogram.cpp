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
    int largestRectangleAreaDynamic(vector<int>& heights) {
        //动态规划写法
        /**
        	执行耗时:120 ms,击败了86.66% 的C++用户
			内存消耗:83.6 MB,击败了4.99% 的C++用户
        */
        vector<int> leftSmallIt;
        vector<int> rightSmallIt(heights.size());
        int smallTemp=0;
        int res=0;
        int size=heights.size();
        leftSmallIt.push_back(-1);
        for (int i = 1; i <= size- 1; i++) {
            if (heights[i]>heights[i-1]){
                leftSmallIt.push_back(i-1);
            } else if(heights[i]==heights[i-1]){
                leftSmallIt.push_back(leftSmallIt[i-1]);
            } else{
                //why so wawawawawawwawawwwwwwwwwawaawawawawawawawawawawawawawawaw
                smallTemp=i-1;
                //while (heights[i]<=heights[smallTemp]&&smallTemp>=0){//每当要判断&条件时就要注意前后顺序，不然会出现bug
                while (smallTemp>=0&&heights[i]<=heights[smallTemp]){
                    smallTemp=leftSmallIt[smallTemp];
                }
                leftSmallIt.push_back(smallTemp);//这样子理解会好一点：只要前面的while推出了就是height大于的第一个，所以push迭代结束后的smalltemp
            }
        }


        rightSmallIt[size-1]=size;//设置成size，用于计算最后一块砖
        for (int j = size-2; j >=0 ; j--) {
            if (heights[j]>heights[j+1]){
                rightSmallIt[j]=j+1;
            }else if (heights[j]==heights[j+1]){
                rightSmallIt[j]=rightSmallIt[j+1];
            }else{
                smallTemp=j+1;
                while (smallTemp<size&&heights[j]<=heights[smallTemp]){
                    smallTemp=rightSmallIt[smallTemp];
                }
                rightSmallIt[j]=smallTemp;
            }
        }

//        for (int i = 0; i <= size - 1; i++) {
//            cout<<leftSmallIt[i]<<" ";
//        }
//        cout<<endl;
//        for (int i = 0; i <= size - 1; i++) {
//            cout<<rightSmallIt[i]<<" ";
//        }
//        cout<<endl;

        for (int k = 0; k <= size - 1; k++) {
            smallTemp=heights[k]*(rightSmallIt[k]-leftSmallIt[k]-1);
            if (res<smallTemp){
                res=smallTemp;
            }
        }
        return res;

    }

    int largestRectangleArea(vector<int>& heights) {
        //单调栈写法
        /**
        	执行耗时:108 ms,击败了95.95% 的C++用户
			内存消耗:73.4 MB,击败了98.32% 的C++用户
        */
        stack<int> st;
        st.push(0);
        heights.insert(heights.begin(), 0); // 数组头部加入元素0
        heights.push_back(0); // 数组尾部加入元素0
        int tempRes=0;
        int res=0;
        int popIt=0;

        for (int i = 1;i<= heights.size()-1; i++) {//包括最后补的0但是包括最前面补的0
            //考虑序列1，2，3，4，5，1，1，1，6，2；最后计算补的0时才算以1为最低的面积
            if (heights[i]>heights[st.top()]){
                st.push(i);
            } else if (heights[i]==heights[st.top()]){
                st.pop();//当然也可以不pop
                //此处只留右边的可以的原因和接雨水42题不同，接雨水是计算最长的宽，而此处只保留右边的，此位置做参考时，用的是右边的；做最低点计算时，同样用右边的。
                st.push(i);
            }else{
                while (st.size()>1&&heights[i]<heights[st.top()]){
                    popIt=st.top();
                    st.pop();
                    tempRes=heights[popIt]*(i-st.top()-1);
                    if (res<tempRes){
                        res=tempRes;
                    }
                }

                st.push(i);//while结束后就是前面的两种情况了。

            }
        }

        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
    vector<int> nums1={2,1,5,6,2,3};
//    vector<int> nums2={3};
    int res;
    res=solution.largestRectangleArea(nums1);
    cout<<"---sre---"<<res<<endl;
    return 0;
}