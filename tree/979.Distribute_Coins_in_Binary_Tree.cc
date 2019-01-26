
#include <math.h>
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
// 给定一个有 N 个结点的二叉树的根结点 root，树中的每个结点上都对应有 node.val 枚硬币，并且总共有 N 枚硬币。
// 在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。(移动可以是从父结点到子结点，或者从子结点移动到父结点。)。
// 返回使每个结点上只有一枚硬币所需的移动次数。
// 提示：
// 1<= N <= 100
// 0 <= node.val <= N
// 算法思想，划分问题为求每个子树的值和1的绝对值之差
class Solution {
public:
    int distributeCoins(TreeNode* root)
    {
        path;
        dfs(root);
        return path;
    }
    int dfs(TreeNode* root)
    {
        if (!root)
            return 0;
        //处理左子树和右子树
        int ans = dfs(root->left) + dfs(root->right);
        //处理自己
        ans += root->val - 1;
        path += abs(ans);
        return ans;
    }
private:
    int path = 0;
};