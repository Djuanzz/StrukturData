#include <stdio.h>


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int query[5];
    int top = -1;
    int total = 0;
    for(int i = 0; i < 3; i++){
        scanf("%d", &query[i]);
    }
    int num[query[0]];

    for(int i = 0; i < query[0]; i++){
        top++;
        scanf("%d", &num[i]);
    }

    quickSort(num, 0, query[0]-1);

    for(int i = 0; i < query[1]; i++){
        num[top] = query[2];
        top--;
    }

    for (int i = 0; i < query[0]; i++) {
        total += num[i];
    }

    printf("%d", total);
    return 0;
}