#include <Platform/OpenGL/GLUIImage.h>

#include <glad/glad.h>

namespace bGUI {
    namespace GLBackend {
        GLUIImage::GLUIImage(int width, int height, int channels, const uint8_t* data) {
            glGenTextures(1, &handle);
            setData(width, height, channels, data);
        }

        void GLUIImage::setData(int width, int height, int channels, const uint8_t* data) {
            bind();
            // update to select between GL_RGB and GL_RGBA
            GLenum dataType = GL_RGBA;
            
            if(channels == 3) {
                dataType = GL_RGB;
            }

            glTexImage2D(GL_TEXTURE_2D, 0, dataType, width, height, 0, dataType, GL_UNSIGNED_BYTE, data);
            unbind();
        }
    }
}