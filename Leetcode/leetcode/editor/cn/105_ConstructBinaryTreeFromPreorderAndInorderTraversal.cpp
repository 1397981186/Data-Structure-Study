/**
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回
其根节点。 

 

 示例 1: 
 
 
输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
 

 示例 2: 

 
输入: preorder = [-1], inorder = [-1]
输出: [-1]
 

 

 提示: 

 
 1 <= preorder.length <= 3000 
 inorder.length == preorder.length 
 -3000 <= preorder[i], inorder[i] <= 3000 
 preorder 和 inorder 均 无重复 元素 
 inorder 均出现在 preorder 
 preorder 保证 为二叉树的前序遍历序列 
 inorder 保证 为二叉树的中序遍历序列 
 

 Related Topics 树 数组 哈希表 分治 二叉树 👍 1696 👎 0

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
    //前提： preorder 和 inorder 均 无重复 元素
    //二叉树但不一定是平衡的
    //？？？ 没有想法

    //preorder第一个元素为root，在inorder里面找到root，在它之前的为左子树（长l1），之后为右子树（长l2）。
    // preorder[1]到preorder[l1]为左子树,之后为右子树，分别递归。

    //思路清楚，但是递归却不好设计
    //        curNode->left= makeTree(leftPre,leftNodes);
    //        curNode->right= makeTree(rightPre,rightNodes);
    //这样设计十分巧妙
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        /**
        	执行耗时:116 ms,击败了5.45% 的C++用户
	        内存消耗:204.4 MB,击败了5.01% 的C++用户
        */
        if (preorder.empty()){
            return NULL;
        }
        return makeTree(preorder,inorder);


    }

    TreeNode* makeTree(vector<int> pre,vector<int> mid){
        if (mid.empty()){
            return NULL;
        }

        int curVal = pre[0];
        TreeNode * curNode = new TreeNode(curVal);
        if (mid.size()==1){
            return curNode;
        }

        vector<int> leftNodes;
        vector<int> rightNodes;
        bool findcur= false;
        for (int i:mid) {
            if (findcur){
                rightNodes.push_back(i);
            }else{
                if (i==curVal){
                    findcur = true;
                }else{
                    leftNodes.push_back(i);
                }
            }
        }

        vector<int > leftPre;
        vector<int > rightPre;
        pre.erase(pre.begin());
        if (!leftNodes.empty()){
            for (int j = 0; j <= leftNodes.size() - 1; j++) {
                leftPre.push_back(pre[j]);
            }
        }

        for (int k = leftPre.size(); k <= pre.size() - 1; k++) {
            rightPre.push_back(pre[k]);
        }
        curNode->left= makeTree(leftPre,leftNodes);
        curNode->right= makeTree(rightPre,rightNodes);
        return curNode;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
