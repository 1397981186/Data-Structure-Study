/**
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。 


 示例 : 给定二叉树 

           1
         / \
        2   3
       / \     
      4   5    
 

 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。 

 

 注意：两结点之间的路径长度是以它们之间边的数目表示。 

 Related Topics 树 深度优先搜索 二叉树 👍 1133 👎 0

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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    //思考
    //不一定是root左右两边子树的两端节点。有可能是同一侧的节点
    //思路：对每一个结点求出其左右子树深度之和，可以用到动态规划
    //     不要求输出路径，只要结果
public:
    int diameterOfBinaryTree(TreeNode* root) {
        /**
        	执行耗时:8 ms,击败了73.89% 的C++用户
	        内存消耗:19.7 MB,击败了59.45% 的C++用户
        */
        int res = 0;
        if (!root){
            return res;
        }
//        map<TreeNode *,vector<int>> myMap;//vector<int,int>, first left , second right --> 不用map也可以
        behindFind(root,res);
        return res;
    }

    int behindFind(TreeNode * node, int & maxVal){
//        vector<int > tempVal;
        int maxLeft = 0;
        int maxRight = 0;
        if ((!node->left)&&(!node->right)){
//            tempVal.push_back(0);
//            tempVal.push_back(0);
//            myMap[node]=tempVal;
            return 0;
        } else if ((!node->left)&&(node->right)){
            maxRight = behindFind(node->right,maxVal);
//            tempVal.push_back(0);
//            tempVal.push_back(maxRight+1);
//            myMap[node]=tempVal;
            maxVal = max(maxRight+1,maxVal);
            return maxRight+1;
        } else if ((node->left)&&(!node->right)){
            maxLeft =  behindFind(node->left,maxVal);
//            tempVal.push_back(maxLeft+1);
//            tempVal.push_back(0);
//            myMap[node]= tempVal;
            maxVal = max(maxLeft+1,maxVal);
            return maxLeft+1;
        }else{
            maxLeft =  behindFind(node->left,maxVal);
            maxRight = behindFind(node->right,maxVal);
//            tempVal.push_back(maxLeft+1);
//            tempVal.push_back(maxRight+1);
//            myMap[node]=tempVal;
            maxVal = max(maxRight+maxLeft+2,maxVal);
            return max(maxLeft+1,maxRight+1);
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)
