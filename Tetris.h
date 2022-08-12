#pragma once
#include "Map.h"
#include "Tetrimino.h"
#include "KeyInput.h"
#include "ConsoleOutput.h"

class CTetris
{
	CMap m_Map;
	CTetrimino m_Tetrimino;
	CKeyInput m_Input;
	CConsoleOutput m_Output;
	char* map = NULL;	//Tetrimino로 전달할 배경 포인터
	int nElapsedTick = 0;	//시간이 지나면 블록이 내려갈 때 사용
	bool run = true;	//게임의 실행 여부

public:
	CTetris(void);
	~CTetris(void);

	void Input(std::list<ST_KEYSTATE>& outState);
	void Update(const std::list<ST_KEYSTATE> stKeyState, int nElapsedTick);
	void Render(void);
	bool GetStatus();
};

