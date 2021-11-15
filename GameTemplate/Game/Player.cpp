#include "stdafx.h"
#include "Player.h"


namespace
{
	//最大HP。
	const int MAXIMUM_HP = 200;			
}


Player::Player()
{

}

Player::~Player()
{

}

bool Player::Start()
{
	m_modelRender.Init("Assets/modelData/unityChan.tkm");
	m_hpBar.Init("Assets/sprite/hpbar.dds",956,116);
	//ピボットを設定する。
	//ピボットは画像の中心である。
	//ピボットを中心に、画像が伸び縮みするので。
	//ピボットの値を変更することにより。
	//画像の大きさを変更しても、画像が移動しないようにする。
	m_hpBar.SetPivot(Vector2(0.0f, 0.5f));
	m_hpBar.SetPosition(Vector3(-960.0f, 482.0f, 0.0f));

	//更新処理。
	m_hpBar.Update();
	m_hp = MAXIMUM_HP;

	m_fontRender.SetText(L"AボタンでHP回復\nBボタンでHP減少");
	m_fontRender.SetPivot(Vector2(0.0f, 0.5f));
	m_fontRender.SetPosition(Vector3(-960.0f, 100.0f, 0.0f));
	return true;
}

void Player::Update()
{
	//Aボタンを押したら,体力回復。
	if (g_pad[0]->IsPress(enButtonA))
	{
		m_hp += 1;
	}
	//Bボタンを押したら、体力を減らす。
	else if (g_pad[0]->IsPress(enButtonB))
	{
		m_hp -= 1;
	}

	//HPが0より減っていたら。
	if (m_hp < 0)
	{
		//HPを0にする。
		m_hp = 0;
	}
	//HPが最大値を超えていたら。
	else if (m_hp > MAXIMUM_HP)
	{
		//HPを最大値にする。
		m_hp = MAXIMUM_HP;
	}

	Vector3 scale = Vector3::One;
	//現HP/最大HPをHPバーのスケールにする。
	//int型同士の計算だと、小数点以下切り捨てになるので。
	//float型に変換して計算を行う。
	scale.x = float(m_hp) / float(MAXIMUM_HP);
	//スケールを設定。
	m_hpBar.SetScale(scale);

	//更新処理。
	m_hpBar.Update();
}

void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
	m_hpBar.Draw(rc);
	m_fontRender.Draw(rc);
}