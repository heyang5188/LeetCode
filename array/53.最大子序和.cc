// Author Herb 
// Time : 2019-01-29 17:40:57
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int x): val(x),next(NULL){}};
struct TreeNode {int val;TreeNode* left;TreeNode* right;TreeNode(int x): val(x), left(nullptr), right(nullptr){}};
class Solution {
public:
   	int maxSubArray(vector<int>& nums) {
        int sum = nums[0],b=0;
        for(int i = 0;i < nums.size(); i++)
        {
            if(b>0)b+=nums[i];
            else b = nums[i];
            if(b>sum) sum = b;
        }
        return sum;
    }
};