#include "Sky.h"

namespace SkyIsland {
	Sky::Sky() {
		
	}

	void Sky::render()
	{
		for (vector<Island>::iterator ret = this->islands.begin(); ret != this->islands.end(); ret++) {
			ret->render();
		}
	}

	bool Sky::addIsland(int x, int y, int z) {
		if (this->getIsland(x, y, z) == nullptr) {
			Island *island = new Island(this, x, y, z);
			this->islands.push_back(*island);
			return true;
		}
		return false;
	}

	Island * Sky::getIsland(int x, int y, int z)
	{
		for (vector<Island>::iterator ret = this->islands.begin(); ret != this->islands.end(); ret++) {
			if (ret->ix == x&&ret->iy == y&&ret->iz == z)
				return &(*ret);
		}
		return nullptr;
	}

	bool Sky::setClod(Clod *newClod,int x, int y, int z)
	{
		int cx = (x) & 15, cy = (x) & 15, cz = (z) & 15;
		int ix = (x) << 4, iy = (y) << 4, iz = (z) << 4;
		Island *i = this->getIsland(ix, iy, iz);

		if (i != nullptr) {
			i->setClod(newClod, cx, cy, cz);
			return true;
		}

		return false;
	}

	Clod * Sky::getClod(int x, int y, int z)
	{
		int cx = (x) & 15, cy = (x) & 15, cz = (z) & 15;
		int ix = (x) << 4, iy = (y) << 4, iz = (z) << 4;
		Island *i = this->getIsland(ix, iy, iz);

		if (i != nullptr) {
			return i->getClod(cx, cy, cz);
		}

		return Clods::Air;
	}
}