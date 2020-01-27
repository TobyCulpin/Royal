#include "rlpch.h"

#include "Application.h"

#include "Royal/Events/ApplicationEvent.h"
#include "Royal/Log.h"

namespace Royal
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		RL_TRACE(e);

		while (true);
	}
}