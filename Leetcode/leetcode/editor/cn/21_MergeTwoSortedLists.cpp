/**
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

 示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
 

 示例 2：
输入：l1 = [], l2 = []
输出：[]
 

 示例 3：
输入：l1 = [], l2 = [0]
输出：[0]

 提示：
 两个链表的节点数目范围是 [0, 50] 
 -100 <= Node.val <= 100 
 l1 和 l2 均按 非递减顺序 排列 
 
 Related Topics 递归 链表 👍 2457 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
			执行耗时:4 ms,击败了92.47% 的C++用户
			内存消耗:14.3 MB,击败了67.65% 的C++用户
*/

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode head, *tail = &head;
        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;//后面的不用排了，直接连接
        return head.next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
