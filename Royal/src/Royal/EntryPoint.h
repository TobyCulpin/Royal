#pragma once

#ifdef RL_PLATFORM_WINDOWS

extern Royal::Application* Royal::CreateApplication();

int main(int argc, char** argv)
{
	printf("Royal Engine starting...");
	auto app = Royal::CreateApplication();
	app->Run();
	delete app;
	//mhm
}

#endif