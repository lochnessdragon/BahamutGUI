#pragma once

#include "GLShader.h"

namespace bGUI {
    namespace GLBackend {
        class GLRectDefaultShader : public GLShader {
        private:
            int colorLocation;
        public:
            GLRectDefaultShader();

            void loadColor(const glm::vec4& color) { 
                loadVec4f(colorLocation, color); 
            }
        };  
    }
}