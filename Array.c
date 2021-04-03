#include <stdio.h>

int main_array(void)
{
	int subwayArray[3];
	subwayArray[0] = 30;
	subwayArray[1] = 40;
	subwayArray[2] = 50;

	for (int i = 0; i < 3; i++)
	{
		printf("지하철 %d호차에 %d명이 탑승\n", i + 1, subwayArray[i]);
	}

	// 값 설정(값은 초기화를 꼭 할것!)
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}

	// 배열 크기는 항상 상수로 선언할 것!(변수를 통한 크기 설정 불가)
	// int size = 10;
	// int arr[size];

	int arrA[3] = { 1, 2 }; // 3번째부터는 '0'이 자동으로 초기화
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arrA[i]);
	}

	float arrF[5] = { 1.0f, 2.0f, 3.0f };
	for (int i = 0; i < 5; i++)
	{
		printf("%.2f\n", arrF[i]);
	}

	// 문자 vs 문자열
	char c = 'A';
	printf("%c\n", c);

	// 문자열 끝에는 '끝'을 의미하는 NULL문자 '\0'이 포함되어야 함
	char str[7] = "coding";
	printf("%s\n", str);

	char codingStr[] = "coding";
	printf("%d\n", sizeof(str));

	for (int i = 0; i < sizeof(str); i++)
	{
		printf("%c\n", str[i]);
	}

	char kor[] = "나도코딩";
	printf("%s\n", kor);
	printf("%d\n", sizeof(kor)); // 나도코딩(8byte) + NULL문자(1byte) = 9byte
	// 영어 1글자: 1byte
	// 한글 1글자: 2byte
	// 한글
	// En gl is h
	// char 크기: 1byte

	char cArray[7] = { 'c','o','d', 'i', 'n','g','\0' };
	printf("%s\n", cArray);

	char codingArray[10] = { 'c','o','d', 'i', 'n','g' };
	printf("%s\n", codingArray); // coding

	for (int i = 0; i < sizeof(codingArray); i++)
	{
		printf("%d\n", codingArray[i]); // ASCII코드값 출력(null문자 0으로 입력)
		// 99 111 100 105 110 103 0 0 0 0
	}

	// 참고: ASCII코드? ANSI(미국표준협회)에서 제시한 표준 코드 체계
	// 7bit, 총 128개 코드(0~127)
	// a: 97(문자 a의 아스키코드 정수값)
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

	// 참고2: 0~127사이의 아스키코드 정수값에 해당하는 문자 확인
	for (int i = 0; i < 128; i++)
	{
		printf("아스키코드 정수 %c : %d\n", i, i);
	}

	// 아빠는 대머리 프로젝트
	srand(time(NULL));
	printf("== 아빠는 대머리 ==\n\n");
	int answer; // 사용자 입력값
	int treatment = rand() % 4; // 발모제 선택(0~3)
	int cntShowBottle = 0; // 이번 게임에 보여줄 병 갯수
	int prevCntShowBottle = 0; // 앞 게임에 보여준 병 갯수
	// 서로 보여주는 병 갯수를 다르게 하여 정답률 향상 (처음에 2개 -> 다음엔 3개)

	// 3번의 기회
	for (int i = 1; i <= 3; i++)
	{
		int bottle[4] = { 0, 0, 0, 0 }; // 4개의 병
		do {
			cntShowBottle = rand() % 2 + 2; // 보여줄 병 갯수(0-1, +2, 2or3)
		} while (cntShowBottle == prevCntShowBottle);
		prevCntShowBottle = cntShowBottle;

		int isIncluded = 0; // 보여줄 병 중에 발모제가 포함되었는지 여부
		printf(" > %d 번째 시도 :", i);

		// 보여줄 병 종류를 선택
		for (int j = 0; j < cntShowBottle; j++)
		{
			int randBottle = rand() % 4; // 0~3

			// 아직 선택되지 않은 병이면, 선택 처리
			if (bottle[randBottle] == 0)
			{
				bottle[randBottle] = 1;

				if (randBottle == treatment)
				{
					isIncluded = 1;
				}
			}

			// 이미 선택된 병이면, 중복이므로 다시 선택
			else
			{
				j--;
			}
		}

		// 사용자에게 문제 표시
		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
			{
				printf("%d", k + 1);
			}
		}
		printf(" 물약을 머리에 바릅니다\n");

		if (isIncluded == 1)
		{
			printf(" >> 성공! 머리가 났어요!\n");
		}
		else
		{
			printf(" >> 실패! 머리가 나지 않았어요!\n");
		}
	}

	printf("\n발모제는 몇번일까요?");
	scanf_s("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("\n >> 정답입니다!\n");
	}
	else
	{
		printf("\n >> 땡! 틀렸어요. 정답은 %d 입니다\n", treatment + 1);
	}

	return 0;
}