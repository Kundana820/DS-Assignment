/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
 
int stack[100], choice, n, top, x, i;
 
/* Function prototypes */
void push(void);
void pop(void);
void display(void);
 
int main() {
    // Initialize top to -1 indicating an empty stack
    top = -1;
 
    printf("\nEnter the size of STACK[MAX=100]: ");
    scanf("%d", &n);
 
    printf("\n\tSTACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t1.PUSH\n\t2.POP\n\t3.DISPLAY\n\t4.EXIT");
 
    do {
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);
 
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\tEXIT POINT");
                break;
            default:
                printf("\n\tPlease Enter a Valid Choice(1/2/3/4)");
        }
    } while(choice != 4);
 
    return 0;
}
 
void push() {
    if(top >= n - 1) {
        printf("\n\tSTACK is overflow. Cannot push %d\n", x);
    } else {
        printf("Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("\n\t%d pushed to stack\n", x);
    }
}
 
void pop() {
    if(top <= -1) {
        printf("\n\tStack is underflow. Cannot pop\n");
    } else {
        printf("\n\tThe popped element is %d\n", stack[top]);
        top--;
    }
}
 
void display() {
    if(top >= 0) {
        printf("\nThe elements in STACK:\n");
        for(i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    } else {
        printf("\nThe STACK is empty\n");
    }
}