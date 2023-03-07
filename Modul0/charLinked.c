#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

void insert(Node **head, char value) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void print_list(Node *head) {
    while (head != NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    insert(&head, 'e');
    insert(&head, 'l');
    insert(&head, 'l');
    insert(&head, 'o');

    printf("List contents: ");
    print_list(head);

    return 0;
}
