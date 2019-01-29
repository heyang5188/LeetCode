// Author herb
// Time : 2019-01-29 10:25:20
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* cur = new ListNode(0);
        ListNode* back;
        auto result = cur;
        cur->next = head;
        while (cur->next && cur->next->next) {
            auto a = cur->next;
            auto b = a->next;
            back = b->next;
            cur->next = b;
            b->next = a;
            a->next = back;
            cur = a;
        }
        return result->next;
    }
};