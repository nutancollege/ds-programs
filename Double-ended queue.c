#include <stdio.h>
#define SIZE 5

int deque[SIZE], front = -1, rear = -1;

void insertFront(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front--;
        }
        deque[front] = value;
        printf("Inserted at front: %d\n", value);
    }
}

void insertRear(int value) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = value;
        printf("Inserted at rear: %d\n", value);
    }
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow\n");
    } else {
        printf("Deleted from front: %d\n", deque[front]);
        if (front == rear) {
            front = rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow\n");
    } else {
        printf("Deleted from rear: %d\n", deque[rear]);
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = SIZE - 1;
        } else {
            rear--;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
    } else {
        printf("Deque elements: ");
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                printf("%d ", deque[i]);
            }
        } else {
            for (int i = front; i < SIZE; i++) {
                printf("%d ", deque[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d ", deque[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
