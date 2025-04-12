#include <iostream>
using namespace std;

#define SIZE 5  // size of circular queue

class CircularQueue {
private:
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }

        if (front == -1) front = 0; // First element
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        cout << "Inserted: " << element << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Deleted: " << items[front] << endl;

        if (front == rear) {
            front = rear = -1;  // Queue becomes empty
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    return 0;
}
