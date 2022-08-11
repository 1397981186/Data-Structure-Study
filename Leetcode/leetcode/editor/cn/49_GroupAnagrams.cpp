/**
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。 

 示例 1: 
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]] 

 示例 2: 
输入: strs = [""]
输出: [[""]]

 示例 3: 
输入: strs = ["a"]
输出: [["a"]] 

 提示： 
 1 <= strs.length <= 10⁴
 0 <= strs[i].length <= 100 
 strs[i] 仅包含小写字母 
 
 Related Topics 数组 哈希表 字符串 排序 👍 1220 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;
//思考
//提示 哈希表、二叉树 ？ 这怎么用
//目前的想法：
//  暴力法：声明strs.length长度数组，对于strs中的每个单词在进行归类到这些数组中，再合并。归类时判断是否由相同字母构成也要遍历？ 如此复杂度很高
//        归类时是否有映射算法，使得相同字母构成的单词得到同样的值？--->sort
//        不用声明strs.length长度数组，vector可以灵活添加
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        /**
			执行耗时:36 ms,击败了35.32% 的C++用户
			内存消耗:17.7 MB,击败了95.99% 的C++用户
        */
        vector<vector<string>> res ;
        string  word;
        int strsLen = strs.size();
        map<string, int> myMap;
        for (int i = 0; i <= strsLen-1; i++) {
            word = strs[i];
            sort(word.begin(),word.end());
            if (!myMap.count(word)){
                res.push_back({});//二维数组添加新的一行的方法
                myMap[word] = res.size()-1;//巧妙的映射单词到同一组，有点哈希的味道，但不是很多
            }
            res[myMap[word]].push_back(strs[i]);
        }
        return  res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /**
			执行耗时:88 ms,击败了5.62% 的C++用户
			内存消耗:26.1 MB,击败了4.99% 的C++用户
        */
        vector<vector<string>> res ;
        map<string,vector<string>> myMap;

        for (int i = 0; i <= strs.size() - 1; i++) {
            string word = strs[i];
            vector<int> letter(26);//声明固定大小数组的方法
            for (char  c : word) {
                letter[c-'a']+=1;
            }
            string hashWord;
            for (int j = 0; j <= 25; j++) {
                if (letter[j]!=0){
                    for (int k = 0; k <= letter[j]-1; k++) {
//                        hashWord += string(1,j+'a')+to_string(j);
                        hashWord += to_string(j+'a');
//                        hashWord += string(1,j+'a');
                    }
                }
            }
//            cout<<hashWord<<endl;
            if (!myMap.count(hashWord)){
                vector<string> vecSpace;
                myMap[hashWord] = vecSpace;
            }
            myMap[hashWord].push_back(word);
            }
        for(auto vec : myMap){
            res.push_back(vec.second);
        }
        return  res;

        }

};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
    vector<string> strs={"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res ;
//    double res;
    res=solution.groupAnagrams(strs);
//    cout<<"---sre---"<<res<<endl;
    for (int i = 0; i <= res.size() - 1; i++) {
        for (int j = 0; j <= res[i].size()-1; j++) {
            cout<< res[i][j] << "  ";
        }
        cout<< endl;
    }
    return 0;
}
