// Author Herb
// Time : 2019-01-30 11:13:17
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    double myPow(double x, int n)
    {
        if (n < 0)
            return 1 / power(x, -n);
        return power(x, n);
    }
private:
    double power(double x, int n)
    {
        if (n == 0)
            return 1;
        double half = power(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        return x * half * half;
    }
};
