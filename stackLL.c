#include<stdio.h> 
#include<stdlib.h> 
int n,c,count=0,item; 
void push(); 
void display(); 
void pop(); 
struct node 
{ 
    int data; 
    struct node*link; 
}*head=NULL,top; 
void main() 
{ 
    printf("enter the size of stack:"); 
    scanf("%d",&n); 
    do 
    { 
        printf("1.push\n2.pop\n3.exit\nENTER THE CHOICE:"); 
        scanf("%d",&c); 
        switch(c) 
        { 
            case 1: push(); 
                    break; 
            case 2: pop(); 
                    break; 
            case 3: exit(0); 
                    break; 
            default:    printf("INVALID ENTERY\n"); 
        } 
    } 
    while(c!=3); 
} 
void push() 
{ 
    if(count==n) 
        printf("OVERFLOW\n"); 
    else 
    { 
            printf("enter the data to be stored:"); 
            scanf("%d",&item); 
            struct node*top; 
            top=(struct node*)malloc(sizeof(struct node)); 
            top->data=item; 
            top->link=head; 
            head=top; 
            count++; 
            display(); 
    } 
} 
void display() 
{ 
    struct node*ptr; 
    ptr=head; 
    if(head==NULL) 
       printf("THE NODE IS EMPTY\n"); 
    while(ptr->link!=NULL) 
    { 
printf("%d\t",ptr->data); 
ptr=ptr->link; 
} 
printf("%d\n",ptr->data); 
} 
void pop() 
{ 
if(head==NULL) 
printf("UNDERFLOW\n"); 
else 
{ 
    printf("deleted item is %d\n",head->data); 
    head=head->link; 
    display(); 
} 
} 