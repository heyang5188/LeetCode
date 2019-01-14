#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int low = 0,high = height.size()-1;
        while(low<high)
        {
            auto quality = findMin(height[low],height[high])*(high - low);
            max = findMax(max,quality);
            if(height[low] > height[high])
                high--;
            else
                low++;
        }
        return max;
    }
    int findMin(int a,int b)
    {
        return a<b ? a:b;
    }
    int findMax(int a,int b)
    {
        return a>b ? a:b;
    }
};