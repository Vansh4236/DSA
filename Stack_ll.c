#include<stdio.h>
#include<stdlib.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

struct node{
    int data;
    struct node *next;
};

BOOL isStackEmpty(struct node *first)
{
    if(first == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void push(struct node **top,int value)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node*));
    newnode->data=value;
    newnode->next=NULL;
    if(isStackEmpty(*top))
    {
        *top=newnode;
    }
    else
    {
        newnode->next=*top;
        *top=newnode;
    }
}

int pop(struct node **top)
{
    if(isStackEmpty(*top))
    {
        printf("Stack is Empty !!\n");
        return -1;
    }
    else
    {
        struct node *temp=NULL;
        temp=*top;
        *top=(*top)->next;
        printf("popped Element:%d\n",temp->data);
        free(temp);
    }
}
void Display(struct node *top)
{
    struct node *temp=top;
    printf("Top->");
    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node *top=NULL;
    push(&top,1);
    push(&top,2);
    push(&top,3);
    push(&top,4);
    push(&top,5);
    push(&top,6);
    push(&top,7);
    push(&top,8);
    Display(top);
    pop(&top);
    pop(&top);
    Display(top);
    return 0;
}