#pragma once

#include "Taurus/Layer.h"

namespace Taurus
{
	class TAURUS_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event &event);

	private:
		float m_Time = 0.0f;
	};
}
