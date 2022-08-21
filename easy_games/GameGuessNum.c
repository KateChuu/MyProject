#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
#define SIZE 4


void getRandNum( int a[]);

int lovelove;

//主要遊戲 
void GameGuessNum(void){

	//自動設定密碼 
	int ans[SIZE] = {0,9,8,5};
	getRandNum(ans); //利用function把密碼存入ans陣列 
	
	//印出遊戲規則
	FILE *file = fopen("rule.txt","r");
	char rule[200];
	while(!feof(file)){
		memset(rule, 0, sizeof(rule));
		fgets(rule, sizeof(rule) - 1, file);
		printf("%s",rule);
	}
	fclose(file);
	printf("\n");

	//開始遊戲
	
	
	int temp = 0; //暫存使用者輸入的數 
	int count = 0;
	int a, b, c, d; //玩家輸入的 千、百、十、個 位數 
	int num[4] = {0}; //將四個數字存入陣列 

	
	printf("請輸入四個數字(數字不可重複): ");
	scanf("%d", &temp);
	a = temp / 1000;
	b = temp % 1000 / 100;
	c = temp % 1000 % 100 / 10;
	d = temp % 1000 % 100 % 10;
	num[0] = a;
	num[1] = b;
	num[2] = c;
	num[3] = d;
	
	while (1){
		
		count++;
		//判斷有幾個A 
		int i = 0;
	    int count_a = 0; //計算A的個數
	    int arr_a[4] = {99,99,99,99}; //暫存A的值 
    	for(i = 0; i < 4; i++){
		    if(num[i] == ans[i]){
			    count_a ++;
			    arr_a[i] = num[i];
		    }
	    }

	
	    //判斷有幾個 B 
        int n = 0, l = 0;
	    int count_b = 0; //計算B的個數
	    int arr_b[4] = {99}; //暫存B的值 
    	for(n = 0; n < 4; n++){
	    	for(l = 0; l < 4; l++){
		    	if(num[n] == ans[l] && n != l){
		    		count_b++;
			    	arr_b[n] = num[n];
		    	}
	    	}
    	}

	
	//印出幾 A 幾 B 和 A 的值 
        printf("%d A %d B : ", count_a, count_b);
	    int j = 0;
    	for(j = 0; j < 4; j++){
		    if(arr_a[j] != 99){
			    printf("%d ",arr_a[j]);
	    	}
    	} 
    	if(count_a == 4){
    		PlaySound(TEXT("ding_wav.wav"),NULL,SND_FILENAME|SND_ASYNC);
//	        Sleep(50000);
	        _getch();
		    printf("恭喜猜中!");
		    break; //猜中就跳出迴圈 
	    }      
	    puts("");
	    
	    printf("請輸入四個數字(數字不可重複): ");
    	scanf("%d", &temp);
	    a = temp / 1000;
    	b = temp % 1000 / 100;
    	c = temp % 1000 % 100 / 10;
    	d = temp % 1000 % 100 % 10;
    	num[0] = a;
	    num[1] = b;
	    num[2] = c;
    	num[3] = d;
    } //end while 還沒猜中
    
    printf("\n總共猜了%d次", count);
    //根據猜的次數結算分數 
    if(count<=5){
    	lovelove+=30;
    	printf("你(妳)的好感度目前為: %d\n\n", lovelove);
	}
	else if(count>5 && count<=7){
		lovelove+=20;
		printf("你(妳)的好感度目前為: %d\n\n", lovelove);
	}
	else if(count>7 && count<=10){
		lovelove+=10;
		printf("你(妳)的好感度目前為: %d\n\n", lovelove);
	}
	else{
		lovelove-=10;
		printf("你(妳)的好感度目前為: %d\n\n", lovelove);
	}
//	return 0;
} //end GameGuessNum

//取得不重複的隨機四個數字 
void getRandNum(int n[]){
	int i, j;	
	srand(time(NULL));
	for (i = 1; i <= SIZE; i++){
		do{
			n[i-1] = rand() % 10 ;
			for(j = 1; j < i; j++){
				if(n[i-1] == n[j-1]){
					break;
				}
			}
		}while(j!=i);
	}
}
