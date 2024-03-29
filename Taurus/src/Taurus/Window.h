#pragma once

#include "tauruspch.h"

#include "Taurus/Core.h"
#include "Taurus/Events/Event.h"

namespace Taurus
{
	struct WindowProperties
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProperties
		(
			const std::string &title = "Taurus Engine", 
			unsigned int width = 1280, 
			unsigned int height = 720
		) : Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representing a desktop based Window
	class TAURUS_API Window
	{
	public:
		using EventCallbackFunction = std::function<void(Event &)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFunction &callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window *Create(const WindowProperties &properties = WindowProperties());
	};
}
