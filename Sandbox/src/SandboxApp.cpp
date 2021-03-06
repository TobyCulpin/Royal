#include "Royal.h"

//glm example code
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}

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