#include<stdio.h> 
void merge(int a[],int low, int mid, int high) 
{ 
    int i=low,j=mid+1,k=0;  
    int temp[high-low+1];  
    while( i<=mid&&j<=high) 
    { 
        if(a[i]<=a[j]) 
        { 
            temp[k++]=a[i++]; 
        } 
        else 
        { 
            temp[k++]=a[j++]; 
        } 
    } 
    while(i<=mid) 
        temp[k++]=a[i++]; 
    while(j<=high) 
        temp[k++]=a[j++];  
    for(i=low,k=0;i<=high;i++,k++) 
        a[i]=temp[k]; 
} 
void mergesort(int a[],int low, int high) 
{ 
if(low<high) 
    { 
        int mid=(low+high)/2; 
        mergesort(a,low,mid); 
        mergesort(a,mid+1,high); 
        merge(a,low,mid,high); 
    } 
} 
int main() 
{ 
    int i,n,a[100]; 
    printf("\nEnter the no:of terms:\t"); 
    scanf("%d",&n); 
    printf("\nEnter the Elements:\t"); 
    for(i=0;i<n;i++) 
    { 
        scanf("%d",&a[i]); 
    } 
    mergesort(a,0,n-1);
    printf("\n The sorted array is\n"); 
    for (i=0;i<n;i++) 
    { 
        printf("%d\t",a[i]); 
    } 
    return 0; 
} 