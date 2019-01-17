#include <set>
#include <vector>
using namespace std;
//my solution
// set的带有一个键参数的insert版本函数返回pair类型对象
// 该对象包含一个迭代器和一个bool值，迭代器指向拥有该键的元素，
// 而bool值表明是否添加了元素。
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        set<int> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k)
                temp.erase(nums[i - k - 1]);
            if (!temp.insert(nums[i]).second)
                return true;
        }
        return false;
    }
};