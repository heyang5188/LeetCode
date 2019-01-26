#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseString(string s)
    {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            swap(s[start++], s[end--]);
        }
        return s;
    }
};