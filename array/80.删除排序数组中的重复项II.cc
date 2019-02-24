// Author Herb
// Time : 2019-01-29 16:40:04
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
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
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i - 2])
                nums[i++] = n;
        return i;
    }
};