#pragma once
#include "stdinc.h"
namespace SkyIsland {
	class Textures
	{
	public:
		enum ClodTextures {
			Stone = 0,
			Soil,
			Grass_Top,
			Grass_Side
		};

		static GLuint TerrainTex;

		static void initTextures();
		static void bindTexture(GLuint tex);

		static GLuint loadGLTexture(string fileName);
		static float getClodTexOffsetX(ClodTextures clod);
		static float getClodTexOffsetY(ClodTextures clod);
	};
}

