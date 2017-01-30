#pragma once
#include "SIE.h"
namespace SkyIsland {
	class SkyIslandGame
	{
	public:
		//OpenGL视图
		GLView *view;

		//默认初始化函数
		SkyIslandGame();

		void initGame();
		//渲染游戏
		void renderGame();
		//更新游戏
		void updateGame();
	};
}

