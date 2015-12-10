/*8.Given a linked list which is in pattern like combination of ascending and descending. Sort it.(First all ascending numbers occur ,next all descending nums )
Note : min of descending part is greater than max of ascending 
Ex: Input 1->2->7->20->15->10
Output 1->2->7->10->15->20*/



#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
}*head;
struct node * sort(struct node *);

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
void display(struct node *p)
{
	struct node *ptr=p;
	while(ptr!=NULL)
	{
		printf("%d",ptr->data);
		ptr=ptr->next;
	}
}

void main()
{
	 int choice;
	 struct node *head=NULL;
	do{
		
		 int num;
		 printf("Enter the number");
		 scanf("%d",&num);
		 add(&head,num);
		
		 printf("Do you want to continue-yes-1,no-0");
		 scanf("%d",&choice);
	}while(choice!=0);
	display(head);
	struct node *p=sort(head);
	printf("\n");
	display(p);

	getch();
}

struct node* sort(struct node *head)
{
	struct node *p=head->next;
	struct node *ptr1=head;
	struct node *ptr2=head;
	while(p!=NULL)
	{
		if(ptr1->data>p->data)
		{ 
			p=p->next;
			ptr2=ptr2->next;
			while(p!=NULL)
			{
				if(ptr2->data<p->data)
				{
					int temp=ptr2->data;
					ptr2->data=ptr1->data;
					ptr1->data=temp;
					break;
				}
				p=p->next;
				ptr2=ptr2->next;
			}

		}
		else
		{
			ptr1=ptr1->next;
			p=p->next;
			ptr2=ptr2->next;

		}

	}
	return head;
}