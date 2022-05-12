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
 挡板法:两个挡板，前面的挡板不允许右边有0，后面的不允许左边有2

 指针不仅可以用来指向数组，还可以用来当做挡板.实现时，挡板本质上是交换+移位

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
        int first,it=0 ;
        int second = nums.size()-1;
        int temp;
        for (int i = 0; i <= nums.size()-1; i++) {
            if (nums[it]==2&&it<=second){
                temp=nums[second];
                nums[second]=2;
                nums[it]=temp;
                second--;
            } else if(nums[it]==0&&it>=first){
                temp=nums[first];
                nums[first]=0;
                nums[it]=temp;
                first++;
                it++;
            }else{
                it++;
            }
        }
        
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution solution;
    vector<int> nums={2,0,1};
    solution.sortColors(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout<<" "<<nums[i];
    }
    return 0;
}
