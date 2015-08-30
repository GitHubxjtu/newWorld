#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};
class PatitionList
{
public:
	PatitionList();
	ListNode* partition(ListNode* head, int x) {
		ListNode *fast, *slow;
		ListNode h(0);
		fast =&h;
		slow = fast;
		fast->next = head;
		while (fast->next){
			if (slow->next->val >= x&&fast->next->val<x)
			{
				ListNode *temp1 = fast->next;
				ListNode *temp2 = slow->next;
				slow->next = temp1;
				fast->next = temp1->next;
				temp1->next = temp2;
			}
			else
				fast = fast->next;
			if (slow->next->val<x)
			{
				slow = slow->next;
			}
		}
		return h.next;
	}
	~PatitionList();
};

