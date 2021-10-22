#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define Easy_Count 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//ÉùÃ÷
void InitBoard(char board[ROWS][COLS],int rows,int cols,char set);
void DisPlayBoard(char board[ROWS][COLS],int row,int col);
void SetMine(char board[ROWS][COLS],int row,int col);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);