#include <UI/UIImage.h>

#include <Renderer/Backend.h>

namespace bGUI {
	UIImage::UIImage(std::string& filename) {
		handle = nvgCreateImage(Backend::getBackend()->getOrCreateContext(), filename.c_str(), 0);
		nvgImageSize(Backend::getBackend()->getOrCreateContext(), handle, &width, &height);
	}

	UIImage::UIImage(const char* filename) {
		handle = nvgCreateImage(Backend::getBackend()->getOrCreateContext(), filename, 0);
		nvgImageSize(Backend::getBackend()->getOrCreateContext(), handle, &width, &height);
	}

	UIImage::~UIImage() {
		nvgDeleteImage(Backend::getBackend()->getOrCreateContext(), handle);
	}

	/*void UIImage::setData(std::string& filename) {
		nvgUpdateImage();
	}

	void UIImage::setData(int width, int height, int channels, const uint8_t* data) {
		nvgUpdate
	}*/
}