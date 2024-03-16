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

void ClearConsole();

void Draw(string _object, COORD _pos, Color _textColor, Color _backColor);

extern RECT consoleScreenSize;
extern RECT playerMovableRect;
extern COORD screenPoint[30];
extern COORD m_screenPoint[5][6];
