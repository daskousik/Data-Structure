#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
void push(int*,int*);
void pop(int*,int*);
void display(int*,int*);
int main()
{
    int stack[SIZE];
    int top=-1,n;
    printf("Enter your choose 1 for push\n 2 for pop\n 3 for element in stack\n");
    while(1)
    {
        scanf("%d",&n);
        switch(n)
        {
            case 1:push(stack,&top);
            break;
            case 2:pop(stack,&top);
            break;
            case 3:display(stack,&top);
            break;
            default:printf("Invalid Choice\n");
        }
    }
}
void push(int*s,int*t)
{
    int val;
    if((*t)==SIZE-1)
    {
        printf("stack is full\n");
    }
    else
    {
    printf("insert the number\n");
    scanf("%d",&val);
    (*t)++;
    s[*t]=val;
    }
}
void pop(int*s,int*t)
{
    int val;
    if((*t)==-1)
    {
        printf("stack is empty\n");
    }
    else
    {
        val=s[*t];
        printf("delect the number %d\n",val);
        (*t)--;
}
    }

void display(int*s,int*t)
{
    int i;
    if(*t==-1)
        printf("stack is empty");
    else
    {
        printf("stack element\n");
        for(i=*t;i>=0;i--)

     printf("%d\n",s[i]);
    }
}
