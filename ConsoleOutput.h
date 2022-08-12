#pragma once

class CConsoleOutput
{
	HANDLE m_hStdOutput;
	HANDLE m_hBackBuffer;
	int m_nBufferWidth;
	int m_nBufferHeight;

	std::vector<CHAR_INFO> m_vecBuffer;

public:
	CConsoleOutput(void);
	~CConsoleOutput(void);

	bool Create(LPCTSTR pszTitle, COORD ScreenSize, COORD WorldSize);
	void Destroy(void);

	void Clear(void);
	void Print(short x, short y, std::string strContext, DWORD dwLen);
	void Flip(SMALL_RECT WorldRect, COORD ScreenPos);
};

