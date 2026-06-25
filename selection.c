#include<stdio.h> 
void main() 
{ 
int a[10],i,n,min; 
printf("ENTER THE NUMBER OF ELEMENTS:"); 
scanf("%d",&n); 
for(i=0;i<n;i++) 
{ 
printf("enter the %d element:",i); 
scanf("%d",&a[i]); 
}  
printf("BEFORE SORTING\n"); 
for(i=0;i<n;i++) 
printf("%d\t",a[i]); 
for(i=0;i<n-1;i++) 
{ 
min=i; 
for(int j=i+1;j<n;j++) 
{ 
if(a[j]<a[min]) 
min=j; 
} 
int t=a[i]; 
a[i]=a[min]; 
a[min]=t; 
} 
printf("\nAFTER SORTING\n"); 
for(i=0;i<n;i++) 
printf("%d\t",a[i]); 
} 