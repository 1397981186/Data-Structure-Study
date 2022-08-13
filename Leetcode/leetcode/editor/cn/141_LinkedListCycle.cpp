/**
给你一个链表的头节点 head ，判断链表中是否有环。

 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表
中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

 如果链表中存在环 ，则返回 true 。 否则，返回 false 。 


 示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

 示例 2： 
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

 示例 3： 
输入：head = [1], pos = -1
输出：false
解释：链表中没有环。

 提示：
 链表中节点的数目范围是 [0, 10⁴] 
 -10⁵ <= Node.val <= 10⁵ 
 pos 为 -1 或者链表中的一个 有效索引 。 

 进阶：你能用 O(1)（即，常量）内存解决此问题吗？ 
 Related Topics 哈希表 链表 双指针 👍 1575 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //思考
 //与142题不同，此题只需要返回ture还是false，不需要返回环开始的节点。更为简单，也有更简单的方法？（不用快慢指针）
 //快慢指针是可以的
 //hashmap法：存储走过的次数，当再次遇到1时代表有环，若走完则无环。空间复杂度1？ hashmap底层是链表，内存实际加载为O（1）？
class Solution {
public:
    bool hasCycle(ListNode * head) {
        /**
        	执行耗时:16 ms,击败了22.42% 的C++用户
			内存消耗:10.3 MB,击败了14.48% 的C++用户
        */
        set<ListNode * > mySet;
        while (head){
//            if (mySet.count(* head)){     不可以比较对象，因为没有重载比较方法。但是可以比较指针
            if (!mySet.count( head)){
                mySet.insert(head);
                head=head->next;
                //这样改变后，set里之前存储的会变吗。 不会，insert是值传递，这里存储的指针也是一个值。
            }else{
                return true;
            }
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
