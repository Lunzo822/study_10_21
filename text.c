//ɨ����Ϸ��ʵ��

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
	//�׵���Ϣ�洢
	//���úõ��׵���Ϣ
	char mine[ROWS][COLS] = {0};
	//�Ų�����׵���Ϣ
	char show[ROWS][COLS] = {0};

	printf("ɨ����Ϸ��ʽ��ʼ������\n");
	//��ʼ��
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//��ӡ����
	//DisPlayBoard(mine,ROW,COL);
	printf("\n");
	DisPlayBoard(show,ROW,COL);
	//������
	SetMine(mine,ROW,COL);
	printf("\n");
	//DisPlayBoard(mine,ROW,COL);		//��ӡ����
	//ɨ��
	FindMine(mine,show,ROW,COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("����ģʽѡ������룺>>>>>>");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ���´��ټ�������\n");
			break;
		default:
			printf("ģʽѡ��������������룡����\n");
			break;
		}
	}while(input);
}

int main()
{
	test();

	return 0;
}