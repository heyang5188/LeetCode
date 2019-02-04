// Author Herb 
// Time : 2019-02-01 18:07:59
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
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        while(head)
        {
            auto nodeToinsert = head;
            head = head->next;
            nodeToinsert->next = dummy.next;
            dummy.next = nodeToinsert;
        }
        return dummy.next;
    }
};