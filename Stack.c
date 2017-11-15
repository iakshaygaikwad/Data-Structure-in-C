#include<stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

typedef struct Stack
{
    node *top;
}stack;

stack * createStack()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = NULL;
    return s;
}

node* createNode(int data)
{
    node *tnode = (node*)malloc(sizeof(node));
    tnode -> data = data;
    tnode -> next = NULL;
    return tnode;
}

int isEmpty( stack *s)
{
    if(s->top == NULL)
        return -1;
    return 1;

}
void push(stack *s, int data)
{
    node *tnode = createNode(data);
    if(isEmpty(s) == -1)
    {
        s->top = tnode;
        return;
    }
    tnode -> next = s->top;
    s->top = tnode;
}

int pop(stack *s)
{
    node *temp;
    int popped = 0;
    if(isEmpty(s) == -1)
        return -1;

    temp = s->top;
    s->top = s->top->next;
    popped = temp->data;
    free(temp);
    return popped;
}

int peek(stack *s)
{
    if(isEmpty(s) == -1)
        return -1;
    return s->top->data;
}

int main()
{
    int ch;
    stack *s = createStack();
    while(1)
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter Choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
            int data;
        case 1 :
            printf("Enter Data : ");
            scanf("%d", &data);
            push(s,data);
            break;
        case 2:
            data = pop(s);
            if(data != -1)
                printf("Popped Successfully : %d", data);
            else
                printf("Stack is Empty!!");
            break;
        case 3:
           data = peek(s);
            if(data != -1)
                printf("top = %d", data);
            else
                printf("Stack is Empty!!");
            break;
        case 4:
            return(0);
            break;
        default:
            printf("Wrong Choice!! \n");
        }

    }
    return 0;
}
