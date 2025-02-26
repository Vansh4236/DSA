//Assignment 3 a)

//Implement Queue using array
#include<iostream>
#include<unistd.h>
using namespace std;

#define size 10

int front=-1;
int rear=-1;
void display(int queue[])
{
    int f=front+1;
    int r=rear;
    do
    {
        sleep(1);
        cout<<queue[f]<<" ";
        f++;
    }while(f<=r);
    cout<<endl;
}

int queuefull()
{
    if(rear>size)
    return 1;

    else
    return 0; 
}
int queueempty()
{
    if(rear==-1||front>=rear)
    return 1;

    else
    return 0; 
}
int *enqueue(int queue[])
{
    if(queuefull())
    {
        cout<<"\nQueue is Full";
    }
    int x;
    cin>>x;
    rear++;
    queue[rear]=x;
    return queue;
}

int *dequeue(int queue[])
{
    if(queueempty())
    {
        cout<<"\nQueue is Full";
    }
    front++;
    cout<<queue[front];
    return queue;
}


int main()
{
    int *queue=new int[size];
    int opt=-1;
    while(opt!=6)
    {   
        cout<<"\nEnter What operation you want:\n1.Queue Full\n2.Queue Empty\n3.Enqueue\n4.Dequeue\n5.Display\n6.Exit\n";
        cin>>opt;
        switch(opt)
        {
            case 1:
            if(queuefull())
            cout<<"\n->Queue is Full\n";
            else
            cout<<"\n->Queue is not Full\n";
            break;
            case 2:
            if(queueempty())
            cout<<"\n->Queue is Empty\n";
            else
            cout<<"\n->Queue is Not Empty\n";
            break;
            case 3:
            cout<<"\nEnter elements:";
            queue=enqueue(queue);
            break;
            case 4:
            queue=dequeue(queue);
            break;
            case 5:
            display(queue);
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