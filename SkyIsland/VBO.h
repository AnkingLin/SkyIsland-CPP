#pragma once
#include "stdinc.h"
namespace SIE {
	class VBO
	{
	public:
		static const int VBSize = 2621440;
		static int vi, vc;
		static bool useTex, useColor;
		static GLfloat *vertices,  texCoordX, texCoordY, colorR, colorG, colorB, colorA;

		static void init();

		static void texCoord2f(float x, float y);
		static void color3f(float r, float g, float b);
		static void color4f(float r, float g, float b, float a);
		static void vertex3f(float x, float y, float z);
		static void vertexAndTexCoord(float x, float y, float z, float s, float t);
		static void renderFace(float x, float y, float z, float w, float h, float d, int face);
		static void renderBox(float x, float y, float z, float w, float h, float d);

		static void flush(GLuint &VBO);
		static void render(GLuint &VBO);

		static GLuint createVBO();
	};
}

