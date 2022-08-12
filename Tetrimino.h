#pragma once
#include "RenderObject.h"
#include <stack>

enum E_TETRIMINO_TYPE
{
	TETRIMINO_I = 0,
	TETRIMINO_O,
	TETRIMINO_J,
	TETRIMINO_L,
	TETRIMINO_S,
	TETRIMINO_Z,
	TETRIMINO_T,
	TETRIMINO_COUNT
};

struct ST_TETRIMINO_STATE
{
	int nRotation;
	int nPosX;
	int nPosY;
};

class CTetrimino : public CRenderObject
{
	char m_szBlock[4][4][4 + 1];
	int m_nRotation;
	bool available = false; //해당 블럭의 활성화 여부
	std::stack<ST_TETRIMINO_STATE> m_stackState;
	char* background = NULL; //CMap을 char* array로 받음.

public:
	void Reset(int nType);
	void PushState(void);
	void RestoreState(void);
	void PopState(void);
	void GetPosition(int* x, int* y); //블럭의 절대 위치 리턴
	void GetBlock(char* map);			//블럭을 바이트 배열로 리턴
	bool GetAvailable();				//활성화 여부 리턴
	void SetAvailable(bool status);		//활성화 여부 지정
	void SetBackground(char*);			//블럭의 투명부분을 치환할 배경 지정

	void Move(int nOffset);
	void Down(int nOffset);
	void Rotate(int nDir = 1);
	void OnDraw(CConsoleOutput*);
};

