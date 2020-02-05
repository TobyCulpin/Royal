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
		//RL_INFO("ExampleLayer::Update");
		if (Royal::Input::IsKeyPressed(RL_KEY_6))
		{
			RL_TRACE("6 key is pressed (poll)!");
		}
	}

	void OnEvent(Royal::Event& event) override
	{
		//RL_TRACE("{0}", event);
		if (event.GetEventType() == Royal::EventType::KeyPressed)
		{
			Royal::KeyPressedEvent& e = (Royal::KeyPressedEvent&)event;
			if (e.GetKeyCode() == RL_KEY_6)
				RL_TRACE("6 key is pressed (event)!");
			RL_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Royal::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new Royal::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Royal::Application* Royal::CreateApplication()
{
	return new Sandbox();
}