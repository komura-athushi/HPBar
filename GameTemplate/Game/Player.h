#pragma once

class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
private:
	ModelRender						m_modelRender;
	int								m_hp = 0;
	SpriteRender					m_hpBar;
	FontRender						m_fontRender;

};

