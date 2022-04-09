#pragma once

#include <semaphore.h>

typedef struct barrier_s
{
	unsigned int n;
	unsigned int count;
	sem_t sem;
	sem_t cond;
} barrier_t;

barrier_t* barrier_init(unsigned int n);
void barrier_destroy(barrier_t* b);
void barrier_wait(barrier_t* b);
