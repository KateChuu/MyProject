#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<windows.h>
#include<pthread.h>


#define N 5

pthread_t philosopher[N];// create philosopher
pthread_mutex_t chopstick[N]; // create chopsticl
pthread_mutex_t mutex;  //mutex for exclusion 
pthread_mutexattr_t mutex_attr; //attributes of mutex
int times = 10;   //the total round that the philosopher can eat
time_t waiting_time = 0;  //initializatino of waiting time for philopher wait to eat

void *start(int *who) 
{
    int id = (int*)who;
    printf("Philosopher %d sits down\n",id);
    sleep(3);  //wait for all philoospher to sits down
    while(times-->=0){
		sleep( rand()%3+1 );	// philosopher think between 1~3 sec
		time_t begin= time(NULL);
		printf("Philosopher %d hungry\n",id);
		take_stick(id);	
    	waiting_time+=time(NULL)-begin;
    	printf ("Philosopher %d start to eat\n",id);
    	sleep( rand()%3+1 ); //philospher eat take 1~3 sec to eat
    	put_stick(id);
	}
	printf("Philosopher %d time out\n",id); // prevent deadlock by limit the round so that chopsticks are all put down at the end
    put_stick(id);
    return NULL;
}
void take_stick(int id){
	pthread_mutex_lock(&mutex);
	bool left = pthread_mutex_trylock(&chopstick[id])==0;
	bool right = pthread_mutex_trylock(&chopstick[(id+1)%5])==0;
	if(left&&right){  //executed when both both right and left chopsticks are taken
    	printf("Philosopher %d picks up number %d and number %d chopstick\n", id, id, (id+1)%5);
    	pthread_mutex_unlock(&mutex);
	}
    else{  //if only one chopstick is pick then put it back
		if(left){
			pthread_mutex_unlock(&chopstick[id]);
		}
		if(right){	
			pthread_mutex_unlock(&chopstick[(id+1)%5]);
		} 
		pthread_mutex_unlock(&mutex);
		Sleep(1); // stop 1 sec to prevent infinity loop
		take_stick(id);
	}
    
}

void put_stick(int id){	
	if(pthread_mutex_unlock(&chopstick[(id+1)%5])==0)
		printf("Philosopher %d put down number %d chopstick\n", id, (id+1)%5);
    if(pthread_mutex_unlock(&chopstick[id])==0)
    	printf("Philosopher %d put down number %d chopstick\n", id, id);
    
} 
int main(){
	int i = 0;
	srand(time(NULL));	// generating different random time seed
	pthread_mutexattr_init(&mutex_attr); //initialize mutex lock
    pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_ERRORCHECK_NP); // preventing unlocking other
	pthread_mutex_init(&mutex, &mutex_attr);	
	for(i = 0;i<N;i++){
		pthread_mutex_init(&chopstick[i],&mutex_attr);
	}
	for(i = 0;i<N;i++){	
		pthread_create(&philosopher[i],NULL,start, (int*)i);
	}
	sleep(2);
	printf("\n-----------------------------\n");
	
	for(i = 0;i<N;i++){
	    pthread_join(philosopher[i], NULL); //wait for every philopher to finish execution
	} 
	printf("total wating time = %ld",waiting_time);
    for(i = 0;i<N;i++){
		pthread_mutex_destroy(&chopstick[i]);
	}	
	return 0;
}
