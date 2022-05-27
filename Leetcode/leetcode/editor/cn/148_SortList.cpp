/**
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 

 示例 1：
输入：head = [4,2,1,3]
输出：[1,2,3,4]

 示例 2：
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]

 示例 3：
输入：head = []
输出：[]


 提示：
 链表中节点的数目在范围 [0, 5 * 10⁴] 内 
 -10⁵ <= Node.val <= 10⁵ 

 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
 Related Topics 链表 双指针 分治 排序 归并排序 👍 1623 👎 0

 题目限定了时间必须为O(nlgn)，符合要求只有快速排序，归并排序，堆排序，而根据单链表的特点，最适于用归并排序。为啥呢？这是由于链表自身的特点决定的(因为是链表，所以不可以运用到随机访问的特性，所以使用归并排序)
 快慢指针找中点
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

/**
 *          Solution1
			执行耗时:180 ms,击败了14.04% 的C++用户
			内存消耗:72.4 MB,击败了5.00% 的C++用户


*/

//leetcode submit region begin(Prohibit modification and deletion)
/**
class Solution1 {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = head;
        while (fast && fast->next) {//如此得到的结果，奇数时（例如5），fast停在5，slow停在3，偶数时是奇数+1的情况
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;//以slow为分界截断

        return merge(sortList(head), sortList(slow));//

    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1);//临时头
        ListNode *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) {
            cur->next = l1;
        }
        if (l2) {
            cur->next = l2;
        }
        return dummy->next;
    }
};
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode *node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        ListNode *dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode *prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode *head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode *head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode *next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode *merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
