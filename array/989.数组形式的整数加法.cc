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
            vec.push_back(K);
            return vec;
        }
        reverse(A.begin(), A.end());
        reverse(ans.begin(), ans.end());
        vector<int> tmp;
        for (auto x : ans)
            tmp.push_back(x - '0');
        if (A.size() > tmp.size()) {
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
        } else {
            for (size_t i = 0; i < A.size(); i++) {
                tmp[i] += A[i];
            }
            for (int i = 0; i < tmp.size(); i++) {
                if (tmp[i] > 9) {
                    tmp[i] = tmp[i] % 10;
                    if (i + 1 == tmp.size()) {
                        tmp.push_back(1);
                    } else {
                        tmp[i + 1]++;
                    }
                }
            }
            reverse(tmp.begin(), tmp.end());
            return tmp;
        }
    }
};