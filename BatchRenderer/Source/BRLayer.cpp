#include "BRLayer.h"

BRLayer::BRLayer() :Layer("BRLayer") {}
BRLayer::~BRLayer() {}

void BRLayer::OnAttach() 
{
	
}

void BRLayer::OnDetach()
{

}

void BRLayer::OnUpdate()
{
	LOG_INFO("BRLayer: Update");
	glClearColor(0.5,0.2,0.8,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(-0.5f, -0.5f);
	glEnd();

}

void BRLayer::OnEvent(GLCore::Event& e)
{
	LOG_TRACE(e);
}