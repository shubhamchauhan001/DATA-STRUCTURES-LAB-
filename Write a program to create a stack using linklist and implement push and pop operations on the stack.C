// Write a program to create a stack using linklist and implement push and pop operations on the stack. //

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initStack(struct Stack* stack) {
    stack->top = NULL;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed to stack\n", data);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;  // Indicating stack is empty
    }
    struct Node* temp = stack->top;
    int poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedData;
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = stack->top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);
    int choice, data;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display Stack\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 2:
                data = pop(&stack);
                if (data != -1)
                    printf("%d popped from stack\n", data);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
