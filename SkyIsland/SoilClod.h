#pragma once
#include "ClodRenderer.h"
#include "Clod.h"
namespace SkyIsland {
	class SoilClod :public Clod
	{
	public:
		SoilClod();

		virtual void render(int x, int y, int z) override;
	};
}

