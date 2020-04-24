//heap
#include<stdio.h>

struct node
{
	int data;
	int pos;
};

struct heap
{
	struct node arr[20];
	int last;
};

struct heap H;

int m[400],l=0;

void insert(struct node p);
struct node delete();
void merge(int a[20][20],int s[],int n);

void main()
{
	int a[20][20],s[20],n,i,j;
    H.last=0;

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

	printf("\nMerged array: ");
	for(i=0;i<l;i++)
		printf("%d ",m[i]);
}

void merge(int a[20][20],int s[],int n)
{
	int k[20],i,j,f=1;
	struct node p,x;

	for(i=0;i<n;i++)
		k[i]=0;

	for(i=0;i<n;i++)
	{
		p.data=a[i][k[i]];
		p.pos=i;
		insert(p);
	}

	while(f!=0)
	{
		f=0;
		x=delete();
		k[x.pos]++;
		if(k[x.pos]<s[x.pos])
		{
			p.data=a[x.pos][k[x.pos]];
			p.pos=x.pos;
			insert (p);
		}

		for(i=0;i<n;i++)
		{
			if(k[i]<s[i])
			{
				f=1;
				break;
			}
		}
	}
}

void insert(struct node p)
{
	H.last++;
	H.arr[H.last] = p;
	int t = H.last;
	struct node temp;

	while((t/2 >= 1) && (H.arr[t].data <= H.arr[t / 2].data))
	{
		temp=H.arr[t];
		H.arr[t]=H.arr[t/2];
		H.arr[t/2]=temp;
		t /= 2;
	}
}

struct node delete()
{
	struct node x = H.arr[1];
	struct node temp;
	H.arr[1] = H.arr[H.last];
	H.last--;
	int t = 1;
	int mi;
	while(2*t  <= H.last)
	{
		if(H.last >= 2*t+1)
		{
			if(H.arr[2*t].data < H.arr[2*t+1].data)
				mi = 2*t;
			else
				mi = 2*t+1;
		}
		else
			mi = 2*t;
		if(H.arr[t].data > H.arr[mi].data)
		{
			temp=H.arr[t];
			H.arr[t]=H.arr[mi];
			H.arr[mi]=temp;
			t = mi;
		}
		else
			break;
	}
	m[l]=x.data;
	l++;
	return x;
}

