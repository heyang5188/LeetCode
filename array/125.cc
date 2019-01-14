#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::towlower); 
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) { 
        while (isalnum(s[i]) == false && i < j) 
            i++; 
        while (isalnum(s[j]) == false && i < j) 
            j--; 
        if (s[i] != s[j]) 
            return false; 
        }
        return true;
    }
};