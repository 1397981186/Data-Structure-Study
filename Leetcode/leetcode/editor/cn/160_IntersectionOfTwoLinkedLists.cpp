/**
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。 

 图示两个链表在节点 c1 开始相交： 

 

 题目数据 保证 整个链式结构中不存在环。
 注意，函数返回结果后，链表必须 保持其原始结构 。 

 自定义评测：
 评测系统 的输入如下（你设计的程序 不适用 此输入）： 

 intersectVal - 相交的起始节点的值。如果不存在相交节点，这一值为 0 
 listA - 第一个链表 
 listB - 第二个链表 
 skipA - 在 listA 中（从头节点开始）跳到交叉节点的节点数 
 skipB - 在 listB 中（从头节点开始）跳到交叉节点的节点数 
 

 评测系统将根据这些输入创建链式数据结构，并将两个头节点 headA 和 headB 传递给你的程序。如果程序能够正确返回相交节点，那么你的解决方案将被 视作正
确答案 。 

 

 示例 1：
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, 
skipB = 3
输出：Intersected at '8'
解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,6,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 

 示例 2：
输入：intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Intersected at '2'
解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [1,9,1,2,4]，链表 B 为 [3,2,4]。
在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 

 示例 3： 
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
这两个链表不相交，因此返回 null 。
 

 

 提示： 
listA 中节点数目为 m
 listB 中节点数目为 n 
 1 <= m, n <= 3 * 10⁴ 
 1 <= Node.val <= 10⁵ 
 0 <= skipA <= m 
 0 <= skipB <= n 
 如果 listA 和 listB 没有交点，intersectVal 为 0 
 如果 listA 和 listB 有交点，intersectVal == listA[skipA] == listB[skipB] 
 


 进阶：你能否设计一个时间复杂度 O(m + n) 、仅用 O(1) 内存的解决方案？ 
 Related Topics 哈希表 链表 双指针 👍 1715 👎 0

 交点不是数值相等，而是指针相等。
 求长度，用小的，找对应（按照剩余长度找）

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
  ListNode(int x) : val(x), next(NULL) {}
};


//leetcode submit region begin(Prohibit modification and deletion)
/**
			执行耗时:36 ms,击败了88.57% 的C++用户
			内存消耗:14.3 MB,击败了43.96% 的C++用户
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto it1=headA;
        auto it2=headB;
        auto longOne=headA;
        auto shortOne=headB;
        int cnt1=0;
        int cnt2=0;
        while(it1){
            cnt1++;
            it1=it1->next;
        }
        while(it2){
            cnt2++;
            it2=it2->next;
        }
//        cout<<"cnt1,cnt2 "<<cnt1<<","<<cnt2<<endl;


        int startNum=0;

        if (cnt1>cnt2){
            startNum=cnt1-cnt2;
        }else{
            startNum=cnt2-cnt1;
            longOne=headB;
            shortOne=headA;
//            cout<<"startNum "<<startNum<<endl;
        }

        for (int i = 0; i <= startNum - 1; i++) {
            longOne=longOne->next;
//            cout<<"longOne value "<<longOne->val<<endl;
        }
//        cout<<"longOne start "<<longOne->val<<endl;


        while (longOne&&shortOne){
            if (longOne==shortOne){
                return longOne;
                cout<<"find value "<<longOne->val<<endl;
            }
//            cout<<"not find value ,longOne at "<<longOne->val<<endl;
            longOne=longOne->next;
            shortOne=shortOne->next;
        }

        return NULL;
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)
