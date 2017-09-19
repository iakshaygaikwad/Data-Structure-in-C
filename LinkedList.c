#include<stdio.h>
#include<stdlib.h>
//	#include<ctype.h>
typedef struct LinkList
{
	int data;
	struct LinkList *next;
}node;

//Insert
void insertAtLast(node **h, int data);
void insertAtFirst(node **h, int data);
int insertAfterX(node **h, int target, int data);
int insertBeforeX(node **h, int target, int data);

//Display
void display(node *h);
//Functions For Optimization
node* createNode(int data);	//Creates Node
int acceptIntData(char *c);

int main()
{
	node *head;
	int choice = 0;
	head = NULL;
	printf("Initial Head : %d\n", head);
	while(1)
	{
		printf("\n\n1.Insert At Last\n2.Insert At First\n3.Insert After X\n4.Insert Before X\n5.Display Linklist\n6.Exit\n");
		choice = acceptIntData("Enter Your Choice : ");
		switch(choice)
		{	int data,tdata,result;
			case 1: data = acceptIntData("\nEnter Data You want to insert : ");
				insertAtLast(&head, data);
				break;
			case 2: data = acceptIntData("\nEnter Data You want to insert : ");
				insertAtFirst(&head, data);
				break;
			case 3: tdata = acceptIntData("\nEnter Target Data : ");
				data = acceptIntData("\nEnter Data You want to insert : ");
				result = insertAfterX(&head, tdata, data);
				if(result == 1){printf("Added Successfully After : %d", tdata); break;}
				printf("Failed To Add...");
				break;
			case 4: tdata = acceptIntData("\nEnter Target Data : ");
				data = acceptIntData("\nEnter Data You want to insert : ");
				result = insertBeforeX(&head, tdata, data);
				if(result == 1){printf("Added Successfully Before : %d", tdata); break;}
				printf("Failed To Add...");
				break;
			case 5: display(head);
				break;
			case 6: return 0;
				break;
			default: printf("Enter Valid Choice...");
		}
	}
	return 0;
}
//Insert
void insertAtLast(node* *h, int data)
{
node *tnode = createNode(data);
node *thead = *h;
printf("Insert Method  Head = %d, Data to be inserted = %d\n", *h,data);
//printf("%d", tnode->data);
if(*h == NULL)
	{
		*h = tnode;
		printf("Link List was empty so added at head position\n");
		return;
	}
while(thead->next != NULL)
	{
		thead = thead->next;
	}
thead->next = tnode;
printf("Added At Last.. \n");
}

void insertAtFirst(node* *h, int data)
{
	node *tnode = createNode(data);
	if(*h == NULL)
	{
		*h = tnode;
		printf("Added Successfully!\n");
		return;
	}
	tnode -> next = *h;
	*h = tnode;
	printf("Added Successfully!\n");	
}

int insertAfterX(node **h, int target, int data)
{
	node *thead,*tnode;
	if(*h == NULL){printf("Linked List is Empty...");  return -1;}
	thead = *h;
	while(thead != NULL && thead->data != target)
	{
		thead = thead->next;
	}
	if(thead == NULL){printf("Target Not Found!\n"); return -1;}
	tnode = createNode(data);
	tnode->next = thead->next;
	thead -> next = tnode;
	return 1;	
}

int insertBeforeX(node **h, int target, int data)
{
	node *tnode,*thead,*prev;
	if(*h == NULL){printf("Linked List is Empty...\n");  return -1;}
	if((*h)->data == target)
	{
		tnode = createNode(data);
		tnode->next = *h;
		*h = tnode;
		return 1;
	}
	prev = *h;
	thead = (*h)->next;
	while(thead != NULL && thead->data != target)
	{
		prev = thead;
		thead = thead->next;
	}
	if(thead == NULL){printf("Target Not Found......\n");	return -1;}
	tnode = createNode(data);
	prev->next = tnode;
	tnode->next = thead;
	return 1;	
}

//Create A Node
node* createNode(int data)
{
	node *n = (node*) malloc(sizeof(node));
	n->data = data;
	n->next = NULL;
	return n;
}

//Display
void display(node *h)
{
	printf("\nDisplaying Link List...\n");
	if(h == NULL){printf("Link List is Currently Empty...!\n");	return;}
	while(h != NULL)
	{
		printf("%d",h->data);
		if(h->next!=NULL) 
			printf(" -> ");
		h = h->next;
	}
	printf("\n");
}
int acceptIntData(char *c)
{
	int a;
	printf("%s", c);
	scanf("%d", &a);
	return a;
}
