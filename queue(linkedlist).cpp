//Assignment 3 c)

//Implement Queue using LinkedList

#include<iostream>
using namespace std;

#define size 10

typedef struct node{
    int data;
    struct node *next = NULL ; 
}node;

bool isfull(node *q)
{
    int c = 0;
    struct node * p = q;
    while(p != NULL)
    {
        c++;
        p = p->next;
    }
    if(c>=size)
        return 1;
    else
        return 0;
}

bool isempty(node *q)
{
    int c = 0;
    node * p = q;
    while(p != NULL)
    {
        c++;
        p = p->next;
    }
    if(c<=0)
    return 1;
    else
    return 0;
}

node *enqueue(node *q)
{
    if (isfull(q))
    {
        cout<<"\nQueue is full"<<endl;
        return q;
    }
    int x;
    cout<<"\nEnter the element to insert in Queue-->";
    cin>>x;

    node *n = new node();
    n->data = x;
    n->next = q;
    q = n;
    return q;
}

node * dequeue(node *q)
{   
    if(isempty(q))
    {
        cout<<"\nQueue is empty"<<endl;
        return NULL;    
    }

    if(q->next == NULL)
    {
       cout<<"--->"<<q->data<<endl;
       delete q;
       return NULL;
    }
    node * p = q;
    while(p->next->next != NULL)
    {
        p=p->next;
    }
    node * temp = p->next;
    int x = temp->data;
    p->next = NULL;
    delete temp;
    cout<<"--->"<<x<<endl;
    return q;

}

void display(node *q)
{
    node * p = q;
    while(p!=NULL)
    {
        cout<<p->data<<"-->";
        p = p->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node *q = new node();
    q =NULL;
    int op = 0;
    while(op!=4)
    {
        cout<<"1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n---->";
        cin>>op;
        switch (op)
        {
            case 1:
                q = enqueue(q);
                break;
            case 2:
               q =  dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                cout<<"\nExiting...";
                break;
        }
    }
    return 0;
}