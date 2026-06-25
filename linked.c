#include<stdio.h>
#include<stdlib.h>
int c,item,key;
void display();
void insertAtB();
void inserAtE();
void inserAtS();
void deleteFromF();
void deleteFromL();
void deleteFromS();
struct node
{
   int data;
   struct node*link;
}*head=NULL;
void main()
{
   do
   {
       printf("1.display\n2.insert node at the begining\n3.insert node at the end\n4.insert at specific position\n5.delete from 1st node\n6.delete from last node\n7.delete node from specific position\n8.EXIT\n");
       printf("enter the choice:");
       scanf("%d",&c);
       switch(c)
       {
           case 1: display();
                   break;
           case 2: insertAtB();
                   break;
           case 3: inserAtE();
                   break;
           case 4: inserAtS();
                   break;
           case 5: deleteFromF();
                   break;
           case 6: deleteFromL();
                   break;
           case 7: deleteFromS();
                   break;
           case 8: exit(0);
           default: printf("INVALID CHOICE\n");
                   break;
       }
   }
   while(c!=8);
}
void display()
{
   if(head==NULL)
   {
       printf("NODE IS EMPTY");
   }
   else
   {
       struct node*ptr;
       ptr=head;
       while(ptr->link!=NULL)
       {
           printf("%d\t",ptr->data);
           ptr=ptr->link;
       }
       printf("%d\n",ptr->data);
    }
}
void insertAtB()
{
   printf("enter the data to be stored in node:");
   scanf("%d",&item);
   struct node*new;
   new=(struct node*)malloc(sizeof(struct node));
   new->data=item;
   new->link=head;
   head=new;
}
void inserAtE()
{
   printf("enter the data to be stored in node:");
   scanf("%d",&item);
   struct node*ptr;
   ptr=head;
   while(ptr->link!=NULL)
   {
       ptr=ptr->link;
   }
   if(ptr->link==NULL)
   {
       struct node*new;
       new=(struct node*)malloc(sizeof(struct node));
       ptr->link=new;
       new->data=item;
       new->link=NULL;
   }
}
void inserAtS()
{
   if(head==NULL)
       printf("THE NODE IS EMPTY\n");
   else
   {
       printf("enter the search key:");
       scanf("%d",&key);
       printf("enter the data to be stored in node: ");
       scanf("%d",&item);
       struct node*new;
       new=(struct node*)malloc(sizeof(struct node));
       new->data=item;
       struct node*ptr;
       ptr=head;
       while(ptr->data!=key&&ptr->link!=NULL)
           ptr=ptr->link;
       if(ptr->link==NULL)
           printf("\nthe search key is not found in the node\n");
       else
       {
           new->link=ptr->link;
           ptr->link=new;
       }
   }
}
void deleteFromF()
{
   if(head==NULL)
       printf("LIST IS EMPTY\n");
   else
   {
       struct node*ptr;
       ptr=head;
       head=ptr->link;
       printf("the data of deleted node is:");
       printf("%d\n",ptr->data);
   }
}
void deleteFromL()
{
   if(head==NULL)
       printf("LIST IS EMPTY\n");
   else
   {
       struct node*prev;
       struct node*cur;
       prev=head;
       cur=head;
       while(cur->link!=NULL)
       {
           prev=cur;
           cur=cur->link;
       }
       prev->link=NULL;
       printf("the data of deleted node is:");
       printf("%d\n",cur->data);
   }
}
void deleteFromS()
{
   if(head==NULL)
       printf("THE NODE IS EMPTY\n");
   else
   {
       printf("enter the search key:");
       scanf("%d",&key);
       struct node*prev;
       struct node*cur;
       prev=head;
       cur=head;
       while(cur->data!=key&&cur->link!=NULL)
       {
           prev=cur;
           cur=cur->link;
       }
       if(cur->link==NULL)
           printf("the node is empty\n");
       else
       {
        prev->link=cur->link;
        printf("the data of deleted node is:");
        printf("%d\n",cur->data);
       }
    }
}