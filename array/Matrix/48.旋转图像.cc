// Author Herb
// Time : 2019-01-30 21:22:37
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        auto size = matrix.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i; j < size; ++j) {
                if (i != j)
                    swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (auto& x : matrix) {
            int begin = 0;
            int end = size - 1;
            while (begin < end) {
                swap(x[begin++], x[end--]);
            }
        }
    }
};