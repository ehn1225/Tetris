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
	char* map = NULL;	//Tetrimino�� ������ ��� ������
	int nElapsedTick = 0;	//�ð��� ������ ����� ������ �� ���
	bool run = true;	//������ ���� ����

public:
	CTetris(void);
	~CTetris(void);

	void Input(std::list<ST_KEYSTATE>& outState);
	void Update(const std::list<ST_KEYSTATE> stKeyState, int nElapsedTick);
	void Render(void);
	bool GetStatus();
};

