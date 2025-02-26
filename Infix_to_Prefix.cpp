#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <cctype>
using namespace std;

struct Node
{
    char data;
    struct Node *next;
};

class Stack
{
private:
    struct Node *Top;

public:
    Stack()
    {
        Top = NULL;
    }
    
    void push(char ele);
    char pop();
    char peek(int pos);
    char stackTop();
    bool isEmpty();
    int isFull();
    void displayStack();
};

void Stack ::push(char ele)
{
    struct Node *t = new Node;
    if (t == NULL)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        t->data = ele;
        t->next = Top;
        Top = t;
    }
}

char Stack ::pop()
{
    struct Node *p;
    char x = '\0';
    if (Top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        p = Top;
        Top = Top->next;
        x = p->data;
        delete p;
    }
    return x;
}

char Stack ::peek(int pos)
{
    struct Node *p = Top;
    for (int i = 0; p != NULL && i < pos - 1; i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        return p->data;
    }
    else
    {
        return -1;
    }
}

char Stack ::stackTop()
{
    if (Top != NULL)
    {
        return Top->data;
    }
    else
    {
        return -1;
    }
}

bool Stack ::isEmpty()
{
    return Top == NULL;
}

int Stack ::isFull()
{
    Node *t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

void Stack ::displayStack()
{
    struct Node *p = Top;
    int i = 0;
    while (p != NULL)
    {
        cout << "Element " << i + 1 << " in stack : " << p->data << endl;
        p = p->next;
        i++;
    }
}

bool parenthesis_matching(string str)
{
    Stack S;

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

int presidance(char op)
{
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    return -1;
}

bool isdigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

string postfix_convert(string str)
{
    string ans = "";
    Stack S;

    if (str.empty()) return ans;

    int i = 0 , j = 0;
    while(str[i] != '\0')
    {
        if(isalnum(str[i]))
        {
            ans += str[i++];
            if (str[i] == ' ' || str[i] == '\0') 
            {
                ans += ' ';
            }
        }
        else if(str[i] == ' ')
            i++;
        else if(str[i] == '(')
            S.push(str[i++]);
        else if(str[i] == ')')
        {
            while(!S.isEmpty() && S.stackTop() != '(')
                ans += S.pop();
            if(!S.isEmpty() && S.stackTop() == '(')
                S.pop();
            i++;
        }   
        else
        {
            while(!S.isEmpty() && presidance(S.stackTop()) >= presidance(str[i]))
            {
                ans += S.pop();
            }
            S.push(str[i++]);
        }
    }

    while(!S.isEmpty())
    {
        ans += S.pop();
    }

    return ans;
}

string reverse(string str)
{
    int i = 0;
    Stack S;
    S.push('\0');
    while(str[i] != '\0')
    {
        if(str[i] == '(')
            S.push(')');
        else if(str[i] == ')')
            S.push('(');
        else
            S.push(str[i]);
        i++;
    }

    string ans = "";
    while(!S.isEmpty())
    {
        ans += S.pop();
    }

    return ans;
}

string prefix_convert(string str)
{
    string rev_infix = reverse(str);

    string postfix_rev_infix = postfix_convert(rev_infix);

    string ans = reverse(postfix_rev_infix);

    return ans;
}

int main()
{
    string str;
    cout<<"Enter the string in prefix : ";
    getline(cin,str);

    string ans = prefix_convert(str);
    cout<<"REversed string : "<<ans;
    
    return 0;
}