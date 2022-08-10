/**
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。 

 示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

 示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

 示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是"wke"，所以其长度为 3。


 提示： 

 0 <= s.length <= 5 * 10⁴ 
 s 由英文字母、数字、符号和空格组成 
 
 Related Topics 哈希表 字符串 滑动窗口 👍 7889 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;
//思考
//暴力法时间复杂度太高,考虑使用滑动窗口(双端队列)但是滑动窗口不好检测重复，故使用map
//通过此题，学习map容器相关方法
// mp[alpha] = i;通过记录下标，避开了双端队列的使用。
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    /**
    		执行耗时:8 ms,击败了88.05% 的C++用户
			内存消耗:8.2 MB,击败了58.29% 的C++用户
    */
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> myMap;
        int res = 0;
        int sLen = s.size();
//        cout<< sLen <<endl;
        int start = 0;
        if (sLen<=1){
            return sLen;
        }
        for (int i = 0; i <= sLen - 1; i++) {
            char alpha = s[i];
            if (myMap.count(alpha)){//myMap.find((s[i]))!=myMap.end() 也可
                res = max(res,i-start);
                start = max(start,myMap[alpha]+1);//精髓，对于"abca" "abcc" "abba"三种情况都适用
            }
            myMap[alpha] = i;
        }
        res = max(res,sLen-start);
        return  res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
//    vector<int> nums1={1,2};
//    vector<int> nums2={3};
//    string s= "abcabcbb";
    string s= "abba";
    int res;
    res=solution.lengthOfLongestSubstring(s);
    cout<<"---sre---"<<res<<endl;
    return 0;
}
