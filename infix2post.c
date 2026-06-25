#include<stdio.h> 
#include<ctype.h> 
#include<math.h> 
#include<string.h> 
char A[10],p[10],s[10]; 
int s1[10],top=-1,top1=-1; 
void infix_to_postfix(); 
int precedence(char c) 
{ 
    switch(c) 
    { 
        case '+': 
        case '-':   return 1; 
        case '*': 
        case '/':   return 2; 
        case '^':   return 3; 
    } 
} 
void infix_to_postfix() 
{ 
    char x,y; 
    int i=0,j=0; 
    while(A[i]!='\0') 
    { 
        if(isdigit(A[i])) 
            p[j++]=A[i]; 
        else if(A[i]=='(') 
            s[++top]=A[i]; 
        else if(A[i]==')') 
        { 
            while(s[top]!='(') 
                p[j++]=s[top--]; 
            top--; 
        } 
        else 
        { 
            x=A[i]; 
            y=s[top]; 
            if(top==-1 || y=='(' || precedence(x)>precedence(y)) 
                s[++top]=x; 
            else 
            { 
                while(top!=-1 && y!='(' && precedence(x)<precedence(y)) 
                { 
                    p[j++]=s[top--]; 
                    y=s[top]; 
                } 
                s[++top]=x; 
            } 
        } 
        i++; 
    } 
    while(top!=-1) 
        p[j++]=s[top--]; 
    p[j]='\0'; 
    printf("postfix exp is: %s",p); 
}
void eval() 
{ 
    char str[10]; 
    int i,op1,op2,result; 
    for(i=0;i<strlen(p);i++) 
    { 
        if(isdigit(p[i])) 
        { 
            str[0]=p[i]; 
            str[1]='\0'; 
            top1++; 
            s1[top1]=atof(str); 
        } 
        else 
        { 
            op1=s1[top1]; 
            top1--; 
            op2=s1[top1]; 
            top1--; 
            switch(p[i]) 
            { 
                case '+':   result=op1+op2; 
                            break; 
                case '-':   result=op2-op1; 
                            break; 
                case '*':   result=op1*op2; 
                            break; 
                case '/':   result=op2/op1; 
                            break; 
                case '^':   result=pow(op2,op1); 
                            break;    
            } 
            top1++; 
            s1[top1]=result; 
        } 
    } 
    printf("\nResult: %d",result); 
} 
 
void main() 
{ 
    printf("enter the infix exp: "); 
    scanf("%s",A); 
    infix_to_postfix(); 
    eval(); 
} 