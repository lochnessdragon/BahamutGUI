#include <UI/UIImage.h>

#include <Renderer/Backend.h>

namespace bGUI {
	UIImage::UIImage(std::string& filename) {
		//nvgImageSize(Backend::getBackend()->getRenderContext(), handle, &width, &height);
	}

	UIImage::UIImage(const char* filename) {
		//nvgImageSize(Backend::getBackend()->getRenderContext(), handle, &width, &height);
	}

	UIImage::~UIImage() {
		nvgDeleteImage(context, handle);
	}

	/*void UIImage::setData(std::string& filename) {
		nvgUpdateImage();
	}

	void UIImage::setData(int width, int height, int channels, const uint8_t* data) {
		nvgUpdate
	}*/
}