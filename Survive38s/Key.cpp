#include "Header.h"
#include "Key.h"

bool m_key[KEYID_END][KETSTATE_END] = {};
int m_keyID[KEYID_END] = { VK_LEFT, VK_RIGHT, VK_SPACE };

void UpdateInput()
{
    bool prePush[KEYID_END] = {};

    for (int i = 0; i < KEYID_END; i++)
    {
        // 직전 키 상태 보관
        prePush[i] = m_key[i][DOWN];

        // 현재 키 상태 보관
        {
            if (GetAsyncKeyState(m_keyID[i]) & 0x8000)
            {
                m_key[i][DOWN] = true;
            }
            else
            {
                m_key[i][DOWN] = false;
            }
        }

        // 탭 여부 판단
        {
            if (prePush[i] == false && m_key[i][DOWN] == true)
            {
                m_key[i][TAP] = true;
            }
            else
            {
                m_key[i][TAP] = false;
            }
        }
    }

    return;
}

bool GetKey(KeyID _keyId, KeyState _keyState)
{
    return m_key[_keyId][_keyState];
}