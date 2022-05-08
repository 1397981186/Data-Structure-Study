/**
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]

 such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0. 

 Notice that the solution set must not contain duplicate triplets. 

 
 Example 1: 
 Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
 Example 2: 
 Input: nums = []
Output: []
 Example 3: 
 Input: nums = [0]
Output: []
 
 
 Constraints: 

 
 0 <= nums.length <= 3000 
 -10⁵ <= nums[i] <= 10⁵ 
 
 Related Topics 数组 双指针 排序 👍 4739 👎 0


 修改for循环中的vector时需要小心做出的修改对迭代器的影响


*/


#include <iostream>
#include <vector>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool IfDulp(vector<vector<int>> res,int num1,int num2,int num3){
        for (auto it =res.begin();it != res.end();it++){
            bool flag= false;
            vector<int > Compare =* it;
            /**
            // 修改for循环中的vector时需要小心做出的修改对迭代器的影响

            for (auto it2 = Compare.begin(); it2 != Compare.end(); it2++) {
                if (*it2 == num1){
//                    cout<<"num1 found *it2 is "<<*it2 <<endl;
                    flag=true;
                    Compare.erase(it2);// 修改for循环中的vector时需要小心做出的修改对迭代器的影响
                }
                if(flag){
                    for (auto it3 = Compare.begin(); it3 != Compare.end(); it3++) {
                        if (*it3 == num2){
                            cout<<"Give false ,num2 found *it3 is "<<*it3 <<endl;
                            return false;
                        }
                    }
                } else{

                }
            }
             */
            for (auto it2 = Compare.begin(); it2 != Compare.end(); it2++) {
                if (*it2 == num1){
                    for (auto it3 = Compare.begin(); it3 != Compare.end(); it3++){
                        if (it3==it2){
                            continue;
                        }
                        if (*it3 == num2){
//                            cout<<"Give false ,num2 found *it3 is "<<*it3 <<endl;
                            return false;
                        }
                    }

                }
            }

        }
        return true;
    }

    bool IfDulp(vector<int> notJ,int num){
        for (int i = 0; i < notJ.size(); i++) {
            if (notJ[i]==num){
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int zero1=0;
        int zero2=0;
        vector<vector<int>> res;
        if(nums.size()>=3){
            for (int i = 0; i <nums.size() ; i++) {
                vector<int> notJ;
                zero1=0-nums[i];
                for (int j = i+1; j < nums.size(); j++) {
                    zero2=zero1-nums[j];
                    if (!IfDulp(notJ,j)){
                        break;
                    }
                    //x+zero1+zero2=0  x=0-zero1-zero2;
                    for (int k = j+1; k <nums.size() ; k++) {
                        if (nums[k]==zero2){
//                            cout<<"test,nums are "<<nums[i]<<nums[j]<<nums[k]<<endl;
                            if (IfDulp(res,nums[i],nums[j],nums[k])){
//                                cout<<"OK ,put in ,nums are "<<nums[i]<<nums[j]<<nums[k]<<endl;
                                res.push_back({nums[i],nums[j],nums[k]});
                                if (IfDulp(notJ,k)){
                                    notJ.push_back(k);
                                }
                            } else{
                                break;
                            }
                        }
                    }

                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
//    vector<int> nums={-9,-14,-3,2,0,-11,-5,11,5,-5,4,-4,5,-15,14,-8,-11,10,-6,1,-14,-12,-13,-11,9,-7,-2,-13,2,2,-15,1,3,-3,-12,-12,1,-2,6,14,0,-4,-13,-10,-12,8,-2,-8,3,-1,8,4,-6,2,1,10,2,14,4,12,1,4,-2,11,9,-7,6,-13,7,-3,8,14,8,10,12,11,-4,-13,10,14,1,-4,-4,2,5,4,-11,-7,3,8,-10,11,-11,-5,7,13,3,-2,8,-13,2,1,9,-12,-11,6};
//    vector<int> nums={3,-9,3,9,-6,-1,-2,8,6,-7,-14,-15,-7,5,2,-7,-4,2,-12,-7,-1,-2,1,-15,-13,-4,0,-9,-11,7,4,7,13,14,-7,-8,-1,-2,7,-10,-2,1,-10,6,-9,-1,14,2,-13,9,10,-7,-8,-4,-14,-5,-1,1,1,4,-15,13,-12,13,12,-11,12,-12,2,-3,-7,-14,13,-9,7,-11,5,-1,-2,-1,-7,-7,0,-7,-4,1,3,3,9,11,14,10,1,-13,8,-9,13,-2,-6,1,10,-5,-6,0,1,8,4,13,14,9,-2,-15,-13};
    vector<int> nums={-1,0,1,2,-1,-4};

    vector<vector<int>> res;
    res=solution.threeSum(nums);
    for (auto itTest1 =res.begin();itTest1!=res.end(); itTest1++) {
        for (auto itTest2 =itTest1->begin();itTest2!= itTest1->end();itTest2++) {
            cout<<* itTest2<<" ";
        }
//        for (int i = 0; i < itTest1->size(); i++) {
//            cout<<(*itTest1)[i]<<" ";
//        }
        cout<<endl;
    }
    return 0;
}
