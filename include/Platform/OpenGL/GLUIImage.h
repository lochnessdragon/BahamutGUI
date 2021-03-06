#pragma once

#include <UI/UIImage.h>
#include <ctype.h>
#include <glad/glad.h>

namespace bGUI {
    namespace GLBackend {
        class GLUIImage : public UIImage {
        private:
            GLuint handle;
        public:
            GLUIImage(int width, int height, int channels, const uint8_t* data);
            void setData(int width, int height, int channels, const uint8_t* data);

            const void bind() const { 
                glBindTexture(GL_TEXTURE_2D, handle); 
            };
            const void unbind() const { glBindTexture(GL_TEXTURE_2D, 0); };
        };
    }
}