#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdbool.h>
#define N 5
//Hierarchy in resources
//Philosopher first picks up the small number chopstick
//But put down the chopstick in reversed order

pthread_t philosopher[N];		//Declare philosophers
pthread_mutex_t chopstick[N];	//Declare chopsticks
pthread_mutexattr_t mutex_attr; //Declare mutex attribute

int times = 10;			 //How many times a philosopher can eat
time_t waiting_time = 0; //How long does the philosopher wait to eat when he is hungry

void *start(int *who) {

	int id = (int *)who;
	printf("Philosopher %d sits down.\n", id);
	sleep(1);

	while (times-- >= 0) {

		sleep(rand() % 3 + 1);	   //Assume each philosopher thinks for 1~3 seconds
		time_t begin = time(NULL); //Current time
		printf("Philosopher%d is hungry.\n", id);
		pickup(id);

		waiting_time += time(NULL) - begin; //Accumulate the waiting time
		printf("Philosopher %d starts to eat.\n", id);
		sleep(rand() % 3 + 1); //Assume each philosopher eats for 1~3 seconds
		putdown(id);
	}

	printf("Philosopher %d runs out of times.\n", id);
	putdown(id);
	//The time is over, preventing the philosopher from holding the chopstick
	//and causing deadlock
	return NULL;
}

void pickup(int id) {
	int first_pick, second_pick;

	if (id != N - 1) { //Philosopher 0~3 first picks up the small number chopstick
		first_pick = id;
		second_pick = (id + 1) % 5;
	}
	else {
		first_pick = (id + 1) % 5; //Except for philosopher 4
		second_pick = id;
	}

	pthread_mutex_lock(&chopstick[first_pick]); //First pick up the small number chopstick
	printf("Philosopher %d picks up chopstick %d.\n", id, first_pick);
	pthread_mutex_lock(&chopstick[second_pick]); //Then the big number one
	printf("Philosopher %d then picks up chopstick %d.\n", id, second_pick);
}

void putdown(int id) {
	int first_pick, second_pick;

	if (id != N - 1) {
		first_pick = id;
		second_pick = (id + 1) % 5;
	}
	else {
		first_pick = (id + 1) % 5;
		second_pick = id;
	}

	//Putting down the chopstick in reversed order
	printf("Philosopher %d puts down chopstick %d.\n", id, second_pick);
	pthread_mutex_unlock(&chopstick[second_pick]);
	printf("Philosopher %d puts down chopstick %d.\n", id, first_pick);
	pthread_mutex_unlock(&chopstick[first_pick]);
}

int main() {
	srand(time(NULL)); //Set the seed for random numbers
	int i = 0;
	pthread_mutexattr_init(&mutex_attr); //Initialize mutex attribute
	pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_ERRORCHECK_NP);
	//Set the mutex type attribute to error checking
	//Returning error in the following 3 situation
	//1. A thread attempting to relock this mutex without first unlocking it
	//2. A thread attempting to unlock an unlocked mutex
	//3. A thread attempting to unlock a mutex which another thread has locked

	for (i = 0; i < N; i++) {
		pthread_mutex_init(&chopstick[i], &mutex_attr);
	}

	for (i = 0; i < N; i++) { //Pass the philosophers to start
		pthread_create(&philosopher[i], NULL, start, i);
	}

	sleep(1);
	printf("\n-------------------------------------------------\n");

	for (i = 0; i < N; i++) { //Main thread is blocked here, waiting for the execution
		pthread_join(philosopher[i], NULL);
	}

	for (i = 0; i < N; i++) { //Destroy the mutex object referenced by mutex
		pthread_mutex_destroy(&chopstick[i]);
	}

	printf("Total waiting time is %ld", waiting_time); //Print total waiting time
	return 0;
}
