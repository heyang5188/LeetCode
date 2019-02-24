// Author Herb
// Time : 2019-02-24 16:52:38
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//算法思想，用hashset ,如果插入失败就删除这个set

class Solution1
{
  public:
    int singleNumber(vector<int> &nums)
    {
        std::set<int> hash;
        for (auto x : nums)
        {
            auto p = hash.insert(x);
            if (!p.second)
                hash.erase(x);
        }
        return *hash.begin();
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans =0;
        for(auto &x:nums) ans^=x;  
        return ans;
    }
};