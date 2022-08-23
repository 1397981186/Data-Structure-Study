/**
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。 

 有效 二叉搜索树定义如下： 

 
 节点的左子树只包含 小于 当前节点的数。 
 节点的右子树只包含 大于 当前节点的数。 
 所有左子树和右子树自身必须也是二叉搜索树。 
 

 

 示例 1： 
 
 
输入：root = [2,1,3]
输出：true
 

 示例 2： 
 
 
输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。
 

 

 提示： 

 
 树中节点数目范围在[1, 10⁴] 内 
 -2³¹ <= Node.val <= 2³¹ - 1 
 

 Related Topics 树 深度优先搜索 二叉搜索树 二叉树 👍 1725 👎 0

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
public:
    //思考
    //递归：参数包含max，min的引用，return 子树 t 还是 f。-->
    //迭代：不是很好判断 ？
    //我是dsb

    //正确解法：中序遍历，如果得到有序的数组则为排序二叉树
    //递归法
    /**
    	执行耗时:16 ms,击败了21.30% 的C++用户
	    内存消耗:21.4 MB,击败了5.01% 的C++用户
    */
    vector<int>myVec;//可以如此使用，也可以传递引用。
    void midAddVec(TreeNode* node){
        if (node->left){
            midAddVec(node->left);
        }
        myVec.push_back(node->val);
        if (node->right){
            midAddVec(node->right);
        }
    }

    bool isValidBST1(TreeNode* root) {
        midAddVec(root);
        for (int i = 1; i <= myVec.size() - 1; i++) {
            if (myVec[i]<=myVec[i-1]){
                return false;
            }
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        /**
        	执行耗时:4 ms,击败了97.65% 的C++用户
	        内存消耗:21.1 MB,击败了51.06% 的C++用户
        */
        stack<TreeNode*> mySt;
//        vector<int> simpleAdd;
        TreeNode * tempNode =root;
        TreeNode * preNode =NULL;
//        while (!mySt.empty()){
//            tempNode = mySt.top();
//            while (tempNode->left){
//                mySt.push(tempNode->left);
//                tempNode=tempNode->left;
//            }
//            simpleAdd.push_back(tempNode->val);
//            mySt.pop();
//            if (tempNode->right){
//                mySt.push(tempNode->right);
//            }
//        }  一段错误的中序遍历代码
        while (!mySt.empty()||tempNode){//tempNode甚至都不能少
            while (tempNode){
                mySt.push(tempNode);
                tempNode=tempNode->left;//这里上下两行顺序甚至都不能换
            }
            tempNode = mySt.top();
            mySt.pop();
//            simpleAdd.push(tempNode->val);
            if ((preNode!=NULL)&&(preNode->val>=tempNode->val)){
                return false;
            }
            preNode=tempNode;
            tempNode=tempNode->right;
        }

//        for (int i = 1; i <= simpleAdd.size() - 1; i++) {
//            if (simpleAdd[i]<=simpleAdd[i-1]){
//                return false;
//            }
//        }

        return true;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
