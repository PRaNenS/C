#include <stdio.h>
#include <time.h>

// ����
int p(int num);
void function_without_return();
int function_with_return();
void function_with_param(int num1, int num2, int num3);
int apple(int total, int ate);
int add(int num1, int num2);
int sub(int num1, int num2);
int mul(int num1, int num2);
int div(int num1, int num2);
int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main_function(void)
{
	// ����
	int num = 2;
	num = p(num); // 2

	// 2 + 3?
	num = p(num + 3); // 5

	// 5 - 1?
	num = p(num - 1); // 4

	// 4 * 3?
	num = p(num * 3); // 12

	// 12 / 6?
	num = p(num / 6); // 2

	function_without_return();
	int value = function_with_return(10);
	num = p(value);
	function_with_param(10, 20, 30);
	printf("total: %d ��, ate: %d ��, ret: %d ��\n", 10, 4, apple(10, 4));
	num = add(3, 2);
	p(num);
	p(sub(10, 4));
	p(mul(2, 3));
	p(div(10, 2));

	// ���� 5��, �� ������ ����� ���� ��� ����
	// ������ ���, Ʋ���� ����
	srand(time(NULL));
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		// x * y = ?
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		showQuestion(i, num1, num2);

		int answer = -1;
		scanf_s("%d", &answer);

		if (answer == -1)
		{
			printf("���α׷� ����\n");
			break;
		}
		else if (answer == num1 * num2)
		{
			// ����
			success();
			count++;
		}
		else
		{
			// ����
			fail();
		}
	}
	printf("�� ���� ����: %d", count);

	return 0;
}

// Function(�Լ�)
int p(int num)
{
	printf("num = %d\n", num);
	return num;
}

void function_without_return()
{
	printf("��ȯ���� ���� �Լ�\n");
}

int function_with_return()
{
	printf("��ȯ�� �ִ� �Լ�\n");
	return 10;
}

void function_with_param(int num1, int num2, int num3)
{
	printf("���ް� �ִ� �Լ�(%d, %d, %d)\n", num1, num2, num3);
}

int apple(int total, int ate)
{
	return total - ate;
}

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}
int mul(int num1, int num2)
{
	return num1 * num2;
}
int div(int num1, int num2)
{
	return num1 / num2;
}

int getRandomNumber(int level)
{
	return rand() % (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2)
{
	printf("%d ��° ��й�ȣ\n", level);
	printf("%d * %d = ?\n", num1, num2);
	printf("��й�ȣ�� �Է��ϼ��� (����: -1) > ");
}

void success()
{
	printf(">> GOOD ����!\n");
}

void fail()
{
	printf(">> BAD ����!\n");
}