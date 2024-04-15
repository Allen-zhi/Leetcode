#include <stdio.h>
#include <stdlib.h>

ListNode *Creatnode (int *a, int k){
	ListNode *head = NULL, tail = NULL;
	for (int i = 0; i < k, k++){
		ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
		head = newnode;
		newnode->val = a[n];
		newnode->next = NULL;
		tail->next = newnode;
		tail = newnode;
	}
	return head;
}
