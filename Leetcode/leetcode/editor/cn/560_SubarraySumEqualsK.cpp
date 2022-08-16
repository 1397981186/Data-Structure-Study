/**
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。 

 示例 1：
输入：nums = [1,1,1], k = 2
输出：2

 示例 2：
输入：nums = [1,2,3], k = 3
输出：2

 提示：
 1 <= nums.length <= 2 * 10⁴ 
 -1000 <= nums[i] <= 1000 
 -10⁷ <= k <= 10⁷ 
 
 Related Topics 数组 哈希表 前缀和 👍 1626 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>
#include <set>
using namespace std;
// 思考
// 暴力法，一个一个，两个两个，三个三个看，使用动态规划，每次累计，复杂度n方  --->Time Limit Exceeded
// 哈希表怎么用？

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarraySum1(vector<int>& nums, int k) {
        /**
            Time Limit Exceeded
        */
        int numsSize = nums.size();
        vector<int> myVec(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i <= numsSize-1; i++) {//以每一个vector中的数字为开始
            if (myVec[i]==k){res++;}
            for (int j = i+1; j <= numsSize -1; j++) {//每一个可以的累加
                myVec[i]+=nums[j];
                if (myVec[i]==k){res++;}
            }
        }
        return res;
    }

    int subarraySum(vector<int>& nums, int k) {
        //前缀和法，详细见笔记
        /**
        	执行耗时:100 ms,击败了15.32% 的C++用户
			内存消耗:42.7 MB,击败了29.37% 的C++用户
        */
        int numsSize = nums.size();
        map<int,int> myMap;
        myMap[0]=1;
        int res = 0;
        int pre = 0;
        for (int i = 0; i <= numsSize - 1; i++) {
            pre+=nums[i];
            if (myMap.count(pre-k)){
                res += myMap[pre-k];
            }
//            if (myMap.count(pre)){
//                myMap[pre]++;
//            } else{
//                myMap[pre]=1;
//            }
            myMap[pre]++;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
    vector<int> nums1={1};
    int k = 0 ;
//    vector<int> nums2={3};
    int res;
    res=solution.subarraySum(nums1,k);
    cout<<"---sre---"<<res<<endl;
    return 0;
}
