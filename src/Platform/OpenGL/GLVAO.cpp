#include <Platform/OpenGL/GLVAO.h>

namespace bGUI
{
    namespace GLBackend
    {
        GLVAO::GLVAO(size_t vertices_size, float *vertices, size_t indices_size, int* indices) : verticesBuffer(0, GL_ARRAY_BUFFER), indicesBuffer(1, GL_ELEMENT_ARRAY_BUFFER)
        {
            glGenVertexArrays(1, &handle);

            bind();

            verticesBuffer.bind();
            verticesBuffer.loadData(vertices_size, vertices);
            verticesBuffer.setupData();

            indicesBuffer.bind();
            indicesBuffer.loadData(indices_size, indices);

            unbind();
        }
    }
}