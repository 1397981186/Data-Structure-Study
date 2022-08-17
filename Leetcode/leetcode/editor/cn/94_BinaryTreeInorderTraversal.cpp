/**
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。 

 示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]

 示例 2： 
输入：root = []
输出：[]

 示例 3： 
输入：root = [1]
输出：[1]

 提示： 

 
 树中节点数目在范围 [0, 100] 内 
 -100 <= Node.val <= 100 


 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
 Related Topics 栈 树 深度优先搜索 二叉树 👍 1531 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
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
    //二叉树进行使用需要：二叉树管理类+二叉树？ --->不需要管理类，树已经构造好
public:
    vector<int> inorderTraversal1(TreeNode* root) {
        //递归法
        /**
        	执行耗时:0 ms,击败了100.00% 的C++用户
			内存消耗:8.1 MB,击败了72.96% 的C++用户
        */
        vector<int> res;
        if (root==NULL){
            return res;
        }
        recurAdd(res,root);
        return res;
    }

    void recurAdd(vector<int>& myVec,TreeNode* node){
        if (node->left!=NULL){
            recurAdd(myVec,node->left);
        }
        myVec.push_back(node->val);
        if (node->right!=NULL){
            recurAdd(myVec,node->right);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        //迭代法
        /**
			执行耗时:0 ms,击败了100.00% 的C++用户
			内存消耗:8.1 MB,击败了80.59% 的C++用户
        */
        vector<int> res;
        stack<TreeNode *> mySt;
        TreeNode * temp = root;
        while (!mySt.empty()||temp){//两重迭代，思路巧妙  temp条件是为了初次进入。
            while (temp){
                mySt.push(temp);
                temp=temp->left;
            }
            temp=mySt.top();
            mySt.pop();
            res.push_back(temp->val);
            temp=temp->right;
        }

        return res;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
