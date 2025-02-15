#include <stdio.h>
#include <stdlib.h>
#define MAX 5
 

void enqueue();
void dequeue();
void display();
 

int queue[MAX], front = 0, rear = 0;
 
int main() {
    int ch = 1;
    printf("Queue using Array\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Display\n");
    printf("4. Exit\n");
 
    while (ch) {
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);
 
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong Choice: please see the options\n");
        }
    }
 
    return 0;
}
 
void enqueue() {
    if (rear == MAX) {
        printf("\nQueue is Full\n");
    } else {
        int value;
        printf("\nEnter value %d: ", rear + 1);
        scanf("%d", &value);
        queue[rear++] = value;
    }
}
 
void dequeue() {
    if (front == rear) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\nDeleted Element is %d\n", queue[front++]);
 
        
        if (front == rear) {
            front = 0;
            rear = 0;
        }
    }
}
 
void display() {
    if (front == rear) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\nQueue Elements are:\n");
        for (int i = front; i < rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}