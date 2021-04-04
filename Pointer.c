#include <stdio.h>

void swap(int a, int b);
void swap_addr(int* a, int* b);
void changeArray(int* ptr);

int main_pointer(void)
{
	// ������(����Ų�� ��, ��ü�� ���� ��� ����Ű�� ��)
	// [ö��] : 101ȣ
	// [����] : 201ȣ
	// [�μ�] : 301ȣ

	int chulsu = 1;
	int younghee = 2;
	int minsu = 3;

	printf("ö���� �ּ� : %d, ��ȣ : %d\n", &chulsu, chulsu);
	printf("����� �ּ� : %d, ��ȣ : %d\n", &younghee, younghee);
	printf("�μ��� �ּ� : %d, ��ȣ : %d\n", &minsu, minsu);

	// �̼�
	int* missionMan; // ������ ����
	missionMan = &chulsu;
	printf("�̼Ǹ��� �湮�ϴ� �ּ� : %d, ��ȣ : %d\n", missionMan, *missionMan);
	// *(������ ������) missionMan�� ����� �ּҰ��� ����, �� chulsu�� ����Ŵ

	// �ι�° �̼�: �� ��ȣ�� 3�� ���ض�
	missionMan = &chulsu;
	*missionMan = *missionMan * 3;
	printf("�̼Ǹ��� ��ȣ�� �ٲ� �ּ� : %d, ��ȣ : %d\n", missionMan, *missionMan);

	// ������
	// �̼Ǹ��� �ٲ� ��ȣ���� 2�� ��
	int* spy = missionMan; // missionMan�� chulsu�� �ּҰ��̱⿡ spy�� chulsu�� �ּҰ��� ����
	printf("�����̰� �̼� ������\n");
	spy = &chulsu;
	*spy = *spy - 2;
	printf("�����̰� �湮�ϴ� �� �ּ�: %d, ��ȣ %d\n", spy, *spy);

	// *missionMan(�ּҰ�: 1, ���� ��: 2) = chulsu(�ּҰ�: 2, ������: 100)�� ���� ��
	// missionMan�� spy�� �ּҰ��� �� �ٸ���
	printf("�̼Ǹ��� �ּ�: %d\n", &missionMan);
	printf("�������� �ּ�: %d\n", &spy);

	int* numptr;
	int num = 10;


	// �迭(����������)
	int arr[3] = { 5, 10, 15 };
	int* ptr = arr; // *ptr�� arr(�迭�� ó�� �ּҰ�)�� ����Ŵ

	for (int i = 0; i < 3; i++)
	{
		printf("�迭 arr[%d]�� ��: %d\n", i, arr[i]); // 3 5 10
	}
	for (int i = 0; i < 3; i++)
	{
		printf("������ ptr[%d]�� ��: %d\n", i, ptr[i]); // *ptr[(�� �������� �ּҰ�, ������ arr�� ����Ű�� �ּҰ�)]
	}
	// ��, ptr(100, 200, 300)[1000, 2000, 3000] =>
	//     arr(1000, 2000, 3000)[5, 10, 15]

	ptr[0] = 100; // arr[0] = 100
	ptr[1] = 200; // arr[1] = 200
	ptr[2] = 300; // arr[2] = 300

	for (int i = 0; i < 3; i++)
	{
		printf("�迭 arr[%d]�� ��: %d\n", i, arr[i]);
		printf("�迭 arr[%d]�� ��: %d\n", i, *(arr + i)); // arr�� ó�� �ּҰ� + i��°�� ���� = arr[i]
	}
	for (int i = 0; i < 3; i++)
	{
		printf("������ ptr[%d]�� ��: %d\n", i, ptr[i]);
		printf("������ ptr[%d]�� ��: %d\n", i, *(ptr + i)); // ptr�� ó�� �ּҰ� + i��°�� ���� = arr[i]
	}

	// *(arr + i) == arr[i] �Ȱ��� ǥ��
	// arr == arr�迭�� ù��° ���� �ּҿ� ���� == &arr[0]
	printf("arr ��ü�� ��: %d\n", arr);
	printf("arr[0]�� �ּ�: %d\n", &arr[0]);
	printf("arr ��ü�� ���� ������ �ּ��� ���� ��: %d\n", *arr); // *(arr + 0)
	printf("arr[0]�� ���� ��: %d\n", *&arr[0]); // &�� �ּ�, *�� �ּ��� �� == *&�� ���
	printf("arr[1]�� �ּҰ�: %d\n", arr + 1);

	// SWAP
	int a = 10;
	int b = 20;
	printf("a�� �ּ�: %d\n", &a);
	printf("b�� �ּ�: %d\n", &b);

	// a�� b�� ���� �ٲ۴�
	printf("SWAP �Լ� �� => a: %d, b: %d\n", a, b);
	swap(a, b);
	printf("SWAP �Լ� �� => a: %d, b: %d\n", a, b);

	// ���� ���� ���� (Call by Value) -> ���� �����Ѵٴ� �ǹ�

	// �ּҰ��� �ѱ�ٸ�?
	printf("(�ּҰ� ����)SWAP �Լ� �� => a: %d, b: %d\n", a, b);
	swap_addr(&a, &b);
	printf("(�ּҰ� ����)SWAP �Լ� �� => a: %d, b: %d\n", a, b);

	// �迭�϶�, arr2 => �ּ�
	int arr2[3] = { 10, 20, 30 };
	changeArray(arr2); // �迭�϶� �ּҰ��� ���� ��, changeArray(&arr2[0])�� ����
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", arr2[i]);
	}

	// scanf���� �ش� ���� &�� ���� ����?
	// char[2] name �̶�� �迭�� ���� => ���� �Է� �޾��� ��� $name�� ���� �ش� �ּҰ��� ���޹޾�
	// name�� ���� ���� �Է��ϴ� ��

	return 0;
}

void swap(int a, int b)
{
	printf("SWAP �Լ� �� a�� �ּ�: %d\n", &a);
	printf("SWAP �Լ� �� b�� �ּ�: %d\n", &b);

	int temp = a;
	a = b;
	b = temp;

	printf("SWAP �Լ� �� => a: %d, b: %d\n", a, b);
}

void swap_addr(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

	printf("(�ּҰ� ����)SWAP �Լ� �� => a: %d, b: %d\n", *a, *b);
}

void changeArray(int* ptr)
{
	ptr[2] = 50;
}