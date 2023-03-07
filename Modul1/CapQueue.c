#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100

struct Queue {
    int front;
    int rear;
    char data[MAX_LENGTH];
};

void enqueue(struct Queue* queue, char c) {
    if (queue->rear < MAX_LENGTH - 1) {
        queue->rear++;
        queue->data[queue->rear] = c;
    }
}

char dequeue(struct Queue* queue) {
    char c = '\0';
    if (queue->front <= queue->rear) {
        c = queue->data[queue->front];
        queue->front++;
    }
    return c;
}

void capitalize_words(char* str) {
    struct Queue queue;
    queue.front = 0;
    queue.rear = -1;

    int i;
    for (i = 0; i < strlen(str); i++) {
        if (i == 0 || isspace(str[i - 1])) {
            enqueue(&queue, toupper(str[i]));
        } else {
            enqueue(&queue, str[i]);
        }
    }

    for (i = 0; i < strlen(str); i++) {
        str[i] = dequeue(&queue);
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
