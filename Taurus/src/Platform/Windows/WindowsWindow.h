#pragma once

#include "Taurus/Window.h"

#include <GLFW/glfw3.h>

namespace Taurus
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProperties &props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFunction &callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled);
		bool IsVSync() const override;

	private:
		virtual void Initialize(const WindowProperties &properties);
		virtual void Shutdown();

	private:
		GLFWwindow *m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFunction EventCallback;
		};

		WindowData m_Data;
	};
}
