#pragma once

enum KeyID
{
    LEFT, RIGHT, SPACE, KEYID_END
};

enum KeyState
{
    DOWN, TAP, KETSTATE_END
};

void InitInput();
void UpdateInput();
void FinalInput();

bool GetKey(KeyID, KeyState);