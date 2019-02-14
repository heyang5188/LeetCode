// Author Herb
// Time : 2019-02-13 17:27:38
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};
class Solution {
public:
    bool isValidBST(TreeNode* root, long smaller = LONG_MIN, long bigger = LONG_MAX)
    {
        if (!root)
            return true;
        if (root->val >= bigger || root->val <= smaller)
            return false;
        return isValidBST(root->left, smaller, root->val) && isValidBST(root->right, root->val, bigger);
    }
};