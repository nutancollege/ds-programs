#include <stdio.h>
#define SIZE 5

int queue[SIZE], priority[SIZE], front = -1, rear = -1;

void enqueue(int value, int prio) {
    if (rear == SIZE - 1) {
        printf("Priority Queue Overflow\n");
    } else {
        if (front == -1) {
            front = rear = 0;
            queue[rear] = value;
            priority[rear] = prio;
        } else {
            int i;
            for (i = rear; i >= front && priority[i] > prio; i--) {
                queue[i + 1] = queue[i];
                priority[i + 1] = priority[i];
            }
            queue[i + 1] = value;
            priority[i + 1] = prio;
            rear++;
        }
        printf("Inserted: %d with priority: %d\n", value, prio);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Priority Queue Underflow\n");
    } else {
        printf("Dequeued: %d with priority: %d\n", queue[front], priority[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Priority Queue is empty\n");
    } else {
        printf("Priority Queue elements:\n");
        for (int i = front; i <= rear; i++) {
            printf("Value: %d, Priority: %d\n", queue[i], priority[i]);
        }
    }
}

int main() {
    int choice, value, prio;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &value, &prio);
                enqueue(value, prio);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
