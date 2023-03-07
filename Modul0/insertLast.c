#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void insertLast(int datanya){
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = datanya;
    temp1->next = NULL;

    struct Node* temp2 = head;
    if(head == NULL){
        head = temp1;
    } else{
        while (temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
}

void mengPrint(){
    struct Node* temp = head;
    printf("Listnya = ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    head = NULL;
    insertLast(9);
    insertLast(3);
    insertLast(8);


    mengPrint();
    return 0;
}