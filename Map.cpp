#include "pch.h"
#include "Map.h"


void CMap::Clear(void)
{
	m_nPosX = 0;
	m_nPosY = 0;

	for (int y = 0; y < g_nMapHeight; y++)
		memset(m_szMapData[y], '*', g_nMapWidth);
	for (int y = 0; y < g_nBlockHeight; y++)
		memset(m_szMapTetrinoData[y], ' ', g_nBlockWidth);
	for (int y = 0; y < g_nBlockHeight; y++)
		memcpy(m_szMapData[y] + g_nMapMargin, m_szMapTetrinoData[y], g_nBlockWidth);
}


bool CMap::IsCollide(CTetrimino* pTetrimino)
{
	//wall	x = 0,1,13,14, y = 18, 19
	//m_szBlock �ٿ���� üũ �� ������ ġȯ
	//���� ���� �κп� ���Ͽ� map�� ��ġ�� ���� ������ üũ

	int* px = new int, *py = new int;
	pTetrimino->GetPosition(px, py);
	char *map = (char *)malloc(sizeof(char) * 20);
	pTetrimino->GetBlock(map);
	//printf("\r");
	for (int i = 0; i < 20; i++) {
		int x = i % 5;
		int y = i / 4;
		if ('A' <= map[i] && map[i] <= 'Z') {
			//printf("(%d, %d)", *px+x, *py+y); absolute position
			//������ġ�� ���Ͽ� �ش� ��ġ�� ������ �ƴ϶�� True
			if (m_szMapData[*py + y][*px + x] != ' ') {
				for (int j = 0; j < g_nBlockWidth; j++) {
					if ('A' <= m_szMapData[1][j] && m_szMapData[1][j] <= 'Z') {
						char text[10] = "GAMEOVER";
						memcpy(m_szMapTetrinoData[10] + 2, text, 8);
						pTetrimino->SetAvailable(false);
					}
				}
				return true;
			}
		}
	}
	free(map);

	return false;
}
void CMap::AppendTetrinoData(CTetrimino* pTetrimino) {
	//������ Tetrimino�� �ʿ� ����
	int* px = new int, * py = new int;
	pTetrimino->GetPosition(px, py);
	char* block = (char*)malloc(sizeof(char) * 20);
	pTetrimino->GetBlock(block);
	for (int i = 0; i < 20; i++) {
		int x = i % 5;
		int y = i / 4;
		if ('A' <= block[i] && block[i] <= 'Z') {
			m_szMapTetrinoData[*py + y - 1][*px + x - 2] = block[i];
		}
	}
	Pile(pTetrimino);
	free(block);
}

void CMap::Pile(CTetrimino* pTetrimino){
	//������ ���� ��ĵ�ϰ�, ����� �ٿ� �迭�� �ٿ��ֱ���
	int sum = 0, position = -1;
	for (int i = g_nBlockHeight - 1; i >= 0; i--) {
		for (int j = 0; j < g_nBlockWidth; j++) {
			if ('Z' < m_szMapTetrinoData[i][j] || m_szMapTetrinoData[i][j] < 'A')
				break; //�ٿ� ������ �ִٸ� ���� �ٷ� �Ѿ
			if (j == g_nBlockWidth - 1){//������ ���� á�ٸ�
				if (position == -1)
					position = i;
				sum++;
				line++;
			}
		}
	}
	
	if (sum == 0)//������ ���� ���ٸ� ����
		return;
	int size = (position - sum + 1) * g_nBlockWidth;
	char tmp[g_nBlockHeight][g_nBlockWidth];
	memcpy(tmp, m_szMapTetrinoData, size);
	memcpy(m_szMapTetrinoData[sum], tmp, size);
	printf("\r Score : %d", line);
}

void CMap::OnDraw(CConsoleOutput* pRender)
{
	for (int y = 0; y < g_nBlockHeight; y++)
		memcpy(m_szMapData[y] + g_nMapMargin, m_szMapTetrinoData[y], g_nBlockWidth);
	for (int i = 0; i < g_nMapHeight; i++)
		pRender->Print(m_nPosX, m_nPosY + i, m_szMapData[i], g_nMapWidth);
}
void CMap::GetMapData(char * data) {
	memcpy(data, m_szMapData, g_nMapHeight * (g_nMapWidth+1));
}
