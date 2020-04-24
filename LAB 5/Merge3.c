//k pointers
#include<stdio.h>

void merge(int a[20][20],int s[],int n);

void main()
{
	int a[20][20],s[20],n,i,j;
	printf("Enter number of arrays: ");
	scanf("%d",&n);
	
	printf("Enter values for %d arrays: ",n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter size of array %d: ",i+1);
		scanf("%d",&s[i]);
		
		for(j=0;j<s[i];j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<n;i++)
	{
		printf("\nArray %d: ",i+1);
		for(j=0;j<s[i];j++)
		{
			printf("%d ",a[i][j]);
		}
	}
	merge(a,s,n);
}

void merge(int a[20][20],int s[20],int n)
{
	int m[400],k[20],l,i,j,min,f=1;
	l=0;
	for(i=0;i<n;i++)
		k[i]=0;
	
	min=a[0][k[0]];
	j=0;
	
	while(f!=0)
	{
		f=0;
		
		for(i=0;i<n;i++)
		{
			if(k[i]<s[i])
			{
				if(a[i][k[i]]<min)
				{
					min=a[i][k[i]];
					j=i;
				}
			}
		}
		m[l]=min;
		l++;
		k[j]++;
		
		for(i=0;i<n;i++)
		{
			if(k[i]<s[i])
			{
				f=1;
				min=a[i][k[i]];
				j=i;
				break;
			}
		}
	}
	printf("\nThe sorted array is: ");
	for(i=0;i<l;i++)
		printf("%d ",m[i]);
}
