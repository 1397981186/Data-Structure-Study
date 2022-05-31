/**
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

 示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

 示例 2：
输入：head = [1,2]
输出：[2,1]

 示例 3：
输入：head = []
输出：[]
 

 提示：
 
 链表中节点的数目范围是 [0, 5000] 
 -5000 <= Node.val <= 5000 

 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？ 

 Related Topics 递归 链表 👍 2546 👎 0

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
 *
            Solution1(迭代法)
			执行耗时:4 ms,击败了96.21% 的C++用户
			内存消耗:8 MB,击败了94.28% 的C++用户

			Solution（递归法）
			执行耗时:8 ms,击败了49.51% 的C++用户
			内存消耗:7.9 MB,击败了96.83% 的C++用户

*/

//leetcode submit region begin(Prohibit modification and deletion)

class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        auto dummyHead = new ListNode(-1);
        auto temp = head;
        auto cur = head;
        while (cur){
            temp=cur->next;
            cur->next=dummyHead->next;
            dummyHead->next=cur;
            cur=temp;
        }
        return dummyHead->next;
    }
};

class Solution {
public:
    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur,temp);
    }
    ListNode* reverseList(ListNode* head) {
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(NULL, head);
    }

};
//leetcode submit region end(Prohibit modification and deletion)
