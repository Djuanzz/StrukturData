#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void insertLast(int datanya){
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = datanya;
    temp1->next = NULL;

    if(head == NULL){
        head = temp1;
    } else{
        struct Node* temp2 = head;
        while (temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
}

void mengPrint(){
    struct Node* temp = head;
    printf("Listnya = ");
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void revese(){
    struct Node *prev, *current, *nextStep;
    current = head;
    prev = NULL;

    while(current != NULL){
        // nextStep tu biar bisa pindah2 maju gitu biar ga ilang address nya (?)
        nextStep = current->next;
        current->next = prev;
        prev = current;
        current = nextStep;
    }
    //biar si head nya ada isinya
    head = prev;
}

int main(){
    head = NULL;
    insertLast(2);
    insertLast(6);
    insertLast(8);
    mengPrint();
    revese();
    mengPrint();
    
    return 0;
}