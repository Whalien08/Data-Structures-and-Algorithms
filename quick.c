#include <stdio.h>  
void swap(int *a, int *b) {  
    int temp = *a;    
    *a = *b;  
    *b = temp;  
}  
int partion(int arr[], int low, int high) {  
    int i = low;  
    int j = high;  
    int pivot = arr[low];    
 while (i < j) {  
        while (arr[i] <= pivot && i < high) {  
            i++;  
        }  
        while (arr[j] > pivot && j > low) {  
            j--;  
        }  
        if (i < j) {  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[low], &arr[j]);  
return j;   
}  
void quickSort(int arr[], int low, int high) {  
    if (low < high) {  
        int mid = partion(arr, low, high);  
        quickSort(arr, low, mid - 1);  
        quickSort(arr, mid + 1, high);  
    }  
}  
void printArray(int arr[], int size) {  
    for (int i = 0; i < size; i++) {  
        printf("%d ", arr[i]);  
    }  
    printf("\n");  
}  
int main() {  
    int n;  
    printf("Enter the number of elements: ");  
    scanf("%d", &n);  
    int arr[n];  
    printf("Enter the elements:\n");  
    for (int i = 0; i < n; i++) {  
        scanf("%d", &arr[i]);  
    }  
    quickSort(arr, 0, n - 1);  
    printf("Sorted array: ");  
    printArray(arr, n);  
    return 0;  
} 