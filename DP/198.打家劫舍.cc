// Author Herb 
// Time : 2019-04-01 18:43:26
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int x): val(x),next(NULL){}};
struct TreeNode {int val;TreeNode* left;TreeNode* right;TreeNode(int x): val(x), left(nullptr), right(nullptr){}};
/*
    递推法，求最优解
 动态规划, 记抢到第 i 户为止的最大收益为 dp[i], 则:
 
 i 有两种情况, 抢或不抢, 抢的话则最大收益是 dp[i-2] + nums[i],
 不抢则保持和前一次结束的收益一致, 等于 dp[i-1], 于是:

 dp[i] = max(nums[i] + dp[i-2], dp[i-1]) 
 
 观察到 dp[i] 只依赖 dp[i-1] 和 dp[i-2], 可以用常数空间复杂度完成
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)return 0;
        if(len == 1)return nums[0];
        int dp[10000];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2;i < len;++i){
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[len-1];
    }
};