#include<stdio.h>
#include<stdlib.h>
typedef struct doublylinkedlist
{
    int data;
    struct doublylinkedlist *succ,*pred;
}DLL;
DLL*front=NULL;
DLL*rear=NULL;
void ENQUEUE ();
void DEQUEUE ();
void DISP ();
int main ()
{
    int n;
    printf ("PRESS:->\n 1 -> insert:\n 2 -> delete:\n 3 ->  display:\n 0 -> quit:\n");
    while (n)
    {
        scanf ("%d",&n);
        switch (n)
        {
            case 0:printf ("thank u fr pressing 0 button:");
                break;
            case 1:ENQUEUE ();
                break;
            case 2:DEQUEUE ();
                break;
            case 3:DISP ();
                 break;
            default:printf ("wrong choice!!!\n");
                break;
        }
    }
}
void ENQUEUE ()
{
    DLL *temp;
    int val;
    printf ("enter the value for insert:");
    scanf ("%d",&val);
        temp=(DLL*)malloc(sizeof(DLL));
        temp->data=val;
        temp->succ=NULL;
        temp->pred=NULL;
    if (front==NULL)
    {
        front=temp;
        rear=temp;
        return;
    }
    rear->succ=temp;
    temp->pred=rear;
    rear=temp;
    temp->succ=NULL;
}
void DEQUEUE ()
{
    DLL *temp;
    if (front==NULL&&rear==NULL)
    {
        printf ("error!!!");
        return;
    }
    if (front==rear&&front!=NULL)
    {
        printf ("the last value is removed:\n");
        temp=front;
        front=rear=NULL;
    }
    else
    {
        printf ("value is removed:\n");
        front=front->succ;
        front->pred=NULL;
    }
        free(temp);
}
void DISP()
{
    DLL*current=front;
    if(current==NULL)
    {
        printf("LinkedList is empty\n");

    }
    else
    {
        while(current)
        {
            printf("%d\t",current->data);
            current=current->succ;
        }
        printf ("\n");
    }
}
