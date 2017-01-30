#include "SkyIslandGame.h"
#include "Sky.h"

namespace SkyIsland {
	Sky *sky;
	GLfloat posx, posy, posz, rotx, roty;

	SkyIslandGame::SkyIslandGame()
	{
		//创建视图
		view = new GLView("SkyIsland", 680, 480, true);
		initGame();
		sky = new Sky();
		sky->addIsland(0, 0, 0);
		sky->addIsland(1, 0, 0);
		sky->addIsland(0, 1, 0);
		sky->addIsland(1, 1, 0);
	}

	void SkyIslandGame::initGame() {
		Textures::initTextures();
		Clods::initClods();
	}

	void SkyIslandGame::renderGame() {
		//开始绘图
		view->beginGL();
		glLoadIdentity();
		glRotatef(-rotx, 1.0f, 0.0f, 0.0f);
		glRotatef(-roty, 0.0f, 1.0f, 0.0f);
		glTranslatef(-posx, -posy, -posz);
		Textures::bindTexture(Textures::TerrainTex);
		sky->render();
		Textures::bindTexture(0);
		view->endGL();
	}

	void SkyIslandGame::updateGame() {
		if (glfwGetKey(view->win, GLFW_KEY_W) == GLFW_PRESS)
			posz -= 0.2f;
		if (glfwGetKey(view->win, GLFW_KEY_S) == GLFW_PRESS)
			posz += 0.2f;
	    if (glfwGetKey(view->win, GLFW_KEY_A) == GLFW_PRESS)
			posx -= 0.2f;
		if (glfwGetKey(view->win, GLFW_KEY_D) == GLFW_PRESS)
			posx += 0.2f;
		if (glfwGetKey(view->win, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
			posy -= 0.2f;
		if (glfwGetKey(view->win, GLFW_KEY_SPACE) == GLFW_PRESS)
			posy += 0.2f;

		if (glfwGetKey(view->win, GLFW_KEY_UP) == GLFW_PRESS)
			rotx += 0.5f;
		if (glfwGetKey(view->win, GLFW_KEY_DOWN) == GLFW_PRESS)
			rotx -= 0.5f;
		if (glfwGetKey(view->win, GLFW_KEY_LEFT) == GLFW_PRESS)
			roty += 0.5f;
		if (glfwGetKey(view->win, GLFW_KEY_RIGHT) == GLFW_PRESS)
			roty -= 0.5f;
	}
}
