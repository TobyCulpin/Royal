#pragma once

#ifdef RL_PLATFORM_WINDOWS

extern Royal::Application* Royal::CreateApplication();

int main(int argc, char** argv)
{

	Royal::Log::Init();

	RL_CORE_INFO("Initialized Log!");
	RL_INFO("Initialized Log!");

	RL_CORE_INFO("Royal Engine starting...");
	auto app = Royal::CreateApplication();
	app->Run();
	delete app;
}

#endif