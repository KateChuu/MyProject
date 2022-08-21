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
 
pthread_t philosopher[N];// �]�w philosopher
pthread_mutex_t chopstick[N];// �]�w chopstick
int chopstick_status[2][N];// �Ĥ@������ chopstick �{�b�b�֤�W�A�ĤG���h�O�� chopstick dirty or clean 
int  philosopher_status[N];// philosopher �����A 
int times = 10;// �`���榸�� 
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
			chopstick_status[1][ N - 1 ] = DIRTY;// �s���̤p�� philosopher�h���s���̤j�� chopstick
		}
	}
    sleep(3);// ���Ҧ� philosopher ���i�� 
    while(times-->=0)// ����Ҧ� philosopher �Y�����`���� 
	{
		think(index);
		hungry(index);
	}
	printf("Philosopher %d ���ƨ�F\n", index);
    return NULL;
}
void think(int index){
	printf("Philosopher %d start to thinking\n", index);
	philosopher_status[index] =  THINKING;
	sleep( rand() % 3 + 1 );// ���]�C�� philosopher �|��� 1~3 ��
}
void hungry(int index){
	philosopher_status[index] =  HUNGRY;
	printf("Philosopher %d is hungry\n", index);
	int first = (index + N - 1) % 5, second = index;// �����s���C���A�A������ 
	if(first > second){
		first = index;
		second = (index + N - 1) % 5;
	}
	time_t begin= time(NULL);
	
	request(index,first);
	request(index,second);// ��ݭn�� chopstick �o�e request 
	
    waiting_time += time(NULL) - begin;// �p�ⵥ�h�[�~�}�l�Y
	eating(index, first, second); 
}
void request(int index,int chopstick_id){
	if(chopstick_status[0][chopstick_id] != index)// chopstick ���b�ڤ�W 
	{
		int chopstick_owner = chopstick_status[0][chopstick_id];//���o�� chopstick �� philosopher
		if(pthread_mutex_lock(&chopstick[chopstick_id]) == 0){
				chopstick_status[0][chopstick_id] = index;// chopstick ���n�� philosopher
				chopstick_status[1][chopstick_id] = CLEAN;// �� chopstick �����b	
				printf("Philosopher %d �q %d ���䮳�F %d �� chopstick\n", index, chopstick_owner, chopstick_id);
		}
	}
	else{
		pthread_mutex_lock(&chopstick[chopstick_id]);
		printf("Philosopher %d �Φۤv�� %d �� chopstick\n", index, chopstick_id);	
	} 
}
void eating(int index,int first,int second){
	//pthread_mutex_lock(&mutex);
	printf ("Philosopher %d start to eating\n", index);
	philosopher_status[index] =  EATING;
	chopstick_status[1][first] = DIRTY;
	chopstick_status[1][second] = DIRTY;
	sleep( rand() % 3 + 1 );// ���]�C�� philosopher �|�Y1~3��
	printf ("Philosopher %d finished\n", index);
	pthread_mutex_unlock(&chopstick[first]);// �Y�������X chopstick ���b���� philosopher �i�H�� 
	pthread_mutex_unlock(&chopstick[second]);
	
	//pthread_mutex_unlock(&mutex);
}
int main(){
	int i = 0;
	srand(time(NULL));// ���üƷ|���� 
	
	for(i = 0; i < N; i++){
		pthread_mutex_init(&chopstick[i], NULL);// �]���@�몺��A����L�H�i�H unlock �O�H�� chopstick 
	}
	
	for(i = 0; i < N; i++){	
		pthread_create(&philosopher[i], NULL, start, (int*)i);
	}
	sleep(2);
	printf("\n-----------------------------\n");
	
	for(i = 0; i < N; i++){
	    pthread_join(philosopher[i], NULL);//���Ҧ� philosopher ���槹 
	} 
	printf("total wating time = %ld", waiting_time);
    for(i = 0; i < N; i++){
		pthread_mutex_destroy(&chopstick[i]);
	}
	
	return 0;
}
