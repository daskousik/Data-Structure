#include<stdio.h>
#include<stdlib.h>
typedef struct circularlinkedlist
{
	int data;
	struct circularlinkedlist *add;
}CLL;
void CRET (CLL**,int*);
void DEL (CLL**,int*);
void DISP (CLL**);
int main (void )
{
	int n,count=0;
	CLL*head=NULL;
	printf ("CHOICE::\n 1 for create linkedlist\n 2 for delete\n 3 for display\n 4 for count node number\n");
	while (n)
	{
		scanf ("%d",&n);
		switch (n)
		{
			case 0:printf ("EXIT\n");
				break;
			case 1:CRET (&head,&count);
				break;
			case 2:DEL (&head,&count);
				break;
			case 3:DISP (&head);
				break;
			case 4:printf ("total number of node is:%d\n",count);
				break;
			default:printf ("wrong choice entered!!!\n");
				break;
		}
	}
return 0;
}
void CRET (CLL**header,int*c)
{
	CLL *current,*temp;
	int val;
	printf ("enter the value:");
	scanf ("%d",&val);
	if (*header==NULL)
	{
		temp=(CLL*)malloc(sizeof(CLL));
		temp->data=val;
		temp->add=temp;
		*header=temp;
		(*c)++;
		return;
	}
	current=*header;
	while (current->add!=*header)
	{
		current=current->add;
	}
	temp=(CLL*)malloc(sizeof(CLL));
	temp->data=val;
	current->add=temp;
	temp->add=*header;
	(*c)++;
}
void DISP (CLL**header)
{
	CLL*current;
	if (*header==NULL)
	{
		printf ("LinkedList is empty\n");
		return;
	}
	current=*header;
	printf ("Elements in Linkedlist are:\n");
	do 
	{
		printf ("%d\t",(current->data));
		current=current->add;
	}while (current!=*header);
	printf ("\n");
}
void DEL (CLL**header,int*c)
{
	CLL *temp,*current;
	int target;
	if ((*c)==0)
		printf ("LinkedList is empty!!\n");
	printf ("enter the target:");
	scanf ("%d",&target);
	current=*header;
	do
	{
		if (current->add->data==target)
		{
			printf ("Number found\n");
			printf ("Value is deleted\n");
			break;
		}
		else
			current=current->add;
	}while (current!=*header);
	if (current->add->data!=target)
	{
		printf ("Number you entered not found!!\n");
		return;
	}
	if (current->add==*header)
	{
		temp=current->add;
		*header=current->add->add;
		current->add=*header;
	}
	else
	{
		temp=current->add;
		current->add=current->add->add;
	}
	free (temp);
	(*c)--;
}
