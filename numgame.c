#include<stdio.h>
#include<conio.h>
#include<time.h>
void board_disp(int brd[][3])
{
	int i, j;
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<3; j++)
		{
			if (brd[i][j] != -5)
			{
				printf("\t  %d  ", brd[i][j]);
			}
			else
				printf("\t     ");
		}
		printf("\n");
	}
}
int check(int brd[][3], int mov)
{
	int i, j, i1, j1;
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<3; j++)
		{
			if (brd[i][j] == -5)
			{
				i1 = i;
				j1 = j;
			}
		}
	}
	if (mov == -4 && j1 - 1 >= 0)
	{
		return 1;
	}
	else if (mov == -2 && i1 + 1<3)
	{
		return 1;
	}
	else if (mov == -6 && j1 + 1<3)
	{
		return 1;
	}
	else if (mov == -8 && i1 - 1 >= 0)
	{
		return 1;
	}
	else
		return 0;
}
void swap(int brd[][3], int i, int j)
{
	int temp, i1, j1, rw, cl;
	for (i1 = 0; i1<3; i1++)
	{
		for (j1 = 0; j1<3; j1++)
		{
			if (brd[i1][j1] == -5)
			{
				rw = i1;
				cl = j1;
			}
		}
	}
	temp = brd[i][j];
	brd[i][j] = -5;
	brd[rw][cl] = temp;
}
void move(int brd[][3], int mov)
{
	int i, j, i1, j1;
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<3; j++)
		{
			if (brd[i][j] == -5)
			{
				i1 = i;
				j1 = j;
			}
		}
	}
	if (check(brd, mov))
	{
		if (mov == -4)
		{
			i = i1;
			j = j1 - 1;
			swap(brd, i, j);
		}
		else if (mov == -6)
		{
			i = i1;
			j = j1 + 1;
			swap(brd, i, j);
		}
		else if (mov == -8)
		{
			i = i1 - 1;
			j = j1;
			swap(brd, i, j);
		}
		else if (mov == -2)
		{
			i = i1 + 1;
			j = j1;
			swap(brd, i, j);
		}
	}
	else
		printf(" \n Wrong Selection ! \n ");
}
int win(int brd[][3])
{
	int i, j, cnt = 1;
	if (brd[0][0] == -5)
	{
		for (i = 0; i<3; i++)
		{
			for (j = 0; j<3; j++)
			{
				if (i == 0 && j == 0)
				{
					continue;
				}
				else if (brd[i][j] == cnt)
				{
					cnt++;
				}
			}
		}
		if (cnt == 9)
			return 1;
		else
			return 0;
	}
	else if (brd[2][2] == -5)
	{
		for (i = 0; i<3; i++)
		{
			for (j = 0; j<3; j++)
			{
				if (i == 2 && j == 2)
				{
					continue;
				}
				else if (brd[i][j] == cnt)
				{
					cnt++;
				}
			}
		}
		if (cnt == 9)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}
void main()
{
	int ch,ch1;
	int i, j, brd[3][3], rnd, mov;
	static int list_rand[9];
	time_t t;
	srand((unsigned)time(&t));
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<3; j++)
		{
			if (i == 2 && j == 2)
			{
				brd[i][j] = -5;
			}
			else if (i == 0 && j == 0)
			{
				rnd = rand() % 8 + 1;
				list_rand[rnd] = 1;
				brd[i][j] = rnd;
			}
			else
			{

				while (1)
				{
					rnd = rand() % 8 + 1;
					if (list_rand[rnd] == 1)
					{
						continue;
					}
					else
					{
						list_rand[rnd] = 1;
						brd[i][j] = rnd;
						break;
					}
				}
			}
		}
	}
	printf("\n \t  BOARD : \n");
	//board_disp(brd);
	do
	{
	cc:
		system("cls");
		board_disp(brd);
		printf("\n Press the arrow keys for the movements and  e : Exit\n");
		ch1 =_getch();
		ch = 0;
		if (ch1 == 0xE0)
		{ // a scroll key was pressed
			ch =_getch();
			fflush(stdin);
			switch (ch)
			{
			case 75:
				mov = -4;
				break;
			case 77:
				mov = -6;
				break;
			case 72:
				mov = -8;
				break;
			case 80:
				mov = -2;
				break;
			case 'e':
				exit(0);
			default:
				printf("\n Wrong Key pressed ! Try again !\n");
				goto cc;
			}
			move(brd, mov);
			board_disp(brd);
			if (win(brd))
			{
				printf("\n congrats winner \n ");
				getchar();
				exit(0);
			}
		}
	} while (ch != 'e');
	getchar();
}

