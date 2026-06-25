#include<stdio.h> 
int n,item,front=-1,rear=-1,q[20],s[20],top=-1; 
void queue() 
{ 
    printf("enter the elements to be inserted:"); 
    for(int i=1;i<=n;i++)
    { 
    scanf("%d",&item); 
    if(front==-1&&rear==-1) 
    front=0; 
    rear=rear+1; 
    q[rear]=item; 
    } 
    printf("BEFORE REVERSING\n"); 
    for(int i=front;i<=rear;i++) 
    printf("%d\t",q[i]); 
} 
void reverse() 
{ 
    for(int i=front;i<=rear;i++)
    { 
        if(front==rear)
        { 
            top++; 
            s[top]=q[front]; 
            front=-1; 
            break; 
        } 
        top++; 
        s[top]=q[front]; 
        front=front+1; 
    } 
    front=rear=-1; 
    while(top!=-1) 
    { 
        if(front==-1&&rear==-1) 
        front=0; 
        rear=rear+1; 
        q[rear]=s[top]; 
        top=top-1; 
    } 
    printf("\nAFTER REVERSING\n"); 
    for(int i=front;i<=rear;i++) 
    printf("%d\t",q[i]); 
} 
void main() 
{ 
    printf("enter the size of stack:"); 
    scanf("%d",&n); 
    queue(); 
    reverse(); 
}