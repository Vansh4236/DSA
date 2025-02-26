#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
    
class Stack
{
private:
    int size;
    int Top;
    char *s;

public:
    Stack(int n)
    {
        size = n;
        Top = -1;
        s = new char[n];
    }
    
    void push(char ele);
    char pop();
    int peek(char pos);
    int stackTop();
    int isEmpty();
    int isFull();
    void displayStack();
};

void Stack ::push(char ele)
{
    if (Top == size - 1)
    {
        cout << "Stack overflow";
    }
    else
    {
        Top++;
        s[Top] = ele;
    }
}

char Stack ::pop()
{
    int x = -1;
    if (Top == -1)
    {
        cout << "Stack Underflow";
    }
    else
    {
        x = s[Top];
        Top--;
    }
    return x;
}

int Stack ::peek(char pos)
{
    int x = -1;
    if (Top - pos + 1 == 0)
    {
        cout << "ERROR : Invalid index";
    }
    else
    {
        x = s[Top - pos + 1];
    }
    return x;
}

int Stack ::stackTop()
{
    if (Top == -1)
    {
        return -1;
    }
    else
    {
        return s[Top];
    }
}

int Stack ::isEmpty()
{
    if (Top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Stack ::isFull()
{
    if (Top == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Stack ::displayStack()
{
    for (int i = 0; i < Top + 1; i++)
    {
        cout << "Element " << i + 1 << " in stack : " << s[i] << endl;
    }
}
    
int main()
{
    string str;
    cout<<"Enter the string you want to reverse : ";
    getline(cin,str);

    int n = str.size();

    Stack S(n);
    for(int i = 0 ; i < str.size() ; i++)
    {
        S.push(str[i]);
    }
    
    char str_rev[n+1];
    // string str_rev;
    // str_rev.resize(str.size());
    // string str_rev(str.size(), ' ');
    for(int i = 0 ; i < str.size() ; i++)
    {
        str_rev[i] = S.pop();
    }
    // str_rev[n] = '/0';

    cout<<"REversed string : "<<str_rev;

    return 0;
}