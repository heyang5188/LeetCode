#include <vector>
using namespace std;
class Solution {
public:
    //两指针对撞，扫描一遍就可以得到答案
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int low = 0, high = numbers.size() - 1, sum = 0;
        while(low<high)
        {
            sum = numbers[low] + numbers[high];
            if(sum > target)
                --high;
            else if(sum < target)
                ++low;
            else if(sum == target)
            {
                result.push_back(low+1);
                result.push_back(high+1);
                break;
            }
        }
        return result;
    }
    
    vector<int> twoSumN2(vector<int>& numbers, int target) {
        vector<int> result;
        
        for(int i=0; i<numbers.size(); i++)
        {
            for(int j = i+1; j< numbers.size(); j++)
            {
                if(numbers[i]+numbers[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};