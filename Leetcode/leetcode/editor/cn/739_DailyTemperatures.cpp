/**
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几
天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。 


 示例 1:
输入: temperatures = [73,74,75,71,69,72,76,73]
输出:[1,1,4,2,1,1,0,0]


 示例 2:
输入: temperatures = [30,40,50,60]
输出:[1,1,1,0]


 示例 3:
输入: temperatures = [30,60,90]
输出: [1,1,0] 

 提示：
 1 <= temperatures.length <= 10⁵ 
 30 <= temperatures[i] <= 100 
 
 Related Topics 栈 数组 单调栈 👍 1233 👎 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;
//思路
//维持单调递减的单调栈，每当遇到不递减的情况就更新answer
//通常是一维数组，要寻找任一个元素的右边或者左边第一个比自己大或者小的元素的位置，此时我们就要想到可以用单调栈了。
//这种下标间隔的，一般栈里都放坐标
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    /**
    		执行耗时:136 ms,击败了66.73% 的C++用户
			内存消耗:86.8 MB,击败了50.24% 的C++用户
    */
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        stack<int> myStack;
        vector<int> answer(size);
        myStack.push(0);
        for (int i = 1; i <= size - 1; i++) {
//            cout<<"here"<<endl;
            if (temperatures[i]<=temperatures[myStack.top()]){
                myStack.push(i);
//                answer[i-1]=1;
            }else{
                while (!myStack.empty()&&temperatures[i]>temperatures[myStack.top()]){
                    answer[myStack.top()]=i-myStack.top();
                    myStack.pop();
                }
                myStack.push(i);
            }
        }
        int remain = myStack.size();
        for (int j = remain-1; j >=0 ; j-- ){//定义result数组的时候，就应该直接初始化为0，如果result没有更新，说明这个元素右面没有更大的了，也就是为0。
            answer[myStack.top()]=0;
            myStack.pop();
        }
        return answer;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{
    Solution solution;
    vector<int> nums1={55,38,53,81,61,93,97,32,43,78};
//    vector<int> nums2={3};
    vector<int> res;
    res=solution.dailyTemperatures(nums1);
    cout<<"---sre---"<<endl;
    for (int i = 0; i <= res.size()-1; i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
