/**
Given two strings s and t of lengths m and n respectively, return the minimum 
window substring of s such that every character in t (including duplicates) is 
included in the window. If there is no such substring, return the empty string "". 

 The testcases will be generated such that the answer is unique. 

 A substring is a contiguous sequence of characters within the string. 

 Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' 
from string t.
 

 Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
 

 Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

 
 Constraints:
 m == s.length 
 n == t.length 
 1 <= m, n <= 10⁵ 
 s and t consist of uppercase and lowercase English letters. 
 

 
Follow up: Could you find an algorithm that runs in O(m + n) time? Related 
Topics 哈希表 字符串 滑动窗口 👍 1866 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/**
 *          不进行剪枝，第一次提交
			执行耗时:180 ms,击败了5.21% 的C++用户
			内存消耗:342.1 MB,击败了5.01% 的C++用户
*/

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        unordered_map<char,int> tMap;
        for (char c:t){
            if (tMap.find(c)!=tMap.end()){
                tMap[c]++;
            } else{
                tMap.insert(pair<char,int>(c,1));
            }
        }


        int cnt=0;//声明时最好就附个初值，有出现不为0的情况
        int left=0;
        int minLen=999999;

        for (int i = 0; i <= s.length()-1; i++) {
            if (tMap.find(s[i])!=tMap.end()){
                if (tMap[s[i]]>0){
                    cnt++;
                }
                tMap[s[i]]--;
            }
//            if (--tMap[s[i]] >= 0) ++cnt;
            while (cnt==t.length()){
                /**
                 *          剪掉下面两支，可见三目运算符比较耗费内存。
                			执行耗时:12 ms,击败了81.83% 的C++用户
			                内存消耗:16.1 MB,击败了7.78% 的C++用户

                */
//                minLen=minLen<(i-left+1)? minLen:(i-left+1);
//                res=minLen<(i-left+1)? res:s.substr(left,minLen);
                if (minLen>(i-left+1)){
                    minLen=i-left+1;
                    res=s.substr(left,minLen);
                }
//                cout<<res<<endl;
                if (tMap.find(s[left])!=tMap.end()){
                    tMap[s[left]]++;
                    if (tMap[s[left]]>0){
                        cnt--;
                    }
                }
                left++;
            }
        }



        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
    string s="abc";
    string t="b";
    string res;
    res=solution.minWindow(s, t);
    cout<<"---res---"<<endl<<res<<endl;
    return 0;
}