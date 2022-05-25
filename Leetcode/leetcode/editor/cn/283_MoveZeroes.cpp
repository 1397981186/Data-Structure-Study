/**
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。 

 请注意 ，必须在不复制数组的情况下原地对数组进行操作。 


 示例 1:
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
 

 示例 2:
输入: nums = [0]
输出: [0] 


 提示:
 1 <= nums.length <= 10⁴ 
 -2³¹ <= nums[i] <= 2³¹ - 1 

 进阶：你能尽量减少完成的操作次数吗？ 
 Related Topics 数组 双指针 👍 1596 👎 0

 啊呦，写的真垃
 怎么总是有问题，需要反思一下

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include<map>

using namespace std;
/**
			Solution0
			执行耗时:24 ms,击败了36.10% 的C++用户
			内存消耗:19.1 MB,击败了5.15% 的C++用户

            Solution
			执行耗时:16 ms,击败了87.31% 的C++用户
			内存消耗:18.7 MB,击败了68.33% 的C++用户
*/

//leetcode submit region begin(Prohibit modification and deletion)
class Solution0 {
public:
    void moveZeroes(vector<int>& nums) {
        int cntAll=0;
        vector<int> zeroPos={};
        for(auto it=nums.begin();it!=nums.end();it++){
            if (*it==0){
                zeroPos.push_back(cntAll);
            }
            cntAll++;
        }

//        for (int i = 0; i <= zeroPos.size()-1; i++) {
//            cout<<zeroPos[i]<<" ";
//        }
//        cout<<endl;

        int zeroIt = 0;
        int zeroItMax = zeroPos.size()-1;
        if (nums.size()>1&&zeroPos.size()>0){
            for (int i = 0; i <= nums.size()-1; i++) {
//                if (nums[i]!=0&&zeroIt<zeroItMax&&i>zeroPos[zeroIt]&&i<zeroPos[zeroIt+1]){
//                    cout<<"here 1"<<endl;
//                    nums[i-(zeroIt+1)]=nums[i];
//                }else if(nums[i]!=0&&zeroIt<zeroItMax&&i>zeroPos[zeroIt+1]){
//                    cout<<"here 2"<<endl;
//                    zeroIt++;
//                    nums[i-(zeroIt+1)]=nums[i];
//                }else if(nums[i]!=0&&zeroIt==zeroItMax&&i>zeroPos[zeroIt]){
//                    cout<<"here 3"<<endl;
//                    nums[i-(zeroIt+1)]=nums[i];
//                }else if (i>=zeroPos[zeroIt]){
//                    cout<<"here 4"<<endl;
//                    zeroIt++;
//                }
//当三次else if都不行或者感觉逻辑有点混乱时，就要考虑是不是该换个思路
                if(i>zeroPos[zeroIt]){
                    nums[i-zeroIt-1]=nums[i];
                }
                if(zeroIt!=zeroItMax&&i==zeroPos[zeroIt+1]){//i==zeroPos[zeroIt+1]&&zeroIt!=zeroItMax不要写反了，不然会报错
                    zeroIt++;
                }
            }

            for (int k = 0; k <= nums.size() - 1; k++) {
                cout<<nums[k]<<" ";
            }
            cout<<endl;

            for (int j = nums.size()- zeroPos.size(); j <= nums.size()-1; j++) {
                nums[j]=0;
            }

        }

    }
};

//快慢指针一遍过
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fastIt=0;
        int slowIt=0;
        int cnt=0;
        for (int i = 0; i <= nums.size() - 1; i++) {
            if(nums[i]==0){
                fastIt++;
            }else{
                nums[slowIt]=nums[fastIt];
                fastIt++;
                slowIt++;
            }
        }
        for (int j = slowIt; j <= nums.size() - 1; j++) {
            nums[j]=0;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution solution;
    vector<int> nums={0,1,0,3,12};
//    vector<int> nums={0};
    solution.moveZeroes(nums);
    for (int i = 0; i <= nums.size()-1; i++) {
        cout<<nums[i]<<" ";
    }

    return 0;
}
