/**
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。 

 实现 MinStack 类: 

 
 MinStack() 初始化堆栈对象。 
 void push(int val) 将元素val推入堆栈。 
 void pop() 删除堆栈顶部的元素。 
 int top() 获取堆栈顶部的元素。 
 int getMin() 获取堆栈中的最小元素。 

 示例 1:
输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 

 

 提示：
 -2³¹ <= val <= 2³¹ - 1 
 pop、top 和 getMin 操作总是在 非空栈 上调用 
 push, pop, top, and getMin最多被调用 3 * 10⁴ 次 
 
 Related Topics 栈 设计 👍 1347 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;
/**
			执行耗时:20 ms,击败了71.44% 的C++用户
			内存消耗:15.8 MB,击败了93.94% 的C++用户
*/
//leetcode submit region begin(Prohibit modification and deletion)
class MinStack {
public:
    stack<int> min;
    stack<int> allData;

    MinStack() {

    }
    
    void push(int val) {
        if (allData.size()==0){
            min.push(val);
        }else{
            if (val<=min.top()){//若遇到相同的最小值，则都入栈；防止pop完一个后，min栈没有该最小值的情况
                min.push(val);
            }
        }
        allData.push(val);
    }
    
    void pop() {
        if (allData.top()==min.top()){
            allData.pop();
            min.pop();
        }else{
            allData.pop();
        }
    }
    
    int top() {
        return allData.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//leetcode submit region end(Prohibit modification and deletion)
