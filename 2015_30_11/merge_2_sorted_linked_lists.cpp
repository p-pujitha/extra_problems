/*   2.Merge two linked list which are in sorted order   */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node *merge(struct node *head1, struct node *head2);
struct node *Array_to_linked_list(int *arr, int len);
void dotest();
int checkoutput(int );
struct test
{
	int input1[100];
	int len1;
	int input2[100];
	int len2;
	int output[200];
	int len3;
}testcases[8] = {
/*1*/	{ { 1, 3, 5 }, 3, { 2, 4, 6 }, 3, { 1, 2, 3, 4, 5, 6 }, 6 },

/*2*/	{ { 1, 2, 3 }, 3, { 4, 5, 6, 7, 8 }, 5, { 1, 2, 3, 4, 5, 6, 7, 8 }, 8 },

/*3*/	{ { 4, 5, 6 }, 3, { 1, 2, 3 }, 3, { 1, 2, 3, 4, 5, 6 }, 6 },

/*4*/	{ { 2, 4, 6 }, 3, { 1, 7, 9 }, 3, { 1, 2, 4, 6, 7, 9 }, 6 },

/*5*/	{ { 1, 1, 1, 1, 1 }, 5, { 1, 1, 1 }, 3, { 1, 1, 1, 1, 1, 1, 1, 1 }, 8 },

/*6*/	{ NULL, 1, { 1 }, 1, { 1 }, 1 },

/*7*/	{ { 1 }, 1, NULL, 1, { 1 }, 1 },

/*8*/	{ NULL, 1, NULL, 1, NULL, 1 }
};


struct node
{
	int data;
	struct node *next;
};

struct node * createNode(int n1) {
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode->data= n1;
			newNode->next = NULL;
			return newNode;
		}
void add(struct node **head, int p){
			struct node *temp = *head;
			if (*head == NULL){
				(*head) = createNode(p);
				(*head)->next = NULL;
			}
			else{
				while (temp->next != NULL){
					temp = temp->next;
				}
				temp->next = createNode(p);
				temp->next->next = NULL;
			}
		}


void main()
{
	dotest();
	getch();
}
void dotest()
{
	int i, count = 8;

	for (i = 0; i < count; i++)
	{
		if (checkoutput(i) == 1)
			printf("TESTCASE %d Valid\n", i + 1);
		else
			printf("TESTCASE %d Valid\n", i + 1);
	}
}

int checkoutput(int i)
{
	int j, count = 2, flag = 1;
	struct node *head, *temp;
	struct node *ptr1=Array_to_linked_list(testcases[i].input1, testcases[i].len1);
	struct node *ptr2=Array_to_linked_list(testcases[i].input2, testcases[i].len2);
	head = merge(ptr1,ptr2);
	for (j = 0, temp = head; j < testcases[i].len3; j++, temp = temp->next)
	{
		if (testcases[i].output[j] != temp->data)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

struct node *Array_to_linked_list(int *arr, int len)
{
	int j;
	struct node *temp = (struct node*)malloc(sizeof(struct node)), *head = NULL;

	if (arr == NULL || len == 0)
		return NULL;
	else
	{
		temp->next = NULL;
	for (j = 0; j <=len-1; j++)
		{
		 
			add(&head,arr[j]);
			
		}
		return head;
	}
}

struct node *merge(struct node *head1, struct node *head2)
{
	struct node *i = head1, *j = head2, *temp, *first, *temp2;

	if (i == NULL)
		return j;
	else if (j == NULL)
		return i;
	else
	{
		if (i->data > j->data)
		{
			first = j;
			j = i;
			i = first;
		}

		else
			first = i;

		while (1)
		{
			if (i->next->data > j->data)
			{
				temp = i->next;
				i->next = j;
				temp2 = j->next;
				j->next = temp;
				i = j;
				j = temp2;
			}
			else
				i = i->next;

			if (i->next == NULL)
			{
				i->next = j;
				break;
			}

			if (j == NULL)
				break;
		}

		return first;
	}
}