//C���Ը�ϰ
//1.ʵ����������Ϸ
#include "game.h"
void menu()
{
	printf("************************\n");
	printf("******   1.play   ******\n");
	printf("******   0.exit   ******\n");
	printf("************************\n");
}
void game()
{
	char ret = '0';
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
			break;
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = CheckWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("���Ӯ!\n");
	else if (ret == '#')
		printf("����Ӯ!\n");
	else if (ret == 'Q')
		printf("ƽ��!\n");
}
void testfunc()
{
	int input = 0;
	srand((unsigned int)time(NULL));//�������ù�rand()ʹ�õ����������
	menu();
	printf("��ѡ��:>");
	scanf("%d", &input);
	do
	{
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (input);
}
int main()
{
	testfunc();
	system("pause");
	return 0;
}