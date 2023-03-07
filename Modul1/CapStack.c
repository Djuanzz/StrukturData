#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

struct Stack {
    int top;
    char data[MAX_LENGTH];
};

void push(struct Stack* stack, char c) {
    if (stack->top < MAX_LENGTH - 1) {
        stack->top++;
        stack->data[stack->top] = c;
    }
}

char pop(struct Stack* stack) {
    char c = '\0';
    if (stack->top >= 0) {
        c = stack->data[stack->top];
        stack->top--;
    }
    return c;
}

void capitalize_words(char* str) {
    struct Stack stack;
    stack.top = -1;

    int i;
    for (i = 0; i < strlen(str); i++) {
        if (i == 0 || isspace(str[i - 1])) {
            push(&stack, toupper(str[i]));
        } else {
            push(&stack, str[i]);
        }
    }

    for (i = 0; i < strlen(str); i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    char str[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    capitalize_words(str);

    printf("Modified string: %s", str);

    return 0;
}
