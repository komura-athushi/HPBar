#include "stdafx.h"
#include "Player.h"


namespace
{
	//�ő�HP�B
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
	//�s�{�b�g��ݒ肷��B
	//�s�{�b�g�͉摜�̒��S�ł���B
	//�s�{�b�g�𒆐S�ɁA�摜���L�яk�݂���̂ŁB
	//�s�{�b�g�̒l��ύX���邱�Ƃɂ��B
	//�摜�̑傫����ύX���Ă��A�摜���ړ����Ȃ��悤�ɂ���B
	m_hpBar.SetPivot(Vector2(0.0f, 0.5f));
	m_hpBar.SetPosition(Vector3(-960.0f, 482.0f, 0.0f));

	//�X�V�����B
	m_hpBar.Update();
	m_hp = MAXIMUM_HP;

	m_fontRender.SetText(L"A�{�^����HP��\nB�{�^����HP����");
	m_fontRender.SetPivot(Vector2(0.0f, 0.5f));
	m_fontRender.SetPosition(Vector3(-960.0f, 100.0f, 0.0f));
	return true;
}

void Player::Update()
{
	//A�{�^������������,�̗͉񕜁B
	if (g_pad[0]->IsPress(enButtonA))
	{
		m_hp += 1;
	}
	//B�{�^������������A�̗͂����炷�B
	else if (g_pad[0]->IsPress(enButtonB))
	{
		m_hp -= 1;
	}

	//HP��0��茸���Ă�����B
	if (m_hp < 0)
	{
		//HP��0�ɂ���B
		m_hp = 0;
	}
	//HP���ő�l�𒴂��Ă�����B
	else if (m_hp > MAXIMUM_HP)
	{
		//HP���ő�l�ɂ���B
		m_hp = MAXIMUM_HP;
	}

	Vector3 scale = Vector3::One;
	//��HP/�ő�HP��HP�o�[�̃X�P�[���ɂ���B
	//int�^���m�̌v�Z���ƁA�����_�ȉ��؂�̂ĂɂȂ�̂ŁB
	//float�^�ɕϊ����Čv�Z���s���B
	scale.x = float(m_hp) / float(MAXIMUM_HP);
	//�X�P�[����ݒ�B
	m_hpBar.SetScale(scale);

	//�X�V�����B
	m_hpBar.Update();
}

void Player::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
	m_hpBar.Draw(rc);
	m_fontRender.Draw(rc);
}