#include <stdio.h>
#include <time.h>

// ����Ⱑ 6���� �־��
// �̵��� ���׿� ��� �ִµ�, �縷�̿���
// �縷�� �ʹ� ������, �ʹ� �����ؼ� ���� ���� ���� ������ �ؿ�
// ���� �� �����ϱ� ���� �������� ���׿� ���� �༭ ����⸦ ����ּ���
// ������ �ð��� �������� ���� Ŀ���� ���߿��� �ȳ�..

int level;
int arrayFish[6];
int* cursor;

void initData();
void printFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main_project(void)
{
	long startTime = 0; // ���� ���� �ð�
	long totalElapsedTime = 0; // �� ��� �ð�
	long prevElapsedTime = 0; // ���� ��� �ð�(�ֱٿ� ���� �� �ð� ����)

	int num; // �� �� ���׿� ���� �ٰ���, ����� �Է�
	initData();

	cursor = arrayFish;

	startTime = clock(); // ���� �ð��� milSecond

	while (1)
	{
		printFishes();
		printf("�� �� ���׿� ���� �ֽðھ��? >");
		scanf_s("%d", &num);

		// �Է°� üũ
		if (num < 1 || num > 6)
		{
			printf("\n�Է°��� �߸��Ǿ����ϴ�\n");
			continue;
		}

		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // CLOCKS_PER_SEC => �и��� / 1000
		printf("�� ��� �ð�: %ld ��\n", totalElapsedTime);

		// ���� �� �� �ð� (���������� �� �� �ð�) ���ķ� �帥 �ð�
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("�ֱ� ��� �ð�: %ld ��\n", prevElapsedTime);

		// ������ ���� ���� (����)
		decreaseWater(prevElapsedTime);

		// ����ڰ� �Է��� ���׿� ���� �ش�
		// 1. ������ ���� 0�̸�? ���� ���� �ʴ´�
		if (cursor[num - 1] <= 0)
		{
			printf("%d �� ������ �̹� �׾����ϴ�\n", num);
		}

		// 2. ������ ���� 0�� �ƴ� ���? ���� �ְ�, 100�� ���� �ʴ��� üũ
		else if (cursor[num - 1] + 1 <= 100)
		{
			// ���� �ش�
			printf("%d�� ���׿� ���� �ش�\n", num);
			cursor[num - 1] += 1; // cursor[num - 1] = cursor[num - 1] + 1
		}

		// ������(20�ʸ��� �ѹ��� ����)
		if (totalElapsedTime / 20 > level - 1) // intŸ�Կ��� �Ҽ����� ����ó���� �� 0.9 = 0
		{
			level++; // ������
			printf(" *** �� ������ *** \n");

			if (level == 5)
			{
				printf("�����մϴ�! �ְ� ������ �޼��Ͽ����ϴ�!\n");
				exit(0);
			}
		}

		// ��� ����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0)
		{
			// ����Ⱑ ��� ����
			printf("��� ����� ����\n");
			exit(0);
		}
		else
		{
			// �ּ� 1���� �̻� �������
			printf("����Ⱑ ����־��!\n");
		}
		prevElapsedTime = totalElapsedTime;
		// ���� 10�� -> 15�� (5��: prevElapsedTime -> 15��) -> 25�� (10��)
	}

	return 0;
}

void initData()
{
	level = 1; // (���ӷ��� 1 ~ 5)
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; // ������ �� ���� (0~100)
	}
}

void printFishes()
{
	printf("%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);

	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n");
}

void decreaseWater(long elapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 3 * (int)elapsedTime);

		if (arrayFish[i] < 0)
		{
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
		{
			return 1;
		}
		return 0;
	}
}