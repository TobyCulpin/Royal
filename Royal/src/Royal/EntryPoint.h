#pragma once

#ifdef RL_PLATFORM_WINDOWS

extern Royal::Application* Royal::CreateApplication();

int main(int argc, char** argv)
{

	Royal::Log::Init();

	RL_CORE_WARN("Initialized Log!");
	int a = 5;
	int b = 10;
	RL_INFO("Initialized Log!  a = {1}", a, b);

	printf("Royal Engine starting...");
	auto app = Royal::CreateApplication();
	app->Run();
	delete app;
}

#endif