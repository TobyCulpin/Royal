#include "Royal.h"

class Sandbox : public Royal::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Royal::Application* Royal::CreateApplication()
{
	return new Sandbox();
}