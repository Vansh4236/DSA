// Write a C program to reverse a string using stack 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
    int data;
    struct stack *next;
}node;

node* push(node *top,char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        node *temp=(node*)malloc(sizeof(node));
        temp->data=s[i];
        temp->next=top;
        top=temp;
        i++;
    }
    return top;
    
}
void reverse(node *top)
{
    do
    {
        printf("%c",top->data);
        top=top->next;
    }
    while(top->next!=NULL);
}
int main()
{
    node *top=(node*)malloc(sizeof(node));
    top->next=NULL;
    char s[100];
    printf("Enter your string:");
    scanf("%s",&s);
    top=push(top,s);
    printf("Reversed String is:");
    reverse(top);
    return 0;
}