#include "Clods.h"
#include "SoilClod.h"

namespace SkyIsland {
	Clod *Clods::Air, *Clods::Soil;

	void Clods::initClods()
	{
		Air = new Clod();
		Soil = new SoilClod();
	}
}
