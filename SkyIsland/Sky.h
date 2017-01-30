#pragma once
#include "stdinc.h"
#include "Island.h"
namespace SkyIsland {
	class Sky {
	public:
		vector<Island> islands;

		Sky();

		void render();

		bool addIsland(int x, int y, int z);
		Island *getIsland(int x, int y, int z);
		bool setClod(Clod *newClod,int x, int y, int z);
		Clod *getClod(int x, int y, int z);
	};
}