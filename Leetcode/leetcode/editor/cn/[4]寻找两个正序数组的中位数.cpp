/**
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 算法的时间复杂度应该为 O(log (m+n)) 。 

 示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
 

 示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5


 提示：
 nums1.length == m 
 nums2.length == n 
 0 <= m <= 1000 
 0 <= n <= 1000 
 1 <= m + n <= 2000 
 -10⁶ <= nums1[i], nums2[i] <= 10⁶
 Related Topics 数组 二分查找 分治 👍 5409 👎 0

*/
//#include <vector>
//leetcode submit region begin(Prohibit modification and deletion)
/**
number of submit 1
1 7 10      7
1 2 3       2
4.5

 1 1 2 3 7 10
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=nums1.size+nums2.size;
        bool flagOdd= true;
        int i,j=0;
        double res;
        if (len%2==0){
            flagOdd=false;
        }
        if (flagOdd){
            int pos=(len-1)/2;
            for (int k = 0; k < pos; k++) {
                if (nums1[i]<=nums2[j]){
                    i++;
                    res=nums1[i];
                } else{
                   j++
                    res=nums2[j];
                }
            }
        }
        for (int i = 0; i <nums1.length ; i++) {

        }

        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
