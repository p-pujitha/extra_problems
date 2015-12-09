/*		1.Find median of a given linked list (Sorted Linked List)		*/
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
	int data;
	struct node *next;
};
void dotest();
float median_1(struct node *);							// Count Method
float median_2(struct node* );							// Two pointer Method
struct node *Array_to_linked_list(int *arr, int len);		// Array to Linked list converter


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



struct test
{
	int a[1000];
	int len;
	float output;
}testcases[7] = {
	{ { 1, 2, 3, 4 }, 4, 2.5 },	
	{ { 1, 2, 3, 4, 5 }, 5, 3 },
	{ { 1, 1, 1, 1, 2}, 5, 1 },
	{ NULL, 1, 0 },
	{ {-1, 1}, 2, 0 },
	{ { -1, -2, -3, -4, -5, -6}, 6, -3.5},
	{ { 1111111, 222222222, 333333333 }, 3, 222222222 }
};

void main()
{
	dotest();
	getch();
}

void dotest()
{
	int i, count = 7;



	printf(" Finding median by count Method\n\n");
	for (i = 0; i < count; i++)
	{
		struct node *ptr=Array_to_linked_list(testcases[i].a,testcases[i].len);
		if (testcases[i].output == median_1(ptr))
			printf("TESTCASE %d Valid\n", i + 1);
		else
			printf("TESTCASE %d Invalid\n", i + 1);
	}

	printf("\n\n Finding median by Two pointer Method\n\n");
	for (i = 0; i < count; i++)
	{
		if (testcases[i].output == median_2(Array_to_linked_list(testcases[i].a, testcases[i].len)))
			printf("TESTCASE %d Valid\n", i + 1);
		else
			printf("TESTCASE %d Invalid\n", i + 1);
	}
}

float median_1(struct node *start)
{

	int count=0, n;
	float medianvalue;
	struct node *ptr=start;	

	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}

	if ((count % 2) != 0)
	{
		int no = (count / 2) + 1;
		count = 1;
	   ptr=start;
		while (ptr!= NULL)
		{
		
			if (count == no)
			{
				//printf("Median=%f", ptr->data);
				medianvalue=ptr->data;
				return medianvalue;
				break;
			}
			ptr = ptr->next;
			count++;
		}
	}
	else{
		int n1=0, n2=0;
		int ct = 1;
		ptr=start;
		while (ptr != NULL)
		{
			
			if (ct == (count / 2))
				n1 = ptr->data;
				if (ct == ((count / 2) + 1))
				{
					n2 = ptr->data;
					break;
				}
			ptr = ptr->next;
			ct++;
		}
	//	printf("Median=%f", (n1 + n2) / (2.0));
		medianvalue=(n1+n2)/(2.0);
		return medianvalue;
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


float median_2(struct node* head)		// Two Pointers method
{
	if(head == NULL)
		return NULL;
	node *first=head, *second=head;
	while(1)
	{
		 if(second->next == NULL)
		 {
			 return (float)first->data;
		 }
		 if(second->next->next == NULL)
		 {
			 return (float)(first->data + first->next->data) / (2.0);
		 }
		 first=first->next;
		 second=second->next->next;
	}
	
}

