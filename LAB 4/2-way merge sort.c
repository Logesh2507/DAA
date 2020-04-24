#include<stdio.h>

void merge_sort(int a[],int beg,int end);

void main()
{
	int n,a[20],i;
	
	printf("Enter number of integers: ");
	scanf("%d",&n);
	
	printf("Enter %d integers: ",n);
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	merge_sort(a,0,n-1);
	
	printf("\nSorted array: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void merge_sort(int a[],int beg,int end)
{
	if(beg==end)
		return;
	else
	{
		merge_sort(a,beg,(beg+end)/2);
		merge_sort(a,((beg+end)/2)+1,end);
		int b[20],i=beg,j=((beg+end)/2)+1,k=beg;
		
		while(i<=(beg+end)/2 && j<=end)
		{
			if(a[i]<a[j])
			{
				b[k]=a[i];
				i++;
				k++;
			}
			else
			{
				b[k]=a[j];
				j++;
				k++;
			}
		}
		if(i<=(beg+end)/2)
		{
			while(i<=(beg+end)/2)
			{
				b[k]=a[i];
				i++;
				k++;
			}
		}
		else
		{
			while(j<=end)
			{
				b[k]=a[j];
				j++;
				k++;
			}
		}
		for(i=beg;i<=end;i++)
			a[i]=b[i];
	}
}
