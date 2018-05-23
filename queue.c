#include<stdio.h>
#include<stdlib.h>
#define size 4
void push(int*,int*,int*);
int pop(int*,int*,int*);
int main()
{
    int queue[size],n;
    int rear=-1,front=-1;
    while(1)
    {
         printf("Enter your choose 1 for insert\n 2 for deletion\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:push(queue,&front,&rear);
            break;
            case 2:pop(queue,&rear,&front);
            break;
        }
    }

}
void push(int*q,int*f,int*r)
{
    int val,i;
    if((*f)==0 && (*r)==size-1)
        printf("Queue if full");
    else
    {
        if((*r)==size-1)
        {
            for(i=0;i=(*r-*f);i++)
        {
            q[i]=q[(*f)+1];
        }
        (*r)=*r-*f;
        *f=0;
        }
        if((*f)==-1)

            (*f)=0;
        printf("Enter elemet in queue\n");
        scanf("%d",&val);
        (*r)++;
        q[*r]=val;
    }
}
int pop(int*q,int*r,int*f)
{
    int val;
    if(*f==-1)
        printf("Queue is empty");
    else
    {
        val=q[*f];
        *f++;
        if(*f > *r)
        {
            (*f)=-1;
            (*r)=-1;
        }
        printf("deletion element is%d\n",val);
    }

}
