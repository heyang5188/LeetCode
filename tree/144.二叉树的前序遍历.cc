// Author Herb 
// Time : 2019-01-30 21:01:33
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int x): val(x),next(NULL){}};
struct TreeNode {int val;TreeNode* left;TreeNode* right;TreeNode(int x): val(x), left(nullptr), right(nullptr){}};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        while(root||!stk.empty())
        {
            if(root)
            {
                ans.push_back(root->val);
                stk.push(root);
                root = root->left;
            }
            else
            {
                root = stk.top()->right;
                stk.pop();
            }
        }
        return ans;
    }
};