#include "Island.h"
#include "SIE.h"

namespace SkyIsland {
	Island::Island(Sky *sky, int ix, int iy, int iz) {
		this->sky = sky;

		this->ix = ix;
		this->iy = iy;
		this->iz = iz;
		this->sx = ix * 16;
		this->iy = iy * 16;
		this->sz = iz * 16;

		this->isFlush = false;

		this->vbo = VBO::createVBO();

		build();
	}

	void Island::build()
	{
		for (int x = 0; x < 16; x++) {
			for (int y = 0; y < 16; y++) {
				for (int z = 0; z < 16; z++) {
					clods[(x << 8) ^ (y << 4) ^ z] = Clods::Soil;
				}
			}
		}
	}

	void Island::flushVBO()
	{
		VBO::init();
		for (int x = 0; x < 16; x++) {
			for (int y = 0; y < 16; y++) {
				for (int z = 0; z < 16; z++) {
					this->clods[(x << 8) ^ (y << 4) ^ z]->render(this->sx + x, this->iy + y, this->sz + z);
				}
			}
		}
		VBO::flush(this->vbo);
		this->isFlush = true;
	}

	void Island::render()
	{
		if (!isFlush)
			flushVBO();
		VBO::render(this->vbo);
	}

	bool Island::setClod(Clod *newClod, int x, int y, int z)
	{
		if (x > 15 || x < 0 || y>15 || y < 0 || z>15 || z < 0)
			return false;
		clods[(x << 8) ^ (y << 4) ^ z] = newClod;
		return true;
	}

	Clod *Island::getClod(int x, int y, int z)
	{
		if (x > 15 || x < 0 || y>15 || y < 0 || z>15 || z < 0)
			return Clods::Air;
		return clods[(x << 8) ^ (y << 4) ^ z];
	}
}