#include<bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v) :val(v), next(NULL) {};
};

bool isHuiwen(ListNode *head) {
	if (!head)
		return true;
	if (!head->next)
		return true;
	ListNode *p1 = head;
	ListNode *p2 = head;
	while (p2->next && p2->next->next) {
		p1 = p1->next;
		p2 = p2->next->next;
	}
	ListNode *pre = p1;
	ListNode *cur = p1->next;
	while (cur) {
		ListNode *nx = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nx;
	}
	ListNode *c1 = head;
	ListNode *c2 = pre;
	
	bool res = true;
	while (c2 != p1) {
		if (c1->val != c2->val)
			res = false;
		c1 = c1->next;
		c2 = c2->next;
	}

	ListNode *pre1 = NULL;
	ListNode *cur1 = pre;
	while (cur1 != p1) {
		ListNode *nx = cur1->next;
		cur1->next = pre1;
		pre1 = cur1;
		cur1 = nx;
	}

	return res;
}

int main() {

	ListNode *head = new ListNode(1);
	ListNode *cur = head;
	cur->next = new ListNode(2);
	cur = cur->next;
	cur->next = new ListNode(2);
	cur = cur->next;
	cur->next = new ListNode(1);
	cout << isHuiwen(head) << endl;
	return 0;
}