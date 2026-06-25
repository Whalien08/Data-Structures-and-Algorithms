#include<stdio.h>
void main()
{
    int n,a[10],key,i,j;
    printf("enter the number of elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the %dth term ",i);
        scanf("%d",&a[i]);
    }
    printf("before sorting\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    printf("\nafter sorting\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}