#include <stdio.h>
#include <windows.h>

int lovelove;
int math (void){
	getch();
	system("cls");
	printf("【星期四 上午 管理數學】\n\n");
	printf ("正當我還沉浸在昨晚的愛心消夜時\n\n");
	getch();
	printf ("耳邊突然響起她和她好朋友輕快的笑聲\n\n");
	getch();
	printf ("她們踏著輕快的腳步走進教室\n\n");
	getch();
	printf ("我抬頭想看看她，卻不想...\n\n");
	getch();
	printf ("她也正在看我，我們眼中彷彿有電流在閃動。\n\n");
	PlaySound(TEXT("zzz.wav"),NULL,SND_FILENAME|SND_ASYNC);
	getch();
	printf ("這時，老師踏著從容的步伐走進教室，打斷了我們甜蜜的對視，她直接坐在我身旁的位置上，我們相視一笑。\n\n\n");
	getch();
	printf ("淯程開始了他的數學奇幻之旅，但我們卻被他出色的外表所吸引\n\n");
	getch();
	printf ("我和女孩相視，心中不約而同地想起一個人，他是\n\n");
	getch();
	printf ("1.偶像練習生的李榮浩\n2.青春有你2的Jony J\n3.創造營2020的毛不易\n\n");
//	getch();
	int ans;
	scanf ("%d", &ans);
	if (ans == 1){
		PlaySound(TEXT("model.wav"),NULL,SND_FILENAME|SND_ASYNC);
	    _getch();
		printf ("恭喜答對!!!\n\n");
		lovelove = lovelove + 20;
	}
	else if (ans == 2){
		PlaySound(TEXT("eggyellow.wav"),NULL,SND_FILENAME|SND_ASYNC);
	    _getch();
		printf ("QQ 答錯了~");
		lovelove = lovelove - 10;
	}
	else if (ans == 3){
		PlaySound(TEXT("answrong.wav"),NULL,SND_FILENAME|SND_ASYNC);
	    _getch();
		printf ("QQ 答錯了~");
		lovelove = lovelove - 10;
	}
	printf ("你(妳)的好感度目前為: %d\n\n", lovelove); 
	
}
