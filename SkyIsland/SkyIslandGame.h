#pragma once
#include "SIE.h"
namespace SkyIsland {
	class SkyIslandGame
	{
	public:
		//OpenGL��ͼ
		GLView *view;

		//Ĭ�ϳ�ʼ������
		SkyIslandGame();

		void initGame();
		//��Ⱦ��Ϸ
		void renderGame();
		//������Ϸ
		void updateGame();
	};
}

