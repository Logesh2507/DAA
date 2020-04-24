//incremental Design
#include<stdio.h>

void merge(int a[20][20],int s[],int n);

int c[400],x=0;

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
		merge(a,s,i);
	printf("\nMerged Sorted Array:\n");
	for(i=0;i<x;i++)
		printf("%d ",c[i]);
}

void merge(int a[20][20],int s[],int n)
{
	int i=0,j=0,t[400],k=0;
	
	if(n==0)
	{
		for(i=0;i<s[0];i++)
		{
			c[x]=a[0][i];
			x++;
		}
	}
	else
	{
		while(i<x && j<s[n])
		{
			if(c[i]<a[n][j])
			{
				t[k]=c[i];
				i++;
				k++;
			}
			else
			{
				t[k]=a[n][j];
				j++;
				k++;
			}
		}
		if(i<x)
		{
			while(i<x)
			{
				t[k]=c[i];
				i++;
				k++;
			}
		}
		else
		{
			while(j<s[n])
			{
				t[k]=a[n][j];
				j++;
				k++;
			}
		}
		x=k;
		for(i=0;i<k;i++)
			c[i]=t[i];
	}
}
