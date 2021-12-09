#pragma once

#include "GLShader.h"

namespace bGUI {
    namespace GLBackend {
        class GLRectDefaultShader : public GLShader {
        private:
            int colorLocation;
						int modelMatLoc;
						int projMatLoc;
						int viewMatLoc;
        public:
            GLRectDefaultShader();

            void loadColor(const glm::vec4& color) { 
                loadVec4f(colorLocation, color); 
            }

						void loadProjectionMatrix(const glm::mat4& projMat) 
						{
							loadMat4f(projMatLoc, projMat);
						}

						void loadModelMatrix(const glm::mat4& modelMat)
						{
							loadMat4f(modelMatLoc, modelMat);
						}

						void loadViewMatrix(const glm::mat4& viewMat) 
						{
							loadMat4f(viewMatLoc, viewMat);
						}
        };  
    }
}