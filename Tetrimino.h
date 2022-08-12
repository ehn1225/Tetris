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
	bool available = false; //�ش� ���� Ȱ��ȭ ����
	std::stack<ST_TETRIMINO_STATE> m_stackState;
	char* background = NULL; //CMap�� char* array�� ����.

public:
	void Reset(int nType);
	void PushState(void);
	void RestoreState(void);
	void PopState(void);
	void GetPosition(int* x, int* y); //���� ���� ��ġ ����
	void GetBlock(char* map);			//���� ����Ʈ �迭�� ����
	bool GetAvailable();				//Ȱ��ȭ ���� ����
	void SetAvailable(bool status);		//Ȱ��ȭ ���� ����
	void SetBackground(char*);			//���� ����κ��� ġȯ�� ��� ����

	void Move(int nOffset);
	void Down(int nOffset);
	void Rotate(int nDir = 1);
	void OnDraw(CConsoleOutput*);
};

