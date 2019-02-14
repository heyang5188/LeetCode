// Author Herb
// Time : 2019-02-11 16:26:44
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K)
    {
        vector<int> vec;
        if (K == 0)
            return A;
        auto ans = std::to_string(K);
        if (A.size() == 0) {
            return { K };
        }
        reverse(A.begin(), A.end());
        reverse(ans.begin(), ans.end());
        vector<int> tmp;
        for (auto x : ans)
            tmp.push_back(x - '0');
        if (A.size() <= tmp.size()) {
            swap(A, tmp);
        }
        for (size_t i = 0; i < tmp.size(); i++) {
            A[i] += tmp[i];
        }
        for (int i = 0; i < A.size(); i++) {
            if (A[i] > 9) {
                A[i] = A[i] % 10;
                if (i + 1 == A.size()) {
                    A.push_back(1);
                } else {
                    A[i + 1]++;
                }
            }
        }
        reverse(A.begin(), A.end());
        return A;
    }
};
