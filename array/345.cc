#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        int low = 0, high = s.size() - 1;
        while(low < high)
        {
            while(!isVowel(tolower(s[low])))
                low++;
            while(!isVowel(tolower(s[high])))
                high--;
            if(low < high )   
                swap(s[low++],s[high--]);
        }
        return s;
    }
    bool isVowel(char st) //判断是不是元音
    {
        return (st=='a'||st=='e'||st=='i'||st=='o'||st=='u');
    }
};