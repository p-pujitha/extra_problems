/* 
6.Write a program to add two linked list 
(Each node is represented by a digit ) 
(Note: Unequal Lengths can also be given )

Ex: Input 1->2->3->4 and 1->2->3->4
Output 2->4->6->8
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
	int num;
	struct node *next;
};

struct test
{
	int a[100];
	int len_a;
	int b[100];
	int len_b;
	int ans[100];
	int len_ans;
}testDB[6] = {
	{ { 1, 2, 3, 4, 5 }, 5, { 1, 2, 3, 4, 5 }, 5, { 2, 4, 6, 9, 0 }, 5 },
	{ { 9, 9, 9 }, 3, { 1 }, 1, { 1, 0, 0, 0 }, 4 },
	{ { 9, 9, 9, 8, 9, 9, 9 }, 7, { 1 }, 1, { 9, 9, 9, 9, 0, 0, 0 }, 7 },
	{ { 1, 2, 3 }, 3, { 2, 4, 8, 1, 2, 3 }, 6, { 2, 4, 8, 2, 4, 6 }, 6 },
	{ { 9 }, 1, { 2 }, 1, { 1, 1 }, 2 },
	{NULL, 1, NULL, 1, NULL, 1}
};

struct node *reverse_SLL(struct node  *head, int *count);
struct node *Add_two_SLL(struct node *list1, struct node *list2);	
void print_output();
int compare(int i, int function);
struct node *Array_to_SLL(int *arr, int len);

void main()
{
	print_output();
	_getch();
}

struct node *Add_two_SLL(struct node *list1, struct node *list2)
{
	struct node *temp, *i, *j;
	int count1 = 1, count2 = 1, carry = 0, j_num;

	if (list1 == NULL)
		return list2;
	else if (list2 == NULL)
		return list1;

	list1 = reverse_SLL(list1, &count1);
	list2 = reverse_SLL(list2, &count2);

	if (count1 < count2)
	{
		temp = list1;
		list1 = list2;
		list2 = temp;		
	}

	j_num = list2->num;
	j = list2;

	for (i = list1; i != NULL; i = i->next)
	{
		i->num = i->num + j_num + carry;

		if (i->num > 9)
		{
			i->num = i->num % 10;
			carry = 1;
		}
		else
			carry = 0;

		if (j->next != NULL)
		{
			j_num = j->next->num;
			j = j->next;
		}
		else
		{
			if (carry == 0)
				break;
			j_num = 0;
		}
	}

	list1 = reverse_SLL(list1, &count1);

	if (carry == 1)
	{
		list2 = (struct node*)malloc(sizeof(struct node));
		list2->num = 1;
		list2->next = list1;
		list1 = list2;
	}
	
	return list1;

}



struct node *reverse_SLL(struct node *head, int *count)
{
	struct node *tail;

	if (head == NULL)
		return NULL;
	else
	{
		if (head->next == NULL)
			return head;
		
		tail = reverse_SLL(head->next, count);
		(*count)++;
		head->next->next = head;
		head->next = NULL;
		return tail;
	}
}

int compare(int i, int function)		// Function comparing outputs
{
	int j, count = 2, flag = 1;
	struct node *head = NULL, *temp1, *temp2;
	temp1 = Array_to_SLL(testDB[i].a, testDB[i].len_a);
	temp2 = Array_to_SLL(testDB[i].b, testDB[i].len_b);

	if (function == 1)
		head = Add_two_SLL(temp1, temp2);
	

	for (j = 0, temp1 = head; j < testDB[i].len_ans; j++, temp1 = temp1->next)
	{
		if (testDB[i].ans[j] != temp1->num)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

void print_output()			// Function that prints on cmd
{
	int i, count = 6, function_select = 1;

	for (i = 0; i < count; i++)
	{
		if (compare(i, function_select) == 1)
			printf("TESTCASE %d Valid\n", i + 1);
		else
			printf("TESTCASE %d Invalid\n", i + 1);
			
	}
}

struct node *Array_to_SLL(int *arr, int len)
{
	int j;
	struct node *temp = (struct node*)malloc(sizeof(struct node)), *head = NULL;

	if (arr == NULL || len == 0)
		return NULL;
	else
	{
		temp->next = NULL;
		for (j = len - 1; j >= 0; j--)
		{
			temp->num = arr[j];
			head = (struct node*)malloc(sizeof(struct node));
			head->next = temp;
			temp = head;
		}
		return head->next;
	}
}