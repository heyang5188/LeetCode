#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int singleNumber1(vector<int>& nums)
    {
        std::set<int> hash;
        for (auto x : nums) {
            auto p = hash.insert(x);
            if (!p.second)
                hash.erase(x);
        }
        return *hash.begin();
    }
    //solution 2
    int singleNumber2(vector<int>& nums)
    {
        int len = nums.size();
        int tmp = nums[0];
        for (int i = 1; i < len; i++) {
            tmp ^= nums[i];
        }
        return tmp;
    }
};