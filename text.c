//扫雷游戏的实现

#include"game.h"

void menu()
{
	printf("********************************\n");
	printf("******       1.play       ******\n");
	printf("******       0.exit       ******\n");
	printf("********************************\n");
	printf("\n");
}

void game()
{
	//雷的信息存储
	//布置好的雷的信息
	char mine[ROWS][COLS] = {0};
	//排查过的雷的信息
	char show[ROWS][COLS] = {0};

	printf("扫雷游戏正式开始！！！\n");
	//初始化
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//打印棋盘
	//DisPlayBoard(mine,ROW,COL);
	printf("\n");
	DisPlayBoard(show,ROW,COL);
	//布置雷
	SetMine(mine,ROW,COL);
	printf("\n");
	//DisPlayBoard(mine,ROW,COL);		//打印雷盘
	//扫雷
	FindMine(mine,show,ROW,COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("进入模式选项，请输入：>>>>>>");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏，下次再见！！！\n");
			break;
		default:
			printf("模式选择错误，请重新输入！！！\n");
			break;
		}
	}while(input);
}

int main()
{
	test();

	return 0;
}