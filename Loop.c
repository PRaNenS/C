#include <stdio.h>

int main(void)
{
	printf("Hello World\n");

	// ++(해당 값에 +1)
	int a = 10;
	printf("a = %d\n", a);
	a++;
	printf("a = %d\n", a);

	int b = 20;
	printf("b = %d\n", ++b); // ++를 먼저 실행하여 21을 출력
	printf("b = %d\n", b++); // 21을 출력하고 ++을 실행
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

	// 2중 반복문(구구단)
	for (int x = 2; x <= 9; x++)
	{
		for (int y = 1; y <= 9; y++)
		{
			printf("%d * %d = %d\n", x, y, x * y);
		}
	}

	/* 하나씩 늘려가며 출력
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

	return 0;
}