#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int count = 0;
        for(int i = shifts.size()-1;i>=0;i--)
        {
            count += (shifts[i]%26);
            S[i] = (S[i] - 'a' + count)%26 + 'a';
        }
        return S;
    }
};