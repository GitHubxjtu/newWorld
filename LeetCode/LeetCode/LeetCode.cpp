// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SwapPairs.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SwapPairs m;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	ListNode* ans = m.swapPairs(head);
	while (ans){
		printf("%d",ans->val);
		ans = ans->next;
	}
	while (1);
	return 0;
}

