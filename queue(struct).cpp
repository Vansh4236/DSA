//Assignment 3 b)

//Implement Queue using structure

#include<iostream>
#include<unistd.h>
using namespace std;

#define size 10


typedef struct queue
{
    int front;
    int rear;
    int queue[size];
}queue;


void display(queue *q)
{
    int f=q->front+1;
    int r=q->rear;
    do
    {
        cout<<q->queue[f]<<" ";
        f++;
    }while(f<=r);
    cout<<endl;
}

int queuefull(queue *q)
{
    if(q->rear>size)
    return 1;

    else
    return 0; 
}
int queueempty(queue *q)
{
    if(q->rear==-1||q->front>=q->rear)
    return 1;

    else
    return 0; 
}
void enqueue( queue *q)
{
    if(queuefull(q))
    {
        cout<<"\nQueue is Full";
    }
    else
    {
    int x;
    cin>>x;
    q->rear++;
    q->queue[q->rear]=x;
    }
}

void dequeue(queue *q)
{
    if(queueempty(q))
    {
        cout<<"\nQueue is Empty";
    }
    else
    {
    q->front++;
    cout<<q->queue[q->front];
    }
}


int main()
{
    queue *q= new queue;
    q->rear=-1;
    q->front=-1;
    int opt=-1;
    while(opt!=6)
    {   
        cout<<"\nEnter What operation you want:\n1.Queue Full\n2.Queue Empty\n3.Enqueue\n4.Dequeue\n5.Display\n6.Exit\n";
        cin>>opt;
        switch(opt)
        {
            case 1:
            if(queuefull(q))
            cout<<"\n->Queue is Full\n";
            else
            cout<<"\n->Queue is not Full\n";
            break;
            case 2:
            if(queueempty(q))
            cout<<"\n->Queue is Empty\n";
            else
            cout<<"\n->Queue is Not Empty\n";
            break;
            case 3:
            cout<<"\nEnter elements:";
            enqueue(q);
            break;
            case 4:
            dequeue(q);
            break;
            case 5:
            display(q);
            break;
            case 6:
            cout<<"\n->Exiting...";
            break;
            default:
            cout<<"\n->Wrong Option.. Try Again"<<endl;
        }
    }
    return 0;
}