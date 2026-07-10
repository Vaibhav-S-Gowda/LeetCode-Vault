#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char* data;
    int top;
    int capacity;
}Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    stack->data[++stack->top] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->data[stack->top--];
}

void freeStack(Stack* stack) {
    free(stack->data);
    free(stack);
}

bool isValid(char* s) {
    int len = 0;
    while (s[len] != '\0') len++;

    if (len % 2 != 0) return false;

    Stack* stack = createStack(len);

    for (int i = 0; i < len; i++) {
        char current = s[i];

        if (current == '(' || current == '[' || current == '{') {
            push(stack, current);
        }
        else {
            if (isEmpty(stack)) {
                freeStack(stack);
                return false;
            }

            char topChar = pop(stack);
            if ((current == ')' && topChar != '(') || (current == ']' && topChar != '[') || (current == '}' && topChar != '{')) {
                freeStack(stack);
                return false;
            }
        }
    }

    bool valid = isEmpty(stack);
    freeStack(stack);
    return valid;
}