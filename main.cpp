#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

void Input();
void Process();
void Draw();
void Terminate();

void MovePlayer(int XDirection, int YDirection);
void EndCheck();
void ChangeColor(int Color);

//1. �ʱ�ȭ
int Map[2][10][10] = {
	{{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,9,1},
	{1,1,1,1,1,1,1,1,1,1}},
	{{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,0,1},
	{1,9,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
	{1,1,1,1,1,1,1,1,1,1}}
};

int PlayerX = 1;
int PlayerY = 1;
int Key;
bool bIsRunning = true;
int Level = 0;

int main()
{
	// ���ʿ� �ѹ� �̸� �׷��ֱ�
	Draw();
	while (bIsRunning)
	{
		Input();
		Process();
		Draw();
		Terminate();
	}
	
	return 0;
}

void Input()
{
	//2. �Է�
	Key = _getch();
	if (Key == 0x00 || Key == 0xE0)
	{
		Key = _getch();
	}
}

void Process()
{
	//3. ó��
// �÷��̾ �����δ�
	switch (Key)
	{
		//up
		case 'W':
		case 'w':
		{
			MovePlayer(-1, 0);
			break;
		}
		//left
		case 'A':
		case 'a':
		{
			MovePlayer(0, -1);
			break;
		}
		//down
		case 'S':
		case 's':
		{
			MovePlayer(1, 0);
			break;
		}
		//right
		case 'D':
		case 'd':
		{
			MovePlayer(0, 1);
			break;
		}
		//end
		case 'Q':
		case 'q':
		{
			bIsRunning = false;
			break;
		}
	}
	EndCheck();
}

void Draw()
{
	// ȭ���� �����
	system("cls");
	cout << Level + 1 << "�ܰ�" << endl;
	//4. ���
	for (int X = 0; X < 10; X++)
	{
		for (int Y = 0; Y < 10; Y++)
		{
			if (PlayerX == X && PlayerY == Y)
			{
				ChangeColor(10);
				cout << "P";
				ChangeColor(7);
				cout << " ";
			}
			else if (Map[Level][X][Y] == 1)
			{
				cout << "o" << " ";
			}
			else if (Map[Level][X][Y] == 9)
			{
				ChangeColor(14);
				cout << "G";
				ChangeColor(7);
				cout << " ";
			}
			else 
			{
				cout << " " << " ";
			}
		}
		cout << endl;
	}
}

void Terminate()
{
	if (Map[Level][PlayerX][PlayerY] == 9)
	{
		cout << "Goal";
	}
	else if (Key == 'Q' || Key == 'q')
	{
		cout << "qŰ�� ���� ����";
	}
}

void MovePlayer(int XDirection, int YDirection)
{
	int NewPlayerX = PlayerX + XDirection;
	int NewPlayerY = PlayerY + YDirection;

	if (Map[Level][NewPlayerX][NewPlayerY] != 1)
	{
		PlayerX = NewPlayerX;
		PlayerY = NewPlayerY;
	}
}

void EndCheck()
{
	//Map[Level][PlayerX][PlayerY] == 9 ? true : false;
	if (Map[Level][PlayerX][PlayerY] == 9)
	{
		if (Level == 1)
		{
			bIsRunning = false;
		}
		else
		{
			Level++;
			PlayerX = 1;
			PlayerY = 1;
		}
	}
}

void ChangeColor(int Color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
}
