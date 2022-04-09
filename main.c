#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "barrier.h"

#define NUM_THREADS 4

barrier_t* b;

struct arg_s
{
	pthread_t tid;
	int index;
};

void* thread1(void* data)
{
	struct arg_s* arg = (struct arg_s*)data;
	while (1)
	{
		sleep(arg->index);
		printf("Thread %d\n", arg->index);	
		barrier_wait(b);
	}
	return 0;
}

int main(void)
{
	struct arg_s args[NUM_THREADS];
	b = barrier_init(NUM_THREADS);
	for (int i = 0; i < NUM_THREADS; i++)
	{
		args[i].index = i;
		pthread_create(&args[i].tid, 0, thread1, &args[i]);
	}

	for (int i = 0; i < NUM_THREADS; i++)
		pthread_join(args[i].tid, 0);
	barrier_destroy(b);
}
