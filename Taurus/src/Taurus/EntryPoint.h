#pragma once

#ifdef TAURUS_PLATFORM_WINDOWS
	extern Taurus::Application *Taurus::CreateApplication();

	int main(int argc, char **argv)
	{
		// Console title
		SetConsoleTitle(TEXT("Taurus Engine - Sandbox"));

		// Log initialization
		TAURUS_LOG_INITIALIZE();
		TAURUS_CORE_INFO("Logger initialized!");

		auto application = Taurus::CreateApplication();
		application->Run();
		delete application;
	}
#endif
