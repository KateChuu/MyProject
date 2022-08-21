#include<stdio.h>
#include <windows.h>

int lovelove;
void GameGuessNum(void);

void dayThree(void){
	
	//宣告一個暫存使用者回覆的變數 
	char reply = NULL, garbage;
	
	//第二天(自言自語)
	getch();
	system("cls");
	printf("\n【星期二 上午 國文課】\n");
	printf("\n三個小時的國文課，少了她的早九真是令人提不起勁，不知道此刻她身在何處?\n是否也和我一樣正讀著余光中稱頌西子灣的詩，如果可以，我願成為只為她創作的詩人。\n");
	getch();
	//第三天早上(計概課) 
	PlaySound(TEXT("alarmClock.wav"),NULL,SND_FILENAME|SND_ASYNC);
    _getch();
	printf("\n【星期三 上午 計概課】\n");
	printf("\n糟糕!昨天打電動打太晚了，驚醒的時候看看時間...小考都結束了!!!\n");
    getch();
	printf("\n現在進教室也太尷尬了吧...\n");
	getch();
	printf("\n不管了!我已經超過24小時沒有見到她了，就算是在遠遠的地方看她幾眼也好。\n");
	getch();
	printf("\n(進教室後)\n天啊!今天也太多人來上課了吧!\n");
	getch();
	printf("\n(四處張望搜索座位，突然心跳漏了一拍)\n她還是一樣可愛呢~欸等等，她的旁邊那是...空位!!!!\n");
	getch();
	printf("\n天啊!還好今天有來!正當我歡喜至極、偷偷瞥向她一眼的時候，看見她的眉頭微微一蹙，原來是3051的網路又斷了。 \n");
	getch();
	printf("\n【進入遊戲】 \n網路小偷悄悄地把ip位址最後四碼改掉了，想取得正確的ip位址，就必須進入遊戲破解這組密碼!\n進入遊戲【Y】 與我何干【N】\n ");
	
	//讀取使用者回覆 
	scanf("%c", &garbage);
	scanf("%c", &reply);
	if(reply == 'y'|| reply == 'Y'){
//		GameGuessNum();
        printf("\n進入遊戲\n");
        GameGuessNum();
        reply = '\0';
	}
	else {
		printf("\n另一位同學馬上破解了密碼並且很謙虛地接受老師的表揚，你發現她用一種你從來看過的眼神注視著那位同學，心裡很不是滋味...\n");
		printf("\n好感度-20\n");
		lovelove-=20;
		printf("你(妳)的好感度目前為: %d\n\n", lovelove);
        reply = '\0';
	}
	
	//第三天下午(走去0052上會計實習的路上)
	getch();
	system("cls");
	printf("\n【星期三 下午 會計實習課】\n");
	printf("(走去0052的路上)\n");
	printf("\n唉…又要上魔鬼助教的實習課了，魔鬼助教加上地獄會計，能支持我繼續在這個空間裡的也就只有她了吧。\n") ;
	getch();
	printf("\n不知道她來上課了沒? 【Y】【N】\n ");
	scanf("%c", &garbage);
	scanf("%c", &reply);
	if(reply == 'y' || reply == 'Y'){
		PlaySound(TEXT("anscorrect.wav"),NULL,SND_FILENAME|SND_ASYNC);
//	    _getch();
		printf("\n答對了!她很準時的進了教室!\n好感度+5\n"); 
		lovelove+=5;
		printf("你(妳)的好感度目前為: %d\n\n", lovelove);
	}
	else if (reply == 'n' || reply == 'N'){
		PlaySound(TEXT("answrong.wav"),NULL,SND_FILENAME|SND_ASYNC);
//	    _getch();
		printf("\n答錯了!她很準時的進了教室!\n好感度-5\n");
		lovelove-=5;
		printf("你(妳)的好感度目前為: %d\n\n", lovelove);
	}
}
