#pragma once 
#include "Sprite2D.h"

class GameButton : public Sprite2D
{
public:
	GameButton(std::shared_ptr<Models> model, std::shared_ptr<Shaders> shader, std::shared_ptr<Texture> texture);
	~GameButton();
	void	SetOnClick(void	(*pBtClick)());
	void	HandleTouchEvents(GLint x, GLint y, bool bIsPressed);
	void	HandleKeyEvents(int key, bool bIsPressed);
	bool	IsHandle();

private:
	void	(*m_pBtClick)();
	bool	m_isHandle;

};
