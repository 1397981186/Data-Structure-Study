/**
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。 

 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。 

 

 示例 1： 

 
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。 

 示例 2： 

 
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
 

 

 提示： 

 
 0 <= nums.length <= 10⁵ 
 -10⁹ <= nums[i] <= 10⁹ 
 
 Related Topics 并查集 数组 哈希表 👍 1362 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>


using namespace std;
//思考
//复杂度 O（n），遍历两三次  ---->hashset 常数级复杂度
//若先排序，然后记录最大连续次数。 但是排序算法复杂度都大于O（n）
//怎么办？
//学习set ---看笔记
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestConsecutive1(vector<int>& nums) {
        /**
        	执行耗时:96 ms,击败了79.94% 的C++用户
			内存消耗:44.5 MB,击败了81.27% 的C++用户
        */
        unordered_set<int > mySet(nums.begin(),nums.end());//set，集合
        int numsLen = nums.size();
        int res = 0;
        for (int value :nums) {
            if (!mySet.count(value)){//没找见，则在之前已经被计数过。
                continue;
            }
            int onceLen = 1;
            int pre = value-1;
            int next = value+1;
            mySet.erase(value);
            while (mySet.count(pre)){
                mySet.erase(pre);
                pre--;
            }
            while (mySet.count(next)){
                mySet.erase(next);
                next++;
            }
            onceLen = next-pre-1;
            res = max(res,onceLen);
        }
        return  res;
    }

    int longestConsecutive(vector<int>& nums) {
        /**
			执行耗时:108 ms,击败了61.65% 的C++用户
			内存消耗:48.5 MB,击败了68.70% 的C++用户
        */
        unordered_map<int,int> myMap;
        int numsLen = nums.size();
        int res = 0;
        for (int value:nums) {
            if (myMap.count(value)){
                continue;
            }
            int left = 0;
            int right = 0;
            int onceLen = 0;
            left = myMap.count(value-1)? myMap[value-1]:0;
            right = myMap.count(value+1)? myMap[value+1]:0;
            onceLen = right+left+1;
            myMap[value]=onceLen;
            myMap[value-left]=onceLen;//关键步骤，更新左右。
            myMap[value+right]=onceLen;
            res= max(res,onceLen);
        }
        return  res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
    vector<int> nums1={1,2,3,4,234,34,3};
//    vector<int> nums2={3};
    int res;
    res=solution.longestConsecutive(nums1);
    cout<<"---sre---"<<res<<endl;
    return 0;
}
