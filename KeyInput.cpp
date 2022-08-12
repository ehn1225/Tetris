#include "pch.h"
#include "KeyInput.h"

CKeyInput::CKeyInput(void)
{
}

void CKeyInput::Register(int nID, int nVirtKey)
{
    m_mapRegisteredKey.insert(std::make_pair(nID, nVirtKey));
}

void CKeyInput::Query(std::list<ST_KEYSTATE>& outState)
{
    for (auto iter : m_mapRegisteredKey)
    {
        short nCurState = GetKeyState(iter.second);
        short nPreState = m_mapLastKeyState[iter.second];
        m_mapLastKeyState[iter.second] = nCurState;

        short nDiff = nCurState ^ nPreState;
        if (0 == (nDiff & 0x8000))        // 키가 눌리지 않았다면
            continue;

        ST_KEYSTATE KeyState;
        KeyState.nID = iter.first;
        KeyState.nVirtKey = iter.second;
        KeyState.bPressed = (nCurState & 0x8000) ? true : false;
        KeyState.bReserved = 0;
        outState.push_back(KeyState);
    }
}
