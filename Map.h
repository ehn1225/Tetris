#pragma once
#include "Tetrimino.h"
#include "RenderObject.h"

const int g_nBlockWidth = 12;
const int g_nBlockHeight = 18;
const int g_nMapMargin = 2;
const int g_nMapWidth = g_nBlockWidth + g_nMapMargin * 2;
const int g_nMapHeight = g_nBlockHeight + g_nMapMargin;

class CMap : public CRenderObject
{
	char m_szMapData[g_nMapHeight][g_nMapWidth + 1];
	char m_szMapTetrinoData[g_nBlockHeight][g_nBlockWidth];
	int line = 0;

public:
	void Clear(void);
	bool IsCollide(CTetrimino* pTetrimino);
	void AppendTetrinoData(CTetrimino* pTetrimino);
	void Pile(CTetrimino* pTetrimino);
	void OnDraw(CConsoleOutput* pOutput);
	void GetMapData(char * arr);
};

