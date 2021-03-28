#include <stdio.h>

int main(void)
{
	// 계산기
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
}

// Function(함수)
int p(int num)
{
	printf("num = %d\n", num);
	return num;
}