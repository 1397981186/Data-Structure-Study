/**
Given an array nums with n objects colored red, white, or blue, sort them in-
place so that objects of the same color are adjacent, with the colors in the order 
red, white, and blue. 

 We will use the integers 0, 1, and 2 to represent the color red, white, and 
blue, respectively. 

 You must solve this problem without using the library's sort function. 

 
 Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

 Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

 
 Constraints:
 n == nums.length 
 1 <= n <= 300 
 nums[i] is either 0, 1, or 2. 

 Follow up: Could you come up with a one-pass algorithm using only constant 
extra space? 
 Related Topics 数组 双指针 排序 👍 1266 👎 0

 2 0 1 2
 双指针，三指针？ 一个在最后，一个在开头？

*/

#include <iostream>
#include <vector>
//#include <algorithm>
#include <unordered_set>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution solution;
    vector<int> nums={1,2};
    solution.sortColors(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout<<" "<<nums[i]<<endl;
    }
    return 0;
}
