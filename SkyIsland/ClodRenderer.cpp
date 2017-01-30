#include "ClodRenderer.h"

namespace SkyIsland {
	Textures::ClodTextures ClodRenderer::tex1, ClodRenderer::tex2, ClodRenderer::tex3, 
		ClodRenderer::tex4, ClodRenderer::tex5, ClodRenderer::tex6;
	float ClodRenderer::offsetX, ClodRenderer::offsetY, ClodRenderer::clodTexSize = 0.03125f;
	int ClodRenderer::renderPosX, ClodRenderer::renderPosY, ClodRenderer::renderPosZ;

	void ClodRenderer::setRenderPos(int x, int y, int z)
	{
		renderPosX = x; renderPosY = y; renderPosZ = z;
	}

	void ClodRenderer::setTexture(Textures::ClodTextures tex)
	{
		setTexture(tex, tex, tex, tex, tex, tex);
	}
	void ClodRenderer::setTexture(Textures::ClodTextures tex1, Textures::ClodTextures tex2, Textures::ClodTextures tex3)
	{
		setTexture(tex1, tex1, tex2, tex2, tex3, tex3);
	}
	void ClodRenderer::setTexture(Textures::ClodTextures tex1, Textures::ClodTextures tex2, Textures::ClodTextures tex3, Textures::ClodTextures tex4, Textures::ClodTextures tex5, Textures::ClodTextures tex6)
	{
		ClodRenderer::tex1 = tex1;
		ClodRenderer::tex2 = tex2;
		ClodRenderer::tex3 = tex3;
		ClodRenderer::tex4 = tex4;
		ClodRenderer::tex5 = tex5;
		ClodRenderer::tex6 = tex6;
	}

	void ClodRenderer::renderFace(float x, float y, float z, float w, float h, float d, int face)
	{
		if (face == 0)
		{
			offsetX = Textures::getClodTexOffsetX(tex1); offsetY = Textures::getClodTexOffsetY(tex1);

			VBO::vertexAndTexCoord(-(w / 2) + renderPosX + x, -(h / 2) + renderPosY + y, d / 2 + renderPosZ + z,
				(offsetX + (x*clodTexSize)), (offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(w / 2 + renderPosX + x, -(h / 2) + renderPosY + y, d / 2 + renderPosZ + z,
				((w * clodTexSize) + offsetX + (x*clodTexSize)), (offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(w / 2 + renderPosX + x, h / 2 + renderPosY + y, d / 2 + renderPosZ + z,
				((w * clodTexSize) + offsetX + (x*clodTexSize)), ((h * clodTexSize) + offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(-(w / 2) + renderPosX + x, h / 2 + renderPosY + y, d / 2 + renderPosZ + z,
				(offsetX + (x*clodTexSize)), ((h * clodTexSize) + offsetY + (y*clodTexSize)));
		}
		else if (face == 1)
		{
			offsetX = Textures::getClodTexOffsetX(tex2); offsetY = Textures::getClodTexOffsetY(tex2);

			VBO::vertexAndTexCoord(-(w / 2) + renderPosX + x, -(h / 2) + renderPosY + y, -(d / 2) + renderPosZ + z,
				((w * clodTexSize) + offsetX + (x*clodTexSize)), (offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(-(w / 2) + renderPosX + x, h / 2 + renderPosY + y, -(d / 2) + renderPosZ + z,
				((w * clodTexSize) + offsetX + (x*clodTexSize)), ((h * clodTexSize) + offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(w / 2 + renderPosX + x, h / 2 + renderPosY + y, -(d / 2) + renderPosZ + z,
				(offsetX + (x*clodTexSize)), ((h * clodTexSize) + offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(w / 2 + renderPosX + x, -(h / 2) + renderPosY + y, -(d / 2) + renderPosZ + z,
				(offsetX + (x*clodTexSize)), (offsetY + (y*clodTexSize)));
		}
		else if (face == 2)
		{
			offsetX = Textures::getClodTexOffsetX(tex3); offsetY = Textures::getClodTexOffsetY(tex3);

			VBO::vertexAndTexCoord(-(w / 2) + renderPosX + x, h / 2 + renderPosY + y, -(d / 2) + renderPosZ + z,
				(offsetX + (x*clodTexSize)), (offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(-(w / 2) + renderPosX + x, h / 2 + renderPosY + y, d / 2 + renderPosZ + z,
				((w * clodTexSize) + offsetX + (x*clodTexSize)), (offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(w / 2 + renderPosX + x, h / 2 + renderPosY + y, d / 2 + renderPosZ + z,
				((w * clodTexSize) + offsetX + (x*clodTexSize)), ((d * clodTexSize) + offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(w / 2 + renderPosX + x, h / 2 + renderPosY + y, -(d / 2) + renderPosZ + z,
				(offsetX + (x*clodTexSize)), ((d * clodTexSize) + offsetY + (y*clodTexSize)));
		}
		else if (face == 3)
		{
			offsetX = Textures::getClodTexOffsetX(tex4); offsetY = Textures::getClodTexOffsetY(tex4);

			VBO::vertexAndTexCoord(-(w / 2) + renderPosX + x, -(h / 2) + renderPosY + y, -(d / 2) + renderPosZ + z,
				((w * clodTexSize) + offsetX + (x*clodTexSize)), (offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(w / 2 + renderPosX + x, -(h / 2) + renderPosY + y, -(d / 2) + renderPosZ + z,
				((w * clodTexSize) + offsetX + (x*clodTexSize)), ((d * clodTexSize) + offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(w / 2 + renderPosX + x, -(h / 2) + renderPosY + y, d / 2 + renderPosZ + z,
				(offsetX + (x*clodTexSize)), ((d * clodTexSize) + offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(-(w / 2) + renderPosX + x, -(h / 2) + renderPosY + y, d / 2 + renderPosZ + z,
				(offsetX + (x*clodTexSize)), (offsetY + (y*clodTexSize)));
		}
		else if (face == 4)
		{
			offsetX = Textures::getClodTexOffsetX(tex5); offsetY = Textures::getClodTexOffsetY(tex5);

			VBO::vertexAndTexCoord(-(w / 2) + renderPosX + x, -(h / 2) + renderPosY + y, -(d / 2) + renderPosZ + z,
				(offsetX + (x*clodTexSize)), (offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(-(w / 2) + renderPosX + x, -(h / 2) + renderPosY + y, d / 2 + renderPosZ + z,
				((d * clodTexSize) + offsetX + (x*clodTexSize)), (offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(-(w / 2) + renderPosX + x, h / 2 + renderPosY + y, d / 2 + renderPosZ + z,
				((d * clodTexSize) + offsetX + (x*clodTexSize)), ((h * clodTexSize) + offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(-(w / 2) + renderPosX + x, h / 2 + renderPosY + y, -(d / 2) + renderPosZ + z,
				(offsetX + (x*clodTexSize)), ((h * clodTexSize) + offsetY + (y*clodTexSize)));
		}
		else if (face == 5)
		{
			offsetX = Textures::getClodTexOffsetX(tex6); offsetY = Textures::getClodTexOffsetY(tex6);

			VBO::vertexAndTexCoord(w / 2 + renderPosX + x, -(h / 2) + renderPosY + y, -(d / 2) + renderPosZ + z,
				((d * clodTexSize) + offsetX + (x*clodTexSize)), (offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(w / 2 + renderPosX + x, h / 2 + renderPosY + y, -(d / 2) + renderPosZ + z,
				((d * clodTexSize) + offsetX + (x*clodTexSize)), ((h * clodTexSize) + offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(w / 2 + renderPosX + x, h / 2 + renderPosY + y, d / 2 + renderPosZ + z,
				(offsetX + (x*clodTexSize)), ((h * clodTexSize) + offsetY + (y*clodTexSize)));

			VBO::vertexAndTexCoord(w / 2 + renderPosX + x, -(h / 2) + renderPosY + y, d / 2 + renderPosZ + z,
				(offsetX + (x*clodTexSize)), (offsetY + (y*clodTexSize)));
		}
	}

	void ClodRenderer::renderBox(float x, float y, float z, float w, float h, float d)
	{
		renderFace(x, y, z, w, h, d, 0);
		renderFace(x, y, z, w, h, d, 1);
		renderFace(x, y, z, w, h, d, 2);
		renderFace(x, y, z, w, h, d, 3);
		renderFace(x, y, z, w, h, d, 4);
		renderFace(x, y, z, w, h, d, 5);
	}
}