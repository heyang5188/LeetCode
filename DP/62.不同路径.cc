// Author Herb 
// Time : 2019-03-31 21:25:40
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int x): val(x),next(NULL){}};
struct TreeNode {int val;TreeNode* left;TreeNode* right;TreeNode(int x): val(x), left(nullptr), right(nullptr){}};

/*
题目是求点到终点的条件。
主要问题可以分割成为两个向下一步的子问题和向右一步的子问题
递归求解。并用一个合适的数据结垢来动态保存计算结果。
dp(m,n) = dp(m -1, n) + dp (m,n-1); 动态转移方程
难度不大

*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        map<pair<int,int>,int> map;
        return dp(map,m,n);
    }
    
private:
    int dp(map<pair<int,int>,int> &map,int m,int n)
    {
        if(m <= 0 && n <= 0) return 0;
        if(m == 1|| n == 1) return 1;
        if(map.find({m,n}) == map.end())
            map[{m,n}] = dp(map,m -1, n) + dp (map,m,n-1);
        return map[{m,n}];
    }
};