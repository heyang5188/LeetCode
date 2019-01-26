#include <regex>
#include <string>
using namespace std;
//暴力
class Solution1 {
public:
    bool checkRecord(string s) {
        int Absent = 0;
        int Latesize = 0;
        for(auto x:s)
        {
            if(x == 'A')
                Absent++;
            if(x == 'L')
                Latesize++;
            else
                Latesize=0;
            if(Absent>1||Latesize>2)
                return false;
        }
        return true;
    }
};
//regex pattern
class Solution2 {
public:
    bool checkRecord(string s) {
        return !std::regex_search(s,std::regex("A.*A|LLL"));
        
    }
};
