#include "GSIntro.h"

extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine


GSIntro::GSIntro()
{
	m_time = 0;
}


GSIntro::~GSIntro()
{
}


void GSIntro::Init()
{
	Application::gSoloud.stopAll();
	GameManager::GetInstance()->Init();

	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture("logo");

	m_logo = std::make_shared<AnimationSprite>(model, shader, texture, 6, 0.13f, 3);
	m_logo->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_logo->SetSize(83, 104);

	m_introSound = std::make_shared<SoLoud::Wav>();
	m_introSound->load("..\\Data\\Sounds\\ohoho.wav");

	Application::gSoloud.play(*m_introSound, GameManager::GetInstance()->GetSfxVolume());
}

void GSIntro::Exit()
{
	
}


void GSIntro::Pause()
{
	
}

void GSIntro::Resume()
{
	
}


void GSIntro::HandleEvents()
{
	
}

void GSIntro::HandleKeyEvents(int key, bool bIsPressed)
{

}

void GSIntro::HandleTouchEvents(int x, int y, bool bIsPressed)
{

}

void GSIntro::Update(float deltaTime)
{
	m_logo->Update(deltaTime);
	m_time += deltaTime;
	if (m_time > 3.0)
	{
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
		m_time = 0;
	}
}

void GSIntro::Draw()
{
	m_logo->Draw();
}
