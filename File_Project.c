#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 10000
// ��й�ȣ�� �Է� �޾Ƽ�
// �´� ���? ��� �ϱ⸦ �о�ͼ� �����ְ�, ��� �ۼ��ϵ��� �մϴ�
// Ʋ�� ���? ��� �޼����� ǥ���ϰ� ����

int main(void)
{
	// fgets, fputsȰ��
	char line[MAX]; // ���Ͽ��� �ҷ��� ������ ������ ����
	char contents[MAX]; // �ϱ��忡�� �Է��� ����
	char password[20]; // ��й�ȣ �Է�
	char c; // ��й�ȣ �Է� �� �� Ű�� Ȯ�ο� (����ŷ)

	printf("'����ϱ�'�� ���� ���� ȯ���մϴ�\n");
	printf("��й�ȣ�� �Է��ϼ��� : ");

	// getchar() / getch() �� ����?
	// getchar() : ���͸� �Է¹޾ƾ� ����
	// getch() : Ű �Է½� �ٷ� ����
	int i = 0;
	while (1)
	{
		c = _getch();
		if (c == 13) // Enter -> ��й�ȣ �Է� ����
		{
			password[i] = '\0';
			break;
		}
		else
		{
			printf("*");
			password[i] = c;
		}
		i++;
	}

	// ��й�ȣ : ���� �ڵ� skehzheld
	printf("\n\n===��й�ȣ Ȯ�� ��...===\n\n");
	if (strcmp(password, "skehzheld") == 0) // ��й�ȣ ��ġ
	{
		printf("===��й�ȣ Ȯ�� �Ϸ�===\n\n");
		char* fileName = "d:\\secretdiary.txt";
		FILE* file = fopen(fileName, "a+b"); // ������ ������ ����, ������ ������ append�� �Ѵ�
		if (file == NULL)
		{
			printf("���� ���� ����\n");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL)
		{
			printf("%s", line);
		}
		printf("\n\n������ ��� �ۼ��ϼ���! �����Ͻ÷��� EXIT�� �Է��ϼ���\n\n");

		while (1)
		{
			scanf("%[^\n]", contents); // �ٹٲ��� ������ ������ ��� ���ڿ��� �о��(�� ���徿)
			getchar(); // ENTER �Է� (\n) Flushó��

			if (strcmp(contents, "EXIT") == 0)
			{
				printf("����ϱ� �Է��� �����մϴ�\n\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file); // ENTER �� ������ ���� ó�� �Ͽ����Ƿ� ���Ƿ� �߰�
		}
		fclose(file);
	}
	else // ��й�ȣ�� Ʋ���� ���
	{
		printf("===��й�ȣ�� Ʋ�Ⱦ��===\n\n");
		printf("��! ��� ������? ���� �� �ϱ�����?\n");
	}

	return 0;
}