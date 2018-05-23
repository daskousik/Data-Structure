#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*add;
}LL;
void inst(LL**);
void del(LL**);
void disp(LL*);
int main()
{
    int n;
    LL*head=NULL;
    while(1)
    {
        printf("Enter your chose 1 for insert value\n 2 for deleted\n 3 for display\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:inst(&head);
            break;
            case 2:del(&head);
            break;
            case 3:disp(head);
            break;
            default:printf("wrong chosse!!!");
            break;
        }
    }

}
void inst(LL**head)
{
    int val;
    LL*temp,*current;
    if(*head==NULL)
    {
       printf("insert first value is:");
        temp=(LL*)malloc(sizeof(LL));
        scanf("%d\n",&(temp->data));
        *head=temp;
        temp->add=NULL;
        return;
    }
    printf("Enter the  value:\n");
    scanf("%d",&val);
    current=*head;
    if(current->data==val)
    {
        printf("duplicate value");
        return;
    }
    if(current->data<val)
    {
       // printf("insert the value :\n");
        temp=(LL*)malloc(sizeof(LL));
        temp->data=val;
        temp->add=current;
        *head=temp;
        //printf("%d",&(temp->data));
    }
    else
    {
        while(current->add!=NULL)
        {
            if(current->data==val)
            {
            printf("duplicate value");
            return;
            }
              if(current->data<val)
                break;
             // else
                //current=current->add;
        }
        temp=(LL*)malloc(sizeof(LL));
        temp->data=val;
        current->add=temp;
        temp->add=current->add;

    }
}
void del(LL**head)
{
    int val;
    LL*temp,*current,*prev;
    if(*head==NULL)
    {
        printf("Linklist is empty:");
        return;
    }
    current=*head;
    printf("Enter the the value deleted:");
    scanf("%d",&val);
    while(current!=NULL)
    {
        if(current->data==val)
        {
            printf("Data is found!!:");
            break;
        }
        prev=current;
        current=current->add;
    }
    if(current==NULL)
    {
        printf("Data not found :::");
        return;
    }
    if(current==*head)
    {
        temp=current;
        *head=current->add;
        printf("First value is deleted:");
        free(temp);
    }
    else
    {
        temp=current;
        prev->add=current->add;
        printf("value is deleted::");
        free(temp);
    }
}
void disp(LL*current)
{

    if(current==NULL)
    {
        printf("Linklist is empty");
        return;
    }
        printf("linklist element are ::");
        while(current!=NULL)
        {
            printf("%d\t",current->data);
            current=current->add;
        }
        printf("\n");
}
