#include "pch.h"
#include "ConsoleOutput.h"

CConsoleOutput::CConsoleOutput(void)
	: m_hStdOutput(nullptr)
	, m_hBackBuffer(nullptr)
	, m_nBufferWidth(0)
	, m_nBufferHeight(0)
{
}

CConsoleOutput::~CConsoleOutput(void)
{

}

bool CConsoleOutput::Create(LPCTSTR pszTitle, COORD ScreenSize, COORD WorldSize)
{
	m_nBufferWidth = WorldSize.X;
	m_nBufferHeight = WorldSize.Y;

	try
	{
		SetConsoleTitle(pszTitle);

		{	// 후면 버퍼 생성
			m_hBackBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
			if (nullptr == m_hBackBuffer)
				throw std::runtime_error("CreateConsoleScreenBuffer error");

			CONSOLE_SCREEN_BUFFER_INFOEX stBufferInfo;
			stBufferInfo.cbSize = sizeof(stBufferInfo);
			if (!GetConsoleScreenBufferInfoEx(m_hBackBuffer, &stBufferInfo))
				throw std::runtime_error("Failed to GetConsoleScreenBufferInfoEx");

			stBufferInfo.dwSize.X = WorldSize.X;
			stBufferInfo.dwSize.Y = WorldSize.Y;
			stBufferInfo.dwMaximumWindowSize.X = WorldSize.X;
			stBufferInfo.dwMaximumWindowSize.Y = WorldSize.Y;
			if (!SetConsoleScreenBufferInfoEx(m_hBackBuffer, &stBufferInfo))
				throw std::runtime_error("Failed to SetConsoleScreenBufferInfoEx");
		}

		{	// 디스플레이 버퍼 생성
			m_hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
			SMALL_RECT stDisplayArea = { 0, 0, ScreenSize.X, ScreenSize.Y };
			if (!SetConsoleWindowInfo(m_hStdOutput, TRUE, &stDisplayArea))
				throw std::runtime_error("Failed to StdOut SetConsoleWindowInfo");

			CONSOLE_SCREEN_BUFFER_INFOEX stBufferInfo;
			stBufferInfo.cbSize = sizeof(stBufferInfo);
			if (!GetConsoleScreenBufferInfoEx(m_hStdOutput, &stBufferInfo))
				throw std::runtime_error("Failed to GetConsoleScreenBufferInfoEx");

			stBufferInfo.dwSize.X = ScreenSize.X;
			stBufferInfo.dwSize.Y = ScreenSize.Y;
			stBufferInfo.dwMaximumWindowSize.X = ScreenSize.X;
			stBufferInfo.dwMaximumWindowSize.Y = ScreenSize.Y;
			if (!SetConsoleScreenBufferInfoEx(m_hStdOutput, &stBufferInfo))
				throw std::runtime_error("Failed to SetConsoleScreenBufferInfoEx");

			// 콘솔 커서 없애기
			CONSOLE_CURSOR_INFO cursorInfo = { 0, };
			cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
			cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
			SetConsoleCursorInfo(m_hStdOutput, &cursorInfo);
		}
	}
	catch (const std::exception& e)
	{
		printf("%s\n", e.what());
		Destroy();
		return false;
	}
	return true;
}

void CConsoleOutput::Destroy(void)
{
	if (m_hBackBuffer)
		CloseHandle(m_hBackBuffer);
	m_hBackBuffer = nullptr;
}

void CConsoleOutput::Clear(void)
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(m_hBackBuffer, ' ', m_nBufferWidth * m_nBufferHeight, Coor, &dw);
}

void CConsoleOutput::Print(short x, short y, std::string strContext, DWORD dwLen)
{
	dwLen = std::min<DWORD>(dwLen, strContext.length());

	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(m_hBackBuffer, CursorPosition);
	WriteFile(m_hBackBuffer, strContext.c_str(), dwLen, &dw, NULL);
}

void CConsoleOutput::Flip(SMALL_RECT WorldRect, COORD ScreenPos)
{
	SMALL_RECT rtRead = WorldRect;
	const COORD size = { WorldRect.Right - WorldRect.Left + 1, WorldRect.Bottom - WorldRect.Top + 1 };
	const COORD pos = { WorldRect.Left, WorldRect.Top };

	m_vecBuffer.resize(size.X * size.Y);

	ReadConsoleOutput(m_hBackBuffer, &m_vecBuffer[0], size, pos, &rtRead);

	SMALL_RECT rtWrite = rtRead;
	rtWrite.Left = ScreenPos.X;
	rtWrite.Top = ScreenPos.Y;
	rtWrite.Right = ScreenPos.X + size.X;
	rtWrite.Bottom = ScreenPos.Y + size.Y;
	WriteConsoleOutput(m_hStdOutput, &m_vecBuffer[0], size, COORD{ 0, 0 }, &rtWrite);
}
