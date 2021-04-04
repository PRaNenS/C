#include <stdio.h>
#include <time.h>

// 물고기가 6마리 있어요
// 이들은 어항에 살고 있는데, 사막이에요
// 사막이 너무 더워서, 너무 건조해서 물이 아주 빨리 증발을 해요
// 물이 다 증발하기 전에 부지런히 어항에 물을 줘서 물고기를 살려주세요
// 물고기는 시간이 지날수록 점점 커져서 나중에는 냠냠..

int level;
int arrayFish[6];
int* cursor;

void initData();
void printFishes();
void decreaseWater(long elapsedTime);
int checkFishAlive();

int main_project(void)
{
	long startTime = 0; // 게임 시작 시간
	long totalElapsedTime = 0; // 총 경과 시간
	long prevElapsedTime = 0; // 직전 경과 시간(최근에 물을 준 시간 간격)

	int num; // 몇 번 어항에 물을 줄건지, 사용자 입력
	initData();

	cursor = arrayFish;

	startTime = clock(); // 현재 시간을 milSecond

	while (1)
	{
		printFishes();
		printf("몇 번 어항에 물을 주시겠어요? >");
		scanf_s("%d", &num);

		// 입력값 체크
		if (num < 1 || num > 6)
		{
			printf("\n입력값이 잘못되었습니다\n");
			continue;
		}

		totalElapsedTime = (clock() - startTime) / CLOCKS_PER_SEC; // CLOCKS_PER_SEC => 밀리초 / 1000
		printf("총 경과 시간: %ld 초\n", totalElapsedTime);

		// 직전 물 준 시간 (마지막으로 물 준 시간) 이후로 흐른 시간
		prevElapsedTime = totalElapsedTime - prevElapsedTime;
		printf("최근 경과 시간: %ld 초\n", prevElapsedTime);

		// 어항의 물을 감소 (증발)
		decreaseWater(prevElapsedTime);

		// 사용자가 입력한 어항에 물을 준다
		// 1. 어항의 물이 0이면? 물을 주지 않는다
		if (cursor[num - 1] <= 0)
		{
			printf("%d 번 물고기는 이미 죽었습니다\n", num);
		}

		// 2. 어항의 물이 0이 아닌 경우? 물을 주고, 100을 넘지 않는지 체크
		else if (cursor[num - 1] + 1 <= 100)
		{
			// 물을 준다
			printf("%d번 어항에 물을 준다\n", num);
			cursor[num - 1] += 1; // cursor[num - 1] = cursor[num - 1] + 1
		}

		// 레벨업(20초마다 한번씩 수행)
		if (totalElapsedTime / 20 > level - 1) // int타입에서 소숫점은 내림처리됨 즉 0.9 = 0
		{
			level++; // 레벨업
			printf(" *** 축 레벨업 *** \n");

			if (level == 5)
			{
				printf("축하합니다! 최고 레벨을 달성하였습니다!\n");
				exit(0);
			}
		}

		// 모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0)
		{
			// 물고기가 모두 죽음
			printf("모든 물고기 죽음\n");
			exit(0);
		}
		else
		{
			// 최소 1마리 이상 살아있음
			printf("물고기가 살아있어요!\n");
		}
		prevElapsedTime = totalElapsedTime;
		// 최초 10초 -> 15초 (5초: prevElapsedTime -> 15초) -> 25초 (10초)
	}

	return 0;
}

void initData()
{
	level = 1; // (게임레벨 1 ~ 5)
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] = 100; // 어항의 물 높이 (0~100)
	}
}

void printFishes()
{
	printf("%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);

	for (int i = 0; i < 6; i++)
	{
		printf(" %4d ", arrayFish[i]);
	}
	printf("\n");
}

void decreaseWater(long elapsedTime)
{
	for (int i = 0; i < 6; i++)
	{
		arrayFish[i] -= (level * 3 * (int)elapsedTime);

		if (arrayFish[i] < 0)
		{
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive()
{
	for (int i = 0; i < 6; i++)
	{
		if (arrayFish[i] > 0)
		{
			return 1;
		}
		return 0;
	}
}