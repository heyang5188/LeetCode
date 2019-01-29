// Author Herb 
// Time : 2019-01-29 11:11:54
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
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        for(auto element:nums)
        {
            if(target>element)
            {
                i++;
            }else
                break;
        }
        return i;
    }
};