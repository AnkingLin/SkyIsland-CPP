#include "VBO.h"

namespace SIE {
	int VBO::vi, VBO::vc;
	GLfloat *VBO::vertices, VBO::texCoordX, VBO::texCoordY,
		VBO::colorR, VBO::colorG, VBO::colorB, VBO::colorA;
	bool VBO::useTex, VBO::useColor;

	void VBO::init() {
		texCoordX = texCoordY = 0.0f;
		colorR = colorG = colorB = colorA = 1.0f;
		useTex = useColor = false;
		vi = vc = 0;
		delete[] vertices;
		vertices = new GLfloat[VBSize];
	}

	void VBO::texCoord2f(float x, float y)
	{
		useTex = true;
		texCoordX = x;
		texCoordY = y;
	}

	void VBO::color3f(float r, float g, float b)
	{
		color4f(r, g, b, 1.0f);
	}

	void VBO::color4f(float r, float g, float b, float a)
	{
		useColor = true;
		colorR = r;
		colorG = g;
		colorB = b;
		colorA = a;
	}

	void VBO::vertex3f(float x, float y, float z) {
		vertices[vi] = x;
		vertices[vi + 1] = y;
		vertices[vi + 2] = z;
		vi += 3;
		if (useColor) {
			vertices[vi] = colorR;
			vertices[vi + 1] = colorG;
			vertices[vi + 2] = colorB;
			vertices[vi + 3] = colorA;
			vi += 4;
		}
		if (useTex) {
			vertices[vi] = texCoordX;
			vertices[vi + 1] = texCoordY;
			vi += 2;
		}
		vc++;
	}

	void VBO::vertexAndTexCoord(float x, float y, float z, float s, float t)
	{
		texCoord2f(s, t);
		vertex3f(x, y, z);
	}

	void VBO::renderFace(float x, float y, float z, float w, float h, float d, int face)
	{
		if (face == 0)
		{
			vertexAndTexCoord(-(w / 2) + x, -(h / 2) + y, d / 2 + z, 0, 0);
			vertexAndTexCoord(w / 2 + x, -(h / 2) + y, d / 2 + z, 1, 0);
			vertexAndTexCoord(w / 2 + x, h / 2 + y, d / 2 + z, 1, 1);
			vertexAndTexCoord(-(w / 2) + x, h / 2 + y, d / 2 + z, 0, 1);
		}
		else if (face == 1)
		{
			vertexAndTexCoord(-(w / 2) + x, -(h / 2) + y, -(d / 2) + z, 0, 0);
			vertexAndTexCoord(-(w / 2) + x, h / 2 + y, -(d / 2) + z, 1, 0);
			vertexAndTexCoord(w / 2 + x, h / 2 + y, -(d / 2) + z, 1, 1);
			vertexAndTexCoord(w / 2 + x, -(h / 2) + y, -(d / 2) + z, 0, 1);
		}
		else if (face == 2)
		{
			vertexAndTexCoord(-(w / 2) + x, h / 2 + y, -(d / 2) + z, 0, 0);
			vertexAndTexCoord(-(w / 2) + x, h / 2 + y, d / 2 + z, 1, 0);
			vertexAndTexCoord(w / 2 + x, h / 2 + y, d / 2 + z, 1, 1);
			vertexAndTexCoord(w / 2 + x, h / 2 + y, -(d / 2) + z, 0, 1);
		}
		else if (face == 3)
		{
			vertexAndTexCoord(-(w / 2) + x, -(h / 2) + y, -(d / 2) + z, 0, 0);
			vertexAndTexCoord(w / 2 + x, -(h / 2) + y, -(d / 2) + z, 1, 0);
			vertexAndTexCoord(w / 2 + x, -(h / 2) + y, d / 2 + z, 1, 1);
			vertexAndTexCoord(-(w / 2) + x, -(h / 2) + y, d / 2 + z, 0, 1);
		}
		else if (face == 4)
		{
			vertexAndTexCoord(w / 2 + x, -(h / 2) + y, -(d / 2) + z, 0, 0);
			vertexAndTexCoord(w / 2 + x, h / 2 + y, -(d / 2) + z, 1, 0);
			vertexAndTexCoord(w / 2 + x, h / 2 + y, d / 2 + z, 1, 1);
			vertexAndTexCoord(w / 2 + x, -(h / 2) + y, d / 2 + z, 0, 1);
		}
		else if (face == 5)
		{
			vertexAndTexCoord(-(w / 2) + x, -(h / 2) + y, -(d / 2) + z, 0, 0);
			vertexAndTexCoord(-(w / 2) + x, -(h / 2) + y, d / 2 + z, 1, 0);
			vertexAndTexCoord(-(w / 2) + x, h / 2 + y, d / 2 + z, 1, 1);
			vertexAndTexCoord(-(w / 2) + x, h / 2 + y, -(d / 2) + z, 0, 1);
		}
	}

	void VBO::renderBox(float x, float y, float z, float w, float h, float d)
	{
		renderFace(x, y, z, w, h, d, 0);
		renderFace(x, y, z, w, h, d, 1);
		renderFace(x, y, z, w, h, d, 2);
		renderFace(x, y, z, w, h, d, 3);
		renderFace(x, y, z, w, h, d, 4);
		renderFace(x, y, z, w, h, d, 5);
	}

	void VBO::flush(GLuint &vbo) {
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vi * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void VBO::render(GLuint &vbo) {
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glEnableClientState(GL_VERTEX_ARRAY);

		if (useColor) {
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(4, GL_FLOAT, (3 + (useColor ? 4 : 0) + (useTex ? 2 : 0)) * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
		}
		if (useTex) {
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glTexCoordPointer(2, GL_FLOAT, (3 + (useColor ? 4 : 0) + (useTex ? 2 : 0)) * sizeof(GLfloat), (void*)((3 + (useColor ? 4 : 0)) * sizeof(GLfloat)));
		}

		glVertexPointer(3, GL_FLOAT, (3 + (useColor ? 4 : 0) + (useTex ? 2 : 0)) * sizeof(GLfloat), (void*)(0));

		glDrawArrays(GL_QUADS, 0, vc);

		glDisableClientState(GL_VERTEX_ARRAY);
		if (useColor)
			glDisableClientState(GL_COLOR_ARRAY);
		if (useTex)
			glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	GLuint VBO::createVBO()
	{
		GLuint ret;
		glGenBuffers(1, &ret);
		return ret;
	}
}
