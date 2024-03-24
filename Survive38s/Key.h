#pragma once

enum KeyID
{
    LEFT, RIGHT, SPACE, KEYID_END
};

enum KeyState
{
    DOWN, TAP, KETSTATE_END
};

void InitKey();
void UpdateKey();
bool GetKey(KeyID, KeyState);