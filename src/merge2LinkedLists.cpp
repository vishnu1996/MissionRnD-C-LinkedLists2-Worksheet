/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node 
{
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2)
{
	struct node *head = head1, *temp;
	if (head1 == NULL && head2 == NULL)
		return NULL;
	else if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else
	{
		while (head->next != NULL)
			head = head->next;
		head->next = head2;
		head = head1;
		while (head != NULL)
		{
			temp = head->next;
			while (temp != NULL)
			{
				if (head->num >= temp->num)
				{
					head->num = head->num + temp->num;
					temp->num = head->num - temp->num;
					head->num = head->num - temp->num;
				}
				temp = temp->next;
			}
			head = head->next;
		}
		return head1;
	}
}