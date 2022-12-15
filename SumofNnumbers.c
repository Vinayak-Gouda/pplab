#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main(int argc,char** argr)
{
	int partial_sum,total_sum;
	#pragma omp parallel private(partial_sum) shared(total_sum)
	{
		partial_sum=0;
		total_sum=0;
		#pragma omp for
		{
			for(int i=1;i<=100;i++)
			{
				partial_sum+=i;
			}
		}
		#pragma omp critical
		{
			total_sum+=partial_sum;
		}
	}
	printf("Total Sum:%d\n",total_sum);
	return 0;
}
