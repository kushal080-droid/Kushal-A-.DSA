#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
    return ((rear + 1) % SIZE == front);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int id) {
    if (isFull()) {
        printf("Queue is full. Cannot add call ID: %d\n", id);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = id;
    printf("Call added: %d\n", id);
}

void dequeue() {
    if (isEmpty()) {
        printf("No calls to remove.\n");
        return;
    }
    printf("Call removed: %d\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void display() {
    if (isEmpty()) {
        printf("No calls in queue.\n");
        return;
    }
    printf("Current calls in queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(101);
    enqueue(102);
    enqueue(103);
    display();

    dequeue();
    display();

    enqueue(104);
    enqueue(105);
    enqueue(106); // Overflow test
    display();

    return 0;
}

