#include <stdio.h>
#include <time.h>

int arrayAnimal[4][5];
int checkAnimal[4][5]; // 카드 뒤집혔는지 확인
char* strAnimal[10];
void initAnimalArray();
void initAnimalName();
void shuffleAnimal();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimal();
void printQuestion();
int foundAllAnimals();

int main_m_array_project(void)
{
	srand(time(NULL));
	initAnimalArray();
	initAnimalName();
	shuffleAnimal();

	int failCount = 0; // 실패횟수

	while (1)
	{
		int select1 = 0;
		int select2 = 0;

		printAnimal();
		printQuestion();
		printf("뒤집을 카드를 2개 고르시오 : ");
		scanf_s("%d %d", &select1, &select2);

		if (select1 == select2) // 같은 카드 선택 시 무효
		{
			continue;
		}

		// 좌표에 해당하는 카드를 뒤집어 보고 같은지 안같은지 확인
		int firstSelect_x = conv_pos_x(select1);
		int firstSelect_y = conv_pos_y(select1);

		int secondSelect_x = conv_pos_x(select2);
		int secondSelect_y = conv_pos_y(select2);

		// 같은 동물일 경우
		if ((checkAnimal[firstSelect_x][firstSelect_y] == 0
			&& checkAnimal[secondSelect_x][secondSelect_y] == 0)
			&& (arrayAnimal[firstSelect_x][firstSelect_y]
			== arrayAnimal[secondSelect_x][secondSelect_y])
			) // 카드가 뒤집혀 있는지 && 두 동물이 같은지
		{
			printf("빙고! : %s 발견\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			checkAnimal[firstSelect_x][firstSelect_y] = 1;
			checkAnimal[secondSelect_x][secondSelect_y] = 1;
		}

		// 다른 동물일 경우
		else
		{
			printf("땡! (틀렸거나, 이미 뒤집힌 카드!)\n");
			printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
			printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
			
			failCount++;
		}

		// 모든 동물을 찾았는지 여부 (참: 1, 거짓: 0)
		if (foundAllAnimals() == 1)
		{
			printf("축하합니다! 모든 동물을 다 찾았습니다\n");
			printf("지금까지 총 %d번 실수하였습니다\n", failCount);
			break;
		}
	}

	return 0;
}

void initAnimalArray()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arrayAnimal[i][j] = -1;
		}
	}
}

void initAnimalName()
{
	strAnimal[0] = "원숭이";
	strAnimal[1] = "하마";
	strAnimal[2] = "강아지";
	strAnimal[3] = "고양이";
	strAnimal[4] = "돼지";
	strAnimal[5] = "코끼리";
	strAnimal[6] = "기린";
	strAnimal[7] = "낙타";
	strAnimal[8] = "타조";
	strAnimal[9] = "호랑이";
}

void shuffleAnimal()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int pos = getEmptyPosition();
			int x = conv_pos_x(pos);
			int y = conv_pos_y(pos);

			arrayAnimal[x][y] = i;
		}
	}
}

int getEmptyPosition()
{
	while (1)
	{
		int randPos = rand() % 20; // 0 ~ 19 사이의 숫자 반환
		// 19 -> (3,4)
		int x = conv_pos_x(randPos);
		int y = conv_pos_y(randPos);

		if (arrayAnimal[x][y] == -1)
		{
			return randPos;
		}
	}
	return 0;
}

int conv_pos_x(int x)
{
	return x / 5;
}

int conv_pos_y(int y)
{
	return y % 5;
}

void printAnimal() // 동물 위치 출력
{
	printf("============================================\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%8s", strAnimal[arrayAnimal[i][j]]);
		}
		printf("\n");
	}
	printf("============================================\n");
}

void printQuestion() // 문제 출력
{
	printf("문제\n");
	int seq = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// 카드를 뒤집어서 정답을 맞췄으면 '동물이름'
			if (checkAnimal[i][j] != 0)
			{
				printf("%8s", strAnimal[arrayAnimal[i][j]]);
			}
			// 아직 뒤집지 못했으면 (정답을 못맞혔으면) 뒷면 -> 위치를 나타내는 숫자
			else
			{
				printf("%8d", seq);
			}
			seq++;
		}
		printf("\n");
	}
}

int foundAllAnimals()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (checkAnimal[i][j] == 0)
			{
				return 0;
			}
		}
	}
	return 1; // 모든 동물을 찾음
}