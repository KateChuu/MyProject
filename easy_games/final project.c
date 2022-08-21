#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

//其他人function的宣告
void dayThree(void);
int friday_m(void);
int supper();
int thursday_n(void);
int snake(void);
int math (void);
int supper();
int end (void);

void script1();
void script2();
void shuffle(char *[16]);
void display(int[16]);
int showFace(int, int, int[16], char *[16]);
int calculus();

int lovelove = 0;

int main(void) {
	PlaySound(TEXT("game_start.wav"),NULL,SND_FILENAME|SND_ASYNC);
	printf("歡迎來到戀愛養成遊戲!\n\n請輸入你的名字:");
	char name[10] = "";
	gets(name);
	system("cls");
	
	printf("\n我 %s ", name);
	script1();//印出第一段劇情 
	getch();
	script2();
	system("pause..");
	system("cls");
	
	
	//遊戲開始
	//規則介紹 
	printf("對了，今天去上課之前，我來玩玩\"絕對神準理想型戀愛占卜!\"吧\n\n");
	printf("規則介紹:一次輸入兩個號碼來翻牌，記住每張牌的位置，將牌湊成兩兩一對就贏了(顯示的卡片五秒後會消除喔)。\n");
	printf("輸入\"0 0\"直接結束遊戲。\n"); 
	printf("越快將所有牌配對完成，今後的戀情就會越順利喔!\n");
	
	int i;
	char *card[16];
	//將所有牌顯示的字統一設定成0 
	for(i = 0; i < 17; ++i){
		card[i] = "0";
	}
	//隨機分配牌面上的中文字 
	shuffle(card);
	
	int choice1 = 0, choice2 = 0;//玩家選擇的兩個號碼 
	int allDone = 0, totalTries = 0;
	int correct[16] = {0};//此陣列紀錄玩家選擇的卡牌號碼 
	
	while(allDone == 0){
		display(correct);//展示卡牌背面讓玩家選擇號碼 
		
		printf("輸入兩張牌的號碼:");
		scanf("%d %d", &choice1, &choice2);
		
		//防呆
		while((choice1>16||choice1<0) || ((choice2>16||choice2<0))){
			printf("請輸入正確編號:");
			scanf("%d %d", &choice1, &choice2);
		}
		
		if(choice1 == 0|| choice2 == 0){//玩家直接跳出遊戲 
			totalTries = 37;
			system("cls");
			break;
		}
		++totalTries;
		system("cls");
		
		allDone = showFace(choice1, choice2, correct, card);//印出玩家選擇的牌上面的中文字 
		sleep(2);//給玩家五秒時間記憶卡牌的位置和中文字 
		system("cls");
		
	}
	
	//遊戲結束，計算好感度 
	if(totalTries <= 16)
		lovelove = 20;
	else if(totalTries <= 26)
		lovelove = 15;
	else if(totalTries <= 36)
		lovelove = 5;
	else
		lovelove = -10;
		
	printf("恭喜破關!你目前累積的好感度:%d。\n", lovelove);
	system("pause..");
	
	lovelove += calculus();//印出微積分課的劇情 
	printf("正解是(1)!\n你目前累積的好感度:%d。\n\n", lovelove);
	
	//其他人的function
	snake();
	dayThree();
	supper();
	math ();
	thursday_n();
	friday_m();
	end();
	return(0);
}

void script1(){
	FILE *fptr = fopen("script1.txt", "r");
	char str[100] = "";
	fgets(str, sizeof(str), fptr);
	while(!feof(fptr)){
		puts(str);
		fgets(str, sizeof(str), fptr);
	}
	fclose(fptr);
}

void script2(){
	FILE *fptr = fopen("script2.txt", "r");
	char str[100] = "";
	fgets(str, sizeof(str), fptr);
	while(!feof(fptr)){
		puts(str);
		fgets(str, sizeof(str), fptr);
	}
	fclose(fptr);
}

void shuffle(char *card[16]){
	char *face[8] = {"傲嬌","年上","清純","老師","活潑","神秘","年下","天然"};
	srand(time(0));
	int i;
	for(i = 0; i < 8; ++i){
		int m1 = 0, m2 = 0;
		do{
			m1 = rand() % 16;
		}while(card[m1] != "0");
		card[m1] = face[i];
		
		do{
			m2 = rand() % 16;
		}while(card[m2]!= "0");
		card[m2] = face[i];
		
	}
}

void display(int correct[16]){
	
	int i;
	printf("----------   ----------   ----------   ----------\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("|   %2s   |   |   %2s   |   |   %2s   |   |   %2s   |\n", correct[0] == 0 ? "1" : " ", correct[1] == 0 ? "2" : " ", correct[2] == 0 ? "3" : " ", correct[3] == 0 ? "4" : " ");
	printf("|        |   |        |   |        |   |        |\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("----------   ----------   ----------   ----------\n");
	printf("----------   ----------   ----------   ----------\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("|   %2s   |   |   %2s   |   |   %2s   |   |   %2s   |\n", correct[4] == 0 ? "5" : " ", correct[5] == 0 ? "6" : " ", correct[6] == 0 ? "7" : " ", correct[7] == 0 ? "8" : " ");
	printf("|        |   |        |   |        |   |        |\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("----------   ----------   ----------   ----------\n");
	printf("----------   ----------   ----------   ----------\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("|   %2s   |   |   %2s   |   |   %2s   |   |   %2s   |\n", correct[8] == 0 ? "9" : " ", correct[9] == 0 ? "10" : " ", correct[10] == 0 ? "11" : " ", correct[11] == 0 ? "12" : " ");
	printf("|        |   |        |   |        |   |        |\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("----------   ----------   ----------   ----------\n");
	printf("----------   ----------   ----------   ----------\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("|   %2s   |   |   %2s   |   |   %2s   |   |   %2s   |\n", correct[12] == 0 ? "13" : " ", correct[13] == 0 ? "14" : " ", correct[14] == 0 ? "15" : " ", correct[15] == 0 ? "16" : " ");
	printf("|        |   |        |   |        |   |        |\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("----------   ----------   ----------   ----------\n");
	if(i % 4 == 0){
		printf("\n");
	}
}

int showFace(int choice1, int choice2, int correct[16], char *card[16]){
	char *str1 = card[choice1-1];
	char *str2 = card[choice2-1];
	if(strcmp(str1, str2) == 0){
		++correct[choice1-1];
		++correct[choice2-1];
	}
	
	int choice[16] = {0};
	choice[choice1-1] = choice1;
	choice[choice2-1] = choice2;

	printf("----------   ----------   ----------   ----------\n");
	printf("|        |   |        |   |        |   |        |\n"); 
	printf("|  %s  |   |  %s  |   |  %s  |   |  %s  |\n", choice[0] == 0 ? "    " : card[choice[0]-1], choice[1] == 0 ? "    " : card[choice[1]-1], choice[2] == 0 ? "    " : card[choice[2]-1], choice[3] == 0 ? "    " : card[choice[3]-1]);
	printf("|        |   |        |   |        |   |        |\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("----------   ----------   ----------   ----------\n");
	printf("----------   ----------   ----------   ----------\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("|  %s  |   |  %s  |   |  %s  |   |  %s  |\n", choice[4] == 0 ? "    " : card[choice[4]-1], choice[5] == 0 ? "    " : card[choice[5]-1], choice[6] == 0 ? "    " : card[choice[6]-1], choice[7] == 0 ? "    " : card[choice[7]-1]);
	printf("|        |   |        |   |        |   |        |\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("----------   ----------   ----------   ----------\n");
	printf("----------   ----------   ----------   ----------\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("|  %s  |   |  %s  |   |  %s  |   |  %s  |\n", choice[8] == 0 ? "    " : card[choice[8]-1], choice[9] == 0 ? "    " : card[choice[9]-1], choice[10] == 0 ? "    " : card[choice[10]-1], choice[11] == 0 ? "    " : card[choice[11]-1]);
	printf("|        |   |        |   |        |   |        |\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("----------   ----------   ----------   ----------\n");
	printf("----------   ----------   ----------   ----------\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("|  %s  |   |  %s  |   |  %s  |   |  %s  |\n", choice[12] == 0 ? "    " : card[choice[12]-1], choice[13] == 0 ? "    " : card[choice[13]-1], choice[14] == 0 ? "    " : card[choice[14]-1], choice[15] == 0 ? "    " : card[choice[15]-1]);
	printf("|        |   |        |   |        |   |        |\n");
	printf("|        |   |        |   |        |   |        |\n");
	printf("----------   ----------   ----------   ----------\n");
	
	int i;
	for(i = 0; i < 16; ++i){
		if(correct[i] == 0){
			return 0;
		}
	}
	return 1;
}

int calculus(){
	system("cls");

	printf("【星期一 上午 微積分】\n");
	PlaySound(TEXT("BellRing.wav"),NULL,SND_FILENAME|SND_ASYNC);
	_getch();
	printf("\n開學第一天~~~\n\n我和朋友一起到1019上課\n\n");
	_getch();
	printf("微積分即為危機分，我在開學第一天，她走進教室的瞬間就體會到了\n\n那個女孩體型纖細，容貌清秀，氣質文雅");
    _getch();
	printf("\n\n我剛剛玩的絕對神準理想型占卜一點也不準!我的理想型就是她!");
	PlaySound(TEXT("Tornado.wav"),NULL,SND_FILENAME|SND_ASYNC);
	_getch();
	
	FILE *fptr = fopen("calculus.txt", "r");
	char str[100] = "";
	fgets(str, sizeof(str), fptr);
	while(!feof(fptr)){
		puts(str);
		fgets(str, sizeof(str), fptr);
	}
	fclose(fptr);
	
	int choice = 0;
	printf("請輸入你的選擇:");
	scanf("%d", &choice);
	if(choice == 1){
		system("cls");
		PlaySound(TEXT("anscorrect.wav"),NULL,SND_FILENAME|SND_ASYNC);
//	    _getch();
		printf("答對了!");
		return 10;
	}else{
		system("cls");
		PlaySound(TEXT("answrong.wav"),NULL,SND_FILENAME|SND_ASYNC);
//	    _getch();
		printf("答錯了!");
		return 0;
	}
	
}
