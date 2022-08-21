// 記得main()要改成int game_bomb(int game) 
// 失敗game = 0, 成功game = 1
/************ 宵夜時間_地雷 ************/
// 9: bomb 10:邊邊 
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> //---------------------> system(cls)

// 遊戲面板大小 
#define ROW 7
#define COLUMN 4
// 包括邊框的 
#define BIGROW (ROW + 2) 
#define BIGCOLUMN (COLUMN + 2)
// 地雷有幾個 
#define BOMB 5

typedef struct table{
	int element; // 格子代表的值 
	int ifopen; // 1: 開過了 或 應該要開還沒開 0: 還沒開  2:因為記號才開 
}Table;

// function
void makeTable(int counter, Table [][BIGCOLUMN], int [], int [], int [], int []); // 遊戲面板 
int randomNumber(int range); // 隨機變數 
void setElement(Table [][BIGCOLUMN], int []); // 設置每一格的數值，過後不再變 
void input(int [], int [], int []); // input
void correctInput(int [], int [], int []); // check if input is in the range of the table
void aroundElement(int row, int column, Table [][BIGCOLUMN], int []); // 周圍8格 等等!剛才是Table [][COLUMN]嗎? 
void aroundOpen(int row, int column, Table [][BIGCOLUMN], int []); // 開啟旁邊連帶的格子 



// main
int game_bomb(int game){
	/************ 事前處理 ************/
	Table table[BIGROW][BIGCOLUMN];
	int eight[8] = {0};	

	// 將table內全reset 0
	int i = 0, j = 0;
	for(i; i < BIGROW; ++i){
		// column
		for(j = 0; j < BIGCOLUMN; ++j){
			table[i][j].element = 0;
			table[i][j].ifopen = 0;
		}
	}	
	
	/************ 遊戲開始 ************/ 
	/***** player input *****/
	int dig[1] = {0}, rowInput[1] = {0}, columnInput[1] = {0}, breaker = 1;
	int counter = 0; // 做了多少次 
	makeTable(counter, table, rowInput, columnInput, dig, eight);
	
	// debug print show all element
	i = 0; j = 0;
	for(i; i < BIGROW; ++i){
		for(j = 0; j < BIGCOLUMN; ++j){
			printf("%3d", table[i][j].element);
		}
		printf("\n");
	}
	i = 0; j = 0;
	for(i; i < BIGROW; ++i){
		for(j = 0; j < BIGCOLUMN; ++j){
			printf("%3d", table[i][j].ifopen);
		}
		printf("\n");
	}
	// end debug print
	
	input(dig, rowInput, columnInput);
	
	for(counter = 1; breaker == 1; ){
		/***** react to input *****/
		switch(dig[0]){
			// dig: 1: 開挖 2: 做記號 3: 解除記號 
			case 1:
				// condition1: is bomb
				if(table[rowInput[0]][columnInput[0]].element == 9){
					makeTable(counter, table, rowInput, columnInput, dig, eight);
					system("cls");
					printf("<<GAME OVER>>\n");// ----------------------->扣分100 
					sleep(5);
					breaker = 0; // ----------------------------->遊戲結束 
				}
				// condition2: not bomb
				else if(table[rowInput[0]][columnInput[0]].element != 9){
					table[rowInput[0]][columnInput[0]].ifopen == 1;
					makeTable(counter, table, rowInput, columnInput, dig, eight);
					
					// debug print show all element
					i = 0; j = 0;
					for(i; i < BIGROW; ++i){
						for(j = 0; j < BIGCOLUMN; ++j){
							printf("%3d", table[i][j].element);
						}
						printf("\n");
					}
					i = 0; j = 0;
					for(i; i < BIGROW; ++i){
						for(j = 0; j < BIGCOLUMN; ++j){
							printf("%3d", table[i][j].ifopen);
						}
						printf("\n");
					}
					// end debug print
					
					counter++;
					/***** 遊戲結束 *****/
					// 除了地雷以外都打開了 
					i = 1; j = 1;
					int complete = 0;
					for(i; i <= ROW; ++i){
						for(j = 0; j <= COLUMN; ++j){
							if(table[i][j].ifopen == 1 || table[i][j].element == 9){
								++complete;
							}
						}
					} 
					if(complete == ROW * COLUMN){
						system("cls");
						printf("<<COMPLETE>>\n"); // -------------------->加分 
						sleep(5);
						breaker = 0; // --------------------------->遊戲結束 
					}else{
						input(dig, rowInput, columnInput);
					}
				}
				break;
			
			// 做記號 
			case 2:
				makeTable(counter, table, rowInput, columnInput, dig, eight); 
				input(dig, rowInput, columnInput);
				break;
				
			// 解除記號 
			case 3:
				makeTable(counter, table, rowInput, columnInput, dig, eight);
				input(dig, rowInput, columnInput);
				break;
			default:
				break;
		} // end switch 
	} // end for
	
	return 0; // end game_bomb
} // end main

/************* function區 ************/

// 遊戲面板
void makeTable(int counter, Table table[][BIGCOLUMN], int row[], int column[], int dig[], int eight[]){
	system("cls");
	// 遊戲開始
	int row_bomb = 0, column_bomb = 0;
/**********************************還沒input過***************************************************/	
	if(counter == 0){
		// 創造地雷 
		int b = 1;
		for(b; b <= BOMB; ++b){
			row_bomb = randomNumber(ROW); 
			column_bomb = randomNumber(COLUMN);
			// 已經是地雷
			if(table[row_bomb][column_bomb].element == 9){
				b -= 1;
			}else{ // 還不是 
				table[row_bomb][column_bomb].element = 9;	
			}
		}
		
		// 為中間遊戲面板設置數值 (!!不會再變!!) 
		setElement(table, eight);
		
		// 印面板 
		// row
		int i = 0, j = 0, k = 0, h = 1;
		// search every element
		for(i; i < BIGROW; ++i){
			// column
			for(j = 0; j < BIGCOLUMN; ++j){
				// 印邊緣的提示數字 
				if(i == 0){
					if(k != 0){
						if(j == COLUMN + 1){ // 右邊那排邊框 
							table[i][j].element = 10; // 10代表邊界 
						}else{
							printf("%3d", k);
							table[i][j].element = 10;	
						}
					}
					else if(k == 0){
						printf("   ");
						table[i][j].element = 10;
					}
					++k;
				}
				else if(j == 0){
					if(i == ROW + 1){ // 下面那排邊框 
						table[i][j].element = 10;
					}else{
						printf("%3d", h);
						table[i][j].element = 10;
					}
					++h;
				}
				else if(i == ROW + 1 || j == COLUMN + 1){ // 右邊+下那排邊框 
					table[i][j].element = 10;
				}
				// 結束印邊緣的提示數字
				// 以上印的都只是邊界 && 用邊界(10)把遊戲面板圍起來 
				else if(i!= ROW + 1 && j != COLUMN + 1){
					printf("  *");	
				}
			}
			printf("\n");
		} // end for
	} // end if
/*********************************第一次input後*********************************************/	
	else if(counter == 1){
		int i = 0, j = 0, k = 0, h = 1;
		if(dig[0] == 1){ // 開挖才要!! 
			aroundOpen(row[0], column[0], table, eight);
		}
		
		for(i; i < ROW + 1; ++i){
			for(j = 0; j < COLUMN + 1; ++j){
				if(i == 0){ // 要印旁邊的1234框框 
					if(k == 0){
						printf("   ");
					}
					else{
						printf("%3d", k);
					}
					++k;
				}
				else if(j == 0){ // 也是要印框框 
					printf("%3d", h);
					++h;
				}
				// 印完框框了 
				
				// 到了我選的格子了 
				else if(i == row[0] && j == column[0]){
					// 開挖 
					if(dig[0] == 1){
						table[row[0]][column[0]].ifopen = 1; 
						printf("   ");
					}
					// 記號 
					else if(dig[0] == 2){
						table[row[0]][column[0]].ifopen = 2; //專屬於做記號的2 
						printf("  -");
					}
					//解除記號 
					else if(dig[0] == 3){
						table[row[0]][column[0]].ifopen = 0;// 唯一會把ifopen變回0的部分 
						printf("  *");
					}
				}
				// 早就開了的 
				else if(table[i][j].ifopen == 1){
					if(table[i][j].element == 0){
						printf("   ");
					}else{
						printf("%3d", table[i][j].element);
					}
				}
				// not dig
				else if(table[i][j].ifopen == 2){
					printf("  -");
				}
				// 從沒開過的 
				else{
					printf("  *");
				}
			}
			printf("\n");
		} // end for
	} // end else if
/********************************之後的input************************************************/	
	// 不是第一次開了 
	else{
		int i = 0, j = 0, k = 0, h = 1;
		if(dig[0] == 1 && table[row[0]][column[0]].element == 0){ // 開挖and挖開的是0才要!! 
			aroundOpen(row[0], column[0], table, eight);
		}
		for(i; i < ROW + 1; ++i){
			for(j = 0; j < COLUMN + 1; ++j){
				if(i == 0){ // 繼續印框框 
					if(k == 0){
						printf("   ");
					}
					else{
						printf("%3d", k);
					}
					++k;
				}
				else if(j == 0){
					printf("%3d", h);
					++h;
				} // 以上是印框框
				 
				// 到了我選的格子了 
				else if(i == row[0] && j == column[0]){
					// 開挖 
					if(dig[0] == 1){
						if(table[i][j].element == 0){
							table[row[0]][column[0]].ifopen = 1; 
							printf("   ");
						}else{
							table[row[0]][column[0]].ifopen = 1;
							printf("%3d", table[i][j].element);
						}
					}
					// 記號 
					else if(dig[0] == 2){
						table[row[0]][column[0]].ifopen = 2;
						printf("  -");
					}
					//解除記號 
					else if(dig[0] == 3){
						table[row[0]][column[0]].ifopen = 0;// 唯一會把ifopen變回0的部分 
						printf("  *");
					}
				}
				// 早就開了的 
				else if(table[i][j].ifopen == 1){
					if(table[i][j].element == 0){
						printf("   ");
					}else{
						printf("%3d", table[i][j].element);
					}
				}
				// not dig
				else if(table[i][j].ifopen == 2){
					printf("  -");
				}
				// 從沒開過的 
				else if(table[i][j].element != 10){
					printf("  *");
				}
			}
			printf("\n");
		} // end for
	} // else
} // end function makeTable

// 隨機變數 1 ~ range
int randomNumber(int range){
	srand(time(NULL));
	return rand() % range + 1;
} // end function randomNumber

// 設定每格數值，訂好就不變了!! 
void setElement(Table table[][BIGCOLUMN], int eight[]){
	int i = 1, j = 1, k = 0, nBomb = 0;
	
	// search every element
	for(i; i <= ROW; ++i){
		for(j = 1; j <= COLUMN; ++j){
			// 如果那格不是bomb 
			if(table[i][j].element != 9){
				aroundElement(i, j, table, eight); // 偵測旁邊8格的數值 
				// search every eight(eight 就是周邊8格歐) 
				for(k = 0; k < 8; ++k){
					if(eight[k] == 9){
						++nBomb; // 若是旁邊有一個bomb，就++ 
					} // end if 
				} // end for
				if(nBomb == 0){ //旁邊沒有bomb 
					table[i][j].element = 0;
				}else{ // 幾個bomb，數值就多少 
					table[i][j].element = nBomb;
					nBomb = 0;	
				} // end if
			} // end outer if
		} // end for
	} // end search every element
} // end function setElement

// Input position
void input(int dig[], int row[], int column[]){
	// reset(debug)
	dig[0] = 1;
	row[0] = 1;
	column[0] = 1;  
	
	printf("1: 開挖 2: 做記號 3: 解除記號\nEnter: ");
	scanf("%d", dig);
	correctInput(dig, row, column);
	
	printf("輸入座標");
	printf("\nrow: ");
	scanf("%d", row);
	correctInput(dig, row, column);
	
	printf("column: ");
	scanf("%d", column); 
	correctInput(dig, row, column);
} // end function input

// Check if input is in the range of the table
void correctInput(int dig[], int row[], int column[]){
		
	// condition1: dig is ^1 || ^2 || ^3
	if(dig[0] != 1 && dig[0] != 2 && dig[0] != 3){
		printf("<<無效選項，請重新輸入>>\n\n");
		input(dig, row, column);
	}
	
	// condition2: row too large
	if(row[0] > ROW){
		printf("<<row 超出範圍，請輸入新座標>>\n\n");
		input(dig, row, column);
	}
	
	// condition3: column too large
	if(column[0] > COLUMN){
		printf("<<column 超出範圍，請輸入新座標>>\n\n");
		input(dig, row, column);
	}
} // end function correctInput

// 偵測某格周圍的數值 
void aroundElement(int row, int column, Table table[][BIGCOLUMN], int eight[]){
	eight[0] = table[row - 1][column - 1].element; // 左上 
	eight[1] = table[row - 1][column].element; // 上 
	eight[2] = table[row - 1][column + 1].element; // 右上 
	eight[3] = table[row][column - 1].element; // 左 
	eight[4] = table[row][column + 1].element; // 右 
	eight[5] = table[row + 1][column - 1].element; // 左下 
	eight[6] = table[row + 1][column].element; // 下 
	eight[7] = table[row + 1][column + 1].element; // 右下 
} // end function aroundElement

/*** 開啟附近的格子 ***/
void aroundOpen(int row, int column, Table table[][BIGCOLUMN], int eight[]){
	aroundElement(row, column, table, eight); // --------------->segmental fault ?!!! 
	int k = 0;
	// search旁邊的格子(eight)，從左上開始 
	for(k = 0; k <= 7; ++k){
		// 如果旁邊的格子不是邊緣(10) 且如果是記號的話也不開 
		if((row > 0 && row < ROW + 1) && (column > 0 && column < COLUMN + 1) && table[row][column].ifopen != 2){
			if(eight[k] == 0){
				// 如果開的是0的話 
				// recursive 
					switch(k){
						// 左上 
						case 0:  
							if(table[row - 1][column - 1].ifopen == 1){
								continue;
							}else{
								table[row - 1][column - 1].ifopen = 1; // 開起來 
								aroundOpen(row - 1, column - 1, table, eight); // 以左上為主角繼續開 
								break;
							} 
							
						// 上 
						case 1:
							if(table[row - 1][column].ifopen == 1){
								continue;
							}else{
								table[row - 1][column].ifopen = 1;
							    aroundOpen(row - 1, column, table, eight);
							    break;
							}
	
						// 右上 
						case 2:
							if(table[row - 1][column + 1].ifopen == 1){
								continue;
							}else{
								table[row - 1][column + 1].ifopen = 1;
							    aroundOpen(row - 1, column + 1, table, eight);
							    break;
							}
							
						// 左 
						case 3:
							if(table[row][column - 1].ifopen == 1){
								continue;
							}else{
								table[row][column - 1].ifopen = 1;
							    aroundOpen(row, column - 1, table, eight);
							    break;
							}
							
						// 右 
						case 4:
							if(table[row ][column + 1].ifopen == 1){
								continue;
							}else{
								table[row][column + 1].ifopen = 1;
							    aroundOpen(row, column + 1, table, eight);
							    break;
							}
							
						// 左下 
						case 5:
							if(table[row + 1][column - 1].ifopen == 1){
								continue;
							}else{
								table[row + 1][column - 1].ifopen = 1;
							    aroundOpen(row + 1, column - 1, table, eight);
							    break;
							}
							
						// 下 
						case 6:
							if(table[row + 1][column].ifopen == 1){
								continue;
							}else{
								table[row + 1][column].ifopen = 1;
							    aroundOpen(row + 1, column, table, eight);
							    break;
							}
							
						// 右下 
						case 7:
							if(table[row + 1][column + 1].ifopen == 1){
								continue;
							}else{
								table[row + 1][column + 1].ifopen = 1;
							    aroundOpen(row + 1, column + 1, table, eight);
							    break;
							}
							
					} // end inner switch
				// end case 0
			}
			else if(eight[k] == 9 || eight[k] == 10){
				// do nothing
			}
			else{
				// 旁邊的是數字就一樣打開，但到此為止
				switch(k){
					// 左上 
					case 0:  
						table[row - 1][column - 1].ifopen = 1; // 開起來 
						break;
					// 上 
					case 1:
						table[row - 1][column].ifopen = 1;
						break;
					// 右上 
					case 2:
						table[row - 1][column + 1].ifopen = 1;
						break;
					// 左 
					case 3:
						table[row][column - 1].ifopen = 1;
						break;
					// 右 
					case 4:
						table[row][column + 1].ifopen = 1;
						break;
					// 左下 
					case 5:
						table[row + 1][column - 1].ifopen = 1;
						break;
					// 下 
					case 6:
						table[row + 1][column].ifopen = 1;
						break;
					// 右下 
					case 7:
						table[row + 1][column + 1].ifopen = 1;
						break;
				} // end switch
			} // end else
		} // end if
	} // end for
} // end function aroundOpen
