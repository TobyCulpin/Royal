#pragma once

#ifdef RL_PLATFORM_WINDOWS

#include "Royal/Input.h"

namespace Royal
{
	class WindowsInput : public Input
	{
	public:

	protected:
		//Keys
		virtual bool IsKeyPressedImpl(int keycode) override;

		//Mouse
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual float GetMouseXImpl() override;
		virtual	float GetMouseYImpl() override;
	private:

	};
}

#endif // RL_PLATFORM_WINDOWS
