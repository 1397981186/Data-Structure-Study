/**
给定一个经过编码的字符串，返回它解码后的字符串。
 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。 


 示例 1： 
输入：s = "3[a]2[bc]"
输出："aaabcbc"
 

 示例 2：
输入：s = "3[a2[c]]"
输出："accaccacc"
 

 示例 3：
输入：s = "2[abc]3[cd]ef"
输出："abcabccdcdcdef"
 

 示例 4：
输入：s = "abc3[cd]xyz"
输出："abccdcdcdxyz"


 提示：
 1 <= s.length <= 30 
 s 由小写英文字母、数字和方括号 '[]' 组成 
 s 保证是一个 有效 的输入。 
 s 中所有整数的取值范围为 [1, 300] 
 
 Related Topics 栈 递归 字符串 👍 1220 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>
//思考：遇到这种匹配的，需要栈处理
//如果遇到左括号、数字、字母则入栈
//若遇到右括号，则出栈直到遇到一个数字，将出栈得到的所有符号按照规则翻译后再入栈
//所有符号均判断结束后，从栈中读取结果
//如何按照规则翻译：char转int，s+=s；

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string decodeString(string s) {
        stack<char> theStack;


    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
    string s = "3[a]2[bc]";
//    string s = s = "3[a2[c]]"";
//    vector<int> nums2={3};
    string res;
    res=solution.decodeString(s);
    cout<<" ---sre--- "<<endl<<res<<endl;
    return 0;
}