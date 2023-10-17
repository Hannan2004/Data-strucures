#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int stack[], int val);
int pop(int stack[]);
void display(int stack[]);
int peek(int stack[]);

int main()
{
    int val, option;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\n enter the number to be pushed on stack: ");
            scanf("%d", &val);
            push(stack, val);
            break;
        case 2:
            val = pop(stack);
            if (val != -1)
                printf("\n The value deleted from stack is: %d", val);
            break;
        case 3:
            val = peek(stack);
            if (val != -1)
                printf("\n The value stored at top of stack is: %d", val);
            break;
        case 4:
            display(stack);
            break;
        }
    } while (option != 5);
    return 0;
}

void push(int stack[], int val)
{
    if (top == MAX - 1)
    {
        printf("\n STACK OVERFLOW");
    }
    else
    {
        top++;
        stack[top] = val;
    }
}
int pop(int stack[])
{
    int val;
    if (top == -1)
    {
        printf("\n STACK UNDERFLOW");
        return -1;
    }
    else
    {
        val = stack[top];
        top--;
        return val;
    }
}
void display(int stack[])
{
    int i;
    if (top == -1)
        printf("\n STACK IS EMPTY");
    else
    {
        for (i = top; i >= 0; i--)
            printf("\n %d", stack[i]);
        printf("\n"); // Added for formatting purposes
    }
}
int peek(int stack[])
{
    if (top == -1)
    {
        printf("\n STACK IS EMPTY");
        return -1;
    }
    else
        return (stack[top]);
}
