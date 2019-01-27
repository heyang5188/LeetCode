
#include <string>
using namespace std;
class Solution {
public:
    string strWithout3a3b(int A, int B)
    {
        string str;
        int cur = A - B;
        if (cur >= 0) {
            while (B > 0) {
                str += "ab";
                B--;
                A--;
            }
        } else {
            while (A > 0) {
                str += "ba";
                B--;
                A--;
            }
        }
        for (auto it = str.begin(); it != str.end(); it++) {
            int time = abs(cur);
            if (cur > 0) {
                if ((*it) == 'a') {
                    it = str.insert(it, 'a');
                    it++;
                    cur--;
                }

            } else if (cur < 0) {
                if ((*it) == 'b') {
                    it = str.insert(it, 'b');
                    it++;
                    cur++;
                }
            }
        }
        while (cur > 0) {
            str += 'a';
            cur--;
        }
        while (cur < 0) {
            str += 'b';
            cur++;
        }
        return str;
    }
};