/**
给你一个二叉树的根节点 root ， 检查它是否轴对称。 


 示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true
 

 示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false
 

 

 提示： 

 
 树中节点数目在范围 [1, 1000] 内 
 -100 <= Node.val <= 100 
 


 进阶：你可以运用递归和迭代两种方法解决这个问题吗？ 
 Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 2069 👎 0

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
    //递归法；分成左右子树，并控制后续的比较为对称比较
    //迭代法：需要借助数据结构进行存储，每次存储需要比较的节点。
public:
    bool isSymmetric(TreeNode* root) {
        //递归法
        /**
        	执行耗时:8 ms,击败了27.08% 的C++用户
			内存消耗:16 MB,击败了33.77% 的C++用户
        */
        if (!root){
            return true;
        }
        return compareNode(root->left,root->right);
    }

    bool compareNode(TreeNode * left,TreeNode * right){
        if (left == NULL && right ==NULL){
            return true;
        }
        if ((left == NULL && right !=NULL)||(left != NULL && right ==NULL)){//此处这个判断不能少，不然会导致后面left->value中产生空指针异常
            return false;
        }

        if (left->val == right ->val){
            bool compareLeft = compareNode(left->left,right->right);
            bool compareRight = compareNode(left->right,right->left);
            return compareLeft&&compareRight;
        }
        return false;
    }

    bool isSymmetric1(TreeNode* root) {
        //迭代法
        //之前一直在想，将要比较的全部放进栈中，但是如何判断迭代到某一步时，到底是往下走还是下面的比较完了应该往上走
        //正确思路：每次比较时取出当前组，比较完后加入后面要比的
        /**
        	执行耗时:0 ms,击败了100.00% 的C++用户
			内存消耗:16.1 MB,击败了20.34% 的C++用户
        */
        if (!root){
            return true;
        }
        stack<TreeNode *> mySt;
        mySt.push(root->left);
        mySt.push(root->right);
        while (!mySt.empty()){
            TreeNode * leftTemp = mySt.top();
            mySt.pop();
            TreeNode * rightTemp = mySt.top();
            mySt.pop();

            if (leftTemp == NULL&& rightTemp==NULL){
                continue;
            }
            if ((leftTemp!=NULL&&rightTemp==NULL)||(leftTemp==NULL&&rightTemp!=NULL)){
                return false;
            }
            if (leftTemp->val!=rightTemp->val){
                return false;
            }
            //巧妙控制对称
            mySt.push(leftTemp->left);
            mySt.push(rightTemp->right);
            mySt.push(leftTemp->right);
            mySt.push(rightTemp->left);
        }

        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
