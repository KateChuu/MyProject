#include <stdio.h>
#include <windows.h>

int lovelove;

int thursday_n(void){
	
	int a1, a2, a3;
	getch();
	system("cls");
	printf("\n\n【星期四 晚上 網研】\n");
	printf("又是跟我朋友一起去上網研的日子，"
	"真不知道什麼時候才可以跟心儀的她一起去上呢？"
	"而且，這星期因為太忙沒有交糠哥上次出的作業，會不會被糠哥討厭啊？"
	"更重要的是，會不會被她以為我是不交作業的壞學生啊？"
	"啊啊啊好麻煩，早知道就不要來網研了，給我自己找麻煩，"
	"雖然可以看到她，但是我現在只擔心我好不容易建立起來的資優生形象會在她面前崩毀啊？"
	"不行！！！不能讓這種事情發生，等一下玩Kahoot的時候，我一定要好好表現給她看！\n\n");
	getch();
	printf("問題：請按照題目要求的順序寫出相應答案的編號\n\n");
	printf("題目：當前文件所在層級的上一層級 ---> 當前文件所在的層級 ---> 根目錄\n\n");
	PlaySound(TEXT("Kahoot.wav"),NULL,SND_FILENAME|SND_ASYNC);
	_getch();
	printf("選項 ：(1)./    (2)/    (3)../\n\n？");
	scanf("%d %d %d", &a1, &a2, &a3);
	
	if(a1 == 3 && a2 == 1 && a3 == 2){
		PlaySound(TEXT("anscorrect.wav"),NULL,SND_FILENAME|SND_ASYNC);
	    _getch();
		printf("\n恭喜答對！你（妳）好棒棒，讓她覺得你（妳）是就算不交作業成績還是很好的聰明學生（好感度+10）\n\n");
		lovelove = lovelove + 10;
		printf("你(妳)的好感度目前為: %d", lovelove);
	}
	else{
		PlaySound(TEXT("answrong.wav"),NULL,SND_FILENAME|SND_ASYNC);
	    _getch();
		printf("\n你（妳）答錯了！你（妳）並沒有登上排行榜的前三名，失去了重新建立優秀形象的機會（好感度-5）\n\n");
		lovelove = lovelove - 5;
		printf("你(妳)的好感度目前為: %d", lovelove);
	}
}
