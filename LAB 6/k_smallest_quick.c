#include<stdio.h>
#include<stdlib.h>

int swap(int *p,int *q)
{
	int temp=*p;
	*p=*q;
	*q=temp;
}

int mainsort(int a[],int start,int end)
{
	int index=start-1;
	int j,pivot;
	pivot=end;
	for(j=start;j<=end-1;j++)
	{
		if(a[j]<a[pivot])
		{
			index++;
			if(index!=j)
			swap(&a[index],&a[j]);
		}
		
	}
	swap(&a[index+1],&a[end]);
		return (index+1);
	
}

void qs(int a[],int start,int end,int k)
{   
	if(start<end)
	{
		int index=mainsort(a,start,end);
		if(index>k)
			qs(a,start,index-1,k);
		else if(index<k)
			qs(a,index+1,end,k);
		else
			return;
	}
}

void main()
{
	int n,i,start,end,k;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n];
	
	printf("Enter %d number: ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	start=0;
	end=n-1;
		
	printf("Enter value for k: ");
	scanf("%d",&k);
	
	qs(a,start,end,k);
	
	printf("\nFirst %d smallest numbers: ",k);
	for(i=0;i<k;i++)
		printf("%d ",a[i]);
}
