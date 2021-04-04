#include <stdio.h>

void swap(int a, int b);
void swap_addr(int* a, int* b);
void changeArray(int* ptr);

int main_pointer(void)
{
	// 포인터(가리킨다 즉, 자체의 값이 어디를 가리키는 것)
	// [철수] : 101호
	// [영희] : 201호
	// [민수] : 301호

	int chulsu = 1;
	int younghee = 2;
	int minsu = 3;

	printf("철수네 주소 : %d, 암호 : %d\n", &chulsu, chulsu);
	printf("영희네 주소 : %d, 암호 : %d\n", &younghee, younghee);
	printf("민수네 주소 : %d, 암호 : %d\n", &minsu, minsu);

	// 미션
	int* missionMan; // 포인터 변수
	missionMan = &chulsu;
	printf("미션맨이 방문하는 주소 : %d, 암호 : %d\n", missionMan, *missionMan);
	// *(역참조 연산자) missionMan에 저장된 주소값에 접근, 즉 chulsu를 가리킴

	// 두번째 미션: 각 암호에 3을 곱해라
	missionMan = &chulsu;
	*missionMan = *missionMan * 3;
	printf("미션맨이 암호를 바꾼 주소 : %d, 암호 : %d\n", missionMan, *missionMan);

	// 스파이
	// 미션맨이 바꾼 암호에서 2를 뺌
	int* spy = missionMan; // missionMan이 chulsu의 주소값이기에 spy도 chulsu의 주소값을 가짐
	printf("스파이가 미션 수행중\n");
	spy = &chulsu;
	*spy = *spy - 2;
	printf("스파이가 방문하는 곳 주소: %d, 암호 %d\n", spy, *spy);

	// *missionMan(주소값: 1, 실제 값: 2) = chulsu(주소값: 2, 실제값: 100)와 같은 셈
	// missionMan과 spy의 주소값은 또 다르다
	printf("미션맨의 주소: %d\n", &missionMan);
	printf("스파이의 주소: %d\n", &spy);

	int* numptr;
	int num = 10;


	// 배열(포인터적용)
	int arr[3] = { 5, 10, 15 };
	int* ptr = arr; // *ptr이 arr(배열의 처음 주소값)을 가리킴

	for (int i = 0; i < 3; i++)
	{
		printf("배열 arr[%d]의 값: %d\n", i, arr[i]); // 3 5 10
	}
	for (int i = 0; i < 3; i++)
	{
		printf("포인터 ptr[%d]의 값: %d\n", i, ptr[i]); // *ptr[(각 포인터의 주소값, 각각의 arr을 가리키는 주소값)]
	}
	// 즉, ptr(100, 200, 300)[1000, 2000, 3000] =>
	//     arr(1000, 2000, 3000)[5, 10, 15]

	ptr[0] = 100; // arr[0] = 100
	ptr[1] = 200; // arr[1] = 200
	ptr[2] = 300; // arr[2] = 300

	for (int i = 0; i < 3; i++)
	{
		printf("배열 arr[%d]의 값: %d\n", i, arr[i]);
		printf("배열 arr[%d]의 값: %d\n", i, *(arr + i)); // arr의 처음 주소값 + i번째에 접근 = arr[i]
	}
	for (int i = 0; i < 3; i++)
	{
		printf("포인터 ptr[%d]의 값: %d\n", i, ptr[i]);
		printf("포인터 ptr[%d]의 값: %d\n", i, *(ptr + i)); // ptr의 처음 주소값 + i번째에 접근 = arr[i]
	}

	// *(arr + i) == arr[i] 똑같은 표현
	// arr == arr배열의 첫번째 값의 주소와 동일 == &arr[0]
	printf("arr 자체의 값: %d\n", arr);
	printf("arr[0]의 주소: %d\n", &arr[0]);
	printf("arr 자체의 값이 가지는 주소의 실제 값: %d\n", *arr); // *(arr + 0)
	printf("arr[0]의 실제 값: %d\n", *&arr[0]); // &는 주소, *는 주소의 값 == *&는 상쇄
	printf("arr[1]의 주소값: %d\n", arr + 1);

	// SWAP
	int a = 10;
	int b = 20;
	printf("a의 주소: %d\n", &a);
	printf("b의 주소: %d\n", &b);

	// a와 b의 값을 바꾼다
	printf("SWAP 함수 전 => a: %d, b: %d\n", a, b);
	swap(a, b);
	printf("SWAP 함수 후 => a: %d, b: %d\n", a, b);

	// 값에 의한 복사 (Call by Value) -> 값만 복사한다는 의미

	// 주소값을 넘긴다면?
	printf("(주소값 전달)SWAP 함수 전 => a: %d, b: %d\n", a, b);
	swap_addr(&a, &b);
	printf("(주소값 전달)SWAP 함수 후 => a: %d, b: %d\n", a, b);

	// 배열일때, arr2 => 주소
	int arr2[3] = { 10, 20, 30 };
	changeArray(arr2); // 배열일때 주소값을 전달 즉, changeArray(&arr2[0])와 동일
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", arr2[i]);
	}

	// scanf에서 해당 값에 &을 넣은 이유?
	// char[2] name 이라는 배열을 가정 => 값을 입력 받았을 경우 $name을 통해 해당 주소값을 전달받아
	// name의 값을 새로 입력하는 것

	return 0;
}

void swap(int a, int b)
{
	printf("SWAP 함수 내 a의 주소: %d\n", &a);
	printf("SWAP 함수 내 b의 주소: %d\n", &b);

	int temp = a;
	a = b;
	b = temp;

	printf("SWAP 함수 내 => a: %d, b: %d\n", a, b);
}

void swap_addr(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

	printf("(주소값 전달)SWAP 함수 내 => a: %d, b: %d\n", *a, *b);
}

void changeArray(int* ptr)
{
	ptr[2] = 50;
}