#include "barrier.h"
#include <stdlib.h>
#include <semaphore.h>

barrier_t* barrier_init(unsigned int n)
{
	barrier_t *b;
	b = calloc(1, sizeof(barrier_t));
	if (b == NULL)
		return NULL;
	b->n = n;
	b->count = 0;
	if (sem_init(&b->sem, 0, n) == -1)
	{
		free(b);
		return NULL;
	}
	if (sem_init(&b->cond, 0, 0) == -1)
	{
		sem_destroy(&b->sem);
		free(b);
		return NULL;
	}
	return b;
}

void barrier_destroy(barrier_t* b)
{
	sem_destroy(&b->sem);
	free(b);
}

void barrier_wait(barrier_t* b)
{
	sem_wait(&b->sem);
	b->count++;
	if (b->count == b->n)
	{
		while(b->count--)
			sem_post(&b->cond);
		b->count = 0;
	}
	sem_post(&b->sem);
	sem_wait(&b->cond);
}

