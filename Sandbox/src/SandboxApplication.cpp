#include <Taurus.h>

class Sandbox : public Taurus::Application
{
public:
	Sandbox() 
	{

	}

	~Sandbox()
	{

	}
};

Taurus::Application *Taurus::CreateApplication()
{
	return new Sandbox();
}
