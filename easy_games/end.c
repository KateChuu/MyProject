#include <stdio.h>
#include <windows.h>

int lovelove;

int end (void){
	
	printf("\n\n【星期五 晚上 海堤】\n");
	puts("經過了幾天的相處，你明白現在就是出擊的時候了....\n\n");
	getch();
	printf("遠遠地你看見她向你走來...");
	PlaySound(TEXT("light.wav"),NULL,SND_FILENAME|SND_ASYNC);
	_getch();
	puts("，白色的無袖上衣襯得她嬌滴滴的臉更加紅潤可人，我感覺到肚子裡有成千上萬隻蝴蝶在翩翩起舞。\n\n" 
		 "一陣海風拂過，空氣中夾帶著的除了大海的鹹味，還有她頭髮的香氣，"
		 "那一頭烏亮的秀髮散落在她的肩上，我明白自己早已對眼前的她無法自拔......\n\n ");
	printf("【點擊任意鍵清算好感度 進入結局】 \n\n");
	getch();
	printf("好感度 : %d\n\n", lovelove);
	getch(); 
	if(lovelove <= -69){
//		getch();
		PlaySound(TEXT("QQ.wav"),NULL,SND_FILENAME|SND_ASYNC);
		printf("【結局5】\n");
		
	    _getch();
		puts("「其實......我喜歡的是你的朋友ㄟ......我之所以坐在你旁邊不過就是為了可以接近他罷了!」\n");
		puts("「那...那次微積分的聊天呢?管理數學充滿閃光的對視呢?計概實習課的心跳加速呢? 」\n");
		puts("「那些都是為了能夠多看你朋友一眼啊!!不然你以為呢?」\n");
		puts("「怎麼會......」\n");
		puts("我第一次的愛情還未萌芽就已經枯萎了......。");
	}
	else if(lovelove <= 2 && lovelove >= -68){
//		getch();
		printf("【結局4】\n");
		PlaySound(TEXT("QQ.wav"),NULL,SND_FILENAME|SND_ASYNC);
	    _getch();
		puts("「謝謝你(妳)的喜歡，但是...不好意思!!!我已經有心儀的對象了!!」 \n");
		puts("「啊...是是嗎？那...我可以知道是誰嗎？」 \n");
		puts("「你(妳)還記得每次上課都陪我一起走的那個女生嗎？她就是我喜歡的人」\n");
		puts("「原...原來是這樣啊...」\n");
		puts("我居然沒有注意到她們兩人之間曖昧的小動作，以及她每次提到她時臉上揚起的甜蜜笑容，我真是太失敗了... ");
	}
	else if(lovelove <= 74 && lovelove >= 3){
//		getch();
		printf("【結局3】\n");
		PlaySound(TEXT("hebe.wav"),NULL,SND_FILENAME|SND_ASYNC);
	    _getch();
		puts("女孩感念你為她付出的一切，可是她還沒有準備好進入一段戀情... \n");
		puts("「我們...還是好朋友吧?」\n");
		puts("你看著眼前這張使你神魂顛倒的臉龐，勉強擠出一絲微笑 \n");
		puts("「當然囉~那明天見吧」");
	}
	else if(lovelove <= 146 && lovelove >= 75){
//		getch();
		printf("【結局2】\n");
		PlaySound(TEXT("aini.wav"),NULL,SND_FILENAME|SND_ASYNC);
	    _getch();
		puts("我鼓起勇氣告白了，女孩微笑著，害羞的點點頭。\n"
			 "我永遠忘不了在夕陽照耀下美麗動人的她，以及我牽起她的手時，她羞澀的臉龐。\n"
			 "我終於脫單了，戀愛之神謝謝你。\n");
	}
	else if(lovelove >= 147){
//		getch();
		printf("【結局1】\n");
		PlaySound(TEXT("destiny.wav"),NULL,SND_FILENAME|SND_ASYNC);
	    _getch();
		puts("你知道嗎?我其實在交叉查榜時就愛上你了喔..."
		"看到你的臉書頭像的那一眼一瞬間，我就已經深深沉淪，"
		"微積分向你搭話、會計課裝作很冷、計概課斷掉網路、會計實習說要去酒吧、計概實習碰你的手肘，"
		"全都是我的精心策畫，我是你愛情的俘虜，把我帶走吧!");
	}
	system("pause");
}
