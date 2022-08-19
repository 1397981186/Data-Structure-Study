/**
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。 

 示例 1： 
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]

 示例 2：
输入：root = [1]
输出：[[1]]

 示例 3： 
输入：root = []
输出：[]
 

 

 提示： 

 
 树中节点数目在范围 [0, 2000] 内 
 -1000 <= Node.val <= 1000 
 
 Related Topics 树 广度优先搜索 二叉树 👍 1427 👎 0

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
    //二叉树，但不是平衡的，两边层数存在相差很大的问题
    //此题考查 树如何进行广度优先遍历
    //目前想法：递归进行前序遍历，并维护一个int数和一个map<int , vector<int>>，根据层数往里面放数据
    //迭代法
public:
    vector<vector<int>> levelOrder1(TreeNode* root) {
        //递归法
        /**
            执行耗时:0 ms,击败了100.00% 的C++用户
            内存消耗:13.4 MB,击败了5.01% 的C++用户
        */
        vector<vector<int>> res;
        map<int ,vector<int>> myMap;
        if (!root){return res;}
        preVisit(root,0,myMap);


        for (int i = 0; i <= myMap.size()-1; i++) {
            res.push_back(myMap[i]);
        }
        return res;
    }

    void preVisit(TreeNode * node,int iterator,map<int ,vector<int>> & myMap){
        if (node!=NULL){
            myMap[iterator].push_back(node->val);
            preVisit(node->left,iterator+1,myMap);
            preVisit(node->right,iterator+1,myMap);
        }
    }

    //迭代法
    vector<vector<int>> levelOrder(TreeNode* root) {
        //迭代法
        //学习如何巧妙控制到同一层
        /**
        	执行耗时:0 ms,击败了100.00% 的C++用户
	        内存消耗:12.1 MB,击败了69.86% 的C++用户
        */
        queue<TreeNode* > myQ;
        vector<vector<int>> res;
        if (!root){
            return res;
        }
        myQ.push(root);

        while (!myQ.empty()){
            int queueSize = myQ.size();
            vector<int> tempVal;
            TreeNode* tempNode;
            for (int i = 0; i <= queueSize - 1; i++) {
                tempNode= myQ.front();
                myQ.pop();
                tempVal.push_back(tempNode->val);
                if (tempNode->left){
                    myQ.push(tempNode->left);
                }
                if (tempNode->right){
                    myQ.push(tempNode->right);
                }
            }
            res.push_back(tempVal);
        }
        return res;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
