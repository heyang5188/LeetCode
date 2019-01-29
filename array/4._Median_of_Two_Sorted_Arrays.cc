#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // we can use max-heap priority queue
        priority_queue<int> pq;

        int i = 0, j = 0;
        int M = nums1.size();
        int N = nums2.size();

        while (i < M && j < N) {
            pq.push(nums1[i++]);
            pq.push(nums2[j++]);
        }

        while (i < nums1.size()) {
            pq.push(nums1[i++]);
        }

        while (j < nums2.size()) {
            pq.push(nums2[j++]);
        }

        if ((M + N) % 2 == 0) {
            for (int i = 0; i < (M + N) / 2 - 1; i++) {
                pq.pop();
            }
        } else {
            for (int i = 0; i < (M + N) / 2; i++) {
                pq.pop();
            }
        }

        if ((M + N) % 2 == 0) {
            int val1 = pq.top();
            pq.pop();
            int val2 = pq.top();
            return (double(val1 + val2)) / 2;
        } else
            return pq.top();
    }
};