#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

int length;
int bend_no;
int len;
char key;
int life;
int breakers = 1;
int lovelove;

// function declaration
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();


struct coordinate{
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;

coordinate head, bend[400], food, body[30];

// function main begins program execution

int snake(void){
	int score;
	printf("【星期一 下午 會計學】\n\n");
	printf("哲芬穿著裙子加涼鞋走進教室，一邊說著:「外面好熱喔!你們有沒有開冷氣啊?好熱喔!」接著把冷氣調到18度......\n\n");
   	getch();
   	printf("我看著女孩瑟瑟發抖、楚楚可憐故作堅強的樣子，使我的內心生起了想脫下外套給他的衝動，這時，戀愛之神出現了!!\n\n");
   	getch();
   	printf ("告訴我:若你能把我餵飽，我就將時間暫停，只有那女孩和你可以知道這中間發生了甚麼事，到時候...\n\n");
    getch();
    printf ("你想幹嘛就幹嘛喔~~~\n\n");
    getch();
    printf ("你願意接受挑戰嗎? (Y = 1 or N = 2)\n");
    
    char option;
    char key;
    scanf ("%d", &option);
    if (option == 1){
    	Print();
    	system("cls");
    	length = 5;
    	head.x = 25;
    	head.y = 20;
    	head.direction = RIGHT;
    	Boarder();
    	Food();  
    	bend[0] = head;
    	Move();   
    	score = length - 5;
    	if (score <= 4){
    		lovelove = lovelove + 10;
    		printf ("你(妳)的好感度目前為: %d\n\n", lovelove);
		} // end inner if
		else if (score >= 5 && score <= 9){
			lovelove = lovelove + 20;
			printf ("你(妳)的好感度目前為: %d\n\n", lovelove);
			printf ("(時間暫停中......)\n\n");
			getch();
			printf ("女孩看見那男孩，如王子般向她走來，怦然心動，心中對他的好感度又多了幾分。\n\n");
			getch();
		} // end inner else if
		else if (score >= 10){
			lovelove = lovelove + 30;
			printf ("你(妳)的好感度目前為: %d\n\n", lovelove);
			printf ("(時間暫停中......)\n\n");
			getch();
			printf ("女孩看見那男孩，如王子般向她走來，怦然心動，心中對他的好感度又多了幾分。\n\n");
			getch();
		} // end inner else if
    } // end outer if
	else if (option == 2){
    	printf ("你現在單身我真的不意外...\n\n"); 
    	lovelove = lovelove - 20;
    	printf ("你(妳)的好感度目前為: %d\n\n", lovelove);
	} // end outer else if
	
	printf ("這時，哲芬開始了她的板書時間，那有如藝術品一般的文字，讓大家看得眼花撩亂、頭暈目眩。\n\n");
	getch();
	printf ("「曼華小姐，不要睡覺!」\n\n");
	getch();
	printf ("「應付帳款是借還是貸?」\n\n");
	getch();
	printf ("這時戀愛之神又出現了，問我:\n\n");
	getch();
	printf ("你要回答嗎?答對可以加分喔~~ (Y = 1 or N = 2) \n");
	
	int ans;
	int choice;
	scanf("%d", &choice);
	if (choice == 1){
		printf ("你的答案是 (1)借(2)貸??\n");
		scanf ("%d", &ans);
		if (ans == 1){
			lovelove = lovelove - 10;
			PlaySound(TEXT("answrong.wav"),NULL,SND_FILENAME|SND_ASYNC);
//	        _getch();
			printf ("回答錯誤!!\n上課要專心!!\n\n"); 
		} // end inner if
		else if (ans == 2){
			PlaySound(TEXT("anscorrect.wav"),NULL,SND_FILENAME|SND_ASYNC);
//	        _getch();
			printf ("回答正確!!!\n\n");
			lovelove = lovelove + 10;
	    } // end inner else
	} // end outer if
	else if (choice == 2){
		lovelove = lovelove - 20;
		printf ("難怪你現在還...單身...\n\n");
	} // end outer else if
	printf ("你(妳)的好感度目前為: %d\n\n", lovelove);
} // end function main

// function definition
void Move()
{
    int a, i;
    do{
        Food();
        fflush(stdin);
        len = 0;
        for (i = 0; i < 30; i = i + 1){
            body[i].x = 0;
            body[i].y = 0;
            if (i == length){
            	break;
			} // end inner if
        } // end for
        Delay (length);
        Boarder ();
        if (head.direction == RIGHT){
        	Right();
		} // end if
        else if (head.direction == LEFT) {
        	Left();
		} // end else if
        else if (head.direction==DOWN){
        	Down();
		} // end else if
        else if (head.direction==UP){
        	Up();
		} // end else if
        ExitGame();
    }while (!kbhit() && breakers != 0);
    if(breakers == 0){
    	return 0;
	}
    a = getch();
    key = getch ();
    if ((key == RIGHT && head.direction != LEFT && head.direction != RIGHT) || (key == LEFT && head.direction != RIGHT && head.direction!=LEFT) || (key == UP && head.direction != DOWN && head.direction != UP) || (key == DOWN && head.direction != UP && head.direction != DOWN))
    {	
       	bend_no++;
        bend[bend_no] = head;
        head.direction = key;
        if (key == UP){
        	head.y = head.y - 1;
		} // end if
        if (key == DOWN){
        	head.y = head.y + 1;
		} // end if
        if (key == RIGHT){
        	head.x = head.x + 1;
		} // end if
        if(key == LEFT){
        	head.x = head.x - 1;
		} // end if
        Move();
    } // end outer if
    else {
        printf("\a");
        Move();
    } // end outer else
} // end move function

void gotoxy(int x, int y)
{
 	COORD coord;
 	coord.X = x;
 	coord.Y = y;
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
} // end gotoxy function

void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush (stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition (a, b);
} // end GotoXY function

void Down()
{
    int i;
    for(i = 0; i <= (head.y - bend[bend_no].y) && len < length; i++){
        GotoXY (head.x, head.y-i);
        if (len == 0){
        	printf("v");
		} // end inner if   
        else {
        	printf("*");
		} // end inner else
        body[len].x = head.x;
        body[len].y = head.y - i;
        len = len + 1;
    } // end for
    Bend ();
    if (!kbhit ()){
    	head.y = head.y + 1;
	} // end if      
} // end Down function 

void Delay(long double k)
{
    Score ();
    long double i;
    for(i = 0; i <= (10000000); i = i + 1);
} // end Delay function

void ExitGame()
{
    int i, check = 0;
    for (i = 4; i < length; i = i + 1){
        if (body[0].x == body[i].x && body[0].y == body[i].y){
            check = check + 1;   
        } // end inner if
        if (i == length || check != 0){
        	break;
		} // end inner if          
    } // end for
    if (head.x <= 10 || head.x >= 70 || head.y <= 10 || head.y >= 30 || check != 0){
        	int score;
            system("cls");
            printf ("遊戲結束!!\n\n");
            score = length - 5;
            printf ("Score : %d\n\n", score);
			breakers = 0;	
         // end else
    } // end outer if
} // end ExitGame function 

void Food()
{
    if (head.x == food.x && head.y == food.y){
        length = length + 1;
        time_t a;
        a = time(0);
        srand(a);
        food.x = rand() % 70;
        if (food.x <= 10){
        	food.x = food.x + 11;
		} // end inner if   
        food.y = rand() % 30;
        if (food.y<=10){
        	food.y = food.y + 11;
		} // end inner if       
    } // end outer if
    else if (food.x==0){
        food.x = rand() % 70;
        if (food.x <= 10){
        	food.x = food.x + 11;
		} // end inner if
        food.y = rand() % 30;
        if (food.y <= 10){
        	food.y = food.y + 11;
		} // end inner if     
    } // end else if
} // end Food function 

void Left()
{
    int i;
    for (i = 0; i <= (bend[bend_no].x - head.x) && len < length; i = i + 1){
        GotoXY((head.x+i),head.y);     
        if (len == 0){
        	printf("<");
		} // end inner if             
        else {
        	printf("*");
		} // end inner else
        body[len].x = head.x + i;
        body[len].y = head.y;
        len = len + 1;
    } // end for
    Bend();
    if (!kbhit()){
    	head.x = head.x - 1;
	} // end if
} // end Left function

void Right()
{
    int i;
    for (i = 0; i <= (head.x - bend[bend_no].x) && len < length; i = i + 1){
        body[len].x = head.x - i;
        body[len].y = head.y;
        GotoXY (body[len].x, body[len].y);
        if (len == 0){
        	printf(">");
		} // end inner if 
        else {
        	printf("*");
		} // end inner else
        len = len + 1;
    } // end for
    Bend();
    if (!kbhit()){
    	head.x = head.x + 1;
	} // end if
} // end Right function

void Bend()
{
    int i, j, diff;
    for (i = bend_no; i >= 0 && len < length; i = i - 1){
        if (bend[i].x == bend[i-1].x){
            diff = bend[i].y - bend[i - 1].y;
            if (diff < 0) {
                for (j = 1; j <= (-diff); j = j + 1){
                    body[len].x = bend[i].x;
                    body[len].y = bend[i].y + j;
                    GotoXY (body[len].x, body[len].y);
                    printf ("*");
                    len = len + 1;
                    if (len == length){
                    	break;
					} // end if           
                } // end for
			} // end inner if
            else if (diff > 0) {
            	for (j = 1; j <= diff; j = j + 1){
                    body[len].x = bend[i].x;
                    body[len].y = bend[i].y - j;
                    GotoXY (body[len].x, body[len].y);
                    printf ("*");
                    len = len + 1;
                    if (len == length){
                    	break;
					} // end if           
                } // end for
			} // end inner else if 
	    } // end outer if
        else if (bend[i].y == bend[i - 1].y){
            diff = bend[i].x - bend[i - 1].x;
            if (diff < 0){
            	for (j = 1; j <= (-diff) && len < length; j = j + 1){
                    body[len].x = bend[i].x+j;
                    body[len].y = bend[i].y;
                    GotoXY (body[len].x, body[len].y);
                    printf ("*");
                   	len = len + 1;
                   	if (len == length){
                   		break;
					} // end if
                } // end for
			} // end inner if   
            else if (diff > 0){
            	for (j = 1; j <= diff && len < length; j = j + 1){
                	body[len].x = bend[i].x - j;
                	body[len].y = bend[i].y;
                	GotoXY (body[len].x, body[len].y);
                	printf ("*");
                	len = len + 1;
                	if (len == length){
                		break;
					} // end if         
               	} // end for
			} // end inner else if 
        } // end outer else if
   	} // end for
} // end Bend function 

void Boarder()
{
   	system("cls");
   	int i;
   	GotoXY (food.x,food.y);   /*displaying food*/
    printf ("F");
   	for(i = 10; i < 71; i = i + 1){
       	GotoXY (i, 10);
        printf ("-");
       	GotoXY (i, 30);
        printf ("-");
   	} // end for
    for(i = 10; i < 31; i = i + 1){
       	GotoXY (10, i);
        printf ("|");
       	GotoXY (70, i);
       	printf ("|");
   	} // end for
} // end Boarder function
void Print()
{
   	//GotoXY(10,12);
   	printf("\n\n\t歡迎來到戀愛之神所創造的世界~(請按任意鍵繼續)\n");
   	getch();
   	system("cls");
   	printf("\t遊戲說明:\n");
   	printf ("\n-> 以上下左右的箭頭控制小精靈");
   	printf ("\n\n-> 每吃到一個食物就可以加一分，若分數大於6分即通過遊戲。");
   	printf ("\n\n-> 準備好了嗎?");
   	printf("\n\n請按任意鍵開始遊戲...");
   	if(getch()==27);
    
} // end Print function

int Score()
{
   	int score;
   	GotoXY (20, 8);
   	score = length - 5;
   	printf ("SCORE : %d", (length - 5));
   	score = length - 5;
   	return score;
} // end Score function

void Up()
{
   	int i;
   	for(i = 0; i <= (bend[bend_no].y - head.y) && len < length; i = i + 1){
       	GotoXY(head.x,head.y+i);
       	if (len == 0){
       		printf ("^");
		} // end inner if
       	else {
       		printf ("*");
		} // end inner else
       	body[len].x = head.x;
       	body[len].y = head.y + i;
       	len = len + 1;
   	} // end for
   	Bend();
   	if (!kbhit()){
   		head.y = head.y - 1;
	} // end if      
} // end Up function
