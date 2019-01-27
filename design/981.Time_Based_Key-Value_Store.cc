
//https://leetcode-cn.com/contest/weekly-contest-121/problems/time-based-key-value-store/
#include <string>
#include <unordered_map>
#include <map>
using namespace std;
class TimeMap {
public:
    class TimeNode {
    public:
        TimeNode(const string& str, int timestamp)
            : _str(str)
            , _timestamp(timestamp)
        {
        }
        string _str;
        int _timestamp;
    };
    /** Initialize your data structure here. */
    TimeMap()
    {
    }
    void set(string key, string value, int timestamp)
    {
        if (data.count(key) > 0) {
            for (auto beg = data.lower_bound(key), end = data.upper_bound(key); beg != end; beg++) {
                if (beg->second._str == value) {
                    if (timestamp > beg->second._timestamp) {
                        beg->second._timestamp = timestamp;
                    }
                    return;
                }
            }
            data.insert({ key, TimeNode(value, timestamp) });
        } else {
            data.insert({ key, TimeNode(value, timestamp) });
        }
    }
    string get(string key, int timestamp)
    {
        TimeNode temp("", -2147483648);

        for (auto beg = data.lower_bound(key), end = data.upper_bound(key); beg != end; beg++) {
            if (beg->second._timestamp > temp._timestamp && beg->second._timestamp <= timestamp) {
                temp = beg->second;
            }
        }
        return temp._str;
    }
    std::multimap<string, TimeNode> data;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */