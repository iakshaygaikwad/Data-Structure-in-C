#include<stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

typedef struct Queue
{
    node *front;
    node *rear;
}queue;

queue * createQueue()
{
    queue *q = (queue *)malloc(sizeof(node));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

node * createNode(int data)
{
    node *tnode = (node *)malloc(sizeof(node));
    tnode->data = data;
    tnode->next = NULL;
    return tnode;
}

void enqueue(queue *q, int data)
{
    node * tnode = createNode(data);

    if(q->rear == NULL)
    {
        q->front = q->rear = tnode;
        return;
    }
    (q->rear)->next = tnode;
    q->rear = (q->rear)->next;
}

int dequeue(queue *q)
{
    node * tnode;
    int res;
    if(q->rear == NULL)
        return 0;
    if(q->front == q->rear)
    {
        tnode = q->front;
        q->front = q->rear = NULL;
        res = tnode->data;
        free(tnode);
        return res;
    }
    tnode = q->front;
    q->front = (q->front)->next;
    res = tnode->data;
    free(tnode);
    return res;
}

int main()
{
    queue *q = createQueue();
    int ch;
    while(1)
    {
    printf("\n1. enqueue\n2. dequeue\n3. Print Front and Rear\n4. Exit\nEnter Your Choice : ");
    scanf("%d", &ch);
    switch(ch)
    {
        int res,data;
    case 1:
        printf("\nEnter Data : \n");
        scanf("%d", &data);
        enqueue(q, data);
        break;
    case 2:
        res = dequeue(q);
        if(res != 0)
        printf("Successfully Deleted : %d\n", res);
        else
            printf("Queue is Empty!!\n");
        break;
    case 3:
        if(q->front != NULL)
            printf("Front = %d, Rear = %d\n", q->front->data, q->rear->data);
        else
            printf("Queue is Empty!! Nothing to print!!\n");
        break;
    case 4:
        return 0;
    }
    }
}
