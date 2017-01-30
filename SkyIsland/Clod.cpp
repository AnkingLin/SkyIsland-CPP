#include "Clod.h"

namespace SkyIsland {
	Clod Clod::clods[65536];

	Clod::Clod(unsigned short id)
	{
		this->ID = id;
		clods[id] = *this;
	}

	bool Clod::isNormalBlock() const {
		return false;
	}

	void Clod::render(int x, int y, int z)
	{
		ClodRenderer::setRenderPos(x, y, z);
	}
}
