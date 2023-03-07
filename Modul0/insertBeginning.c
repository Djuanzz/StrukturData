#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void insert(int x){
    // membuat node baru dulu
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    // data dari node baru di ini dengan nilai x
    temp->data = x;
    // sekarang address nya pake punya e head (?) 
    temp->next = head;
    // baru ntar head nya jadi punya e temp (mksdnya nyisipin di awal) (?)
    head = temp;
}

void mengPrint(){
    // membuat temporary biar ga merubah alamat awal dari Head nya
    struct Node* temp1 = head;
    printf("listnya :");
    // ketika blom sampe ujung (NULL) dia bakal pindah2 trus sampe ujung
    while (temp1 != NULL)
    {
        printf(" %d", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}

int main(){
    // make a empty list (?)
    head = NULL;
    int angka;
    int p;
    printf("----- Insert Node in Beginning -----\n\n");
    printf("mau insert brapa angka : ");
    scanf("%d", &angka);
    for(int i = 0; i < angka; i++){
        printf("masukkan angka : ");
        scanf("%d", &p);
        insert(p);
        mengPrint();
    }
    return 0;
}