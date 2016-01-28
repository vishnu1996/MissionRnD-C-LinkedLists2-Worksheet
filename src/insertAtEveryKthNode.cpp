/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node 
{
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K)
{
	struct node *new_node = 0, *temp = 0, *first = head;
	int count = 0;
	if (head == NULL)
		return NULL;
	while (head != NULL)
	{
		if ((count + 1) % K == 0)
		{
			new_node = (struct node *)malloc(sizeof(struct node));
			temp = head;
			new_node->num = K;
			new_node->next = temp->next;
			head->next = new_node;
			head = new_node->next;
		}
		else
			head = head->next;
		count++;
	}
	return first;
}
