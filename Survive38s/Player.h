#pragma once

void updatePlayerPos();
void updatePlayerMove();

void InitPlayer();

extern COORD m_pos;
extern COORD m_prePos;
extern bool m_isCrash;
