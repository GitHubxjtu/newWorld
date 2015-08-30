#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

 struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};
class ReverseLinkList
{
public:
	ReverseLinkList();
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (!head) return head;
		ListNode *pm, *pn;
		ListNode node(0);
		node.next = head;
		pm = &node;
		while (m>1){
			pm = pm->next;
			m--;
			n--;
		}
		ListNode *pstart;
		pstart = pm->next;
		pn = pstart;
		while (n>0){
			ListNode *temp;
			temp = pn->next;
			pn->next = pstart;
			pstart = pn;
			pn = temp;
			n--;
		}
		pm->next->next = pn;
		pm->next = pstart;
		return node.next;
	}
	virtual ~ReverseLinkList();
};

