#include <stdio.h>
int main_printfscanf(void)
{
	/* multi line
	   comment */

	// 정수형 변수
	int age = 12;
	printf("%d\n", age);
	age = 13;
	printf("%d\n", age);

	printf("1\n");
	// printf("1 line comment \n");
	printf("3\n");

	// 실수형 변수
	float f = 46.5f;
	printf("%.2f\n", f);
	double d = 4.428;
	printf("%.2lf\n", d); // 4.43(round)

	// 상수(변하지 않는 수)
	const int YEAR = 2000;
	printf("태어난 년도 : %d\n", YEAR);
	// YEAR = 2001;

	// printf(출력)
	int add = 3 + 7; // 3 + 7 = 10
	printf("3 + 7 = %d\n", add);
	printf("%d + %d = %d\n", 3, 7, 3 + 7);
	printf("%d * %d = %d\n", 30, 79, 30 * 79);

	// scanf(키보드 입력을 받아 저장)
	int input;
	printf("값을 입력> ");
	scanf_s("%d", &input);
	printf("입력값: %d\n", input);

	int one, two, three;
	printf("3개의 정수 입력> ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("첫번째 값: %d\n", one);
	printf("두번째 값: %d\n", two);
	printf("세번째 값: %d\n", three);

	// 문자, 문자열
	char c = 'A';
	printf("%c\n", c);
	char str[256]; // 문자를 배열로 하여 문자열 생성
	scanf_s("%s", str, sizeof(str)); // sizeof로 str의 크기(256)까지만 문자를 입력
	printf("%s\n", str);

	/* Ex) 조서 작성
	   이름, 나이, 몸무게, 키, 범죄명 등을 입력받아 출력 */
	char name[256];
	printf("이름 >");
	scanf_s("%s", name, sizeof(name));

	printf("나이 >");
	scanf_s("%d", &age);

	float weight;
	printf("몸무게(kg) >");
	scanf_s("%f", &weight);

	double height;
	printf("키(cm) >");
	scanf_s("%lf", &height);

	char crime[256];
	printf("범죄명 >");
	scanf_s("%s", crime, sizeof(crime));

	printf("\n----- 범죄자 정보 -----\n");
	printf(" 이름    : %s\n", name);
	printf(" 나이    : %d 세\n", age);
	printf(" 몸무게  : %.2f kg\n", weight);
	printf(" 키      : %.2lf cm\n", height);
	printf(" 범죄명  : %s\n", crime);

	return 0;
}