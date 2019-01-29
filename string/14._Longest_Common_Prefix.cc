#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
		return "";
        string LCP = "";
        string aux = strs[0];
        int ans = 0, count = INT_MAX;

        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == aux[j]) {
                    ans++;
                }
                else {
                    break;
                }
            }
            count = fmin(count, ans);
            ans = 0;
        }
        if (count == 0) 
            return LCP;
        for (int i = 0; i < count; i++) {
            LCP += aux[i];
        }
	return LCP;
    }
};