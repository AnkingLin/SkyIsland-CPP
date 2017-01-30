#pragma once
#include "stdinc.h"
#include "SIE.h"

#include "Textures.h"
namespace SkyIsland {
	class ClodRenderer {
	public:
		static Textures::ClodTextures tex1, tex2, tex3, tex4, tex5, tex6;
		static float offsetX, offsetY, clodTexSize;
		static int renderPosX, renderPosY, renderPosZ;

		static void setRenderPos(int x, int y, int z);

		static void setTexture(Textures::ClodTextures tex);
		static void setTexture(Textures::ClodTextures tex1, Textures::ClodTextures tex2, Textures::ClodTextures tex3);
		static void setTexture(Textures::ClodTextures tex1, Textures::ClodTextures tex2, Textures::ClodTextures tex3, 
			Textures::ClodTextures tex4, Textures::ClodTextures tex5, Textures::ClodTextures tex6);

		static void renderFace(float x, float y, float z, float w, float h, float d, int face);
		static void renderBox(float x, float y, float z, float w, float h, float d);
	};
}