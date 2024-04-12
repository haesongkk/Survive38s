#include "Header.h"
#include "Input.h"

const int keyID[KEYID_END] = { 
    VK_LEFT, 
    VK_RIGHT, 
    VK_SPACE };

bool key[KEYID_END][KETSTATE_END] = {};

void InitInput()
{
    for (int i = 0; i < KEYID_END; i++)
        for (int j = 0; j < KETSTATE_END; j++)
            key[i][j] = false;
}

void UpdateInput()
{
    bool prePush[KEYID_END] = {};

    for (int i = 0; i < KEYID_END; i++)
    {
        // 직전 키 상태 보관
        prePush[i] = key[i][DOWN];

        // 현재 키 상태 보관
        {
            if (GetAsyncKeyState(keyID[i]) & 0x8000)
            {
                key[i][DOWN] = true;
            }
            else
            {
                key[i][DOWN] = false;
            }
        }

        // 탭 여부 판단
        {
            if (prePush[i] == false && key[i][DOWN] == true)
            {
                key[i][TAP] = true;
            }
            else
            {
                key[i][TAP] = false;
            }
        }
    }

    return;
}

void FinalInput()
{
}

bool GetKey(KeyID _keyId, KeyState _keyState)
{
    return key[_keyId][_keyState];
}