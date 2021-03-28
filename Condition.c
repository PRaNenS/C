#include <stdio.h> // �⺻
#include <time.h> // �ð�
#include <stdlib.h> // ���̺귯��

int main_condition(void) // swich, if
{
	// ������ ź�ٰ� ����, �л�/�Ϲ���(20�� �̻�)���� ����
	int age;
	printf("���� > ");
	scanf_s("%d", &age);

	if (age >= 20)
	{
		printf("�Ϲ���\n");
	}
	else
	{
		printf("�л�\n");
	}

	// �ʵ��л�(8~13)/���л�(14~16)/����л�(17~19)�� ������?
	printf("���� > ");
	scanf_s("%d", &age);
	if (age >= 8 && age <= 13)
	{
		printf("�ʵ��л�\n");
	}
	else if (age >= 14 && age <= 16)
	{
		printf("���л�\n");
	}
	else if (age >= 17 && age <= 19)
	{
		printf("����л�\n");
	}
	else
	{
		printf("�л��ƴ�\n");
	}

	// swich
	printf("���� > ");
	scanf_s("%d", &age);
	switch (age)
	{
	case 8: printf("�ʵ��л�\n");
	case 9: printf("�ʵ��л�\n");
	case 10: printf("�ʵ��л�\n");
	case 11: printf("�ʵ��л�\n");
	case 12: printf("�ʵ��л�\n");
	case 13: printf("�ʵ��л�\n");
	case 14: printf("���л�\n");
	case 15: printf("���л�\n");
	case 16: printf("���л�\n");
	case 17: printf("����л�\n");
	case 18: printf("����л�\n");
	case 19: printf("����л�\n");
	default: printf("�л��ƴ�\n");  break;
	}

	// break / continue
	for (int i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10)
		{
			printf("������\n");
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
				printf("%d ����\n", i);
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
	printf("��(4��) > ");
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
		printf("���� ��� �ٸ�\n");
	}

	// Random
	srand(time(NULL)); // ���� �ʱ�ȭ
	int num = rand() % 3; // 0 ~ 2
	if (num == 0)
	{
		printf("����\n");
	}
	else if (num == 1)
	{
		printf("����\n");
	}
	else if (num == 2)
	{
		printf("��\n");
	}
	else
	{
		printf("��\n");
	}

	srand(time(NULL)); // ���� �ʱ�ȭ
	num = rand() % 3;
	switch (num)
	{
	case 0: printf("����\n"); break;
	case 1: printf("����\n"); break;
	case 2: printf("��\n"); break;
	default: printf("��"); break;
	}

	// Up and Down
	srand(time(NULL));
	num = rand() % 100 + 1; // 1 ~ 100
	printf("���� : %d\n", num);
	int answer = 0; // ����
	int chance = 5; // ��ȸ
	while (chance > 0)
	{
		printf("���� ��ȸ : %d\n", chance--);
		printf("����(1 ~ 100) > ");
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
			printf("����\n");
			break;
		}
		else
		{
			printf("����\n");
		}
		if (chance <= 0)
		{
			printf("���� ����\n");
		}
	}

	return 0;
}