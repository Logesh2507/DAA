//divide & conquer
#include<stdio.h>

void merge(int a[20][20],int s[],int beg,int end);

int c[400],x=0,b[400];

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
		x=x+s[i];

	merge_sort(a,s,0,n-1);

	printf("\nMerged Sorted Array:\n ");
	for(i=0;i<x;i++)
		printf("%d ",c[i]);

	printf("\n");
}

void merge_sort(int a[20][20],int s[],int beg,int end)
{
	int n1,n2,k=0,i,j=0;
	int m=beg+((end-beg)/2);

	for(i=beg;i<=m;i++)
		n1=n1+s[i];
	for(i=m+1;i<=end;i++)
		n2=n2+s[i];
	for(i=0;i<beg;i++)
		k=k+i;

	int st=k,e=k+n1+n2;

	if(beg==end-1)
	{
		i=0,j=0;

		while(i<s[beg] && j<s[end])
		{
			if(a[beg][i]<a[end][j])
			{
				b[k]=a[beg][i];
				i++;
				k++;
			}
			else
			{
				b[k]=a[end][j];
				j++;
				k++;
			}
		}
		if(i<s[beg])
		{
			b[k]=a[beg][i];
			i++;
			k++;
		}
		else
		{
			b[k]=a[end][j];
			j++;
			k++;
		}
		for(i=st;i<=e;i++)
			c[i]=b[i];
	}
	else
	{
		int m=(beg=end)/2;

		merge_sort(a,s,beg,m);
		merge_sort(a,s,m+1,end);

		i=k;
		j=k+n1;

		while(i<=m && j<=end)
		{
			if(c[i]<c[j])
			{
				c[k]=a[i];
				i++;
				k++;
			}
			else
			{
				c[k]=b[j];
				j++;
				k++;
			}
		}
		if(i<=m)
		{
			while(i<=m)
			{
				c[k]=b[i];
				i++;
				k++;
			}
		}
		else
		{
			while(j<=end)
			{
				c[k]=b[j];
				j++;
				k++;
			}
		}
		for(i=st;i<=e;i++)
			c[i]=b[i];
	}
}
