//
// Created by Mihtop on 2022/5/2.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if (nums[i]+nums[j]==target){
                    answer[0]=i;
                    answer[1]=j;
                    return answer;
                }
            }
        }
        return answer;
    }
};
