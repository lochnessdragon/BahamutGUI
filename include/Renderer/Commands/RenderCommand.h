#pragma once

#include <Utils/Vector.h>

namespace bGUI {
	enum class RenderCommandType {
		DRAW_RECT,
		DRAW_TEXT,
		DRAW_CIRCLE,
		DRAW_LINE,
    DRAW_IMG,
		INVALID
	};
	
	class RenderCommand {
	protected:
		RenderCommandType type = RenderCommandType::INVALID;
		RenderCommand(RenderCommandType type) : type(type) {}

	public:
		RenderCommandType getType() { return type; }
	};

	class DrawRectRenderCommand : public RenderCommand {
	public:
		Vector2f position;
		Vector2f size;
		Vector3i color;

		DrawRectRenderCommand() : RenderCommand(RenderCommandType::DRAW_RECT) {};
	};
}