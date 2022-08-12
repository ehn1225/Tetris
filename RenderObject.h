#pragma once

#include "ConsoleOutput.h"

class CRenderObject
{
protected:
	int m_nPosX;
	int m_nPosY;

public:
	virtual void OnDraw(CConsoleOutput* pOutput) = 0;
};
