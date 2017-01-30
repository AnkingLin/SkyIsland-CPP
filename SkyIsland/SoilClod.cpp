#include "SoilClod.h"
#include "Clod.h"

namespace SkyIsland {

	SoilClod::SoilClod() :Clod(1) {

	}

	void SoilClod::render(int x, int y, int z) {
		Clod::render(x, y, z);
		ClodRenderer::setTexture(Textures::ClodTextures::Soil);
		ClodRenderer::renderBox(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f);
	}
}
