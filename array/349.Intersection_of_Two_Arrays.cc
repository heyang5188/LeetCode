#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> a(nums1.begin(),nums1.end());
        set<int> b(nums2.begin(),nums2.end());
        for(auto x : a)
        {
            auto p = b.insert(x);
            if(!p.second)
            {
                ans.push_back(*(p.first));
            }
        }
        return ans;
    }
};