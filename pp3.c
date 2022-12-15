#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main()
{
	int prime[100],i,j,n;
	printf("\n In order to find prime numbers from 1 to n Enter the value of n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		prime[1]=0;
		for(i=2;i*i<n;i++)
		{
			#pragma omp parallel for
			for(j=i*i;j<=n;j++)
			{
				if(prime[i]==1)
					prime[j]=0;
			}
		}
		printf("\n prime numbers from 1 to %d are \n",n);
		for(i=2;i<=n;i++)
		{
			if(prime[i]==1)
			{
				printf("%d \t",i);
			}
		}
		printf("\n");
		
}
