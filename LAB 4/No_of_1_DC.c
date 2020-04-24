#include<stdio.h>

int GCD(int a[],int beg,int end);
int l2_1(int x,int y);

void main()
{
    int a[50],k,i,gcd,c=0;

    printf("Enter number of inputs: ");
    scanf("%d",&k);
    printf("Enter %d integers: ",k);
    for(i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<0)
            a[i]=a[i]*(-1);
    }

    for(i=0;i<k;i++)
        if(a[i]!=0)
        {
            c=1;
            break;
        }
    if(c==0)
        printf("GCD does not exist");
    else
    {
		gcd=GCD(a,0,k-1);
		printf("\nNumber of 1 = %d",gcd);
	}
}

int GCD(int a[],int beg,int end)
{
	if(beg==end)
		return a[beg];
	else
	{
		int x,y,z;
		x=GCD(a,beg,(beg+end)/2);
		y=GCD(a,((beg+end)/2)+1,end);
		
		z=x+y;
		
		return z;
	}
}
