#include<stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

typedef struct QueueUsingStack
{
    node *rear;
}SQ;

SQ * createQueue()
{
    SQ  *q = (SQ*)malloc(sizeof(SQ));
    q->rear = NULL;
    return q;
}


node * createNode(int data)
{
    node *tnode = (node *)malloc(sizeof(node));
    tnode->data = data;
    tnode->next = NULL;

}

int isEmpty(SQ *s)
{
    if(s->rear == NULL)
        return -1;
    return  1;
}

void enqueue(SQ *q, int data)
{
    node *tnode = createNode(data);
    if(isEmpty(q) == -1)
    {
        q->rear = tnode;
        return;
    }
    tnode -> next = q->rear;
    q->rear = tnode;
}

int pop(SQ *sq)
{
    node *tnode;
    int res = 0;
    if(isEmpty(sq) == -1)
        return -1;
    tnode = sq->rear;
    sq->rear = sq->rear->next;
    res = tnode->data;
    free(tnode);
    return res;
}

int dequeue(SQ *q)
{
    int result = 0;
    SQ *s = createQueue();
    while(isEmpty(q) != -1)
        enqueue(s,pop(q));
    result = pop(s);
    while(isEmpty(s) != -1)
        enqueue(q,pop(s));
    return result;
}

int peekRear(SQ *q)
{
    if(isEmpty(q) == -1)
        return -1;
    return q->rear->data;
}

int peekFront(SQ *q)
{
    int result;
    SQ *s = createQueue();
    while(isEmpty(q) != -1)
        enqueue(s,pop(q));
    result = peekRear(s);
    while(isEmpty(s) != -1)
        enqueue(q,pop(s));
    return result;
}


int main()
{
    SQ *q = createQueue();
    int ch;
    while(1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Print Front and Rear\n4. Exit\nEnter Your Choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            int data;
        case 1:
            printf("\nEnter Data: ");
            scanf("%d", &data);
            enqueue(q,data);
            break;
        case 2:
            data = dequeue(q);
            if(data == -1)
                printf("\nQueue is Empty!");
            else
                printf("\nDequeued Successfully : %d", data);
            break;
        case 3:
            printf("\nFront = %d", peekFront(q));
            printf("\nRear = %d",peekRear(q));
            break;
        case 4:
            return(0);
            break;
        default :
            printf("Wrong Choice!!");
        }
    }

    return 0;
}
