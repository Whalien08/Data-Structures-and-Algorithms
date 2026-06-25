#include <stdio.h> 
void swap(int* a, int* b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
void heapify(int arr[], int n, int i) 
{ 
    int largest =i; 
    int le=2*i+1; 
    int right=2*i+2; 
    if (le<n && arr[le]>arr[largest]) 
    { 
        largest=le; 
    } 
    if (right<n && arr[right]>arr[largest]) 
    { 
        largest=right; 
    } 
    if (largest!=i) 
    { 
        swap(&arr[i], &arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
void heapSort(int arr[], int n) 
{ 
    for (int i=n/2-1;i>=0;i--) 
    { 
        heapify(arr,n,i); 
    } 
    for (int i=n-1;i>=0;i--) 
    { 
        swap(&arr[0],&arr[i]); 
        heapify(arr,i,0); 
    } 
} 
void printArray(int arr[], int n) 
{ 
    for (int i=0;i<n;i++) 
    { 
        printf("%d ",arr[i]); 
    } 
    printf("\n"); 
} 
int main() 
{ 
    int arr[100]; 
    int n,i; 
    printf("Enter no of elements "); 
    scanf("%d",&n); 
    printf("Enter the elements "); 
    for(i=0;i<n;i++) 
    { 
        scanf("%d",&arr[i]); 
    } 
    heapSort(arr, n); 
    printf("Sorted array: "); 
    printArray(arr, n); 
    return 0; 
}