#include "stdinc.h"
#include "SkyIslandGame.h"

int main() {
	SkyIsland::SkyIslandGame game;
	//��ѭ��
	while (!glfwWindowShouldClose(game.view->win))
	{
		game.renderGame();
		game.updateGame();
	}
	game.view->destroyWindow();
	return 0;
}