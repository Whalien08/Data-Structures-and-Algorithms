#include<stdio.h> 
struct poly 
{ 
    int coeff; 
    int expo; 
}p1[10],p2[10],p3[10]; 
int readPoly(struct poly[]); 
int add(struct poly[],struct poly[],int t1,int t2,struct poly[]); 
void display(struct poly[],int terms); 
void main() 
{ 
    int t1,t2,t3; 
    printf("1st polynomial\n"); 
    t1=readPoly(p1); 
    display(p1,t1); 
    printf("\n2nd polynomial\n"); 
    t2=readPoly(p2); 
    display(p2,t2); 
    t3=add(p1,p2,t1,t2,p3); 
    printf("\nresultant polynomial\n"); 
    display(p3,t3); 
} 
int readPoly(struct poly p[10]) 
{ 
    int i,t; 
    printf("enter the number of elements:"); 
    scanf("%d",&t); 
    for(i=0;i<t;i++) 
    { 
        printf("enter the %d term coeff and expo:",i+1); 
        scanf("%d,%d",&p[i].coeff,&p[i].expo); 
    } 
    return t; 
} 
void display(struct poly p[10],int terms) 
{ 
    int i; 
    for(i=0;i<terms-1;i++) 
        printf("%d^(%d)+",p[i].coeff,p[i].expo); 
    printf("%d^(%d)",p[terms-1].coeff,p[terms-1].expo); 
} 
int add(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10]) 
{ 
    int i=0,j=0,k=0; 
    while(i<t1&&j<t2) 
    { 
        if(p1[i].expo==p2[j].expo) 
        { 
            p3[k].coeff=p1[i].coeff+p2[j].coeff; 
            p3[k].expo=p1[i].expo; 
            i++,j++,k++; 
        } 
        if(p1[i].expo>p2[j].expo) 
        { 
            p3[k].coeff=p1[i].coeff; 
            p3[k].expo=p1[i].expo; 
            i++,k++; 
        } 
        if(p1[i].expo<p2[j].expo) 
        { 
            p3[k].coeff=p2[j].coeff; 
            p3[k].expo=p2[j].expo; 
            j++,k++; 
        } 
    } 
    while(i<t1) 
    { 
        p3[k].coeff=p1[i].coeff; 
        p3[k].expo=p1[i].expo; 
        i++,k++; 
    } 
    while(j<t2) 
    { 
        p3[k].coeff=p2[j].coeff; 
        p3[k].expo=p2[j].expo; 
        j++,k++;    
    } 
    return k; 
}