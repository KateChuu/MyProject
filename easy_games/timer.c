#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int lovelove;
void rule();

int timer(void)
{
	int heartBeat, totalTime;
    time_t t1, t2;
    //打開遊戲規則 
    rule();
    //遊戲開始 
    printf("請按下任意鍵顯示女生目前心裡所想數字\n");
    getch();
	printf("女生目前心裡所想數字為: "); 
    srand(time(NULL));
    heartBeat = (rand() % 10) + 10;
    printf("%d\n\n", heartBeat);
    printf("請按任意鍵開始計時\n\n");
    getch(); //開始計時 
    t1 = time(NULL);
    printf("開始計時...\n\n");
    printf("請按任意鍵結束計時\n\n");
    
    while(1){
    	if(kbhit() != 0){
    		break;    		
		}
	}

    t2 = time(NULL); //結束計時 
	totalTime = (int)difftime (t2, t1); //計算時間差 

    printf("你(妳)預估的時間為 %d 秒\n", totalTime);
    
    if(totalTime <= heartBeat + 5 && totalTime >= heartBeat - 5){
    	lovelove = lovelove + 30;
    	printf("同學很厲害ㄡ！恭喜獲得好感度30分！\n\n");
    	printf("你(妳)的好感度目前為: %d\n\n", lovelove);
	}
	else if(totalTime <= heartBeat + 10 && totalTime >= heartBeat - 10){
		printf("同學還不錯ㄡ！恭喜獲得好感度20分！\n\n");
		lovelove = lovelove + 20;
		printf("你(妳)的好感度目前為: %d\n\n", lovelove);
	}
	else{
		printf("同學啊！差太多囉～你(妳)這樣是追不到女朋友的:) (獲得好感度10分)\n\n");
		lovelove = lovelove + 10;
		printf("你(妳)的好感度目前為: %d\n\n", lovelove);
	}
	printf("請按下任意鍵結束遊戲...");
	getch();
	while(1){
		if(kbhit() != 0)
			break;
	}
}
//遊戲規則的function 
void rule(){
	FILE *fptr = fopen("timer_rule.txt", "r");
	char str[100] = {0};
	fgets(str, sizeof(str), fptr);
	while(!feof(fptr)){
		puts(str);
		fgets(str, sizeof(str), fptr);
	}
	fclose(fptr);
}
