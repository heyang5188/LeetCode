// Author Herb 
// Time : 2019-03-02 16:35:52
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

  struct ListNode {
      int val;
      struct ListNode *next;
  };


struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode phead;
	phead.next = NULL;
	struct ListNode *cur;
	while (head)
	{
		cur = head;
		head = head->next;
		cur->next = phead.next;
		phead.next = cur;
	}
	return phead.next;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode *mid=head,*fast=head,*prev=NULL;
    while(fast&&fast->next)
    {
        prev = mid;
        mid = mid->next;
        fast = fast->next->next;
    }
    prev&&(prev->next = NULL);
    struct ListNode *cur = reverseList(mid);
    while(head){
        if(cur->val != head->val)
            return false;
        cur = cur->next;
        head = head->next;
    }
    return true;
}