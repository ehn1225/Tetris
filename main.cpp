#include "pch.h"
#include "Tetris.h"
//20220812 BoB 11기 보안제품개발 이예찬
int main()
{
	CTetris tetris;

	int nFPS = 120;
	int nSleepTime = 1000 / nFPS;
	while (tetris.GetStatus())
	{
		std::list<ST_KEYSTATE> keyState;

		tetris.Input(keyState);
		tetris.Update(keyState, nSleepTime);
		tetris.Render();

		Sleep(nSleepTime);
	}
	printf("Game Over (Press Enter to close Game)");
	getchar();
	return 0;
}
