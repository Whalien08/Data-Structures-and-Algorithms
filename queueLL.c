#include <stdio.h>  
#include <stdlib.h>  
struct Queue  
{  
int data;  
struct Queue *Rlink;  
struct Queue *Llink;  
} * head, *front, *rear, *temp;  
void enqueue(int n);  
void dequeue();  
void display();  
void main()  
{  
int opt, inp;  
head = (struct Queue *)malloc(sizeof(struct Queue));  
head->Rlink = NULL;  
head->Llink = NULL;  
while (1) 
{  
printf("\n\nChoose your option\n");  
printf("\n1.Enqueue an element\n2.Dequeue an element\n3.Exit");  
printf("\nEnter your choice: ");  
scanf("%d", &opt);  
switch (opt)  
{  
case 1:  
printf("Enter the element to be pushed: ");  
scanf("%d", &inp);  
enqueue(inp);  
display();  
break;  
case 2:  
dequeue();  
display();  
break;  
default:  
return;  
}  
}  
}  
void enqueue(int n)  
{  
temp = head;  
while (temp->Rlink != NULL)  
temp = temp->Rlink;  
rear = (struct Queue *)malloc(sizeof(struct Queue));  
rear->data = n;  
rear->Rlink = NULL;  
rear->Llink = temp;  
temp->Rlink = rear;  
if (front == NULL)  
front = head->Rlink;  
}  
void dequeue()  
{  
if (head->Rlink != NULL)  
{  
front = front->Rlink;  
if (front != NULL)  
front->Llink = head;  
head->Rlink = front;  
}  
}  
void display()  
{  
if (head->Rlink == NULL)  
printf("\nQueue Empty!!!\b");  
else  
{  
printf("\nElements of the queue are: ");  
temp = head->Rlink;  
while (temp != NULL)  
{  
printf("%d", temp->data);  
temp = temp->Rlink;  
}  
}  
} 