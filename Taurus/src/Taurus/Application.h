#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Taurus 
{
	class TAURUS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application *CreateApplication();
}
