#include <Platform/OpenGL/GLVAO.h>

namespace bGUI
{
	namespace GLBackend
	{
		GLVAO::GLVAO(size_t vertices_size, float* vertices, size_t indices_size, int* indices, size_t texture_coords_size, float* texture_coords) : verticesBuffer(0, GL_ARRAY_BUFFER, 3), indicesBuffer(-1, GL_ELEMENT_ARRAY_BUFFER, 0), textureCoordsBuffer(1, GL_ARRAY_BUFFER, 2)
		{
			glGenVertexArrays(1, &handle);

			bind();

			verticesBuffer.bind();
			verticesBuffer.loadData(vertices_size, vertices);
			verticesBuffer.setupData();

			indicesBuffer.bind();
			indicesBuffer.loadData(indices_size, indices);

			textureCoordsBuffer.bind();
			textureCoordsBuffer.loadData(texture_coords_size, texture_coords);
			textureCoordsBuffer.setupData();

			unbind();
		}

		GLVAO::~GLVAO()
		{
			glDeleteVertexArrays(1, &handle);
		}
	}
}