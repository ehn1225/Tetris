#include "pch.h"
#include "Tetrimino.h"

void CTetrimino::Reset(int nType)
{
	m_nPosX = 5;
	m_nPosY = 0;
	m_nRotation = 0;
	available = true;

	switch (nType)
	{
	case TETRIMINO_I:
		memcpy(m_szBlock[0][0], "I   ", 5);
		memcpy(m_szBlock[0][1], "I   ", 5);
		memcpy(m_szBlock[0][2], "I   ", 5);
		memcpy(m_szBlock[0][3], "I   ", 5);
		
		memcpy(m_szBlock[1][0], "IIII", 5);
		memcpy(m_szBlock[1][1], "    ", 5);
		memcpy(m_szBlock[1][2], "    ", 5);
		memcpy(m_szBlock[1][3], "    ", 5);

		memcpy(m_szBlock[2][0], "I   ", 5);
		memcpy(m_szBlock[2][1], "I   ", 5);
		memcpy(m_szBlock[2][2], "I   ", 5);
		memcpy(m_szBlock[2][3], "I   ", 5);

		memcpy(m_szBlock[3][0], "IIII", 5);
		memcpy(m_szBlock[3][1], "    ", 5);
		memcpy(m_szBlock[3][2], "    ", 5);
		memcpy(m_szBlock[3][3], "    ", 5);
		break;

	case TETRIMINO_O:
		memcpy(m_szBlock[0][0], "OO  ", 5);
		memcpy(m_szBlock[0][1], "OO  ", 5);
		memcpy(m_szBlock[0][2], "    ", 5);
		memcpy(m_szBlock[0][3], "    ", 5);

		memcpy(m_szBlock[1][0], "OO  ", 5);
		memcpy(m_szBlock[1][1], "OO  ", 5);
		memcpy(m_szBlock[1][2], "    ", 5);
		memcpy(m_szBlock[1][3], "    ", 5);

		memcpy(m_szBlock[2][0], "OO  ", 5);
		memcpy(m_szBlock[2][1], "OO  ", 5);
		memcpy(m_szBlock[2][2], "    ", 5);
		memcpy(m_szBlock[2][3], "    ", 5);

		memcpy(m_szBlock[3][0], "OO  ", 5);
		memcpy(m_szBlock[3][1], "OO  ", 5);
		memcpy(m_szBlock[3][2], "    ", 5);
		memcpy(m_szBlock[3][3], "    ", 5);
		break;

	case TETRIMINO_J:
		memcpy(m_szBlock[0][0], "JJJ ", 5);
		memcpy(m_szBlock[0][1], "  J ", 5);
		memcpy(m_szBlock[0][2], "    ", 5);
		memcpy(m_szBlock[0][3], "    ", 5);

		memcpy(m_szBlock[1][0], "JJ  ", 5);
		memcpy(m_szBlock[1][1], "J   ", 5);
		memcpy(m_szBlock[1][2], "J   ", 5);
		memcpy(m_szBlock[1][3], "    ", 5);

		memcpy(m_szBlock[2][0], "J   ", 5);
		memcpy(m_szBlock[2][1], "JJJ ", 5);
		memcpy(m_szBlock[2][2], "    ", 5);
		memcpy(m_szBlock[2][3], "    ", 5);

		memcpy(m_szBlock[3][0], " J  ", 5);
		memcpy(m_szBlock[3][1], " J  ", 5);
		memcpy(m_szBlock[3][2], "JJ  ", 5);
		memcpy(m_szBlock[3][3], "    ", 5);
		break;

	case TETRIMINO_L:
		memcpy(m_szBlock[0][0], "    ", 5);
		memcpy(m_szBlock[0][1], "LLL ", 5);
		memcpy(m_szBlock[0][2], "L   ", 5);
		memcpy(m_szBlock[0][3], "    ", 5);

		memcpy(m_szBlock[1][0], " L  ", 5);
		memcpy(m_szBlock[1][1], " L  ", 5);
		memcpy(m_szBlock[1][2], " LL ", 5);
		memcpy(m_szBlock[1][3], "    ", 5);

		memcpy(m_szBlock[2][0], "  L ", 5);
		memcpy(m_szBlock[2][1], "LLL ", 5);
		memcpy(m_szBlock[2][2], "    ", 5);
		memcpy(m_szBlock[2][3], "    ", 5);

		memcpy(m_szBlock[3][0], "LL  ", 5);
		memcpy(m_szBlock[3][1], " L  ", 5);
		memcpy(m_szBlock[3][2], " L  ", 5);
		memcpy(m_szBlock[3][3], "    ", 5);
		break;

	case TETRIMINO_S:
		memcpy(m_szBlock[0][0], " SS ", 5);
		memcpy(m_szBlock[0][1], "SS  ", 5);
		memcpy(m_szBlock[0][2], "    ", 5);
		memcpy(m_szBlock[0][3], "    ", 5);

		memcpy(m_szBlock[1][0], "S   ", 5);
		memcpy(m_szBlock[1][1], "SS  ", 5);
		memcpy(m_szBlock[1][2], " S  ", 5);
		memcpy(m_szBlock[1][3], "    ", 5);

		memcpy(m_szBlock[2][0], " SS ", 5);
		memcpy(m_szBlock[2][1], "SS  ", 5);
		memcpy(m_szBlock[2][2], "    ", 5);
		memcpy(m_szBlock[2][3], "    ", 5);

		memcpy(m_szBlock[3][0], "S   ", 5);
		memcpy(m_szBlock[3][1], "SS  ", 5);
		memcpy(m_szBlock[3][2], " S  ", 5);
		memcpy(m_szBlock[3][3], "    ", 5);
		break;

	case TETRIMINO_Z:
		memcpy(m_szBlock[0][0], "ZZ  ", 5);
		memcpy(m_szBlock[0][1], " ZZ ", 5);
		memcpy(m_szBlock[0][2], "    ", 5);
		memcpy(m_szBlock[0][3], "    ", 5);

		memcpy(m_szBlock[1][0], " Z  ", 5);
		memcpy(m_szBlock[1][1], "ZZ  ", 5);
		memcpy(m_szBlock[1][2], "Z   ", 5);
		memcpy(m_szBlock[1][3], "    ", 5);

		memcpy(m_szBlock[2][0], "ZZ  ", 5);
		memcpy(m_szBlock[2][1], " ZZ ", 5);
		memcpy(m_szBlock[2][2], "    ", 5);
		memcpy(m_szBlock[2][3], "    ", 5);

		memcpy(m_szBlock[3][0], " Z  ", 5);
		memcpy(m_szBlock[3][1], "ZZ  ", 5);
		memcpy(m_szBlock[3][2], "Z   ", 5);
		memcpy(m_szBlock[3][3], "    ", 5);
		break;

	case TETRIMINO_T:
		memcpy(m_szBlock[0][0], " T  ", 5);
		memcpy(m_szBlock[0][1], "TTT ", 5);
		memcpy(m_szBlock[0][2], "    ", 5);
		memcpy(m_szBlock[0][3], "    ", 5);
		 
		memcpy(m_szBlock[1][0], " T  ", 5);
		memcpy(m_szBlock[1][1], "TT  ", 5);
		memcpy(m_szBlock[1][2], " T  ", 5);
		memcpy(m_szBlock[1][3], "    ", 5);

		memcpy(m_szBlock[2][0], "TTT ", 5);
		memcpy(m_szBlock[2][1], " T  ", 5);
		memcpy(m_szBlock[2][2], "    ", 5);
		memcpy(m_szBlock[2][3], "    ", 5);

		memcpy(m_szBlock[3][0], "T   ", 5);
		memcpy(m_szBlock[3][1], "TT  ", 5);
		memcpy(m_szBlock[3][2], "T   ", 5);
		memcpy(m_szBlock[3][3], "    ", 5);
		break;
	}
}

void CTetrimino::PushState(void)
{
	ST_TETRIMINO_STATE state;
	state.nPosX = m_nPosX;
	state.nPosY = m_nPosY;
	state.nRotation = m_nRotation;
	m_stackState.push(state);
}

void CTetrimino::RestoreState(void)
{
	if (m_stackState.empty())
		return;
	m_nPosX = m_stackState.top().nPosX;
	m_nPosY = m_stackState.top().nPosY;
	m_nRotation = m_stackState.top().nRotation;
	m_stackState.pop();
}
bool CTetrimino::GetAvailable() {
	//테트리미노가 활성화 상태인지
	return available;
}
void CTetrimino::SetAvailable(bool status) {
	//테트리미노가 활성화 여부 설정
	available = status;
}
void CTetrimino::PopState(void)
{
	if (m_stackState.empty())
		return;

	m_stackState.pop();
}

void CTetrimino::Move(int nOffset)
{
	m_nPosX += nOffset;
}

void CTetrimino::Down(int nOffset)
{
	m_nPosY += nOffset;
}
void CTetrimino::GetPosition(int* x, int* y)
{
	*x = m_nPosX;
	*y = m_nPosY;
}
void CTetrimino::GetBlock(char* map) {
	//테트리미노를 매개변수로 받은 포인터로 넘겨줌
	memcpy(map, m_szBlock[m_nRotation], 20);
}

void CTetrimino::Rotate(int nDir)
{
	m_nRotation = (m_nRotation + nDir) % 4;
}
void CTetrimino::SetBackground(char * ptr) {
	//배경을 포인터로 받아옴
	background = ptr;
}
void CTetrimino::OnDraw(CConsoleOutput* pRenderer)
{
	//투명부분은 해당좌표의 CMap으로 바뀌게끔 시각화.
	char buffer[4][5];
	memcpy(buffer, m_szBlock[m_nRotation], 20);
	int tmp = 0;
	for (int i = 0; i < 20; i++) {
		int x = i % 5;
		int y = i / 5;
		if (i % 5 == 4)//null은 건너뜀
			continue;
		if ('Z' < buffer[y][x] || buffer[y][x] < 'A') {
			if (background == NULL)
				break;
			buffer[y][x] = background[((m_nPosY+y) * (17))+(m_nPosX+x)];//공백부분은 배경으로 변경
		}
	}
	pRenderer->Print(m_nPosX, m_nPosY + 0, buffer[0], 4);
	pRenderer->Print(m_nPosX, m_nPosY + 1, buffer[1], 4);
	pRenderer->Print(m_nPosX, m_nPosY + 2, buffer[2], 4);
	pRenderer->Print(m_nPosX, m_nPosY + 3, buffer[3], 4);

}
