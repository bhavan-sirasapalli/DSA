/*A service centre uses a fixed-size request buffer in which released 
positions must be reused.Write a C program to implement a Circular 
Queue using an array with insertion, deletion, display, overflow 
and underflow operations. Demonstrate that positions freed after 
deletion can be reused for new requests.*/

#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return ((rear + 1) % MAX_SIZE == front);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int request_id) {
    if (isFull()) {
        printf("Buffer Overflow: Request %d cannot be added. Queue is full.\n", request_id);
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = request_id;
    printf("Enqueued Request: %d (Stored at index %d)\n", request_id, rear);
}

int dequeue() {
    if (isEmpty()) {
        printf("Buffer Underflow: No requests to service.\n");
        return -1;
    }
    int request_id = queue[front];
    printf("Dequeued Request: %d (Freed index %d)\n", request_id, front);

    if (front == rear) {
        front = rear = -1; // Reset when queue becomes empty
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return request_id;
}

int peek() {
    if (isEmpty()) {
        printf("Buffer is empty.\n");
        return -1;
    }
    return queue[front];
}

void displayQueue() {
    if (isEmpty()) {
        printf("Current Buffer State: [Empty]\n");
        return;
    }
    printf("Current Buffer State (Front to Rear): ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    printf("Step 1: Fill the buffer capacity completely\n");
    enqueue(101);
    enqueue(102);
    enqueue(103);
    enqueue(104);
    enqueue(105);
    displayQueue();

    printf("\nStep 2: Overflow the cqueue\n");
    enqueue(106); 

    printf("\nStep 3: Release positions using Dequeue\n");
    dequeue(); 
    dequeue(); 
    displayQueue();

    printf("\nStep 4: Reuse - (Wrap-Around)\n");
    enqueue(201); 
    enqueue(202); 
    displayQueue();

    printf("\nStep 5: Overflow on Wrapped Indices\n");
    enqueue(203);

    printf("\nStep 6: Peek Front Element\n");
    printf("Next request to be serviced (Peek): %d\n", peek());

    return 0;
}
