#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 10000
// 비밀번호를 입력 받아서
// 맞는 경우? 비밀 일기를 읽어와서 보여주고, 계속 작성하도록 합니다
// 틀린 경우? 경고 메세지를 표시하고 종료

int main(void)
{
	// fgets, fputs활용
	char line[MAX]; // 파일에서 불러온 내용을 저장할 변수
	char contents[MAX]; // 일기장에서 입력할 내용
	char password[20]; // 비밀번호 입력
	char c; // 비밀번호 입력 할 때 키값 확인용 (마스킹)

	printf("'비밀일기'에 오신 것을 환영합니다\n");
	printf("비밀번호를 입력하세요 : ");

	// getchar() / getch() 의 차이?
	// getchar() : 엔터를 입력받아야 동작
	// getch() : 키 입력시 바로 동작
	int i = 0;
	while (1)
	{
		c = _getch();
		if (c == 13) // Enter -> 비밀번호 입력 종료
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

	// 비밀번호 : 나도 코딩 skehzheld
	printf("\n\n===비밀번호 확인 중...===\n\n");
	if (strcmp(password, "skehzheld") == 0) // 비밀번호 일치
	{
		printf("===비밀번호 확인 완료===\n\n");
		char* fileName = "d:\\secretdiary.txt";
		FILE* file = fopen(fileName, "a+b"); // 파일이 없으면 생성, 파일이 있으면 append를 한다
		if (file == NULL)
		{
			printf("파일 열기 실패\n");
			return 1;
		}

		while (fgets(line, MAX, file) != NULL)
		{
			printf("%s", line);
		}
		printf("\n\n내용을 계속 작성하세요! 종료하시려면 EXIT를 입력하세요\n\n");

		while (1)
		{
			scanf("%[^\n]", contents); // 줄바꿈이 나오기 전까지 모든 문자열을 읽어옴(한 문장씩)
			getchar(); // ENTER 입력 (\n) Flush처리

			if (strcmp(contents, "EXIT") == 0)
			{
				printf("비밀일기 입력을 종료합니다\n\n");
				break;
			}
			fputs(contents, file);
			fputs("\n", file); // ENTER 를 위에서 무시 처리 하였으므로 임의로 추가
		}
		fclose(file);
	}
	else // 비밀번호가 틀렸을 경우
	{
		printf("===비밀번호가 틀렸어요===\n\n");
		printf("꺅! 당신 누구야? 감히 내 일기장을?\n");
	}

	return 0;
}