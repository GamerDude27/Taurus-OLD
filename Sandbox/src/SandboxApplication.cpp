#include <Taurus.h>

class ExampleLayer : public Taurus::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		TAURUS_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(Taurus::Event &event) override
	{
		TAURUS_TRACE("{0}", event);
	}
};

class Sandbox : public Taurus::Application
{
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Taurus::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Taurus::Application *Taurus::CreateApplication()
{
	return new Sandbox();
}
