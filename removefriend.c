#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node*next;
	struct node* prev;
	int data;
}node;

node* create(node*head,int num)
{
	node* nn=(node*)malloc(sizeof(node));
	nn->data=num;
	nn->prev=NULL;
	nn->next=NULL;	
	//insert at the beginning
	if(head==NULL)
	{
		
		head=nn;
	}
	//insert at the end
	else
	{
		node*tp=head;
		while(tp->next!=NULL)
		{
			tp=tp->next;
		}
		tp->next=nn;
		nn->prev=tp;
		nn->next=NULL;
	}return head;
}
//function to delete friends
node* delete(node*head,int k)
{
	node*fp=head;node*tp=head;
	for(int i=0;i<=k-1;i++)
	{
		int flag=0;
		while(tp->next!=NULL)
		{
			//to delete the ith element
			if(tp->data<tp->next->data)
			{
 
				node*temp=tp;
				if(temp!=head)
				{
					tp=tp->prev;
				temp->next->prev=temp->prev;
				temp->prev->next=temp->next;
				free(temp);
				}
				else
				{
				    head=temp->next;
				    head->prev=NULL;
					tp=head;
				    free(temp);
				}
				flag=1;
				
				break;
			}
			else
			 tp=tp->next;
		}
		//to delete the last element if list is in descending order
		if(flag==0)
		{
			node*temp=tp;
			//temp->next->prev=temp->prev;
			temp->prev->next=NULL;
			free(temp);
		}
	}
	return head;
		
}
//function to display list		
void display(node* head)
{
	node*tp=head;
	while(tp!=NULL)
	{
		printf("%d ",tp->data);
		tp=tp->next;
	}
	printf("\n");
}
//main function
void main()
{
	
	int t,n,k;int a;
	scanf("%d",&t);
	//array to store all lists
	node* arr[t];
	//taking t inputs
	for(int i=0;i<t;i++)
	{
		node*head=NULL;
		scanf("%d %d",&n,&k);
		for(int j=0;j<n;j++)
		{
			
			scanf("%d",&a);
			head=create(head,a);
		}		
		//display(head);
		head=delete(head,k);
		printf("\n");
		arr[i]=head;
	}
	//to display the list
	for(int i=0;i<t;i++)
	{
		display(arr[i]);
	}
}
