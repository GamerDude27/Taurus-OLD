#pragma once

#include "Core.h"

#include "Window.h"
#include "LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace Taurus 
{
	class TAURUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event &event);

		void PushLayer(Layer *layer);
		void PushOverlay(Layer *overlay);

		inline Window &GetWindow() { return *m_Window; }

		inline static Application &Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent &event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application *s_Instance;
	};

	// To be defined in CLIENT
	Application *CreateApplication();
}
