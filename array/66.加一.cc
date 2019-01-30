// Author Herb
// Time : 2019-01-29 17:45:47
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
class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        vector<int>::reverse_iterator it = digits.rbegin();
        vector<int>::reverse_iterator end = digits.rend();
        if (digits.size() == 0) {
            digits.push_back(1);
            return digits;
        }
        while (it != end) {
            if (*it != 9) {
                ++(*it);
                break;
            } else {
                *it = 0;
                it++;
                if (it == end) {
                    digits.insert(digits.begin(), 1);
                    break;
                }
            }
        }
        return digits;
    }
};