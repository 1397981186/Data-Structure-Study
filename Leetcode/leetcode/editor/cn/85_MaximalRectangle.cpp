/**
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

 示例 1：
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],[
"1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。

 示例 2：
输入：matrix = []
输出：0

 示例 3：
输入：matrix = [["0"]]
输出：0

 示例 4：
输入：matrix = [["1"]]
输出：1

 示例 5：
输入：matrix = [["0","0"]]
输出：0

 提示：
 rows == matrix.length 
 cols == matrix[0].length 
 1 <= row, cols <= 200 
 matrix[i][j] 为 '0' 或 '1' 
 
 Related Topics 栈 数组 动态规划 矩阵 单调栈 👍 1311 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;
//注意行列的获取方式
//注意二维vector声明并初始化仍然可以像二维数组［］［］一样

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    /**
			执行耗时:36 ms,击败了84.66% 的C++用户
			内存消耗:15 MB,击败了34.85% 的C++用户
    */
public:
//    int getMaxSquare(vector<char> &height){
    int getMaxSquare(vector<int> height){
        int res=0;
        int temp=0;
        int midIt=0;


        height.insert(height.begin(),0);
        height.push_back(0);
        stack<int> st;
        st.push(0);

        for (int i = 1; i <= height.size() - 1; i++) {
            if (height[i]>height[st.top()]){
                st.push(i);
            }else if (height[i]==height[st.top()]){
                st.pop();
                st.push(i);
            } else{
                while (st.size()>1&&height[i]<height[st.top()]){
                    midIt=st.top();
                    st.pop();
                    temp=(height[midIt])*(i-st.top()-1);
                    if (temp>res){
                        res=temp;
                    }
                }
                st.push(i);
            }
        }

        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();//行
        int cols=matrix[0].size();//列
        vector<int> heights(matrix[0].size(),0);
        int res=0;
        int tempRes=0;
        res=getMaxSquare(heights);
//        cout<<res<<endl;
        for (int i = 0; i <= rows - 1; i++) {
            for (int j = 0; j <= cols - 1; j++) {
                if (matrix[i][j]=='1'){
                    heights[j]+=1;
                } else{
                    heights[j]=0;
                }
//                cout<<heights[j]<<' ';
            }
//            cout<<endl;
            tempRes= getMaxSquare(heights);
            if (tempRes>res){
                res=tempRes;
            }
        }

        return res;
    }


};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution solution;

//注意二维vector依然可以如此声明，就像二维数组［］［］一样
    vector<vector<char>> nums1({{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}
                                ,{'1','1','1','1','1'}});
    double res;
    res=solution.maximalRectangle(nums1);
    cout<<"---sre---"<<res<<endl;
    return 0;
}

