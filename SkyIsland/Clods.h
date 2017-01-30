#pragma once
#include "stdinc.h"
#include "Clod.h"

namespace SkyIsland {
	class Clods {
	public:
		static Clod *Air, *Soil;

		static void initClods();
	};
}