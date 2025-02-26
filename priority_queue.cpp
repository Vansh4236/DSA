#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

bool isempty() {
    return front == -1;
}

bool isfull() {
    return (rear + 1) % SIZE == front;
}
void enqueue(int value) {
    if (isfull()) {
        cout << "Queue Overflow\n";
        return;
    }

    if (isempty()) {
        front = rear = 0;
        queue[rear] = value;
    } else {
        int i = rear;
        while (i != front - 1 && queue[i] > value) {
            queue[(i + 1) % SIZE] = queue[i];  
            i = (i - 1 + SIZE) % SIZE;
        }
        queue[(i + 1) % SIZE] = value; 
        rear = (rear + 1) % SIZE;
    }
    cout << "Element inserted successfully\n";
}
int dequeue() {
    if (isempty()) {
        cout << "Queue Underflow\n";
        return -1;
    }

    int value = queue[front];
    if (front == rear) {
        front = rear = -1;  
    } else {
        front = (front + 1) % SIZE;
    }
    return value;
}

int peek() {
    if (isempty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    cout << "The front element is [" << queue[front] << "] at index " << front << endl;
    return queue[front];
}

void display() {
    if (isempty()) {
        cout << "Queue is empty\n";
        return;
    }

    int i = front;
    cout << "Queue elements are: ";
    while (true) {
        cout << queue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    int ch, item;
    cout << "Ascending Priority Queue Operations:\n";
    cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";

    do {
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> item;
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if (item != -1)
                    cout << "Deleted element is: " << item << "\n";
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}
