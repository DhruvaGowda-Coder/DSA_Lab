#include <stdio.h>
#define SIZE 5
                                                                       
int queue[SIZE];
int front = -1, rear = -1;
     
// Enqueue operation
void enqueue(int value) {
    if (rear == SIZE - 1)
        printf("Queue is full!\n");
    else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}

// Dequeue operation
void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue is empty!\n");
    else {
        printf("Deleted %d\n", queue[front]);
        front++;
    }
}                                                                   

// Peek operation
void peek() {
    if (front == -1 || front > rear)
        printf("Queue is empty!\n");
    else
        printf("Front element is %d\n", queue[front]);
}

// Display operation
void display() {
    if (front == -1 || front > rear)
        printf("Queue is empty!\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
                                                                     
// Clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Main function with input validation
int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid value! Please enter a number.\n");
                    clearInputBuffer();
                    break;
                }
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

                                                                    


