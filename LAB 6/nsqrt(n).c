#include<stdio.h>

void main()
{
	int n,a[1000],i,j,d=0;
	
	printf("Enter value for n: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		a[i]=1;
	
	for(i=2;i*i<=n;i++)
	{
		for(j=i-1;j<n;j+=i);
		
		if(j==((n-1)+i))
		{
			d=1;
			break;
		}
	}
	if(d==0)
		printf("%d is prime",n);
	else
		printf("%d is not prime",n);
}
