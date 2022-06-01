/**
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。 

 有效字符串需满足：
 左括号必须用相同类型的右括号闭合。 
 左括号必须以正确的顺序闭合。 

 示例 1：
输入：s = "()"
输出：true

 示例 2：
输入：s = "()[]{}"
输出：true

 示例 3：
输入：s = "(]"
输出：false

 示例 4：
输入：s = "([)]"
输出：false

 示例 5：
输入：s = "{[]}"
输出：true

 提示：
 1 <= s.length <= 10⁴ 
 s 仅由括号 '()[]{}' 组成 
 
 Related Topics 栈 字符串 👍 3283 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include<map>
#include <stack>

using namespace std;

/**
			执行耗时:0 ms,击败了100.00% 的C++用户
			内存消耗:6.1 MB,击败了88.20% 的C++用户
*/

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack1;

        for (int i = 0; i <= s.size() - 1; i++) {
            if (s[i]=='('){//此处用单引号是因为string底层保存的还是char
                stack1.push(')');
            }else if (s[i]=='{'){
                stack1.push('}');
            }else if (s[i]=='['){
                stack1.push(']');
            } else if (stack1.empty()){
                return false;
            }else if (s[i]==stack1.top()){
                stack1.pop();
            } else if (s[i]!=stack1.top()){
                return false;
            }
        }

        return stack1.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
    string s1="()()(){]][}{}[][]";
    bool flag=solution.isValid(s1);
    cout<<"---res---"<<flag<<endl;
    return 0;
}