#include<stdio.h>
#include<stdlib.h>
#define size 3
void push(int*,int*,int*);
int pop(int*,int*,int*);
int main()
{
    int queue[size],n;
    int rear=-1,front=-1;
    while(1)
    {
        printf("Enter your choose 1 for insertaion\t 2 for deletion\n ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:push(queue,&rear,&front);
            break;
            case 2:pop(queue,&front,&rear);
            break;
        }
    }
}
void push(int*q,int*r,int*f)
{
    int val;
    if(*f==(*r+1)%size)
        printf("Queue is full");
    else
    {
         if (*f == - 1)
        /*If queue is initially empty */
        *f = 0;


        printf("Insert the element in queue\n");
        scanf("%d",&val);
        *r=((*r+1)%size);
        q[*r]=val;


    }
}
int pop(int*q,int*f,int*r)
{
    int val;
    if(*f==-1)
        printf("Queue is empty");
    else
    {
          val=q[*f];

         if(*f == *r)
        {
            *f=-1;
            *r=-1;
        }
        else
        *f=((*f+1)%size);

        printf("Deleted element in queue is %d\n",val);
    }
}
