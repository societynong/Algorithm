#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v) :val(v), next(NULL) {};
};

void partition(ListNode *head) {
	ListNode *rHead = NULL;
	ListNode *curR = rHead;
	ListNode *cur = head;
	while (cur->next) {
		if (cur->next->val <= head->val)
			cur = cur->next;
		else {
			if (rHead == NULL) {
				rHead = cur->next;
				curR = rHead;
			}
			else {
				curR->next = cur->next;
				curR = curR->next;
				
			}
			cur->next = cur->next->next;
		}
	} 
	if(curR)
		curR->next = NULL;
	ListNode *nHead = head->next == NULL?head:head->next;
	cur->next = head;
	head->next = rHead;

	return;
}



int main() {

	ListNode *head = new ListNode(4);
	ListNode *cur = head;
	cur->next = new ListNode(1);
	cur = cur->next;
	cur->next = new ListNode(5);
	cur = cur->next;
	cur->next = new ListNode(2);
	cur = cur->next;
	cur->next = new ListNode(6);
	cur = cur->next;
	cur->next = new ListNode(3);
	cur = cur->next;
	cur->next = new ListNode(7);
	cur = cur->next;
	partition(head);
	return 0;
}


