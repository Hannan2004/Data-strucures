#include <stdio.h>

#define MAX 10
int queue[MAX];
int front = -1;
int rear = -1;

void enqueue();
int dequeue();
int peek();
void display();

int main() {
    int option, val;
    do {
        printf("Main menu");
        printf("\n 1.Enqueue");
        printf("\n 2.Dequeue");
        printf("\n 3.Peek");
        printf("\n 4.Display");
        printf("\n 5.Exit");

        // Read user's choice
        scanf("%d", &option);

        switch (option) {
            case 1:
                enqueue();
                break;

            case 2:
                val = dequeue();
                if (val != -1)
                    printf("\n The number deleted is : %d", val);
                break;

            case 3:
                val = peek();
                if (val != -1)
                    printf("\n The first value in queue is : %d", val);
                break;

            case 4:
                display();
                break;

            default:
                printf("\n Invalid input");
                break;
        }
    } while (option != 5);
    return 0;
}

void enqueue() {
    int num;
    printf("\n Enter the number to be inserted in the queue :");
    scanf("%d", &num);
    if (rear == MAX - 1)
        printf("\n Overflow");
    else if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear++;
    queue[rear] = num;
}

int dequeue() {
    int val;
    if (front == -1 || front > rear) {
        printf("\n Underflow");
        return -1;
    } else {
        val = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;
        return val;
    }
}

int peek() {
    if (front == -1 || front > rear) {
        printf("\n queue empty");
        return -1;
    } else {
        return queue[front];
    }
}

void display() {
    int i;
    printf("\n");
    if (front == -1 || front > rear)
        printf("queue empty");
    else {
        for (i = front; i <= rear; i++) {
            printf(" \t %d", queue[i]);
        }
    }
}
