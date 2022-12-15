#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main()
{
	#pragma omp parallel
	{
		#pragma omp section
		printf("This is from thread %d\n",omp_get_thread_num());
		
		#pragma omp section
		printf("This is from thread %d\n",omp_get_thread_num());
	}
}
