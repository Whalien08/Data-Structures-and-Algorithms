#include<stdio.h> 
#include<stdlib.h> 
int n,c,count=0,item; 
struct node* polyread(); 
struct node* addpoly(); 
void displaypoly(); 
struct node 
{ 
int coeff,expo; 
struct node*link; 
}*phead,*qhead,*rhead; 
void main() 
{ 
printf("enter the details of 1st polynomial\n"); 
phead=polyread(); 
printf("enter the details of 2nd polynomial\n"); 
qhead=polyread(); 
printf("first polynomial:\n"); 
displaypoly(phead); 
printf("second polynomial:\n"); 
displaypoly(qhead); 
rhead=addpoly(); 
printf("resultant polynomial:\n"); 
displaypoly(rhead); 
} 
struct node*polyread() 
{ 
struct node *ptr,*new,*head=NULL; 
int n,i; 
printf("enter the number of terms in the poynomial:"); 
scanf("%d",&n); 
for(i=1;i<=n;i++) 
{ 
printf("enter the coeff%d and expo%d of polynomial:",i,i); 
new=(struct node*)malloc(sizeof(struct node)); 
scanf("%d",&new->coeff); 
scanf("%d",&new->expo); 
new->link=NULL; 
if(head==NULL) 
{ 
head=new; 
ptr=head; 
} 
else 
{ 
ptr->link=new; 
ptr=new; 
} 
} 
return (head); 
} 
void displaypoly(struct node*head) 
{ 
struct node *ptr; 
if(head==NULL) 
printf("polynomial is empty\n");
else 
{ 
    ptr=head; 
    while(ptr->link!=NULL) 
    { 
        printf("%d^%d + ",ptr->coeff,ptr->expo); 
        ptr=ptr->link; 
    } 
    printf("%d^%d\n",ptr->coeff,ptr->expo); 
} 
} 
struct node*addpoly() 
{ 
struct node *new,*p,*q,*r,*head=NULL; 
p=phead; 
q=qhead; 
while(p!=NULL&&q!=NULL) 
{ 
    if(p->expo==q->expo) 
    { 
        new=(struct node*)malloc(sizeof(struct node)); 
        new->coeff=p->coeff+q->coeff; 
        new->expo=p->expo; 
        new->link=NULL; 
        p=p->link; 
        q=q->link; 
    } 
    else if(p->expo>q->expo) 
    { 
        new=(struct node*)malloc(sizeof(struct node)); 
        new->coeff=p->coeff; 
        new->expo=p->expo; 
        new->link=NULL; 
        p=p->link; 
    } 
    else if(p->expo<q->expo) 
    { 
        new=(struct node*)malloc(sizeof(struct node)); 
        new->coeff=q->coeff; 
        new->expo=q->expo; 
        new->link=NULL; 
        q=q->link; 
    } 
    if(head==NULL) 
    { 
        head=new; 
        r=head; 
    } 
    else 
    { 
        r->link=new; 
        r=new; 
    } 
} 
while(p!=NULL) 
{ 
    new=(struct node*)malloc(sizeof(struct node)); 
    new->coeff=p->coeff;
    new->expo=p->expo; 
    new->link=NULL; 
    if(head==NULL) 
    { 
        head=new; 
        r=head; 
    } 
    else 
    { 
        r->link=new; 
        r=new;
    }  
        p=p->link; 
} 
while(q!=NULL) 
{
    new=(struct node*)malloc(sizeof(struct node)); 
    new->coeff=q->coeff; 
    new->expo=q->expo; 
    new->link=NULL; 
    if(head==NULL) 
    { 
    head=new; 
    r=head; 
    } 
    else 
    { 
    r->link=new; 
    r=new; 
    } 
    q=q->link; 
} 
return (head); 
} 