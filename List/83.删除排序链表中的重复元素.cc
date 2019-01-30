// Author Herb 
// Time : 2019-01-29 17:38:11
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode dummy(0);  
        ListNode *pre = dummy.next = head;
        ListNode *cur = head->next;
        while(pre&&cur)
        {
            if(pre->val != cur->val)
            {
                pre->next = cur;
                pre = pre->next;
                cur = cur->next;
            }
            else
                cur= cur->next;
        }
        pre->next = nullptr;
        return dummy.next;
    }
};