#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    
    for (i = 1; i < n; i++) {
        key = arr[i]; 
        j = i - 1;
        
                while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
               arr[j + 1] = key;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {15, 11, 30, 60, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: \n");
    display(arr, n);
    
    insertionSort(arr, n);
    
    printf("Sorted Array: \n");
    display(arr, n);
    
    return 0;
}
