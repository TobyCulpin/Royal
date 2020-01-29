#pragma once

#include "Core.h"

#include "Window.h"
#include "Royal/LayerStack.h"
#include "Royal/Events/Event.h"
#include "Royal/Events/ApplicationEvent.h"


namespace Royal
{

	class ROYAL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in client
	Application* CreateApplication();
}
