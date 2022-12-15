#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main()
{
	int i;
	const int N=1000;
	int sum=0;
	#pragma omp parallel for private(i)reduction(+:sum)
	for(i=0;i<N;i++)
	{
		sum+=i;
	}
	printf("reduction sum=%d (expected %d)\n",sum,((N-1)*N)/2);
}
