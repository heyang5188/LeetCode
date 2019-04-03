// Author Herb 
// Time : 2019-04-03 21:13:28
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
用一个哈希表来保存其状态，用  map<pair<int,int>,int> map; 来保存其下表说表示的局部最优解
算法基本原理：假设我们可以使用d[ i , j ]个步骤（可以使用一个二维数组保存这个值），表示将串s[ 1…i ] 转换为 串t [ 1…j ]所需要的最少步骤个数，
那么，在最基本的情况下，即在i等于0时，也就是说串s为空，那么对应的d[0,j] 就是 增加j个字符，使得s转化为t，在j等于0时，也就是说串t为空，那么对应的d[i,0] 就是 减少 i个字符，使得s转化为t。
然后我们考虑一般情况，加一点动态规划的想法，我们要想得到将s[1..i]经过最少次数的增加，删除，或者替换操作就转变为t[1..j]，
那么我们就必须在之前可以以最少次数的增加，删除，或者替换操作，使得现在串s和串t只需要再做一次操作或者不做就可以完成s[1..i]到t[1..j]的转换。所谓的“之前”分为下面三种情况：
1）我们可以在k个操作内将 s[1…i] 转换为 t[1…j-1]
2）我们可以在k个操作里面将s[1..i-1]转换为t[1..j]
3）我们可以在k个步骤里面将 s[1…i-1] 转换为 t [1…j-1]
针对第1种情况，我们只需要在最后将 t[j] 加上s[1..i]就完成了匹配，这样总共就需要k+1个操作。
针对第2种情况，我们只需要在最后将s[i]移除，然后再做这k个操作，所以总共需要k+1个操作。
针对第3种情况，我们只需要在最后将s[i]替换为 t[j]，使得满足s[1..i] == t[1..j]，这样总共也需要k+1个操作。而如果在第3种情况下，s[i]刚好等于t[j]，那我们就可以仅仅使用k个操作就完成这个过程。
最后，为了保证得到的操作次数总是最少的，我们可以从上面三种情况中选择消耗最少的一种最为将s[1..i]转换为t[1..j]所需要的最小操作次数。
算法基本步骤： 
关键算法
如果两个字串的自己的界面的是相等的。
方式1 。两个最末的字母相同：
map[{lhs,rhs}] = dp(map,word1,word2,lhs-1,rhs-1);
2：
不同，选取局部最优。
map[{lhs,rhs}] = 1 + min(min(dp(map,word1,word2,lhs-1,rhs-1),dp(map,word1,word2,lhs-1,rhs)),dp(map,word1,word2,lhs,rhs-1));
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int lhs = word1.length();
        int rhs = word2.length();
        map<pair<int,int>,int> map;
        return dp(map,word1,word2,lhs,rhs);
    }
private:
    int dp(map<pair<int,int>,int> &map,string &word1,string &word2 ,int lhs,int rhs){
        if(lhs==0||rhs==0)
            return max(rhs,lhs);
        if(map.find({lhs,rhs}) != map.end())
            return map[{lhs,rhs}];
        if(word1[lhs-1]==word2[rhs-1])
            return map[{lhs,rhs}] = dp(map,word1,word2,lhs-1,rhs-1);
        else
            return map[{lhs,rhs}] = 1 + min(min(dp(map,word1,word2,lhs-1,rhs-1),dp(map,word1,word2,lhs-1,rhs)),
                                            dp(map,word1,word2,lhs,rhs-1));
    }
};