#include<stdio.h>

typedef struct LinkList
{
	int data;
	struct LinkList *next;
}node;

//Insert
void insertAtLast(node* *h, int data);
void insertAtFirst(node* *h, int data);
//Create A Node
node* createNode(int data);
//Display
void display(node *h);

int main()
{
	node *head;
	head = NULL;
	printf("Initial Head : %d\n", head);
	insertAtLast(&head, 10);
	insertAtLast(&head, 20);
	insertAtFirst(&head, 5);
	display(head);
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
		printf("Link List was empty so added at head position\n");
		return;
	}
	tnode -> next = *h;
	*h = tnode;
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
	printf("Displaying Link List...\n");
	while(h != NULL)
	{
		printf("%d",h->data);
		if(h->next!=NULL) 
			printf(" -> ");
		h = h->next;
	}
	printf("\n");
}
