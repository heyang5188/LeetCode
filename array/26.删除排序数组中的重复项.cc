// Author herb 
// Time : 2019-01-29 10:29:56
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
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int low = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[low]!=nums[i])
                nums[++low] = nums[i];
        }
        return low+1;
    }
};
