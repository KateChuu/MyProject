#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <pthread.h>

#define N 5

enum{
	THINKING,
	HUNGRY,
	EATING,
};// the status of philosopher
enum{
	DIRTY,
	CLEAN
};// the status of chopstick
 
pthread_t philosopher[N];// 設定 philosopher
pthread_mutex_t chopstick[N];// 設定 chopstick
int chopstick_status[2][N];// 第一維紀錄 chopstick 現在在誰手上，第二維則記錄 chopstick dirty or clean 
int  philosopher_status[N];// philosopher 的狀態 
int times = 10;// 總執行次數 
time_t waiting_time = 0;

void *start(int *who) {
    int index = (int*)who;
    printf("Philosopher %d sit down\n", index);
    if(index != N - 1) // initialize
	{
		chopstick_status[0][index] = index;
		chopstick_status[1][index] = DIRTY;
		if(index == 0){
			chopstick_status[0][ N - 1 ] = index;
			chopstick_status[1][ N - 1 ] = DIRTY;// 編號最小的 philosopher多拿編號最大的 chopstick
		}
	}
    sleep(3);// 等所有 philosopher 都進來 
    while(times-->=0)// 限制所有 philosopher 吃飯的總次數 
	{
		think(index);
		hungry(index);
	}
	printf("Philosopher %d 次數到了\n", index);
    return NULL;
}
void think(int index){
	printf("Philosopher %d start to thinking\n", index);
	philosopher_status[index] =  THINKING;
	sleep( rand() % 3 + 1 );// 假設每個 philosopher 會思考 1~3 秒
}
void hungry(int index){
	philosopher_status[index] =  HUNGRY;
	printf("Philosopher %d is hungry\n", index);
	int first = (index + N - 1) % 5, second = index;// 先拿編號低的，再拿高的 
	if(first > second){
		first = index;
		second = (index + N - 1) % 5;
	}
	time_t begin= time(NULL);
	
	request(index,first);
	request(index,second);// 對需要的 chopstick 發送 request 
	
    waiting_time += time(NULL) - begin;// 計算等多久才開始吃
	eating(index, first, second); 
}
void request(int index,int chopstick_id){
	if(chopstick_status[0][chopstick_id] != index)// chopstick 不在我手上 
	{
		int chopstick_owner = chopstick_status[0][chopstick_id];//有這個 chopstick 的 philosopher
		if(pthread_mutex_lock(&chopstick[chopstick_id]) == 0){
				chopstick_status[0][chopstick_id] = index;// chopstick 給要的 philosopher
				chopstick_status[1][chopstick_id] = CLEAN;// 把 chopstick 擦乾淨	
				printf("Philosopher %d 從 %d 那邊拿了 %d 號 chopstick\n", index, chopstick_owner, chopstick_id);
		}
	}
	else{
		pthread_mutex_lock(&chopstick[chopstick_id]);
		printf("Philosopher %d 用自己的 %d 號 chopstick\n", index, chopstick_id);	
	} 
}
void eating(int index,int first,int second){
	//pthread_mutex_lock(&mutex);
	printf ("Philosopher %d start to eating\n", index);
	philosopher_status[index] =  EATING;
	chopstick_status[1][first] = DIRTY;
	chopstick_status[1][second] = DIRTY;
	sleep( rand() % 3 + 1 );// 假設每個 philosopher 會吃1~3秒
	printf ("Philosopher %d finished\n", index);
	pthread_mutex_unlock(&chopstick[first]);// 吃完之後放出 chopstick 讓在等的 philosopher 可以拿 
	pthread_mutex_unlock(&chopstick[second]);
	
	//pthread_mutex_unlock(&mutex);
}
int main(){
	int i = 0;
	srand(time(NULL));// 讓亂數會改變 
	
	for(i = 0; i < N; i++){
		pthread_mutex_init(&chopstick[i], NULL);// 設為一般的鎖，讓其他人可以 unlock 別人的 chopstick 
	}
	
	for(i = 0; i < N; i++){	
		pthread_create(&philosopher[i], NULL, start, (int*)i);
	}
	sleep(2);
	printf("\n-----------------------------\n");
	
	for(i = 0; i < N; i++){
	    pthread_join(philosopher[i], NULL);//等所有 philosopher 執行完 
	} 
	printf("total wating time = %ld", waiting_time);
    for(i = 0; i < N; i++){
		pthread_mutex_destroy(&chopstick[i]);
	}
	
	return 0;
}
