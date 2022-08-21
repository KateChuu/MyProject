/************ 宵夜劇情 *************/
#include <stdio.h>
#include <windows.h>

int lovelove;

int supper(){
	getch();
	system("cls");
	printf("【星期三 晚上】\n\n");
	PlaySound(TEXT("alarmClock.wav"),NULL,SND_FILENAME|SND_ASYNC);
	printf("21:49...\n");
	getch();
	printf("只是躺了一下，怎麼就可以吃宵夜了...\n");
	getch();
	printf("啊!實習課時聽到她要和朋友去酒吧...\n");
	getch();
	printf("我買點滷味去跟她巧遇好了!\n");
	getch();
	
	system("cls");
	printf("【抓住她的胃】\n\n");
	getch();
	printf("我是戀愛之小精靈XD\n");
	getch();
	printf("要躲避女神討厭吃的東西\n");
	getch();
	printf("就跟踩地雷遊戲一樣\n");
	getch();
	printf("小精靈踩地雷教學:\n");
	getch();
	printf("step1: 選擇一個格子，分別輸入要1.開挖 2.做記號 3.解除記號\n");
	getch();
	printf("step2: 先輸入列數(Enter)再輸入行數(Enter)\n");
	getch();
	printf("格子裡出現的數字就是格子周圍有的地雷數喔!\n");
	getch();
	printf("一起躲避女神的雷點吧!FIGHTING!\n");
	printf("請按任意鍵抓住她的胃...\n");
	printf("loading...\n");
	getch();
	
	// game over = 0; complete = 1;
	int game = 0;
	game = game_bomb(game);
	
	if(game == 0){
		lovelove -= 30;
		printf("你(妳)的好感度目前為: %d\n\n", lovelove); // --------------------------------------------------->-30
		
		int choice = 0; // 1: yes; 2: no;
		printf("一把香菜破壞了滷味的平衡，也破壞了她的味蕾\n\n<<要再玩一次嗎?>>\n\n");
		printf("(1: yes 2: no)\n");
		printf("Enter the number: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\n人生是沒有第二次機會的\n");
				getch();
				printf("但你可以求我小精靈\n\n<<求小精靈?>>\n\n");
				int secondChoice = 0;
				printf("(1: yes 2: 早就跪好了)\n");
				printf("Enter the number: ");
				scanf("%d", &secondChoice);
				game = game_bomb(game);
				
				// 失敗 
				if(game == 0){
					// 勉強求了小精靈 
					if(secondChoice == 1){
						lovelove += 10; // ------------------------------------>+10
					}
					// 早就跪了小精靈 
					else if(secondChoice == 2){
						lovelove += 20; // ------------------------------------>+20
					}
					
					printf("為何還是要夾香菜?!!\n");
					getch();
					printf("但看在你求了本小精靈的份上...");
					getch();
					printf("幫你去掉一些香菜...\n");
					getch();
					printf("你(妳)的好感度目前為: %d\n\n", lovelove);
					printf("女孩: 哼!我要跟喜歡香菜的人切八段!\n");
					printf("埋怨香菜的她也好可愛...\n\n\n");
				}
				break;
			case 2:
				printf("女孩: 哼!我要跟喜歡香菜的人切八段!\n");
				printf("埋怨香菜的她也好可愛...\n\n\n");
				break;
			default:
				break; 
		} // end switch
	}
	else if(game == 1){
		lovelove += 30;
		printf("你(妳)的好感度目前為: %d\n\n", lovelove); // ------------------------------------------------->+30
		
		int choice = 0;
		printf("女孩: 哇!這家滷味好好吃喔!\n");
		printf("女孩: 你要不要吃點杏鮑菇?\n\n");
		printf("(1: yes 2: no)\n");
		printf("Enter the number: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				lovelove += 10;
				printf("你(妳)的好感度目前為: %d\n\n", lovelove); // ----------------------------------------->+10
				
				printf("\n女孩: 啊!叉子只有一支耶...\n");
				printf("女孩: 你不介意口水吧!\n");
				printf("女: 來!啊----------\n\n");
				printf("(原地幸福死)\n");
				break;
			case 2:
				lovelove += 20;
				printf("你(妳)的好感度目前為: %d\n\n", lovelove); // ----------------------------------------->+20
				
				printf("\n女孩: 恩...真可惜...\n");
				printf("女孩: (一臉幸福地把所有杏鮑菇送入口)");
				printf("女孩: 呵呵!多謝款待!\n\n");
				printf("(原地幸福死)\n");
				break;
			default:
				break;
		} // end switch
	} // end else
} // end supper
