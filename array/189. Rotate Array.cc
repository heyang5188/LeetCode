#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        if (nums.size() < 2)
            return;
        k = nums.size() - k % nums.size();
        rota(0, k - 1, nums);
        rota(k, nums.size() - 1, nums);
        rota(0, nums.size() - 1, nums);
    }
    void rota(int start, int end, vector<int>& nums)
    {
        while (start < end) {
            swap(nums[start++], nums[end--]);
        }
    }
};