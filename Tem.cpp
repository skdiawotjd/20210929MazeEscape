#include <iostream>

using namespace std;

int abc()
{
	//1. 초기화
	int Map[10][10] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	};

	int PlayerX = 1;
	int PlayerY = 1;
	char Key;

	//2. 입력
	cin >> Key;

	//3. 처리
	// 플레이어를 움직인다
	switch (Key)
	{
	case 'W':
	case 'w':
	{
		if (Map[PlayerX][PlayerY - 1] != 1)
		{
			PlayerX -= 1;
		}
	}
	break;
	case 'A':
	case 'a':
	{
		if (Map[PlayerX][PlayerY - 1] != 1)
		{
			PlayerY -= 1;
		}
	}
	break;
	case 'S':
	case 's':
	{
		if (Map[PlayerX][PlayerY - 1] != 1)
		{
			PlayerX += 1;
		}
	}
	break;
	case 'D':
	case 'd':
	{
		if (Map[PlayerX][PlayerY - 1] != 1)
		{
			PlayerY += 1;
		}
	}
	break;
	}

	//4. 출력
	for (int X = 0; X < 10; X++)
	{
		for (int Y = 0; Y < 10; Y++)
		{
			if (PlayerX == X && PlayerY == Y)
			{
				cout << "P" << " ";
			}
			else if (Map[X][Y] == 0)
			{
				cout << " " << " ";
			}
			else if (Map[X][Y] == 1)
			{
				cout << "o" << " ";
			}
		}
		cout << endl;
	}

	return 0;
}