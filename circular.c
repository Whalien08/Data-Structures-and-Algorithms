#include<stdio.h> 
#include<stdlib.h> 
int item,c,n,q[20],front=-1,rear=-1; 
void enqueue(); 
void dequeue(); 
void display(); 
void main() 
{ 
    printf("enter the size of queue:"); 
    scanf("%d",&n); 
    do 
    { 
        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\nenter the choice:"); 
        scanf("%d",&c); 
        switch(c) 
        { 
            case 1: enqueue(); 
                    break; 
            case 2: dequeue(); 
                    break; 
            case 3: display(); 
                    break; 
            case 4: printf("exit"); 
                    exit(0); 
            default:printf("\nINVALID CHOICE\n"); 
        } 
    }while(c!=4); 
} 
void enqueue() 
{ 
    printf("enter the item to be stored:"); 
    scanf("%d",&item); 
    if(front==-1&&rear==-1) 
    { 
        front=0; 
        rear=(rear+1)%n; 
        q[rear]=item; 
    } 
    else if((rear+1)%n==front) 
        printf("OVERFLOW"); 
    else 
    { 
        rear=(rear+1)%n; 
        q[rear]=item; 
    } 
} 
void display() 
{ 
    int i; 
    if(front==-1&&rear==-1) 
        printf("QUEUE IS EMPTY"); 
    else 
    { 
        for(i=front;i!=rear;i=(i+1)%n) 
            printf("%d\t",q[i]); 
        printf("%d\t",q[i]); 
    } 
} 
void dequeue() 
{ 
if(front==-1&&rear==-1) 
printf("UNDEFLOW"); 
else if(front==rear) 
{ 
item=q[front]; 
printf("deleted item is %d",item); 
front=-1,rear=-1; 
} 
else 
{ 
item=q[front]; 
printf("deleted item is %d",item); 
front=(front+1)%n; 
} 
} 