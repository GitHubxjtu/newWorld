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
class reverseLinkedList
{
public:
	reverseLinkedList(); 
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode *pre = NULL;
		ListNode *nxt;
		nxt = head->next;
		head->next = pre;
		while (nxt){
			ListNode *temp = nxt;
			pre = head;
			nxt = temp->next;
			head = temp;
			head->next = pre;
		}
		return head;
	}
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) return true;
		ListNode *fast, *half, *node;
		fast = head; half = head;
		while (fast&&fast->next){
			half = half->next;
			fast = fast->next->next;
		}
		node = half->next;
		if (fast)
			fast = reverse(half->next);
		else
			fast = reverse(half);
		while (node){
			if (node->val != fast->val) return false;
			node = node->next;
			fast = fast->next;
		}
		return true;
	}
	ListNode *reverse(ListNode *head){
		ListNode* pre = NULL;
		while (head){
			ListNode* next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
	virtual ~reverseLinkedList();
};

