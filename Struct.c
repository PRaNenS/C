#include <stdio.h>

struct GameInfo {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // ������ü
};

typedef struct {
	char* name;
	int year;
	int price;
	char* company;

	struct GameInfo* friendGame; // ������ü
} GAME_INFO; // struct GameInformation�� GAME_INFO�� ����

int main_struct(void)
{
	// �������
	// �̸�: ��������
	// �߸ų⵵: 2017��
	// ����: 50��
	// ���ۻ�: ����ȸ��

	// �Ǵٸ� �������
	// �̸�: �ʵ�����
	// �߸ų⵵: 2017��
	// ����: 100��
	// ���ۻ�: �ʵ�ȸ��

	// ����ü ���
	struct GameInfo gameInfo;
	gameInfo.name = "��������";
	gameInfo.year = 2017;
	gameInfo.price = 50;
	gameInfo.company = "����ȸ��";

	// ����ü ���
	printf("\n== ���� ��� ���� ==\n");
	printf(" ���Ӹ�   : %s\n", gameInfo.name);
	printf(" �߸ų⵵ : %d\n", gameInfo.year);
	printf(" ����     : %d\n", gameInfo.price);
	printf(" ���ۻ�   : %s\n", gameInfo.company);

	// ����ü�� �迭ó�� �ʱ�ȭ
	struct GameInfo gameInfo2 = { "�ʵ�����", 2017, 100, "�ʵ�ȸ��" };
	printf("\n== ���� ��� ���� ==\n");
	printf(" ���Ӹ�   : %s\n", gameInfo2.name);
	printf(" �߸ų⵵ : %d\n", gameInfo2.year);
	printf(" ����     : %d\n", gameInfo2.price);
	printf(" ���ۻ�   : %s\n", gameInfo2.company);

	// ����ü �迭
	struct GameInfo gameArray[2] = {
		{"��������", 2017, 50, "����ȸ��"},
		{"�ʵ�����", 2017, 100, "�ʵ�ȸ��"}
	};

	// ����ü ������
	struct GameInfo* gamePtr; // �̼Ǹ�
	gamePtr = &gameInfo;
	printf("\n== �̼Ǹ� ���� ��� ���� ==\n");
	// printf(" ���Ӹ�   : %s\n", (*gamePtr).name);
	// printf(" �߸ų⵵ : %d\n", (*gamePtr).year);
	// printf(" ����     : %d\n", (*gamePtr).price);
	// printf(" ���ۻ�   : %s\n", (*gamePtr).company);
	printf(" ���Ӹ�   : %s\n", gamePtr->name);
	printf(" �߸ų⵵ : %d\n", gamePtr->year);
	printf(" ����     : %d\n", gamePtr->price);
	printf(" ���ۻ�   : %s\n", gamePtr->company);

	// ���� ��ü �Ұ�
	gameInfo.friendGame = &gameInfo2;
	printf("\n== ���� ��ü�� ���� ��� ���� ==\n");
	printf(" ���Ӹ�   : %s\n", gameInfo.friendGame->name);
	printf(" �߸ų⵵ : %d\n", gameInfo.friendGame->year);
	printf(" ����     : %d\n", gameInfo.friendGame->price);
	printf(" ���ۻ�   : %s\n", gameInfo.friendGame->company);

	// typedef
	// �ڷ����� ���� ����
	int i = 1;
	typedef int ����;
	typedef float �Ǽ�;
	���� �������� = 3; // int �������� = 3; �� ����
	�Ǽ� �Ǽ����� = 3.23f;
	printf("\n��������: %d, �Ǽ�����: %.2f\n\n", ��������, �Ǽ�����);

	typedef struct GameInfo ��������;
	�������� game1;
	game1.name = "�ѱ۰���";
	game1.year = 2015;

	GAME_INFO game2;
	game2.name = "�ѱ۰���2";
	game2.year = 2014;

	// struct GameInformation game3; // �ش� ����ü�� ��� GameInformation�� �������� �ʾұ⿡ ���Ұ�
	// game3.name = "�ѱ۰���3";
}