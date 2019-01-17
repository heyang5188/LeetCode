#include <vector>
#include <set>
using namespace std;
//my solution
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto x:nums)
            s.insert(x);
        return s.size() != nums.size();
    }
};