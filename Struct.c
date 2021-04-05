#include <stdio.h>

struct GameInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // 연관업체
};

typedef struct {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // 연관업체
} GAME_INFO; // struct GameInformation을 GAME_INFO로 정의

int main_struct(void)
{
	// 게임출시
	// 이름: 나도게임
	// 발매년도: 2017년
	// 가격: 50원
	// 제작사: 나도회사

	// 또다른 게임출시
	// 이름: 너도게임
	// 발매년도: 2017년
	// 가격: 100원
	// 제작사: 너도회사

	// 구조체 사용
	struct GameInfo gameInfo;
	gameInfo.name = "나도게임";
	gameInfo.year = 2017;
	gameInfo.price = 50;
	gameInfo.company = "나도회사";

	// 구조체 출력
	printf("\n== 게임 출시 정보 ==\n");
	printf(" 게임명   : %s\n", gameInfo.name);
	printf(" 발매년도 : %d\n", gameInfo.year);
	printf(" 가격     : %d\n", gameInfo.price);
	printf(" 제작사   : %s\n", gameInfo.company);

	// 구조체를 배열처럼 초기화
	struct GameInfo gameInfo2 = { "너도게임", 2017, 100, "너도회사" };
	printf("\n== 게임 출시 정보 ==\n");
	printf(" 게임명   : %s\n", gameInfo2.name);
	printf(" 발매년도 : %d\n", gameInfo2.year);
	printf(" 가격     : %d\n", gameInfo2.price);
	printf(" 제작사   : %s\n", gameInfo2.company);

	// 구조체 배열
	struct GameInfo gameArray[2] = {
		{"나도게임", 2017, 50, "나도회사"},
		{"너도게임", 2017, 100, "너도회사"}
	};

	// 구조체 포인터
	struct GameInfo* gamePtr; // 미션맨
	gamePtr = &gameInfo;
	printf("\n== 미션맨 게임 출시 정보 ==\n");
	// printf(" 게임명   : %s\n", (*gamePtr).name);
	// printf(" 발매년도 : %d\n", (*gamePtr).year);
	// printf(" 가격     : %d\n", (*gamePtr).price);
	// printf(" 제작사   : %s\n", (*gamePtr).company);
	printf(" 게임명   : %s\n", gamePtr->name);
	printf(" 발매년도 : %d\n", gamePtr->year);
	printf(" 가격     : %d\n", gamePtr->price);
	printf(" 제작사   : %s\n", gamePtr->company);

	// 연관 업체 소개
	gameInfo.friendGame = &gameInfo2;
	printf("\n== 연관 업체의 게임 출시 정보 ==\n");
	printf(" 게임명   : %s\n", gameInfo.friendGame->name);
	printf(" 발매년도 : %d\n", gameInfo.friendGame->year);
	printf(" 가격     : %d\n", gameInfo.friendGame->price);
	printf(" 제작사   : %s\n", gameInfo.friendGame->company);

	// typedef
	// 자료형에 별명 지정
	int i = 1;
	typedef int 정수;
	typedef float 실수;
	정수 정수변수 = 3; // int 정수변수 = 3; 와 동일
	실수 실수변수 = 3.23f;
	printf("\n정수변수: %d, 실수변수: %.2f\n\n", 정수변수, 실수변수);

	typedef struct GameInfo 게임정보;
	게임정보 game1;
	game1.name = "한글게임";
	game1.year = 2015;

	GAME_INFO game2;
	game2.name = "한글게임2";
	game2.year = 2014;

	// struct GameInformation game3; // 해당 구조체의 경우 GameInformation을 정의하지 않았기에 사용불가
	// game3.name = "한글게임3";
}