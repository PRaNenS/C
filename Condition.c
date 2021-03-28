#include <stdio.h> // 기본
#include <time.h> // 시간
#include <stdlib.h> // 라이브러리

int main_condition(void) // swich, if
{
	// 버스를 탄다고 가정, 학생/일반인(20살 이상)으로 구분
	int age;
	printf("나이 > ");
	scanf_s("%d", &age);

	if (age >= 20)
	{
		printf("일반인\n");
	}
	else
	{
		printf("학생\n");
	}

	// 초등학생(8~13)/중학생(14~16)/고등학생(17~19)로 나누면?
	printf("나이 > ");
	scanf_s("%d", &age);
	if (age >= 8 && age <= 13)
	{
		printf("초등학생\n");
	}
	else if (age >= 14 && age <= 16)
	{
		printf("중학생\n");
	}
	else if (age >= 17 && age <= 19)
	{
		printf("고등학생\n");
	}
	else
	{
		printf("학생아님\n");
	}

	// swich
	printf("나이 > ");
	scanf_s("%d", &age);
	switch (age)
	{
	case 8: printf("초등학생\n");
	case 9: printf("초등학생\n");
	case 10: printf("초등학생\n");
	case 11: printf("초등학생\n");
	case 12: printf("초등학생\n");
	case 13: printf("초등학생\n");
	case 14: printf("중학생\n");
	case 15: printf("중학생\n");
	case 16: printf("중학생\n");
	case 17: printf("고등학생\n");
	case 18: printf("고등학생\n");
	case 19: printf("고등학생\n");
	default: printf("학생아님\n");  break;
	}

	// break / continue
	for (int i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10)
		{
			printf("나머지\n");
			break;
		}
		printf("%d\n", i);
	}

	for (int i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10)
		{
			if (i == 7)
			{
				printf("%d 제외\n", i);
				continue;
			}
			printf("%d\n", i);
		}
	}

	// (and)&& (or)||
	int a;
	int b;
	int c;
	int d;
	printf("값(4개) > ");
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	if (a == b && c == d)
	{
		printf("a == b and c == d\n");
	}
	else if (a == b || c == d)
	{
		printf("a == b or c == d\n");
	}
	else
	{
		printf("값이 모두 다름\n");
	}

	// Random
	srand(time(NULL)); // 난수 초기화
	int num = rand() % 3; // 0 ~ 2
	if (num == 0)
	{
		printf("가위\n");
	}
	else if (num == 1)
	{
		printf("바위\n");
	}
	else if (num == 2)
	{
		printf("보\n");
	}
	else
	{
		printf("모름\n");
	}

	srand(time(NULL)); // 난수 초기화
	num = rand() % 3;
	switch (num)
	{
	case 0: printf("가위\n"); break;
	case 1: printf("바위\n"); break;
	case 2: printf("보\n"); break;
	default: printf("모름"); break;
	}

	// Up and Down
	srand(time(NULL));
	num = rand() % 100 + 1; // 1 ~ 100
	printf("숫자 : %d\n", num);
	int answer = 0; // 정답
	int chance = 5; // 기회
	while (chance > 0)
	{
		printf("남은 기회 : %d\n", chance--);
		printf("숫자(1 ~ 100) > ");
		scanf_s("%d", &answer);

		if (answer > num)
		{
			printf("DOWN\n");
		}
		else if (answer < num)
		{
			printf("UP\n");
		}
		else if (answer == num)
		{
			printf("정답\n");
			break;
		}
		else
		{
			printf("오류\n");
		}
		if (chance <= 0)
		{
			printf("게임 종료\n");
		}
	}

	return 0;
}