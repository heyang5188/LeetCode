#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        vector<bool> mark(rooms.size(), false);
        dfs(rooms, mark, 0);
        auto it = find(mark.begin(), mark.end(), false);
        return it == mark.end();
    };

    void dfs(vector<vector<int>>& rooms, vector<bool>& mark, int index)
    {
        if (!mark[index]) {
            mark[index] = true;
            vector<int> vec = rooms[index];
            for (auto x : vec)
                dfs(rooms, mark, x);
        }
    };
};