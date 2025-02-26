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
    return Top == -1;
}

int Stack ::isFull()
{
    return (Top == size - 1);
}

void Stack ::displayStack()
{
    for (int i = 0; i < Top + 1; i++)
    {
        cout << "Element " << i + 1 << " in stack : " << s[i] << endl;
    }
}

bool parenthesis_matching(string str)
{
    Stack S(str.size() + 1);

    for(int i = 0 ; i < str.size() ; i++)
    {
        if(str[i] == '(' || str[i] =='[' || str[i] =='{')
            S.push(str[i]);
        else if(str[i] == ')' || str[i] ==']' || str[i] =='}')
        {
            if(S.isEmpty())
                return false;
            char top = S.pop();
            if ((str[i] == ')' && top != '(') || 
                (str[i] == ']' && top != '[') || 
                (str[i] == '}' && top != '{'))
                return false;
        }
    }
    return S.isEmpty();
}
    
int main()
{
    string str;
    cout<<"Enter the expression you want to varify : ";
    getline(cin,str);

    bool ans = parenthesis_matching(str);

    if(ans == 1)
        cout<<"Entered expression is correct.";
    else
        cout<<"Entered expression is incorrect.";
    
    return 0;
}