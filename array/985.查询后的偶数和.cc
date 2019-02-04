// Author Herb
// Time : 2019-02-04 09:17:25
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};
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
// Author: Herb, Running time: 3000 ms / 6.5 MB
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries)
    {
        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i) {
            A[queries[i][1]] += queries[i][0];
            int sum = 0;
            for (auto x : A) {
                if (x % 2 == 0)
                    sum += x;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

namespace huahualeetcode {
// Author: Huahua, Running time: 100 ms / 6.5 MB
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries)
    {
        int sum = 0;
        for (int i = 0; i < A.size(); ++i)
            if (A[i] % 2 == 0)
                sum += A[i];
        vector<int> ans;
        for (const auto& query : queries) {
            int& a = A[query[1]];
            if (a % 2 == 0)
                sum -= a;
            a += query[0];
            if (a % 2 == 0)
                sum += a;
            ans.push_back(sum);
        }
        return ans;
    }
};
} // huahualeetcode
