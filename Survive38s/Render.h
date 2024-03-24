#pragma once

enum Color
{
	Black,  	
	DarkBlue,
	DarkGreen,
	DarkSkyBlue,
	DarkRed,

	DarkPurple,
	DarkYellow,
	Gray,		
	DarkGray,	
	Blue,

	Green,
	SkyBlue,	
	Red,
	Purple,
	Yellow,

	White,

	Color_End
};

void InitConsole();

void ClearScreen();

void Draw(string _object, COORD _pos, Color _textColor, Color _backColor);
void Draw(wstring _object, COORD _pos, Color _textColor, Color _backColor);

struct Object
{
	wstring wstr;
	COORD pos;
	Color textColor;
	Color backColor = Black;
};

void Draw(Object _obj);

extern COORD m_screenPoint[5][6];
extern COORD screenPoint[30];
