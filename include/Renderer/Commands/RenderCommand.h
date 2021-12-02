#pragma once

#include <Utils/Vector.h>

namespace bGUI {
	enum class RenderCommandType {
		DRAW_RECT,
		DRAW_TEXT,
		DRAW_CIRCLE,
		DRAW_LINE,
		INVALID
	};
	
	class RenderCommand {
	protected:
		RenderCommandType type;
		RenderCommand(RenderCommandType type) : type(type) {}

	public:
		RenderCommandType getType() { return type; }
	};

	class DrawRectRenderCommand : public RenderCommand {
	public:
		Vector2f position;
		Vector2f size;

		DrawRectRenderCommand() : RenderCommand(RenderCommandType::DRAW_RECT) {};
	};
}