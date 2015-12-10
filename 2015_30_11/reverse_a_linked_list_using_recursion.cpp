/*4. Reverse a linked list */

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
	int data;
	struct node *next;
};
void dotest();

struct node *Array_to_linked_list(int *arr, int len);		
struct node *reverse_a_linkedlist(struct node*);
struct node *reverse_a_linkedlist2(struct node *, struct node*);
int checkoutput(struct node*, struct node*);

struct test
{
	int input[100];
	int output[100];
	int len;
}testcases[5] = {
	{ { 1, 2, 3, 4, 5, 6 }, { 6, 5, 4, 3, 2, 1 }, 6 },
	{ { 1, 1, 1, 1, 1, 2 }, { 2, 1, 1, 1, 1, 1 }, 6 },
	{ { 1 }, { 1 }, 1 },
	{ { 1, 2 }, {2, 1}, 2 },
	{ NULL, NULL, 1 }, 
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
void main()
{
  dotest();
  getch();
}

void dotest()
{
		for(int i=0;i<5;i++)
		{
			struct node *ptr= Array_to_linked_list(testcases[i].input,testcases[i].len);
			struct node *ptr1=reverse_a_linkedlist(ptr);
			struct node *op= Array_to_linked_list(testcases[i].output,testcases[i].len);
			int ans= checkoutput(ptr1,op); 
     		 if(ans == 1)
				   printf("Testcase - %d -> valid\n",i+1);
			 else
				   printf("Testcase -%d -> Invalid\n",i+1);
		}
		printf("\n\n Second Method :\n\n");
		for(int i=0;i<5;i++)
		{
			struct node *ptr= Array_to_linked_list(testcases[i].input,testcases[i].len);
			struct node *ptr1=reverse_a_linkedlist2(ptr,ptr);
			struct node *op= Array_to_linked_list(testcases[i].output,testcases[i].len);
			int ans= checkoutput(ptr1,op); 
     		 if(ans == 1)
				   printf("Testcase - %d -> valid\n",i+1);
			 else
				   printf("Testcase -%d -> Invalid\n",i+1);
		}

}

struct node * reverse_a_linkedlist(struct node *ptr)
{
			struct node *tail;

	if (ptr == NULL)
		return NULL;
	else
	{
		if (ptr->next == NULL)
			return ptr;

		tail = reverse_a_linkedlist(ptr->next);

		ptr->next->next = ptr;
		ptr->next = NULL;
		return tail;
	}
}
int checkoutput(struct node *ptr1, struct node *ptr2)
{
	int flag=1; 
	while(ptr1!=NULL)
	 {
			if(ptr1->data==ptr2->data)
			{
					flag=1;
					ptr1=ptr1->next;
					ptr2=ptr2->next;
			}
			else
			{
				flag=0;
				break;
			}
	 }
	 return flag;
}


struct node *reverse_a_linkedlist2(struct node *first, struct node *last)
{
	struct node *temp;

	if (first == NULL && last == NULL)
		return NULL;
	else
	{
		if (last != NULL)
		{
			if (&first->data == &last->data)
			{
				last = first->next;
				first->next = NULL;
			}
			if (last == NULL)
				return first;
			else 
			{
				temp = last->next;
				last->next = first;
				first = last;
				last = temp;
				first = reverse_a_linkedlist2(first, last);
			}
		}
		return first;
	}
}