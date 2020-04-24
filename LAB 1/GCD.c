
#include<stdio.h>

void l1_1(int x,int y);
int l1_2(int x,int y,int z);
void l2_1(int x,int y);
int  l2_2(int x,int y);
void l3_1(int x,int y);
int  l3_2(int x,int y,int z);
int gcd3=1;
int main()
{
int x,y;
printf("enter two no.s ");
scanf("%d%d",&x,&y);
int min,max;
if(x>y)
{
min=y;
max=x;
}
else if(y>x)
{
min=x;
max=y;
}
l1_1(x,y);
l2_1(min,max);
l3_1(x,y);
int gcd1,gcd2;
gcd1=l2_2(min,max);
gcd2=l3_2(min,max,1);
l1_2(min,max,1);
printf("GCD = %d\n",gcd3);
printf("GCD = %d\n",gcd1);
printf("GCD = %d\n",x*y/gcd2);
return 0;
}




void l1_1(int x,int y)
{
int min,gcd;
if(x>y)
min=y;
else if(y>x)
min=x;
else
gcd=x;
int i;
gcd=1;
for(i=1;i<=min;i++)
{
if(x%i==0&&y%i==0)
gcd=i;
}
printf("GCD = %d\n",gcd);
}
void l2_1(int x,int y)
{
int c;

while(y%x !=0)
{
c=x;
x=y%x;
y=c;
}
printf("GCD = %d\n",x);
}
void l3_1(int x,int y)
{
int max;
//gcd*lcm=x*y
if(x>y)
max=x;
else if(y>x)
max=y;
int i=1,lcm;
while(i*max<=x*y)
{
if((i*max)%x==0&&(i*max)%y==0)
{
lcm=i*max;
break;
}
i++;
}
printf("GCD = %d\n",(x*y)/lcm);
}






int l2_2(int x,int y)
{
if(y%x==0)
return x;
else
{
return l2_2(y%x,x);
}
}
int l3_2(int x, int y,int z)
{
if(z==y)
return x;
else
if(x%y==0)
return x;
else
l3_2(x*(z+1)/z,y,z+1);
}

int l1_2(int x,int y,int z)
{
if(z-1==x)
return gcd3;
else if(x%z==0&&y%z==0)
gcd3=z;
l1_2(x,y,z+1);
}

