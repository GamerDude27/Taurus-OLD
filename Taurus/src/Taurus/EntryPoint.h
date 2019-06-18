#pragma once

#ifdef TAU_PLATFORM_WINDOWS
	extern Taurus::Application *Taurus::CreateApplication();

	int main(int argc, char **argv)
	{
		auto application = Taurus::CreateApplication();
		application->Run();
		delete application;
	}
#endif
