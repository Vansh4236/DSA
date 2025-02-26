//Assignment 2


#include<iostream>
#include<string.h>
using namespace std;
void check(string exp)
{
    int i=0;
    int j=0;
    int x=0;
    while(exp[x]!='\0')
    {
        cout<<exp[x];
        if(exp[x]=='(')
        i++;

        if(exp[x]==')')
        j++;

        if(j>i)
        break;

        x++;
       
    }
    
    if(i==j)
    {
        cout<<"\nBalanced Paranthesis";
    }
    else
    {
        cout<<"\nNot Balanced Paranthesis";
    }
   
}
int main()
{
    string exp;
    cout<<"Enter expression";
    cin>>exp;
    check(exp);
    return 0;
}