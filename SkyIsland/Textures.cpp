#include "Textures.h"

namespace SkyIsland {
	GLuint Textures::TerrainTex;

	void Textures::initTextures()
	{
		TerrainTex = loadGLTexture("Resources/Textures/Terrain.png");
	}

	void Textures::bindTexture(GLuint tex)
	{
		if (!glIsEnabled(GL_TEXTURE_2D))
			glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, tex);

		if (tex = 0)
			glDisable(GL_TEXTURE_2D);
	}

	GLuint Textures::loadGLTexture(string fileName)
	{
		GLint texture;
		texture = SOIL_load_OGL_texture(fileName.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
		if (texture == 0) {
			cerr << "Texture Load Error:" << fileName << endl;
		}
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glBindTexture(GL_TEXTURE_2D, 0);
		return texture;
	}
	float Textures::getClodTexOffsetX(ClodTextures clod)
	{
		switch (clod)
		{
		case Stone:
			return 0.0f;
			break;

		case Soil:
			return 0.03125f;
			break;

		case Grass_Top:
			return 0.03125f * 2;
			break;

		case Grass_Side:
			return 0.03125f * 3;

		default:
			break;
		}
		return 0.0f;
	}
	float Textures::getClodTexOffsetY(ClodTextures clod)
	{
		switch (clod)
		{
		case Stone:
			return 0.0f;
			break;

		default:
			break;
		}
		return 0.0f;
	}
}
