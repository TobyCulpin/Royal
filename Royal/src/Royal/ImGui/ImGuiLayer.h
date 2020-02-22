#pragma once

#include "Royal/Layer.h"

//Royal Events includes
#include "Royal/Events/ApplicationEvent.h"
#include "Royal/Events/KeyEvent.h"
#include "Royal/Events/MouseEvent.h"

namespace Royal
{

	class ROYAL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}