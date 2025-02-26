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

int postfix_solution(string exp)
{
    Stack S;
    int i = 0;
    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
            S.push(exp[i] - '0');
        else
        {
            if (exp.size() < 2) 
            { 
                cout << "Error: Not enough operands in stack for operation!" << endl;
                return -1; 
            }
            int x = S.pop();
            int y = S.pop();
            if(exp[i] == '+')
                S.push(y + x);
            else if(exp[i] == '-')
                S.push(y - x);
            else if(exp[i] == '*')
                S.push(y * x);
            else if(exp[i] == '/')
            {
                if (x == 0) 
                { 
                        cout << "Error: Division by zero!" << endl;
                        return -1; 
                }

                S.push(y / x);
            }
            else
            {
                cout<<"POP-UP : ERROR ERROR !!!!!!!"<<endl;
                break;
            }
        }
    }
    return S.pop();
}

int prefix_solution(string exp)
{
    
}

int expression_solver()
{
    string str;
    int choice = 0;
    int ans = -1;

    while(choice != 4)
    {
        cout<<"Choice :\n";
        cout<<"1. Infix \n2. Prefix \n3. Postfix \n4. Exit\n";
        cout<<"Enter your choice : ";
        cin>>choice;

        if(choice == 1)
        {
            cout<<"Enter a Infix expression : ";
            cin>>str;
            string exp = postfix_convert(str);
            // exp[exp.size() + 1] = '\0';
            cout<<exp;
            // ans = postfix_solution(exp);
            break;
        }
        else if(choice == 2)
        {
            cout<<"Enter a Prefix expression : ";
            cin>>str;
            string exp = str;
            ans = postfix_solution(exp);
            break;
        }
        else if(choice == 3)
        {
            cout<<"Enter a Postfix expression : ";
            cin>>str;
            string exp = str;
            ans = prefix_solution(exp);
            break;
        }
        else if(choice == 4)
        {
            exit(0);
            break;
        }
        else
        {
            cout<<"ERROR : Enter a valid choice..\n";
            cout<<"RE-Enter your choice : \n";
            break;
        }
    }
    return ans;
}

int main()
{
    int ans = expression_solver();
    cout<<ans;
    
    return 0;
}