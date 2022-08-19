/**
给定一个二叉树，找出其最大深度。 

 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。 

 说明: 叶子节点是指没有子节点的节点。 

 示例： 给定二叉树 [3,9,20,null,null,15,7]， 

     3
   / \
  9  20
    /  \
   15   7 

 返回它的最大深度 3 。 

 Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1338 👎 0

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
    //广度优先，层序遍历， 然后不断计数就行
public:
    int maxDepth(TreeNode* root) {
        int res = 0;
        if (!root){
            return  res;
        }
        queue<TreeNode*> myQ;
        myQ.push(root);

        while (!myQ.empty()){
            int tempSize = myQ.size();
            TreeNode * tempNode;
            res++;
            for (int i = 0; i <= tempSize - 1; i++) {
                tempNode = myQ.front();
                myQ.pop();
                if (tempNode->right){
                    myQ.push(tempNode->right);
                }
                if (tempNode->left){
                    myQ.push(tempNode->left);
                }
            }
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
