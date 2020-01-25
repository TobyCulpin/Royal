#pragma once

#include "Core.h"

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
