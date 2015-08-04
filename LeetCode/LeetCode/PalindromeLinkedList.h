#pragma once
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class PalindromeLinkedList
{
public:
	PalindromeLinkedList();    
	bool isPalindrome(ListNode* head) {
		if (!head) return true;
		ListNode* cur = head;
		while (cur&&cur->next){
			cur = cur->next;
		}
		if (head == cur)
			return true;
		if (cur->val != head->val)
			return false;
		delete cur;
		cur = NULL;
		return isPalindrome(head->next);
	}
	virtual ~PalindromeLinkedList();
};

