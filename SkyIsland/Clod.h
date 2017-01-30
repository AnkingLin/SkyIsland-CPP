#pragma once
#include "stdinc.h"
#include "ClodRenderer.h"
namespace SkyIsland {
	class Clod
	{
	public:
		static Clod clods[];

		unsigned short ID;

		Clod() :Clod(0) {}
		Clod(unsigned short id);

		virtual bool isNormalBlock() const;
		virtual void render(int x, int y, int z);
	};
}

