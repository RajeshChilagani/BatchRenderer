#pragma once
#include "GLCore.h"

class BRLayer : public GLCore::Layer
{
public:
	BRLayer();
	virtual ~BRLayer();

	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate() override;
	virtual void OnEvent(GLCore::Event& e) override;
private:
	
};
