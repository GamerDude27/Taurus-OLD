#include "tauruspch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Taurus/Log.h"

namespace Taurus
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent resizeEvent(1280, 720);

		TAURUS_TRACE(resizeEvent);

		while (true);
	}
}
