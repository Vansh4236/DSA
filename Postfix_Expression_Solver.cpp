#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class Stack {
private:
    Node *Top;

public:
    Stack() : Top(nullptr) {}

    void push(int ele) {
        Node *t = new Node;
        if (!t) {
            cout << "Stack overflow\n";
        } else {
            t->data = ele;
            t->next = Top;
            Top = t;
        }
    }

    int pop() {
        if (!Top) {
            cout << "Stack Underflow\n";
            return -1; // Return -1 for error indication
        } else {
            Node *p = Top;
            int x = p->data;
            Top = Top->next;
            delete p;
            return x;
        }
    }

    bool isEmpty() {
        return Top == nullptr;
    }

    ~Stack() {
        while (Top) {
            Node *temp = Top;
            Top = Top->next;
            delete temp;
        }
    }
};

int evaluatePostfix(const string &exp) {
    Stack S;
    int i = 0;
    while (i < exp.length()) {
        char ch = exp[i];

        if (ch == ' ') {
            i++;
            continue;
        }

        if (isdigit(ch)) {
            int num = 0;
            
            while (i < exp.length() && isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            S.push(num);
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (S.isEmpty()) {
                cout << "Error: Not enough operands!\n";
                return -1;
            }
            int b = S.pop();
            if (S.isEmpty()) {
                cout << "Error: Not enough operands!\n";
                return -1;
            }
            int a = S.pop();

            switch (ch) {
                case '+': S.push(a + b); break;
                case '-': S.push(a - b); break;
                case '*': S.push(a * b); break;
                case '/':
                    if (b == 0) {
                        cout << "Error: Division by zero!\n";
                        return -1;
                    }
                    S.push(a / b);
                    break;
                default:
                    cout << "Error: Invalid operator!\n";
                    return -1;
            }
            i++;  // Move to the next character
        } else {
            cout << "Error: Invalid character in expression!\n";
            return -1;
        }
    }

    if (S.isEmpty()) {
        cout << "Error: No result found in stack!\n";
        return -1;
    }

    return S.pop();
}

int main() {
    string postfixExp;
    cout << "Enter a postfix expression: ";
    getline(cin, postfixExp);

    int result = evaluatePostfix(postfixExp);

    if (result != -1) {
        cout << "The result of the postfix expression is: " << result << "\n";
    }

    return 0;
}
