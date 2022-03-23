#include "Playgame.h"
#include "Menu.h"
int direction = 2; //Huong di snake nhan vao
int temp_drt = 2; //Huong snake di
int score = 0;
int speed = 70;
bool Start = false;
struct  Snake
{
	int x = 0, y = 0;
	int x0 = 0, y0 = 0;
};
vector <Snake> snake;
struct Food
{
	int x = 0, y = 0;
};
Food food;
void create_Snake()
{
	score = 0;
	snake.resize(6);
	srand(time(NULL));
	while (snake[0].x <= 40 || snake[0].x >= 60)
		snake[0].x = rand();
	while (snake[0].y <= 10 || snake[0].y >= 20)
		snake[0].y = rand();
	for (int i = 0; i < snake.size(); i++)
	{
		snake[i].x = snake[0].x - i;
		snake[i].y = snake[0].y;
	}
}
bool alive(int x, int y)
{
	for (int i = 1; i < snake.size(); i++)
	{
		if (snake[i].x == x && snake[i].y == y)
			return false;
	}
	return true;
}
void draw_Snake()
{
	for (int i = 0; i < snake.size(); i++)
	{
		gotoxy(snake[i].x, snake[i].y);
		if (i == 0)
		{
			cout << "0";
			gotoxy(110, 0);
		}
		else
		{
			cout << "o";
			gotoxy(110, 0);
		}
	}

}
bool outside(int x, int y)
{
	if (x <= 0 || x >= 101 || y <= 0 || y >= 27)
		return true;
	return false;
}
void draw_Food()
{
	food.x = 0;
	food.y = 0;
	srand(time(NULL));
	while (!alive(food.x, food.y) || outside(food.x, food.y))
	{
		food.x = rand();
		food.y = rand();
	}
	gotoxy(food.x, food.y);
	cout << "o";
}
bool Eat()
{
	if (snake[0].x == food.x && snake[0].y == food.y)
	{
		return true;
	}
	return false;
}

void Move(bool* check)
{
	if (_kbhit())
	{
		char str = _getch();
		if (str == 'W' || str == 'w')
			direction = 1;
		else if (str == 'S' || str == 's')
			direction = -1;
		else if (str == 'A' || str == 'a')
			direction = 2;
		else if (str == 'D' || str == 'd')
			direction = -2;
	}
	if (!Start && direction != 2)
		Start = true;
	if (Start) {
		if (temp_drt != -direction)
			temp_drt = direction;
		switch (temp_drt) {
		case 1: {
			Go_Up();
			break;
		}
		case -1: {
			Go_Down();
			break;
		}
		case 2: {
			Go_Left();
			break;
		}
		case -2: Go_Right();
		}
		if (outside(snake[0].x, snake[0].y) || !alive(snake[0].x, snake[0].y))
		{
			gotoxy(45, 12);
			cout << "You Lose! ";
			*check = false;
			Start = false;
		}
	}
}
void Go_Right()
{
	for (int i = 0; i < snake.size(); i++)
	{
		if (i == 0)
		{
			snake[0].x0 = snake[0].x;
			snake[0].y0 = snake[0].y;
			snake[0].x += 1;
		}
		else
		{
			snake[i].x0 = snake[i].x;
			snake[i].y0 = snake[i].y;
			snake[i].x = snake[i - 1].x0;
			snake[i].y = snake[i - 1].y0;
		}
	}
	gotoxy(snake[snake.size() - 1].x0, snake[snake.size() - 1].y0);
	cout << " ";
	draw_Snake();
	Sleep(speed / Level());
}
void Go_Left()
{
	for (int i = 0; i < snake.size(); i++)
	{
		if (i == 0)
		{
			snake[0].x0 = snake[0].x;
			snake[0].y0 = snake[0].y;
			snake[0].x -= 1;
		}
		else
		{
			snake[i].x0 = snake[i].x;
			snake[i].y0 = snake[i].y;
			snake[i].x = snake[i - 1].x0;
			snake[i].y = snake[i - 1].y0;
		}
	}
	gotoxy(snake[snake.size() - 1].x0, snake[snake.size() - 1].y0);
	cout << " ";
	draw_Snake();
	Sleep(speed / Level());
}
void Go_Up()
{
	for (int i = 0; i < snake.size(); i++)
	{
		if (i == 0)
		{
			snake[0].x0 = snake[0].x;
			snake[0].y0 = snake[0].y;
			snake[0].y -= 1;
		}
		else
		{
			snake[i].x0 = snake[i].x;
			snake[i].y0 = snake[i].y;
			snake[i].x = snake[i - 1].x0;
			snake[i].y = snake[i - 1].y0;
		}
	}
	gotoxy(snake[snake.size() - 1].x0, snake[snake.size() - 1].y0);
	cout << " ";
	draw_Snake();
	Sleep(speed / Level());
}
void Go_Down()
{
	for (int i = 0; i < snake.size(); i++)
	{
		if (i == 0)
		{
			snake[0].x0 = snake[0].x;
			snake[0].y0 = snake[0].y;
			snake[0].y += 1;
		}
		else
		{
			snake[i].x0 = snake[i].x;
			snake[i].y0 = snake[i].y;
			snake[i].x = snake[i - 1].x0;
			snake[i].y = snake[i - 1].y0;
		}
	}
	gotoxy(snake[snake.size() - 1].x0, snake[snake.size() - 1].y0);
	cout << " ";
	draw_Snake();
	Sleep(speed / Level());
}

void Plus_Body()
{
	snake.resize(snake.size() + 1);
	snake[snake.size() - 1].x = snake[snake.size() - 2].x0;
	snake[snake.size() - 1].y = snake[snake.size() - 2].y0;
}
void Score()
{
	gotoxy(111, 5);
	cout << score;
	score++;
}
