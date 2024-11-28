#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  
            }
        }
        
        
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6, 5, 7, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: \n");
    display(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted Array: \n");
    display(arr, n);
    
    return 0;
}
