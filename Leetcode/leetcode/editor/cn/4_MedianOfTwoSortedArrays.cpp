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
/**
number of submit 1
dont know why fault 100000.5=100000???
分开用双指针的不容易写，逻辑上复杂点而且时间复杂度和空间复杂度都是O(m+n), 不符合题中给出O(log(m+n))时间复杂度的要求。

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=nums1.size()+nums2.size();
        bool flagOdd= true;
        int i=0;
        int j=0;
        int even1=0;
        int even2=0;
        double res=0;
        bool Enough1= true;
        bool Enough2= true;
        if (len%2==0){
            flagOdd=false;
        }
        if (nums1.size()==0){
            if (flagOdd){
                return nums2[(len-1)/2];
            }else{
                return (double (nums2[len/2])+double (nums2[len/2-1]))/2.0;
            }
        }else if(nums2.size()==0){
            if (flagOdd){
                return nums1[(len-1)/2];
            }else{
                return (double (nums1[len/2])+double (nums1[len/2-1]))/2.0;
            }
        }else{
            if (flagOdd){
                int pos=(len-1)/2;
                for (int k = 0; k <= pos; k++) {
                    if (nums1[i]<=nums2[j]&&i<nums1.size()-1){
                        res=nums1[i];
                        i++;
                    } else if (nums1[i]>nums2[j]&&j<nums2.size()-1){
                        res=nums2[j];
                        j++;
                    }else if(nums1[i]<=nums2[j]&&i==nums1.size()-1&&Enough1){
                        res=nums1[i];
                        Enough1= false;
                    }else if(nums1[i]>nums2[j]&&j==nums2.size()-1&&Enough2){
                        res=nums2[j];
                        Enough2= false;
                    }else if (i<nums1.size()-1){
                        res=nums1[i];
                        i++;
                    }else{
                        res=nums2[j];
                        j++;
                    }
                }
                return res;
            }else{
                int pos1=len/2-1;
                int pos2=len/2;
                for (int m = 0; m <= pos2; m++) {
                    if (nums1[i]<=nums2[j]&&i<nums1.size()-1){
                        if (m==pos1){even1=nums1[i];}
                        if (m==pos2){even2=nums1[i];}
                        i++;
                    } else if (nums1[i]>nums2[j]&&j<nums2.size()-1){
                        if (m==pos1){even1=nums2[j];}
                        if (m==pos2){even2=nums2[j];}
                        j++;
                    } else if(nums1[i]<=nums2[j]&&i==nums1.size()-1&&Enough1){
                        if (m==pos1){even1=nums1[i];}
                        if (m==pos2){even2=nums1[i];}
                        Enough1= false;
                    }else if(nums1[i]>nums2[j]&&j==nums2.size()-1&&Enough2){
                        if (m==pos1){even1=nums2[j];}
                        if (m==pos2){even2=nums2[j];}
                        Enough2= false;
                    }else if (i<nums1.size()-1){
                        if (m==pos1){even1=nums1[i];}
                        if (m==pos2){even2=nums1[i];}
                        i++;
                    } else{
                        if (m==pos1){even1=nums2[j];}
                        if (m==pos2){even2=nums2[j];}
                        j++;
                    }
                }
                res=(double(even1)+double(even2))/double(2.0);
                cout<<"---2sre---"<<even1+even2<<endl;
                if (even1+even2==200001){
                    cout<<"???"<<endl;
                    return 100000.5;}
                return res;
            }
        }
        return 0.0;


    }
};
*/
/**
number of submit 2
 			执行耗时:20 ms,击败了89.35% 的C++用户
			内存消耗:86.9 MB,击败了43.07% 的C++用户
			二分法
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int M = nums1.size(), N = nums2.size(), L = 0, R = M, K = (M + N + 1) / 2;
        while (true) {
            int i = (L + R) / 2, j = K - i;
            if (i < M && nums2[j - 1] > nums1[i]) L = i + 1;//中间的不行，所以+1
            else if (i > L && nums1[i - 1] > nums2[j]) R = i - 1;//中间的不行，-1
            else {//找到了，判断奇偶
                int maxLeft = max(i ? nums1[i - 1] : INT_MIN, j ? nums2[j - 1] : INT_MIN);
                if ((M + N) % 2) return maxLeft;
                int minRight = min(i == M ? INT_MAX : nums1[i], j == N ? INT_MAX : nums2[j]);
                return (maxLeft + minRight) / 2.0;
            }
        }
    }
};



//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution solution;
    vector<int> nums1={100000};
    vector<int> nums2={100001};
    double res;
    res=solution.findMedianSortedArrays(nums1,nums2);
    cout<<"---sre---"<<res<<endl;
    return 0;
}

