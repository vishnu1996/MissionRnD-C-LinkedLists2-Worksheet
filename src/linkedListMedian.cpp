/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node 
{
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head)
{
	struct node *dob_ptr = head, *sngl_ptr = head;
	if (head == NULL)
		return -1;
	for (sngl_ptr, dob_ptr  ;   dob_ptr->next != NULL && dob_ptr->next->next != NULL   ;   sngl_ptr = sngl_ptr->next, dob_ptr = dob_ptr->next->next)
	{
		if (dob_ptr->next->next == NULL)
			break;		
	}
	if (dob_ptr->next == NULL)
		return sngl_ptr->num;
	if (dob_ptr->next->next == NULL)
		return (sngl_ptr->num + sngl_ptr->next->num) / 2;
}

/*struct node *dob_ptr = head, *sngl_ptr = head;
int result = 0;
if (head == NULL)
return -1;
while (dob_ptr->next != NULL && dob_ptr != NULL && dob_ptr->next->next != NULL)
{
if (dob_ptr->next->next == NULL)
break;
dob_ptr = dob_ptr->next->next;
sngl_ptr = sngl_ptr->next;
}
if (dob_ptr->next == NULL)
return sngl_ptr->num;
if (dob_ptr->next->next == NULL)
return (sngl_ptr->num + sngl_ptr->next->num) / 2;*/
