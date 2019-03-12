#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define LEFT (ph_num+4)%N
#define RIGHT (ph_num+1)%N

sem_t mutex, s[N];

void *philosopher(void *num);
void take_fork(int);
void put_fork(int);
void test(int);

int state[N], phil_num[N]={0, 1, 2, 3, 4};

void main() 
{
	int i;
	pthread_t thread_id[N];
	sem_init(&mutex, 0, 1);
	for(i=0; i<N; ++i) 
	{
		sem_init(&s[i], 0, 0);
	}
	for(i=0;i<N; ++i)
	{
		pthread_create(&thread_id[i], NULL, philosopher, &phil_num[i]);
		printf("Philosopher %d is thinking.\n", i+1);
	}
	for(i=0; i<N; ++i)
	{
		pthread_join(thread_id[i], NULL);
	}
}

void * philosopher(void *num)
{
	while(1)
	{
		long int j=0;
		int *i=num;
		while(j<1000000000)
			++j;
		j=0;
		take_fork(*i);
		while(j<1000000000)
			++j;
		put_fork(*i);
	}
}

void take_fork(int ph_num)
{
	long int j=0;
	sem_wait(&mutex);
	state[ph_num] = HUNGRY;
	printf("Philosopher %d is hungry.\n", ph_num+1);
	test(ph_num);
	sem_post(&mutex);
	sem_wait(&s[ph_num]);
	while(j<1000000000)
		++j;
}

void test(int ph_num)
{
	long int j=0;
	if(state[ph_num]==HUNGRY && state[LEFT]!=EATING && state[RIGHT]!=EATING)
	{
		state[ph_num] = EATING;
		while(j<1000000000)
			++j;
		printf("Philosopher %d takes fork %d and %d.\n", ph_num+1, LEFT+1, ph_num+1);
		sem_post(&s[ph_num]);
	}
}

void put_fork(int ph_num)
{
	sem_wait(&mutex);
	state[ph_num] = THINKING;
	printf("Philosopher %d putting fork %d and %d down and is starting to think.\n", ph_num+1, LEFT+1, ph_num+1);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}


/*

OUTPUT:

Philosopher 1 is thinking.
Philosopher 2 is thinking.
Philosopher 3 is thinking.
Philosopher 4 is thinking.
Philosopher 5 is thinking.
Philosopher 2 is hungry.
Philosopher 2 takes fork 1 and 2.
Philosopher 5 is hungry.
*/

