#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Royal
{

	class ROYAL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
