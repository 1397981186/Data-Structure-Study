/**
Given two sorted arrays nums1 and nums2 of size m and n respectively, return 
the median of the two sorted arrays. 

 The overall run time complexity should be O(log (m+n)). 

 
 Example 1: 

 
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
 

 Example 2: 

 
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

 
 Constraints: 

 
 nums1.length == m 
 nums2.length == n 
 0 <= m <= 1000 
 0 <= n <= 1000 
 1 <= m + n <= 2000 
 -10⁶ <= nums1[i], nums2[i] <= 10⁶ 
 
 Related Topics 数组 二分查找 分治 👍 5414 👎 0

*/
#include <iostream>
#include <vector>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=nums1.size()+nums2.size();
        bool flagOdd= true;
        int i=0;
        int j=0;
        double res=0;
        if (len%2==0){
            flagOdd=false;
        }
        if (flagOdd){
            int pos=(len-1)/2;
            for (int k = 0; k <= pos; k++) {
                if (nums1[i]<=nums2[j]){
                    res=nums1[i];
                    i++;
                } else{
                    res=nums2[j];
                    j++;
                }
            }
            return res;
        }
        for (int l = 0; l <nums1.size() ; l++) {
        }
        return 0;


    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution solution;
    vector<int> nums1={1,2};
    vector<int> nums2={3};
    double res;
    res=solution.findMedianSortedArrays(nums1,nums2);
    cout<<"---sre---"<<res<<endl;
    return 0;
}

