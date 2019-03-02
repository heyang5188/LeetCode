// Author Herb
// Time : 2019-03-02 17:43:52
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int a = getLenth(headA);
        int b = getLenth(headB);
        if (b < a)
            swap(headA, headB);
        int ans = abs(a - b);
        while (ans) {
            ans--;
            headA = headA->next;
        }
        while (headA && headB) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
  private:
    int getLenth(ListNode *head)
    {
        int count = 0;
        while (head) {
            head = head->next;
            count++;
        }
        return count;
    }
};
