#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10
void push(int*,int*,int);
int pop(int*,int*);
int main()
{
    int stack[size],top=-1,num;
    int val1,val2,val;
    char exp[size];
    char *e;
    printf("Enter the postfix expression");
    scanf("%s",exp);
    e=exp;
    while((*e=getchar())!='\n')
    {
        if(isdigit(*e))
        {

            num=*e-48;
        push(stack,&top,num);
        }
        else
        {
            val1=pop(stack,&top);
            val2=pop(stack,&top);
            switch(*e)
            {
                case '+':val=val1+val2;
                break;
                case '-':val=val2-val1;
                break;
                case '*':val=val2*val1;
                break;
                case '/':val=val2/val1;
                break;
            }
            push(stack,&top,val);
        }
        e++;

    }
    val=pop(stack,&top);
    printf("value of expression %d\n",val);
    return 0;
}
void push(int*s,int*t,int x)
{
    //if((*t)==size-1)
      //  printf("stack is empty");
    //else
    //{
        (*t)++;
        s[*t]=x;
    //00}
}
int pop(int*s,int*t)
{
    int val;
    //if((*t)==-1)
      //  printf("stack is empty");
    //else
    //{
        val=s[*t];
        (*t)--;
    //}
    return(val);
}
