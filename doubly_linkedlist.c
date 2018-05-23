#include<stdio.h>
#include<stdlib.h>
typedef struct doublylinkedlist
{
    int data;
    struct doublylinkedlist *succ;
    struct doublylinkedlist *pred;
}DLL;
void CRET (DLL**);
void INST_AFTR (DLL**);
void INST_BEFR (DLL**);
void DEL (DLL**);
void DISP(DLL*);
int main()
{
    int n;
    DLL*head=NULL;
    printf ("PRESS \n 0 for exit\n 1 for create the linked list:\n 2 for insert after node:\n 3 for insert before node:\n 4 for delete:\n 5 for display LinkedList:\n");
    while (n!=0)
    {
        scanf ("%d",&n);
        switch (n)
        {
            case 0:printf ("EXIT\n");
                break;
            case 1:CRET (&head);
                break;
            case 2:INST_AFTR (&head);
                break;
            case 3:INST_BEFR (&head);
                break;
            case 4:DEL (&head);
                break;
            case 5:DISP(head);
                break;
            default: printf ("enter wrong choice:\n");
                break;
        }
    }
    return 0;
}
void CRET (DLL**header)
{
    DLL*current,*temp;
    int val;
    printf ("enter the number to insert:");
    scanf ("%d",&val);
    if (*header==NULL)
    {
        temp=(DLL*)malloc(sizeof(DLL));
        temp->data=val;
        temp->succ=NULL;
        temp->pred=NULL;
        *header=temp;
    }
    else
    {
        current=*header;
        while (current->succ!=NULL)
        {
            current=current->succ;
        }
        temp=(DLL*)malloc(sizeof(DLL));
        temp->data=val;
        temp->succ=NULL;
        temp->pred=current;
        current->succ=temp;
    }
}
void INST_AFTR(DLL**header)
{
    DLL*current,*temp;
    int val,target;
    printf ("enter the target value:");
    scanf ("%d",&target);
    current=*header;
    while (current!=NULL)
    {
        if (current->data==target)
        {
             printf ("number found\n");
             break;
        }
            current=current->succ;
    }
    if (current==NULL)
    {
        printf ("target not found:\n");
        return;
    }
    temp=(DLL*)malloc(sizeof(DLL));
    printf ("enter the value to insert:");
    scanf ("%d",&val);
    temp->data=val;
    temp->pred=current;
    temp->succ=current->succ;
    current->succ=temp;
    current->succ->pred=temp;
}
void INST_BEFR (DLL**header)
{
    int val,target;
    DLL*temp,*current;
    printf ("enter the target:");
    scanf ("%d",&target);
    current=*header;
    while(current!=NULL)
    {
        if(current->data==target)
        {
            printf("Target found\n");
            break;
        }
        else
            current=current->succ;
    }
    if(current==NULL)
    {
        printf("Target not found:\n");
        return ;
    }
    if (current==*header)
    {
        temp=(DLL*)malloc(sizeof(DLL));
        printf("Enter number at 1st pos:");
        scanf("%d",&(temp->data));
        temp->succ=current;
        temp->pred=NULL;
        current->pred=temp;
        *header=temp;
        return;
    }
    else
    {
        printf("Enter a value to insert");
        scanf("%d",&val);
        temp=(DLL*)malloc(sizeof(DLL));
        temp->data=val;
        temp->pred=current->pred;
        temp->succ=current;
        current->pred->succ=temp;
        current->pred=temp;
    }
}
void DEL (DLL**header)
{
    int target;
    DLL*current,*temp;
    if (*header==NULL)
    {
        printf ("doublyLinkedList is empty\n");
        return;
    }
    printf ("enter the number to delete:");
    scanf ("%d",&target);
    current=*header;
    while (current!=NULL)
    {
        if (current->data==target)
        {
            printf ("Match found\n");
            break;
        }
        else
            current=current->succ;
    }
    if (current==NULL)
    {
        printf ("target did not found\n");
        return;
    }
    if (current==*header)
    {
        temp=current;
        *header=current->succ;
        current->succ->pred=NULL;
        free(temp);
    }
    else if (current->succ==NULL)
    {
        temp=current;
        current->pred->succ=NULL;
        free(temp);
    }
    else
    {
        temp=current;
        current->pred->succ=current->succ;
        current->succ->pred=current->pred;
            free(temp);
    }
}
void DISP(DLL*current)
{
    if(current==NULL)
        printf("DoublyLinkedList is empty\n");
    else
    {
        printf("Element of DoublyLinkedList are :\n");
        while(current!=NULL)
        {
            printf("%d\t",(current->data));
            current=current->succ;
        }
        printf ("\n");
    }
}
