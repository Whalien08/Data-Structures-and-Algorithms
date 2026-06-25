#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
struct Node 
{ 
    char data; 
    struct Node *l; 
    struct Node *r; 
}*h = NULL; 
void create(); 
void display(); 
int isPalindrome(); 
void create()  
{ 
    struct Node *t; 
    char str[100]; 
    printf("Enter a string: "); 
    scanf("%s", str); 
    struct Node *new = (struct Node *)malloc(sizeof(struct Node)); 
    new->data = str[0]; 
    new->l = NULL; 
    new->r = NULL; 
    h = new; 
    t = new; 
    for (int i = 1; str[i] != '\0'; i++)  
    { 
        struct Node *new = (struct Node *)malloc(sizeof(struct Node)); 
        new->data = str[i]; 
        new->l = t; 
        new->r = NULL; 
        t->r = new; 
        t = new; 
    } 
} 
void display()  
{ 
    struct Node *temp = h; 
    printf("List: "); 
    while (temp != NULL)    
    { 
        printf("%c ", temp->data); 
        temp = temp->r; 
    } 
    printf("\n"); 
} 
int isPalindrome()  
{ 
    if (h == NULL)  
    return 1; 
    struct Node *left = h; 
    struct Node *right = h; 
    while (right->r != NULL)  
    right = right->r; 
    while (left != right && left->l != right)  
    { 
        if (left->data != right->data)  
        { 
            return 0; 
        } 
            left = left->r; 
            right = right->l; 
        } 
    return 1;  
} 
int main()  
{ 
    create(); 
    display(); 
    if (isPalindrome())
        printf("The string is a palindrome.\n"); 
    else 
        printf("The string is not a palindrome.\n"); 
    return 0; 
} 