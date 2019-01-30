// Author Herb 
// Time : 2019-01-29 16:36:08
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int x): val(x),next(NULL){}};
struct TreeNode {int val;TreeNode* left;TreeNode* right;TreeNode(int x): val(x), left(nullptr), right(nullptr){}};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *fast=head->next,*slow=head;
        while(fast&&fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mergeTwoLists(sortList(head),sortList(mid));
    }
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1&&l2)
            if(l1->val<l2->val)
            {
                l1->next = mergeTwoLists(l1->next,l2);
                return l1;
            }else
            {
                l2->next = mergeTwoLists(l1,l2->next);
                return l2;
            }
        else
            return l1?l1:l2;
    }
};