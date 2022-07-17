/**
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
 返回 滑动窗口中的最大值 。

 示例 1： 
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

 示例 2： 
输入：nums = [1], k = 1
输出：[1]

 提示： 

 
 1 <= nums.length <= 10⁵ 
 -10⁴ <= nums[i] <= 10⁴ 
 1 <= k <= nums.length 
 
 Related Topics 队列 数组 滑动窗口 单调队列 堆（优先队列） 👍 1737 👎 0

*/
//思考
//如何遍历：数组下标、队列
//如何求最大：简单的三个三个求复杂度n*k、使用单调双向队列复杂度小于n*K
//单调队列，为什么不用单调栈？ 此处是双向的deque，需要头、尾都能弹出元素
//从大到小维护两个元素就够了？ 不是两个，窗口是几就最多维护几个

//注意：
//队列的用法
//类中的私有类


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    /**
    		执行耗时:204 ms,击败了88.30% 的C++用户
			内存消耗:131.5 MB,击败了46.32% 的C++用户
    */
private:
    class MQueue{
        deque<int> myQueue;
        public://C++中，类的默认访问权限是private，结构体的默认访问权限是public。
            void pop(int num){
                if (myQueue.front()==num){
                    myQueue.pop_front();
                }
            }

            int front(){
                return myQueue.front();
            }

            void push(int num){
                while (myQueue.size()!=0&&num>myQueue.back()){//注意此处是从back（队列尾部，尾部最后出）进行判断；这样写代码更加简洁
                    myQueue.pop_back();
                }
                myQueue.push_back(num);
            }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MQueue myQueue;
        vector<int> res;
        for (int i = 0; i <= k - 1; i++) {
            myQueue.push(nums[i]);
        }
        res.push_back(myQueue.front());
        for (int j = k; j <= nums.size() - 1; j++) {
            myQueue.pop(nums[j-k]);
            myQueue.push(nums[j]);
            res.push_back(myQueue.front());
        }

        return res;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution solution;
    vector<int> nums1={1,3,-1,-3,5,3,6,7};
    vector<int> res;
    res=solution.maxSlidingWindow(nums1,3);
    cout<<endl;
    for (int i = 0; i <= res.size() - 1; i++) {
        cout<<res[i]<<" ";
    }
    return 0;
}