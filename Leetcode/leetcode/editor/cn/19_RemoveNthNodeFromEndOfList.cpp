/**
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。 

 示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

 示例 2：
输入：head = [1], n = 1
输出：[]

 示例 3：
输入：head = [1,2], n = 1
输出：[1]


 提示：
 链表中结点的数目为 sz 
 1 <= sz <= 30 
 0 <= Node.val <= 100 
 1 <= n <= sz 

 进阶：你能尝试使用一趟扫描实现吗？ 
 Related Topics 链表 双指针 👍 2055 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include<map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
			执行耗时:4 ms,击败了77.59% 的C++用户
			内存消耗:10.3 MB,击败了73.82% 的C++用户
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* leftNode=head;
        ListNode* rightNode=head;
        for (int i = 0; i <= n-1; i++) {
            if(rightNode->next!=NULL){
                rightNode=rightNode->next;
            }else{//n=size
                return head->next;
            }
        }
        while (rightNode->next!=NULL){
            leftNode=leftNode->next;
            rightNode=rightNode->next;
        }
        //leftnode at 倒数n+1
        leftNode->next=leftNode->next->next;
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
