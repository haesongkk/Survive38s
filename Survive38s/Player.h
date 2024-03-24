#pragma once
enum Color;

void updatePlayerPos();
void updatePlayerMove();

void InitPlayer();

extern COORD m_pos;
extern COORD m_prePos;
extern bool m_isCrash;
extern Color g_playerState;
