#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
void makeLink(struct Node** pointerHead, int green){
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = green;
    temp1->next = NULL;

    struct Node* temp2 = *pointerHead;
    if(*pointerHead == NULL){
        *pointerHead = temp1;
    } else {
        while(temp2->next != NULL){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }
}

void mengPrint(struct Node* mengHead){
    struct Node* temp = mengHead;
    printf("Listnya = ");
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteFront(struct Node** gray){
    struct Node* temp = *gray;
    *gray = temp->next;
    free(temp);
}

void sum(struct Node** cyan, struct Node** magenta, struct Node** yellow){
    int temp1 = 0;
    if((*cyan) != NULL || (*magenta) != NULL){
        temp1 += (*cyan)->data;
        temp1 += (*magenta)->data;
    }

    // printf("%d", temp1);
    deleteFront(&*cyan);
    deleteFront(&*magenta);
    makeLink(&*yellow, temp1);
}


int main(){
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;
    struct Node* total = NULL;

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    while(n1 > 0){
        int mod = n1 % 10;
        makeLink(&num1, mod);    
        n1 = n1 / 10; 
    }

    while(n2 > 0){
        int mod = n2 % 10;
        makeLink(&num2, mod);    
        n2 = n2 / 10; 
    }

    while (num1 != NULL || num2 != NULL){
        sum(&num1, &num2, &total);

    }
        
    mengPrint(num1);
    mengPrint(num2);
    mengPrint(total);

    return 0;
}