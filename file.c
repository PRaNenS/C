#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

int main_file(void)
{
	// 파일 입출력
	// 파일에 어떤 데이터를 저장
	// 파일에 저장된 데이터를 불러오기

	// fputs, fgets
	// char line[MAX]; // char line[10000]
	// FILE* file = fopen("d:\\test1.txt", "rb"); // r-읽기전용, w-쓰기전용, a-이어쓰기, t-텍스트, b-바이너리

	// if (file == NULL)
	// {
	//	printf("파일 열기 실패\n");
	//	return 1;
	// }

	// 파일쓰기
	// fputs("fputs를 이용해서 글을 적어볼게요\n", file);
	// fputs("잘 적히는지 확인해주세요\n", file);

	// 파일읽기
	// while (fgets(line, MAX, file) != NULL)
	// {
	//		printf("%s", line);
	// }

	// 파일을 열고 나서 닫지 않은 상태에서 어떤 프로그램에 문제가 생기면?
	// 데이터 손실 발생 가능! 그래서 항상 파일은 닫아주는 습관을 들여주세요
	// fclose(file);

	// fprintf, fscanf
	int num[6] = { 0,0,0,0,0,0 }; // 추첨번호
	int bonus = 0;
	char str1[MAX];
	char str2[MAX];
	/* FILE* file = fopen("d:\\test2.txt", "wb");

	if (file == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}
	fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);

	fscanf(file, "%s %d", str2, &bonus);
	printf("%s %d\n", str2, bonus);

	fclose(file);

	return 0; */

	//// 로또 추첨 번호 저장
	//fprintf(file, "%s %d %d %d %d %d %d\n", "추첨번호: ", 1, 2, 3, 4, 5, 6);
	//fprintf(file, "%s %d\n", "보너스번호: ", 7);

	//fclose(file);

	// 파일읽기
	FILE* file = fopen("d:\\test2.txt", "rb");

	if (file == NULL)
	{
		printf("파일 열기 실패\n");
		return 1;
	}

	fscanf(file, "%s %d %d %d %d %d %d", str1, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
	printf("%s %d %d %d %d %d %d\n", str1, num[0], num[1], num[2], num[3], num[4], num[5]);

	fscanf(file, "%s %d", str2, &bonus);
	printf("%s %d\n", str2, bonus);

	fclose(file);

	return 0;
}