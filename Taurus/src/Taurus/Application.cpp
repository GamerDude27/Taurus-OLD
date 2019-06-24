#include "tauruspch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Taurus/Log.h"

#include <GLFW/glfw3.h>

namespace Taurus
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.247f, 0.247f, 0.247f, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
