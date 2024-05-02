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

void InitRender();
void UpdateRender();
void FinalRender();

void Draw(wstring _object, COORD _pos, Color _textColor = White, Color _backColor = Black);
