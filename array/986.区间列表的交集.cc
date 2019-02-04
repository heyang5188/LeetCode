// Author Herb
// Time : 2019-02-04 17:23:08
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct Interval {
    int start;
    int end;
    Interval()
        : start(0)
        , end(0)
    {
    }
    Interval(int s, int e)
        : start(s)
        , end(e)
    {
    }
};
//O(n^2)sulustion  brote force
//Author huahua  runing time : 68ms
class HerbSolution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B)
    {
        vector<Interval> vec;
        for (auto& s : A) {
            for (auto& e : B) {
                if (isConclusion(s, e))
                    vec.push_back(getInterval(s, e));
            }
        }
        return vec;
    }
private:
    bool isConclusion(Interval& lhs, Interval& rhs)
    {
        return !(lhs.end < rhs.start || rhs.end < lhs.start);
    }
    Interval getInterval(Interval& lhs, Interval& rhs)
    {
        return Interval(max(rhs.start, lhs.start), min(lhs.end, rhs.end));
    }
};

//Author huahua  runing time : 38ms
//Two Pointer
class FasterSolution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        size_t i = 0;
        size_t j = 0;
        vector<Interval> vec;
        while(i<A.size()&&j<B.size())
        {
            const int s = max(A[i].start,B[j].start);
            const int e = min(A[i].end,B[j].end);
            if(s<=e) vec.emplace_back(s,e);
            if(A[i].end<B[j].end)
                i++;
            else
                j++;
        }
        return vec;
    }

};