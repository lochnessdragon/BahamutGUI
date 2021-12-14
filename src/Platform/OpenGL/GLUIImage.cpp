#include <Platform/OpenGL/GLUIImage.h>

#include <glad/glad.h>
#include <iostream>

namespace bGUI {
    namespace GLBackend {
        GLUIImage::GLUIImage(int width, int height, int channels, const uint8_t* data) {
            glGenTextures(1, &handle);
            setData(width, height, channels, data);
        }

        void GLUIImage::setData(int width, int height, int channels, const uint8_t* data) {
            bind();
            // update to select between GL_RGB and GL_RGBA
            GLenum dataType;
            
            switch(channels) {
            case 3:
                dataType = GL_RGB;
                break;
            case 4:
                dataType = GL_RGBA;
                break;
            default:
                std::cout << "OpenGL backend can only handle images with 3 or 4 channels. (i.e. RGB or RGBA)" << std::endl;
                return;
            }

            glTexImage2D(GL_TEXTURE_2D, 0, dataType, width, height, 0, dataType, GL_UNSIGNED_BYTE, data);
            unbind();
        }
    }
}