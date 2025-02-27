#include<stdio.h>
typedef int BOOL;
#define TRUE 1
#define FALSE 0

#define size 10
int stack[size];
int top=-1;

BOOL isStackFull()
{
    if(top == size)
    {
        return TRUE;
    }
    else
    return FALSE;
}

BOOL isStackEmpty()
{
    if(top == -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void push(int value)
{
    if(isStackFull())
    {
        printf("Stack is full !!!\n");
        return ;
    }
    else{
        top++;
        stack[top]=value; //stack[++top]=value;
    }
}

int pop()
{
    if(isStackEmpty())
    {
        printf("Stack is Empty !!!\n");
        return -1;
    }
    else
    {
        int value=stack[top]; // int value=stack[top--];
        top--;
    }
}
void Display(int stack[])
{
    for(int i=0;i<=top;i++)
    {
        printf("%d->",stack[i]);
    }
    printf("NULL\n");
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    Display(stack);
    pop();
    pop();
    Display(stack);
    return 0;
}