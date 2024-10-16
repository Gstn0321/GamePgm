#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#include <windows.h>

#define TIME_LIMIT 5

int intro_game(void);
void game_control(int n, int m);
void print_number(int n, int m, int cnt[]);
int find_num(int n,int cnt[]);
void check_result(int user, int answer, int cnt[]);
int restart_game(void);
int select_matrixsize(void);
int select_level(void);
void textcolor(int foreground,int background);

int main(void)
{
	system("cls");
	int intro_select;
	int matrix_size;
	int max_number;
	srand(time(NULL));
	intro_select = intro_game();
	if(intro_select == 1)
	{
		matrix_size = select_matrixsize();
		max_number = select_level();
		game_control(matrix_size,max_number);
	}
	else if (intro_select == 0)
	{
		system("cls");
		printf("3�� �� ������ ����˴ϴ�.\n");
		printf("GOOD BYE~~!\n");
		Sleep(3000);
		return 0;
	}
	else
	{
		textcolor(4,0);
		printf("���ڸ� �߸� �Է��ϼ̽��ϴ�!\n");
		textcolor(15,0);
		Sleep(3000);
		main();
	}
}


int intro_game(void)
{
	int tf;
	printf("������Ŀ� ��Ÿ�� ���� �߿���\n");
	printf("���� ���� ������ ���ڸ� ã�ƶ�!\n\n");
	printf("���ѽð��� 5���Դϴ�.\n\n");
	printf("1.���ӽ��� 0.�������� \n");
	scanf("%d", &tf);
	return tf;
}

void game_control(int n,int m)
{
	int restart;
	int cnt[10], answer, user;
	clock_t start, end;
	double pst;
	system("cls");
	print_number(n,m,cnt);
	answer = find_num(m,cnt);
	printf("\n\n");
	printf("����Ƚ���� ���� ���� ���� �Է�>");
	start = clock();
	while (!_kbhit())
	{
		end = clock();
		pst = (double)(end - start) / CLK_TCK;
		if (TIME_LIMIT < pst)
		{
			printf("\n���ѽð��� �Ѿ����ϴ�. \n");
			while (1)
			{
				Sleep(3000);
				system("cls");
				restart = restart_game();
				if (restart == 1)
				{
					main();
				}
				else if (restart == 0)
				{
					exit(0);
				}
				else
				{
					textcolor(4,0);
					printf("���ڸ� �߸� �Է��ϼ̽��ϴ�!\n");
					textcolor(15,0);
				}
			}
		}
	}
	user = _getch() - '0';
	printf("%d", user);
	check_result(user, answer, cnt);
	while (1)
	{
		printf("\n");
		restart = restart_game();
		if (restart == 1)
		{
			main();
		}
		else if (restart == 0)
		{
			exit(0);
		}
		else
		{
			textcolor(4,0);
			printf("���ڸ� �߸� �Է��ϼ̽��ϴ�!\n");
			textcolor(15,0);
		}
	}
}

void print_number(int n,int m, int cnt[])
{
	int i, j, r_num;
	for (i = 0; i < m; i += 1)
		cnt[i] = 0;
	for (i = 1; i <= n; i += 1)
	{
		for (j = 1; j <= n; j += 1)
		{
			r_num = rand() % m;
			cnt[r_num] += 1;
			printf("%d ", r_num);
		}
		printf("\n");
	}
}

int find_num(int n,int cnt[])
{
	int i, check, max_num = 0;
	for (i = 0; i < n; i += 1)
	{
		if (max_num <= cnt[i])
		{
			max_num = cnt[i];
			check = i;
		}
	}
	return check;
}

void check_result(int user, int answer, int cnt[])
{
	if (user == answer)
		printf("\n�¾ҽ��ϴ�. \n");
	else
		printf("\nƲ�Ƚ��ϴ�. \n");
	printf("��ȣ: %d, Ƚ�� : %d\n", answer, cnt[answer]);
}

int restart_game(void)
{
	int tf;
	Sleep(1000);
	printf("������ ����Ǿ����ϴ�. �ٽ� �õ��ϰڽ��ϱ�?\n");
	printf("1.�ٽý��� 0.��������\n");
	scanf("%d", &tf);

	return tf;
}

int select_matrixsize(void)
{
	int matrix_size;
	while (1)
	{
		system("cls");
		printf("����� ũ�⸦ �����մϴ�,\n");
		textcolor(4,0);
		printf("�ּ� ũ��� 3�Դϴ�. 3���� ū ���ڸ� �Է����ּ���.\n");
		textcolor(15,0);
		scanf("%d", &matrix_size);
		if (matrix_size < 3)
		{
			select_matrixsize();
		}
		else
		{
			return matrix_size;
		}
	}
}

int select_level(void)
{
	int level;
	int max_number;

	while (1)
	{
		system("cls");
		printf("���̵��� �����մϴ�.\n");
		printf("1.���̵�(��) 2.���̵�(��) 3.���̵�(��)\n");
		scanf("%d", &level);
		if (level == 1)
		{
			printf("���̵�(��)�� �����ϼ̽��ϴ�.\n");
			max_number = 5;
			return max_number;
		}
		else if (level == 2)
		{
			printf("���̵�(��)�� �����ϼ̽��ϴ�.\n");
			max_number = 8;
			return max_number;
		}
		else if (level == 3)
		{
			printf("���̵�(��)�� �����ϼ̽��ϴ�.\n");
			max_number = 10;
			return max_number;
		}
		else
		{
			textcolor(4,0);
			printf("���ڸ� �߸� �Է��ϼ̽��ϴ�!\n");
			textcolor(15,0);
		}
		Sleep(3000);
	}
}

void textcolor(int foreground,int background)
{
	int color=foreground+background*16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}

