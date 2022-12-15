#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main(int argc,char* arge[])
{
	#pragma omp parallel
	{
		printf("hello from thread = %d of %d \n",omp_get_thread_num(),omp_get_num_threads());
	}
}
