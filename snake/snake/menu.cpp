#include "Menu.h"

string str[10];
Box box[10];
int drt = 0;
int DRT = 4;
int Lv = 1;
vector<string> lines;
vector<int> diem;
void draw_Board()
{
	printf("%c", 218);
	for (int i = 1; i <= length_CS - 1; i++)
	{
		gotoxy(i, 0);
		printf("%c", 196);
		gotoxy(i, width_CS - 1);
		printf("%c", 196);
	}
	gotoxy(length_CS - 1, 0);
	printf("%c", 191);
	gotoxy(0, width_CS - 1);
	printf("%c", 192);
	for (int i = 1; i < width_CS - 1; i++)
	{
		gotoxy(0, i);
		printf("%c", 179);
		gotoxy(length_CS - 1, i);
		printf("%c", 179);
	}
	gotoxy(length_CS - 1, width_CS - 1);
	printf("%c", 217);

	gotoxy(103, 7);
	cout << "W: Up";
	gotoxy(103, 8);
	cout << "S: Down";
	gotoxy(103, 9);
	cout << "A: Left";
	gotoxy(103, 10);
	cout << "D: Right";
}
void read_File()
{
	fstream fp;
	fp.open("highscore.txt", ios::in);
	string line;
	int i = 1;
	int D;
	while (!fp.eof())
	{
		getline(fp, line);
		if (i % 2 == 0) {
			D = stoi(line);
			diem.push_back(D);
		}
		else
			lines.push_back(line);
		i++;
	}
	fp.close();
}
void Out_file()
{
	for (int i = 0; i < 5; i++)
		cout << lines[i] << "  " << diem[i] << endl;
}
void String()
{
	str[0] = "START";
	str[1] = "LEVEL";
	str[2] = "HIGHSCORE";
	str[3] = "INTRODUCTION";
	str[4] = "HARD";
	str[5] = "MEDIUM";
	str[6] = "EAZY";
}
void Boxx()
{
	box[0] = { 38,6,26,3 };
	box[1] = { 38,9,26,3 };
	box[2] = { 38,12,26,3 };
	box[3] = { 38,15,26,3 };
	box[4] = { 44,12,14,3 };
	box[5] = { 44,15,14,3 };
	box[6] = { 44,18,14,3 };
}
void draw_Box(int x, int y, int length, int width)
{
	gotoxy(x, y);
	cout << char(218);
	gotoxy(x + length - 1, y);
	cout << char(191);
	gotoxy(x, y + width - 1);
	cout << char(192);
	gotoxy(x + length - 1, y + width - 1);
	cout << char(217);
	for (int i = 1; i < length - 1; i++)
	{
		gotoxy(x + i, y);
		cout << char(196);
		gotoxy(x + i, y + width - 1);
		cout << char(196);
	}
	gotoxy(x + length - 1, y);
	cout << char(191);

	for (int i = 1; i < width - 1; i++)
	{
		gotoxy(x, y + i);
		cout << char(179);
		gotoxy(x + length - 1, y + i);
		cout << char(179);
	}
}
void draw_Box_txt(int b_k, int j) {
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, b_k);
	write_Text(box[j].x, box[j].y, box[j].length, str[j]);
	SetConsoleTextAttribute(hConsoleColor, 3);
	draw_Box(box[j].x, box[j].y, box[j].length, box[j].width);
	SetConsoleTextAttribute(hConsoleColor, 6);
}
void draw_Menu(int bg, int ed, int cdt)
{
	for (int i = bg; i < ed; i++)
		if (i != cdt)
			draw_Box_txt(15, i);
		else
			draw_Box_txt(116, i);
	Nocursortype();
}
void move_Menu()
{
	lines.resize(0);
	diem.resize(0);
	read_File();
	Boxx();
	String();
	draw_Menu(0, 4, drt);
	int bien;
	int k = 0;
	int bac = 1;
	while (k == 0) {
		bien = drt;
		if (_kbhit())
		{
			char c = _getch();
			if (bac == 1) {
				if (c == 'w' || c == 'W') {
					drt--;
					if (drt < 0 || drt > 3)
						drt = bien;
					else 
						draw_Menu(0, 4, drt);
				}
				else if (c == 's' || c == 'S') {
					drt++;
					if (drt < 0 || drt > 3)
						drt = bien;
					else 
						draw_Menu(0, 4, drt);
				}
				else if (c == 13) {
					bac++;
					if (drt == 0)
						k = 1;
					else if (drt == 1) { 
						box[2].y += 9;
						box[3].y += 9;
						system("cls");
						draw_Board();
						draw_Menu(0, 7, 4);
						box[2].y -= 9;
						box[3].y -= 9;
					}
					else if (drt == 2) {
						system("cls");
						gotoxy(0, 0);
						Out_file();
					}
					else if (drt == 3) {
						bac--;
					}
				}

			}
			else {
				if (drt == 1) {
					box[2].y += 9;
					box[3].y += 9;
					bien = DRT;
					if (c == 'w' || c == 'W') {
						DRT--;
						if (DRT < 4 || DRT > 6)
							DRT = bien;
						else {
							draw_Menu(0, 7, DRT);
						}
					}
					else if (c == 's' || c == 'S') {
						DRT++;
						if (DRT < 4 || DRT > 6)
							DRT = bien;
						else {
							draw_Menu(0, 7, DRT);
						}
					}
					else if (c == 13) {
						gotoxy(103, 5);
						cout << "Level: " << str[DRT] << "  ";
					}
					else if (c == 27) {
						bac--;
						box[2].y -= 9;
						box[3].y -= 9;
						system("cls");
						draw_Board();
						gotoxy(103, 5);
						cout << "Level: " << str[DRT] << "  ";
						draw_Menu(0, 4, drt);
						box[2].y += 9;
						box[3].y += 9;
					}
					box[2].y -= 9;
					box[3].y -= 9;
				}
				else if (drt == 2) {
					if (c == 27) {
						system("cls");
						draw_Board();
						gotoxy(103, 5);
						cout << "Level: " << str[DRT] << "  ";
						draw_Menu(0, 4, drt);
						bac--;
					}
				}
				else if (drt == 3) {
					box[2].y -= 9;
					box[3].y -= 9;
					system("cls");
					draw_Board();
					gotoxy(103, 5);
					cout << "Level: " << str[DRT] << "  ";
					draw_Menu(0, 4, drt);
				}

			}
		}
		Lv = DRT;
	}
}
void Level_menu()
{
	box[2].y += 9;
	box[3].y += 9;
	for (int i = 0; i < 7; i++)
	{
		if (i < 4)
			draw_Box_txt(15, i);
		else
			draw_Box_txt(15, i);
	}
	box[2].y -= 9;
	box[3].y -= 9;
}
int Level() {
	return Lv;
}
