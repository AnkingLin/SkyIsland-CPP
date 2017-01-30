#pragma once
#include "stdinc.h"
#include "Clods.h"

namespace SkyIsland {
	class Sky;

	class Island {
	public:
		GLuint vbo;
		int ix, iy, iz, sx, sy, sz;
		bool isFlush;
		Clod *clods[4096];
		Sky *sky;

		Island(Sky *sky, int ix, int iy, int iz);

		void build();
		void flushVBO();
		void render();

		bool setClod(Clod *newClod, int x, int y, int z);
		Clod *getClod(int x, int y, int z);
	};
}