/**
给你二叉树的根结点 root ，请你将它展开为一个单链表： 

 
 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。 
 展开后的单链表应该与二叉树 先序遍历 顺序相同。 
 

 示例 1：
输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
 

 示例 2： 
输入：root = []
输出：[]
 

 示例 3： 
输入：root = [0]
输出：[0]


 提示： 

 
 树中结点数在范围 [0, 2000] 内 
 -100 <= Node.val <= 100 
 

 

 进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？ 

 Related Topics 栈 树 深度优先搜索 链表 二叉树 👍 1278 👎 0

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
    //就是展成列表一样的树
    //递归法：一般是需要借助数据结构，此题要求空间复杂度O 1？ 思路：把右子树移到左边并将原来的左子树加到移好的左子树中序遍历最后节点下面。
    //      直到当前节点没有左子树，指针后移，不断迭代
public:
    void flatten(TreeNode* root) {
        /**
        	执行耗时:4 ms,击败了83.49% 的C++用户
	        内存消耗:13 MB,击败了5.04% 的C++用户
        */
        TreeNode * temp =root;
        TreeNode * rightNode;
        while (temp){
            cout<<temp->val<<endl;
            if ((!temp->left)&&(!temp->right)){
                temp=NULL;
            }else if ((!temp->right)&&temp->left){
                temp->right = temp->left;
                //temp、root指向同一个节点TreeNode，改变temp->left就是改变root->left。改变了指针指向的值。
                //如果temp = temp->left； 不会对root产生影响，这是因为改变得是temp指针指向。
                //关键看左边有没有“->”，分清楚改变的是什么
                temp->left=NULL;
                temp =temp->right;
            }else if ((temp->right)&&(!temp->left)){
                temp = temp->right;
            } else{
                rightNode=temp->right;
                temp->right=temp->left;
                temp->left=NULL;//如果不加这一行会报错：AddressSanitizer: heap-use-after-free
                midLast(temp->right)->right=rightNode;
                temp=temp->right;
            }
        }
        rightNode=NULL;
    }

    TreeNode * midLast(TreeNode * node){
        stack<TreeNode *> mySt;
        mySt.push(node);
        TreeNode * lastNode;
        while (!mySt.empty()){
            lastNode = mySt.top();
            mySt.pop();
            if (lastNode->right){
                mySt.push(lastNode->right);
            }
            if (lastNode->left){
                mySt.push(lastNode->left);
            }

        }
        return lastNode;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
