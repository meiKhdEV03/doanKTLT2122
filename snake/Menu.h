#pragma once
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <math.h>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>

#define length_CS 102
#define width_CS 28
using namespace std;
struct Box
{
	int x, y, length, width;
};
void Out_file();
void read_File();
void draw_Board();
void Nocursortype();
void FixConsoleWindow();
void SET_COLOR(int color);
void gotoxy(int x, int y);
void Boxx();
void draw_Box_txt(int b_k, int j);
void draw_Box(int x, int y, int length, int width);
void write_Text(int x, int y, int length, string txt);
void move_Menu();
void Level_menu();
void draw_Menu(int bg, int ed, int cdt);
int Level();