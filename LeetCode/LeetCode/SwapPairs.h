#pragma once
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
class SwapPairs
{
public:
	SwapPairs();

	ListNode* swapPairs(ListNode* head) {
		if (!head) return head;
		ListNode pre(0);
		pre.next = head;
		ListNode *fast = head, *slow = &pre;
		while (fast)
		{
			ListNode* temp = fast->next;
			if (!temp) break;
			slow->next = temp;
			slow = fast;
			fast = temp->next;
			temp->next = slow;
		}
		slow->next = fast;
		if (fast) fast->next = NULL;
		return pre.next;
	}
	~SwapPairs();
};

