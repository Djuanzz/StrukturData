#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head;

void insert(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void delete(int pos){
    struct Node* temp1 = head;
    if(pos == 1){
        head = temp1->next;
        free(temp1);
        return;
    }
    for(int i = 0; i < pos-2; i++){
        temp1 = temp1->next;
    }
    struct Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

void mengPrint(){
    struct Node* temp = head;
    printf("Listnya : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    
}
int main(){
    insert(2);
    insert(5);
    insert(9);
    insert(3);
    mengPrint();

    delete(2);
    mengPrint();
    return 0;
}
