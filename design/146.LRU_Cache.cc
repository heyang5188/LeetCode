#include <list>
#include <map>
#include <unordered_map>
#include <utility>
using namespace std;

/*用list 来表示链表，用哈希表来查找对应的迭代器，其时间复杂度是）O（1）空间复杂度是n*/
class LRUCache {
public:
    LRUCache(int capacity)
        : _capacity(capacity)
    {
    }

    int get(int key)
    {
        auto it = _hashtable.find(key);
        if(it == _hashtable.end())
        {
            return -1;
        }else
        {
            auto p = _hashtable.at(key);
            _cache.emplace_front(p->first, p->second);
            _cache.erase(p);
            _hashtable[key] = _cache.begin();
            return p->second;
        }
    }

    void put(int key, int value)
    {
        auto it = _hashtable.find(key);
        if (it == _hashtable.end()) {
            if (_cache.size() >= _capacity) {
                auto keyToErase = _cache.back();
                _hashtable.erase(keyToErase.first);
                _cache.pop_back();
                _cache.emplace_front(key, value);
                _hashtable[key] = _cache.begin();
            }else
            {
                _cache.emplace_front(key, value);
                _hashtable[key] = _cache.begin();
            }
        }else
        {
            auto p = _hashtable.at(key);
            _cache.emplace_front(key, value);
            //_cache.erase(it);
            _cache.erase(p);
            _hashtable[key] = _cache.begin();
        }
    }

private:
    int _capacity;
    list<pair<int, int>> _cache;
    unordered_map<int, list<pair<int, int>>::iterator> _hashtable;
};
