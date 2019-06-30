#include "tauruspch.h"
#include "Application.h"

#include "Taurus/Log.h"

#include <glad/glad.h>

namespace Taurus
{
	#define BIND_EVENT_FUNCTION(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application *Application::s_Instance = nullptr;
	
	Application::Application()
	{
		TAURUS_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FUNCTION(OnEvent));
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
			
			for (Layer *layer : m_LayerStack)
			{
				layer->OnUpdate();
			}
			
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event &event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(event);
			if (event.Handled)
			{
				break;
			}
		}
	}

	void Application::PushLayer(Layer *layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer *overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	bool Application::OnWindowClose(WindowCloseEvent &event)
	{
		m_Running = false;
		return true;
	}
}
