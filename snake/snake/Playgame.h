#pragma once

void create_Snake();
void draw_Snake();
bool outside(int x, int y);
void draw_Food();
void Move(int& i);
void Go_Left();
void Go_Right();
void Go_Up();
void Go_Down();
bool Eat();
void Plus_Body();
void Score();
bool alive(int x, int y);