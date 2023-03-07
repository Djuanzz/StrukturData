#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void insertPos(int data, int pos){
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->next = NULL;
    if(pos == 1){
        temp1->next = head;
        head = temp1;
        return;
    }

    // struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp2 = head;
    for(int i = 0; i < pos-2; i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void mengPrint(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    head = NULL;
    insertPos(4, 1);
    insertPos(5, 2);
    insertPos(9, 1);
    insertPos(7, 3);
    mengPrint();
    return 0;
}