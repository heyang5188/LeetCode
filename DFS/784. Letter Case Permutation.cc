#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        result;
        dfs(S,0);
        return result;
    }
    void dfs(string & s,int index)
    {
        if(index == s.length())
        {
            result.push_back(s);
            return;    
        }
        dfs(s,index+1);
        if(!isalpha(s[index]))return;
        //大小写异或
        s[index] ^= (1<<5);
        dfs(s,index+1);
        s[index] ^= (1<<5);
    }
private:
    vector<string> result;
};