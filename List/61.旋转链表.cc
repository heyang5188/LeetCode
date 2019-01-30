// Author Herb
// Time : 2019-01-29 17:42:58
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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head)
            return head;
        int n = getLength(head);
        int num = n - k % n;
        ListNode *p = head->next, *q = head;
        for (int i = 1; i < num; i++) {
            p = p->next;
            q = q->next;
        }
        if (!p)
            return head;
        auto result = p;
        while (p->next)
            p = p->next;
        p->next = head;
        q->next = nullptr;
        return result;
    }

private:
    int getLength(ListNode* head)
    {
        int count = 0;
        while (head) {
            head = head->next;
            count++;
        }
        return count;
    }
};