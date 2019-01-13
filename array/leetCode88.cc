#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         if(n == 0) return;
//         if(m == 0)
//         {
//             for(int i = 0; i<n; i++)
//             {
//                 nums1[i] = nums2[i];
//             }
//         }
//         int j = 0;
//         for(int i = 0; i< m+n; i++)
//         {
//             if(nums1[i]>=nums2[j]&&j<n)
//             {
//                 cout<<" aaaa"<<i<<endl;
//                 for(int k = nums1.size()-1; k>i; k--)
//                 {
//                     nums1[k]=nums1[k-1];
//                 }
//                 nums1[i]=nums2[j++];
//             }else if(i>(m-j+1))
//             {
//                 nums1[i]=nums2[j++];
//             }
            
//         }
        int cur = n+m-1,i = m-1,j = n-1;
        while(i>=0&&j>=0)
        {
            nums1[cur--] = nums1[i]>nums2[j] ? nums1[i--]:nums2[j--];
        }
        while(j>=0)
            nums1[cur--] = nums2[j--];
            
    }
};