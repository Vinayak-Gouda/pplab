#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#include<time.h>

void montecarlo(int N,int k)
{
	double x,y;
	double d;
	int pCircle=0,pSquare=0;
	int i=0;
	#pragma omp parallel firstprivate(x,y,d,i) reduction(+ : pCircle,pSqaure) num_threads(k)
	{
		Srand48((int)time(NULL));
		for(i=0;i<N;i++)
		{
			x=(double)drand48();
			y=(double)drand48();
			d=((x*x)+(y*y));
			if(d<=1)
			{
				pCircle++;
			}
			pSquare++;
	}
		double pi=4.0 *((double)pcircle/(double)(pSquare));
		printf("Final estimation of pi=%f\n",pi);
}

int main()
{
	int N=100000;
	int k=8;
	montecarlo(N,k);
}
