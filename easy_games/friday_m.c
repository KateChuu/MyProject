#include <stdio.h>
#include <windows.h>

int lovelove;
int timer(void);

int friday_m(void){
	
	char choice, garbage;
	getch();
	system("cls");
	printf("\n\n\n【星期五 上午 計概實習課】\n");
	getch();
    printf("星期五早上10：10，"
	"是我跟我朋友一起去上計概實習的時間，"
	"我好想蹺課啊...。但是不行!!!我旁邊坐著她，而為了這短暫與她相處的時間，我今天一定要去上課!!!!\n\n");
	getch();
	printf("（走進教室坐下，看看左邊那個空空的位置）"
	"她還沒來嗎？唉...沒有她在的教室，真是一秒鐘也不想待，"
	"什麼時候才可以看到她的身影呢？我好想她啊...\n\n");
	getch();
	printf("（這時...從遠處傳來了嬉笑聲）"
	"她來了她來了!!!我今天一整天的快樂泉源終於來了，"
	"只要看到她，我覺得我又有用不完的精神，上十堂實習課都沒問題。\n\n");
	getch();
	printf("(崩潰的兩個小時程式地獄後)今天的實習課大概是我一生中最幸福的日子了，"
	"雖然我程式一個字也沒打出來(小聲)，"
	"但是!她因為沒帶電腦的關係跟我借了電腦!!!"
	"拜託，什麼借電腦，整台電腦送她我都願意。"
	"而且更令人開心的是!!!還發生了一件讓我心動不已的事情...\n\n");
	getch();
	printf("(回憶中)當我們都專注在自己電腦上的程式時，誰也沒注意到我和她的手肘漸漸互相靠近...\n\n");
	getch();
	PlaySound(TEXT("heartBeat.wav"),NULL,SND_FILENAME|SND_ASYNC);
	_getch();
	printf("我：嗚！對...對不起，我...我不是故意碰到妳的（啊啊啊啊不小心碰到了，我們之間突然有了心電感應>///<）\n\n");
	getch();
	printf("這時，戀愛之神又出現了，"
	"祂說：「想知道她心中所想嗎？那就接受我的挑戰吧!"
	"如果你(妳)預估的時間跟她心裡所想數字一樣，可以讓你(妳)跟她去海堤約會喔」\n"
	"【Y】接受挑戰\n" 
	"【N】唉唷好害羞喔\n");
	printf("？");
	scanf("%c", &garbage);
	scanf("%c", &choice);
	
	if(choice == 'Y' || choice == 'y'){ //選擇Y或y 
		timer();
		printf("\n\n(回憶結束)這次機會我一定要好好把握，不管如何，我都要說出我心中對她的感覺，我一定要把我的心意傳達給她！！\n");
	}
	else if(choice == 'N' || choice == 'n'){ //選擇N或n 
		printf("\n你(妳)失去了知道她是否有對你(妳)動心的機會(好感度-20)\n\n");
		getch();
		printf("(回憶結束)\n");
		lovelove = lovelove - 20;
		printf("你(妳)的好感度目前為: %d", lovelove);
	}
}
