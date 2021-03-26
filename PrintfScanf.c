#include <stdio.h>
int main_printfscanf(void)
{
	/* multi line
	   comment */

	// ������ ����
	int age = 12;
	printf("%d\n", age);
	age = 13;
	printf("%d\n", age);

	printf("1\n");
	// printf("1 line comment \n");
	printf("3\n");

	// �Ǽ��� ����
	float f = 46.5f;
	printf("%.2f\n", f);
	double d = 4.428;
	printf("%.2lf\n", d); // 4.43(round)

	// ���(������ �ʴ� ��)
	const int YEAR = 2000;
	printf("�¾ �⵵ : %d\n", YEAR);
	// YEAR = 2001;

	// printf(���)
	int add = 3 + 7; // 3 + 7 = 10
	printf("3 + 7 = %d\n", add);
	printf("%d + %d = %d\n", 3, 7, 3 + 7);
	printf("%d * %d = %d\n", 30, 79, 30 * 79);

	// scanf(Ű���� �Է��� �޾� ����)
	int input;
	printf("���� �Է�> ");
	scanf_s("%d", &input);
	printf("�Է°�: %d\n", input);

	int one, two, three;
	printf("3���� ���� �Է�> ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("ù��° ��: %d\n", one);
	printf("�ι�° ��: %d\n", two);
	printf("����° ��: %d\n", three);

	// ����, ���ڿ�
	char c = 'A';
	printf("%c\n", c);
	char str[256]; // ���ڸ� �迭�� �Ͽ� ���ڿ� ����
	scanf_s("%s", str, sizeof(str)); // sizeof�� str�� ũ��(256)������ ���ڸ� �Է�
	printf("%s\n", str);

	/* Ex) ���� �ۼ�
	   �̸�, ����, ������, Ű, ���˸� ���� �Է¹޾� ��� */
	char name[256];
	printf("�̸� >");
	scanf_s("%s", name, sizeof(name));

	printf("���� >");
	scanf_s("%d", &age);

	float weight;
	printf("������(kg) >");
	scanf_s("%f", &weight);

	double height;
	printf("Ű(cm) >");
	scanf_s("%lf", &height);

	char crime[256];
	printf("���˸� >");
	scanf_s("%s", crime, sizeof(crime));

	printf("\n----- ������ ���� -----\n");
	printf(" �̸�    : %s\n", name);
	printf(" ����    : %d ��\n", age);
	printf(" ������  : %.2f kg\n", weight);
	printf(" Ű      : %.2lf cm\n", height);
	printf(" ���˸�  : %s\n", crime);

	return 0;
}