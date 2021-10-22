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
	//��ӡ�к�
	for(i=0;i<=col;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for(i=1;i<=row;i++)
	{
		//��ӡ�к�
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
		int x = rand()%row+1;		//����1-9������
		int y = rand()%col+1;
		//������
		if(board[x][y] == '0')
		{
			board[x][y] = '#';
			count --;
		}
	}
}

//ͳ��������������Χ����
int get_mine_count(char mine[ROWS][COLS],int x,int y)		
{
	return mine[x-1][y+1]+		//���Ͻ�
		mine[x-1][y]+					//���
		mine[x-1][y-1]+				//���½�
		mine[x][y-1]+					//�±�
		mine[x+1][y-1]+				//���½�
		mine[x+1][y]+					//�ұ�
		mine[x+1][y+1]+				//���Ͻ�
		mine[x][y+1]					//�ϱ�
		-8*'0';
}

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while(win<row*col - Easy_Count)
	{
		printf("�������Ų��׵����꣺>>>>");
		scanf("%d %d",&x,&y);
		if(x>=1 && x<=row && y >=1 && y<=col)
		{
			//����Ϸ�
			if(mine[x][y] == '#')		//������
			{
				printf("���ź����㱻ը���ˣ�����\n");
				printf("\n");
				DisPlayBoard(mine,ROW,COL);
				printf("\n");
				printf("�뿪ʼ�µ���Ϸ������\n");
				printf("\n");
				break;
			}
			else		//û�в���
			{
				//ͳ��������������Χ�м�����
				int count = get_mine_count(mine,x,y);
				show[x][y] = count+'0';
				DisPlayBoard(show,ROW,COL);
				win++;
			}
		}
		else
		{
			printf("�Ƿ����꣬���������룡����\n");
		}
	}
	if(win == row*col - Easy_Count)
	{
		printf("��ϲ�㣬���׳ɹ�������\n");
		printf("\n");
		DisPlayBoard(mine,ROW,COL);
		printf("\n");
		printf("������������Ϸ����ȴ�... ...\n");
		printf("\n");
	}
}