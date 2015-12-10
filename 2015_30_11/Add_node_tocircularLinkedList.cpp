/*  3.  Add a node to a sorted circular linked list  */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void swap(int *x, int *y);
void print_output();
int compare(int i, int function);
struct node *Array_to_CLL(int *arr, int len);

struct node *insert_node_loop_method(struct node* head, int N);					

struct node
{
	int num;
	struct node *next;
};

struct testcases
{
	int arr[100];
	int len;
	int N;
	int output[100];
	int op_len;
}testDB[6] = {
    	{ { 1, 2, 4, 5, 6 }, 5, 3, { 1, 2, 3, 4, 5, 6 }, 6 },
		{ { 1, 2, 3, 4, 5 }, 5, 6, { 1, 2, 3, 4, 5, 6 }, 6 },
        { { 1, 2, 2, 3, 3, 3, 5, 5, 7 }, 9, 5, {1, 2, 2, 3, 3, 3, 5, 5, 5, 7}, 10 },
     	{ { 1, 2, 3 }, 3, NULL, {NULL, 1, 2, 3}, 4 },
    	{ NULL, 1, 5, { 5 }, 2 },
     	{ NULL, 1, NULL, NULL, 1 }
};

void main()
{
	print_output();
	_getch();
}

void print_output()			
{
	int i, count = 9, function_select = 1;

	
	for (i = 0; i < count; i++)
	{
		if (compare(i, function_select) == 1)
			printf("TESTCASE %d Valid\n", i + 1);
		else
			printf("TESTCASE %d Invalid\n", i + 1);
		
	}
}

int compare(int i, int function)		
{
	int j, count = 2, flag = 1;
	struct node *head, *temp;
	temp = Array_to_CLL(testDB[i].arr, testDB[i].len);

	if (function == 1)
		head = insert_node_loop_method(temp, testDB[i].N);
	else
		head = insert_node_Recursion_method(temp, testDB[i].N, temp);

	for (j = 0, temp = head; j < testDB[i].op_len; j++, temp = temp->next)
	{
		if (testDB[i].output[j] != temp->num)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}


struct node *insert_node_loop_method(struct node* head, int N)
{
	struct node *i = head, *j = (struct node*)malloc(sizeof(struct node)), *temp1, *ans = head;
	int flag = 0;

	j->num = N;
	j->next = NULL;
	if (head == NULL)
		return j;
	else
	{
		while (1)
		{
			if (i->num >= N || (&i->num == &head->num && flag == 1))
			{
				swap(&i->num, &j->num);
				temp1 = i->next;
				i->next = j;
				j->next = temp1;
				if ((&i->num == &head->num) && flag == 1)
					ans = j;
				break;
			}
			i = i->next;
			flag = 1;
		}
		return ans;
	}
}


void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;	
}

struct node *Array_to_CLL(int *arr, int len)
{
	int j;
	struct node *temp = (struct node*)malloc(sizeof(struct node)), *head = NULL, *circle;

	if (arr == NULL || len == 0)
		return NULL;
	else
	{
		circle = temp;
		for (j = len - 1; j >= 0; j--)
		{
			temp->num = arr[j];
			head = (struct node*)malloc(sizeof(struct node));
			head->next = temp;
			temp = head;
		}

		circle->next = head->next;
		return head->next;
	}
}



