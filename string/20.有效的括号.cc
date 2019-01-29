// Author herb
// Time : 2019-01-29 10:20:48
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(string s)
    {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
            case '(':
            case '{':
            case '[':
                paren.push(c);
                break;
            case ')':
                if (paren.empty() || paren.top() != '(')
                    return false;
                else
                    paren.pop();
                break;
            case '}':
                if (paren.empty() || paren.top() != '{')
                    return false;
                else
                    paren.pop();
                break;
            case ']':
                if (paren.empty() || paren.top() != '[')
                    return false;
                else
                    paren.pop();
                break;
            default:;
            }
        }
        return paren.empty();
    }
};
