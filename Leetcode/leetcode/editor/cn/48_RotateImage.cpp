/**
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。 

 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。 

 

 示例 1： 
 
 
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
 

 示例 2： 
 
 
输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

 

 提示： 

 
 n == matrix.length == matrix[i].length 
 1 <= n <= 20 
 -1000 <= matrix[i][j] <= 1000 
 

 

 Related Topics 数组 数学 矩阵 👍 1398 👎 0

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
    //奇思妙想类题
    //旋转九十度: 先转置再镜像对称。 转置，对称都是相对容易实现的。

public:
    void rotate(vector<vector<int>>& matrix) {
        /**
        	执行耗时:4 ms,击败了48.09% 的C++用户
	        内存消耗:6.8 MB,击败了65.44% 的C++用户
        */
        int row =matrix.size();
        int col = matrix[0].size();
        int tempVal ;
        //转置
        for (int i = 0; i <= row-1; i++) {
            for (int j = 0; j <= i - 1  ; j++) {
                tempVal = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=tempVal;
            }
        }

        //镜像
        for (int i = 0; i <= row - 1; i++) {
            for (int j = 0; j <= col / 2 - 1; j++) {
                tempVal = matrix[i][j];
                matrix[i][j]=matrix[i][col-j-1];
                matrix[i][col-j-1]=tempVal;
            }
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
    vector<vector<int>> nums={{1,2}
                            ,{ 3,4}
                                };
//    vector<int> nums2={3};
//    double res;
    solution.rotate(nums);
    int col = nums[1].size();
    for (int i = 0; i <= nums.size()-1; i++) {
        for (int j = 0; j <= col - 1; j++) {
            cout<< nums[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
