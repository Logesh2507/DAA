#include<stdio.h>
#include<math.h>

void main()
{
    int n,bin[50],i,j,k,len=0,p[50]={0},s[50]={0},a,b,c=0;
    printf("Enter value for n: ");
    scanf("%d",&n);

    while(n!=0)
    {
        bin[len]=n%2;
        n=n/2;
        len++;
    }
    
    for(i=0;i<len;i++)
    {
    	k=i;
   		for(a=0;a<k;a++)
    		p[a]=0;
    	for(j=0;j<len;j++)
    	{
    		p[k]=bin[i]*bin[j];
    		k++;
    	}
    	if(i==0)
    	{
    		for(b=0;b<j;b++)
    			s[b]=p[b];
		}
		else
		{
			c=0;
			for(a=0;a<k;a++)
			{
				if(s[a]==0 && p[a]==0)
				{
					s[a]=c;
					c=0;
				}
				else if((s[a]==0 && p[a]==1) || (s[a]==1 && p[a]==0))
				{
					if(c==0)
						s[a]=1;
					else
					{
						s[a]=0;
						c=1;
					}
				}
				else if(s[a]==1 && p[a]==1)
				{
					s[a]=c;
					c=1;
				}
			}
			if(c==1)
			{
				s[k]=1;
				k++;
			}
		}
	}
	
	int sum=0;
    for(i=0;i<k;i++)
        sum=sum+(pow(2,i)*s[i]);
    printf("%d",sum);
}
