/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct node
{
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head)
{
	struct node *reverse, *temp = 0;
	if (head == NULL)
		return NULL;
	if (head->next != NULL)
	{
		while (head->next != NULL)
		{
			reverse = (struct node *)malloc(sizeof(struct node));
			if (temp == 0)
				reverse->next = NULL;
			else
				reverse->next = temp;
			reverse->num = head->num;
			temp = reverse;
			head = head->next;
		}
		reverse = (struct node *)malloc(sizeof(struct node));
		reverse->num = head->num;
		reverse->next = temp;
		return reverse;
	}
	else
		return head;
}
