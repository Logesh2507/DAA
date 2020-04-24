#include<stdio.h>

void merge_sort(int a[],int beg,int end);
void merge(int a[],int beg,int end);

int main()
{
	int n,a[20],i;
	
	printf("Enter number of integers: ");
	scanf("%d",&n);
	
	printf("Enter %d integers: ",n);
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	
	merge_sort(a,0,n-1);

	printf("\nSorted array: ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}

void merge_sort(int a[],int beg,int end)
{
	int m1=beg+((end-beg)/3);
	int m2=(m1+end)/2;
		
	if(beg < end)
	{
		merge_sort(a,beg,m1);
		merge_sort(a,m1+1,m2);
		merge_sort(a,m2+1,end);
		
		int b[20],i=beg,j=m1+1,k=m2+1,p=beg;

		while(i<=m1 && j<=m2 && k<=end)
		{
			if(a[i]<a[j] && a[i]<a[k])
			{
				b[p]=a[i];
				i++;
				p++;
			}
			else if(a[j]<a[i] && a[j]<a[k])
			{
				b[p]=a[j];
				p++;
				j++;
			}
			else
			{
				b[p]=a[k];
				k++;
				p++;
			}
		}	
			
		if(i>m1)//1
		{
			while(j<=m2 && k<=end)
			{
				if(a[j]<a[k])
				{
					b[p]=a[j];
					j++;
					p++;
				}
				else
				{
					b[p]=a[k];
					k++;
					p++;
				}
			}
			if(j<=m2)
			{
				while(j<=m2)
				{
					b[p]=a[j];
					j++;
					p++;
				}
			}
			else
			{
				while(k<=end)
				{
					b[p]=a[k];
					k++;
					p++;
				}
			}
		}
		else if(j>m2)//2
		{
			while(i<=m1 && k<=end)
			{
				if(a[i]<a[k])
				{
					b[p]=a[i];
					i++;
					p++;
				}
				else
				{
					b[p]=a[k];
					k++;
					p++;
				}
			}
			if(i<=m1)
			{
				while(i<=m1)
				{
					b[p]=a[i];
					i++;
					p++;
				}
			}
			else
			{
				while(k<=end)
				{
					b[p]=a[k];
					k++;
					p++;
				}
			}
		}
		else//3
		{
			while(j<=m2 && i<=m1)
			{
				if(a[i]<a[j])
				{
					b[p]=a[i];
					i++;
					p++;
				}
				else
				{
					b[p]=a[j];
					j++;
					p++;
				}
			}
			if(j<=m2)
			{
				while(j<=m2)
				{
					b[p]=a[j];
					j++;
					p++;
				}
			}
			else
			{
				while(i<=m1)
				{
					b[p]=a[i];
					i++;
					p++;
				}
			}
		}
		for(i=beg;i<=end;i++)
			a[i]=b[i];
	}
}
