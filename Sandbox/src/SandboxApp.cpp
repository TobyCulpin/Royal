#include "Royal.h"

class ExampleLayer : public Royal::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		RL_INFO("ExampleLayer::Update");
	}

	void OnEvent(Royal::Event& event) override
	{
		RL_TRACE("{0}", event);
	}
};

class Sandbox : public Royal::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Royal::Application* Royal::CreateApplication()
{
	return new Sandbox();
}