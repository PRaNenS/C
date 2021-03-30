#include <stdio.h>

int main(void)
{
	int subwayArray[3];
	subwayArray[0] = 30;
	subwayArray[1] = 40;
	subwayArray[2] = 50;

	for (int i = 0; i < 3; i++)
	{
		printf("����ö %dȣ���� %d���� ž��\n", i + 1, subwayArray[i]);
	}

	// �� ����(���� �ʱ�ȭ�� �� �Ұ�!)
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}

	// �迭 ũ��� �׻� ����� ������ ��!(������ ���� ũ�� ���� �Ұ�)
	// int size = 10;
	// int arr[size];

	int arrA[3] = { 1, 2 }; // 3��°���ʹ� '0'�� �ڵ����� �ʱ�ȭ
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arrA[i]);
	}

	float arrF[5] = { 1.0f, 2.0f, 3.0f };
	for (int i = 0; i < 5; i++)
	{
		printf("%.2f\n", arrF[i]);
	}

	// ���� vs ���ڿ�
	char c = 'A';
	printf("%c\n", c);

	// ���ڿ� ������ '��'�� �ǹ��ϴ� NULL���� '\0'�� ���ԵǾ�� ��
	char str[7] = "coding";
	printf("%s\n", str);

	char codingStr[] = "coding";
	printf("%d\n", sizeof(str));

	for (int i = 0; i < sizeof(str); i++)
	{
		printf("%c\n", str[i]);
	}

	char kor[] = "�����ڵ�";
	printf("%s\n", kor);
	printf("%d\n", sizeof(kor)); // �����ڵ�(8byte) + NULL����(1byte) = 9byte
	// ���� 1����: 1byte
	// �ѱ� 1����: 2byte
	// �ѱ�
	// En gl is h
	// char ũ��: 1byte

	char cArray[7] = { 'c','o','d', 'i', 'n','g','\0' };
	printf("%s\n", cArray);

	char codingArray[10] = { 'c','o','d', 'i', 'n','g' };
	printf("%s\n", codingArray); // coding

	for (int i = 0; i < sizeof(codingArray); i++)
	{
		printf("%d\n", codingArray[i]); // ASCII�ڵ尪 ���(null���� 0���� �Է�)
		// 99 111 100 105 110 103 0 0 0 0
	}

	// ����: ASCII�ڵ�? ANSI(�̱�ǥ����ȸ)���� ������ ǥ�� �ڵ� ü��
	// 7bit, �� 128�� �ڵ�(0~127)
	// a: 97(���� a�� �ƽ�Ű�ڵ� ������)
	// A: 65
	// 0: 48

	printf("%c\n", 'a');
	printf("%d\n", 'a');
	printf("%c\n", 'b');
	printf("%d\n", 'b');
	printf("%c\n", 'A');
	printf("%d\n", 'A');
	printf("%c\n", '\0');
	printf("%d\n", '\0');
	printf("%c\n", '0');
	printf("%d\n", '0');
	printf("%c\n", '1');
	printf("%d\n", '1');

	// ����2: 0~127������ �ƽ�Ű�ڵ� �������� �ش��ϴ� ���� Ȯ��
	for (int i = 0; i < 128; i++)
	{
		printf("�ƽ�Ű�ڵ� ���� %c : %d\n", i, i);
	}

	return 0;
}