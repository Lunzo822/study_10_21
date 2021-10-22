#include"game.h"

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
{
	int i = 0;
	int j = 0;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			board[i][j] = set;
		}
	}
}

void DisPlayBoard(char board[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;
	//打印列号
	for(i=0;i<=col;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for(i=1;i<=row;i++)
	{
		//打印行号
		printf("%d ",i);
		for(j=1;j<=col;j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS],int row,int col)
{
	int count = Easy_Count;
	while(count)
	{
		int x = rand()%row+1;		//生成1-9的坐标
		int y = rand()%col+1;
		//放置雷
		if(board[x][y] == '0')
		{
			board[x][y] = '#';
			count --;
		}
	}
}

//统计所输入坐标周围的雷
int get_mine_count(char mine[ROWS][COLS],int x,int y)		
{
	return mine[x-1][y+1]+		//左上角
		mine[x-1][y]+					//左边
		mine[x-1][y-1]+				//左下角
		mine[x][y-1]+					//下边
		mine[x+1][y-1]+				//右下角
		mine[x+1][y]+					//右边
		mine[x+1][y+1]+				//右上角
		mine[x][y+1]					//上边
		-8*'0';
}

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while(win<row*col - Easy_Count)
	{
		printf("请输入排查雷的坐标：>>>>");
		scanf("%d %d",&x,&y);
		if(x>=1 && x<=row && y >=1 && y<=col)
		{
			//坐标合法
			if(mine[x][y] == '#')		//踩雷了
			{
				printf("很遗憾，你被炸死了！！！\n");
				printf("\n");
				DisPlayBoard(mine,ROW,COL);
				printf("\n");
				printf("请开始新的游戏！！！\n");
				printf("\n");
				break;
			}
			else		//没有踩雷
			{
				//统计所输入坐标周围有几个雷
				int count = get_mine_count(mine,x,y);
				show[x][y] = count+'0';
				DisPlayBoard(show,ROW,COL);
				win++;
			}
		}
		else
		{
			printf("非法坐标，请重新输入！！！\n");
		}
	}
	if(win == row*col - Easy_Count)
	{
		printf("恭喜你，排雷成功！！！\n");
		printf("\n");
		DisPlayBoard(mine,ROW,COL);
		printf("\n");
		printf("即将进入新游戏，请等待... ...\n");
		printf("\n");
	}
}