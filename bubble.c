#include<stdio.h> 
void main() 
{ 
    int n,a[50],temp; 
    printf("enter the number of elements:"); 
    scanf("%d",&n); 
    printf("enter the elements:"); 
    for(int i=0;i<n;i++) 
        scanf("%d",&a[i]); 
    printf("before sorting\n"); 
    for(int i=0;i<n;i++) 
        printf("%d\t",a[i]); 
    for(int i=0;i<n-1;i++) 
    { 
        for(int j=0;j<n-i-1;j++) 
        { 
            if(a[j]>a[j+1]) 
            { 
                temp=a[j]; 
                a[j]=a[j+1]; 
                a[j+1]=temp; 
            } 
        } 
    } 
    printf("\nafter sorting\n"); 
    for(int i=0;i<n;i++) 
        printf("%d\t",a[i]); 
} 