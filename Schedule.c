#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
//static : schedule(static,chunk_size)

int main()
{
	printf("Static Scheduling");
	#pragma omp parallel for schedule(static,3)
	for(int i=0;i<10;i++)
		printf("Thread %d in running number %d\n",omp_get_thread_num(),i);
		//return 0;
		

	//dynamic : schedule(dynamic,chunk_size)
	printf("dynamic Scheduling \n");
	#pragma omp parallel for schedule(dynamic,4)
	for(int i=0;i<10;i++)
		printf("Thread %d in running number %d\n",omp_get_thread_num(),i);
		//return 0;
		
	//guided : schedule(guided,chunk_size)
	printf("guided Scheduling \n");
	#pragma omp parallel for schedule(guided,4)
	for(int i=0;i<10;i++)
		printf("Thread %d in running number %d\n",omp_get_thread_num(),i);
		//return 0;
		
	//runtime : schedule(runtime,chunk_size)
	//printf("runtime Scheduling \n");
	#pragma omp parallel for schedule(runtime)
	for(int i=0;i<10;i++)
		printf("Thread %d in running number %d\n",omp_get_thread_num(),i);
		return 0;
}
