#include "pch.h"
#include "Tetris.h"

enum E_GAMEKEY_TYPE
{
    GAMEKEY_LEFT,
    GAMEKEY_RIGHT,
    GAMEKEY_ROTATE,
    GAMEKEY_DOWN,
    GAMEKEY_SMASH,
};

CTetris::CTetris(void)
    : m_Map()
    , m_Tetrimino()
    , m_Input()
    , m_Output()
{
    m_Map.Clear();
    m_Tetrimino.Reset(rand() % TETRIMINO_COUNT);
    m_Input.Register(GAMEKEY_LEFT,      VK_LEFT);
    m_Input.Register(GAMEKEY_RIGHT,     VK_RIGHT);
    m_Input.Register(GAMEKEY_ROTATE,        VK_UP);
    m_Input.Register(GAMEKEY_DOWN,      VK_DOWN);
    m_Input.Register(GAMEKEY_SMASH,    VK_SPACE);
    m_Output.Create(TEXT("BoB TETRIS"), COORD{ 100, 30 }, COORD{ g_nMapWidth, g_nMapHeight });
    map = (char*)malloc(sizeof(char) * (g_nMapWidth+1) * g_nMapHeight);
    m_Map.GetMapData(map);
    m_Tetrimino.SetBackground(map);
}

CTetris::~CTetris(void)
{
    free(map);
    m_Output.Destroy();
}

void CTetris::Input(std::list<ST_KEYSTATE>& outState)
{
    m_Input.Query(outState);
}

void CTetris::Update(const std::list<ST_KEYSTATE> stKeyState, int nSpeed)
{
    m_Tetrimino.PushState();

    if (m_Tetrimino.GetAvailable() == false) {
        m_Tetrimino.Reset(rand() % TETRIMINO_COUNT);
        m_Map.GetMapData(map);
        m_Tetrimino.SetBackground(map);
        return;
    }

    for (ST_KEYSTATE key : stKeyState)
    {
        if (!key.bPressed)
            continue;

        switch (key.nID)
        {
        case GAMEKEY_LEFT:
            m_Tetrimino.Move(-1);
            break;
        case GAMEKEY_RIGHT:
            m_Tetrimino.Move(1);
            break;
        case GAMEKEY_ROTATE:
            m_Tetrimino.Rotate();
            break;
        case GAMEKEY_DOWN:
            m_Tetrimino.Down(1);
            break;
        case GAMEKEY_SMASH:
            while (!m_Map.IsCollide(&m_Tetrimino)) {
                m_Tetrimino.Down(1);
                if (!m_Map.IsCollide(&m_Tetrimino)) {
                    m_Tetrimino.PopState();
                    m_Tetrimino.PushState();
                }
                else {
                    m_Tetrimino.RestoreState();
                    nSpeed = 1000;
                    break;
                }              
            }
            break;
        }
    }
    nElapsedTick += nSpeed;
    bool isDeadBlock = false;
    if (nElapsedTick >= nSpeed * 100) {
        m_Tetrimino.Down(1);
        nElapsedTick = 0;
        isDeadBlock = true;
    }

    if (m_Map.IsCollide(&m_Tetrimino)) {
        if (isDeadBlock) {
            m_Map.AppendTetrinoData(&m_Tetrimino);
            m_Tetrimino.SetAvailable(false);
        }
        if (!isDeadBlock && !m_Tetrimino.GetAvailable()) {
            //DeadBlock 이벤트가 아닌데, Available == false일 경우 게임이 끝난 것임.
            run = false;
        }

        m_Tetrimino.RestoreState();
    }
    else
        m_Tetrimino.PopState();

}
bool CTetris::GetStatus() {
    //게임의 진행 여부를 알려줍니다.
    //게임이 끝났다면 false를 리턴합니다
    return run;
}

void CTetris::Render(void)
{
    m_Output.Clear();
    m_Map.OnDraw(&m_Output);
    m_Tetrimino.OnDraw(&m_Output);
    m_Output.Flip(SMALL_RECT{ 0, 0, g_nMapWidth - 1, g_nMapHeight - 1 }, COORD{ 40, 5 });
}