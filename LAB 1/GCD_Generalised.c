#include<stdio.h>

int GCD(int x,int y);
void gcd1(int a[],int k);
int gcd2(int a[],int k);

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
        gcd1(a,k);
        gcd = gcd2(a,k);
        printf("GCD = %d",gcd);
    }
}

int GCD(int x,int y)
{
    int min,max,c;

    if(x<y)
    {
        min=x;
        max=y;
    }
    else
    {
        min=y;
        max=x;
    }

    if(min==0 && max==0)
        return 1;
    else if(min==0)
        return max;
    else
    {
        while(max%min !=0)
        {
            c=min;
            min=max%min;
            max=c;
        }
        return min;
    }
}
void gcd1(int a[],int k)
{
    int gcd,i;

    gcd=GCD(a[0],a[1]);
    for(i=2;i<k;i++)
        gcd=GCD(gcd,a[i]);
    printf("GCD = %d\n",gcd);
}

int gcd2(int a[],int k)
{
    int gcd,x;

    if(k==1)
        return a[0];
    else
    {
        x=gcd2(a,k-1);
        gcd=GCD(x,a[k-1]);
        return gcd;
    }
}
