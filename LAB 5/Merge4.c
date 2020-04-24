//BST
#include<stdio.h>

struct node
{
	int data;
	struct node *lptr;
	struct node *rptr;
};

struct node *root=NULL;

void insert(int x,struct node *ptr);
void inorder(struct node *ptr);

void main()
{
	int a[20][20],s[20],n,i,j;
	
	printf("Enter number of arrays: ");
	scanf("%d",&n);
	printf("\nEnter values for %d arrays: ",n);
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter size of array %d: ",i+1);
		scanf("%d",&s[i]);
		printf("\nEnter %d values for array %d: ",s[i],i+1);
		for(j=0;j<s[i];j++)
			scanf("%d",&a[i][j]);
	}
	printf("\nArrays: ");
	for(i=0;i<n;i++)
	{
		printf("\nArray %d: ",i+1);
		for(j=0;j<s[i];j++)
			printf("%d ",a[i][j]);
	}
	
	for(i=0;i<n;i++)
		for(j=0;j<s[i];j++)
			insert(a[i][j],root);
			
	printf("\nMerged Sorted Arrays: \n");
	
	inorder(root);
}

void insert(int x,struct node *ptr)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->lptr=temp->rptr=NULL;
	if(root==NULL)
		root=temp;
	else
	{	
		if(x<ptr->data)
		{
			if(ptr->lptr!=NULL)
				insert(x,ptr->lptr);
			else
				ptr->lptr=temp;
		}
		else
		{
			if(ptr->rptr!=NULL)
				insert(x,ptr->rptr);
			else
				ptr->rptr=temp;
		}
	}
}

void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lptr);
		printf("%d ",ptr->data);
		inorder(ptr->rptr);
	}
}
