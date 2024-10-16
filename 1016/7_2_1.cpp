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
		printf("3초 뒤 게임이 종료됩니다.\n");
		printf("GOOD BYE~~!\n");
		Sleep(3000);
		return 0;
	}
	else
	{
		textcolor(4,0);
		printf("숫자를 잘못 입력하셨습니다!\n");
		textcolor(15,0);
		Sleep(3000);
		main();
	}
}


int intro_game(void)
{
	int tf;
	printf("정방행렬에 나타난 숫자 중에서\n");
	printf("가장 많이 출현한 숫자를 찾아라!\n\n");
	printf("제한시간은 5초입니다.\n\n");
	printf("1.게임시작 0.게임종료 \n");
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
	printf("출현횟수가 가장 많은 숫자 입력>");
	start = clock();
	while (!_kbhit())
	{
		end = clock();
		pst = (double)(end - start) / CLK_TCK;
		if (TIME_LIMIT < pst)
		{
			printf("\n제한시간을 넘었습니다. \n");
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
					printf("숫자를 잘못 입력하셨습니다!\n");
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
			printf("숫자를 잘못 입력하셨습니다!\n");
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
		printf("\n맞았습니다. \n");
	else
		printf("\n틀렸습니다. \n");
	printf("번호: %d, 횟수 : %d\n", answer, cnt[answer]);
}

int restart_game(void)
{
	int tf;
	Sleep(1000);
	printf("게임이 종료되었습니다. 다시 시도하겠습니까?\n");
	printf("1.다시시작 0.게임종료\n");
	scanf("%d", &tf);

	return tf;
}

int select_matrixsize(void)
{
	int matrix_size;
	while (1)
	{
		system("cls");
		printf("행렬의 크기를 선택합니다,\n");
		textcolor(4,0);
		printf("최소 크기는 3입니다. 3보다 큰 숫자를 입력해주세요.\n");
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
		printf("난이도를 설정합니다.\n");
		printf("1.난이도(하) 2.난이도(중) 3.난이도(상)\n");
		scanf("%d", &level);
		if (level == 1)
		{
			printf("난이도(하)를 설정하셨습니다.\n");
			max_number = 5;
			return max_number;
		}
		else if (level == 2)
		{
			printf("난이도(중)를 설정하셨습니다.\n");
			max_number = 8;
			return max_number;
		}
		else if (level == 3)
		{
			printf("난이도(상)를 설정하셨습니다.\n");
			max_number = 10;
			return max_number;
		}
		else
		{
			textcolor(4,0);
			printf("숫자를 잘못 입력하셨습니다!\n");
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

