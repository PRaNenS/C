#include <stdio.h>

int main_loop(void)
{
	printf("Hello World\n");

	// ++(�ش� ���� +1)
	int a = 10;
	printf("a = %d\n", a);
	a++;
	printf("a = %d\n", a);

	int b = 20;
	printf("b = %d\n", ++b); // ++�� ���� �����Ͽ� 21�� ���
	printf("b = %d\n", b++); // 21�� ����ϰ� ++�� ����
	printf("b = %d\n", b); // 22

	// for
	for (int i = 1; i <= 10; i++)
	{
		printf("%d\n", i);
	}

	// while
	int i = 1;
	while (i <= 10)
	{
		printf("%d\n", i++);
	}

	// do while
	i = 1;
	do
	{
		printf("%d\n", i++);
	} while (i <= 10);

	// 2�� �ݺ���(������)
	for (int x = 2; x <= 9; x++)
	{
		for (int y = 1; y <= 9; y++)
		{
			printf("%d * %d = %d\n", x, y, x * y);
		}
	}

	/* �ϳ��� �÷����� ���
		*
		**
		***
		****
		*****
	*/
	for (int x = 1; x <= 5; x++)
	{
		for (int y = 1; y <= x; y++)
		{
			printf("*");
		}
		printf("\n");
	}

	/*
		     *
			**
		   ***
		  ****
		 *****
	*/
	for (int x = 0; x < 5; x++)
	{
		for (int y = x; y < 5 - 1; y++)
		{
			printf(" ");
		}
		for (int y = 0; y <= x; y++)
		{
			printf("*");
		}
		printf("\n");
	}

	/* �Ƕ�̵带 �׾ƶ�
	    *
	   ***
	  *****
	 *******
	*/
	int floor;
	printf("�� ������ �װڴ°�? >");
	scanf_s("%d", &floor);
	for (int x = 0; x < floor; x++)
	{
		for (int y = x; y < floor - 1; y++)
		{
			printf(" ");
		}
		for (int y = 0; y < x * 2 + 1 ; y++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}