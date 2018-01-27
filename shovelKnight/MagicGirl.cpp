#include "stdafx.h"
#include "MagicGirl.h"


MagicGirl::MagicGirl()
{

	
}


MagicGirl::~MagicGirl()
{
}

HRESULT MagicGirl::init()
{
	//�����ڿ� �ʱ�ȭ
	//==========���� ���� ����===========//
	_fireBallPrice = 1000;							//���̾Ʈ �󸶴�
	_thunderBoltPrice = 4500;						//�����Ʈ �󸶴�
	_bubblePrice = 9000;							//����ų �󸶴�

	//==========�ȷȴ��� Ȯ�ο� ������==========//
	_stock = 0;										//����̳� �������� �����ߴ��� Ȯ�� ����
	_isSellFireBall = false;						//���̾ �ȷȴ���
	_isSellThunderBolt = false;						//�����Ʈ �ȷȴ���
	_isSellBubble = false;							//����ų �ȷȴ���

	//=========����Ŭ�����κ��� ������ ������ �ʱ�ȭ ==============//
	
	_imgKeyString = "magicGIRLIDLE";				//�̹��� �Ŵ����� ����� �̹��� Ű��
	_imgFileName = "./image/npc/magicGirl.bmp";		//�̹��� ���� �̸�(��� ����)`
		
	_img = IMAGEMANAGER->addFrameImage(_imgKeyString, _imgFileName, 420, 50, 12, 1, true, RGB(255,0,255), false);											// NPC �̹���


	_x = 633/2;
	_y = 280/2;

	_img->setCenter(_x, _y);						//�̹��� ������ǥ�� ������ǥ ��´�. 
	_width = _img->getFrameWidth();					//����ũ��
	_height = _img->getFrameHeight();				//����ũ��
	_rc = RectMakeCenter(_x, _y, _width, _height);	//����NPC ��Ʈ
	_npcType = MAGICGIRL;							//NPCŸ��

	_isCollision = false;							//�÷��̾�� �浹�ߴ°�? true : �׷���, false : �ƴϴ�

	_isAppear = false;								//�⺻���·� �ʿ��� �������� �ʴ´�.

	KEYANIMANAGER->addDefaultFrameAnimation("�����ɾ��̵�", "magicGIRLIDLE", 5, false, true);

	

	_anim = KEYANIMANAGER->findAnimation("�����ɾ��̵�");		//NPC �ִϸ��̼�
	KEYANIMANAGER->start("�����ɾ��̵�");
	return S_OK;
}

void MagicGirl::render()
{
	npcBase::render();
}

void MagicGirl::draw()
{
	npcBase::draw();
}

void MagicGirl::sellSkill()
{
	//��ų���� 
	//storeManager���� ���üũ
	//���⼭�� �����ϰ� ��ų�� �Ǹ�(��ų bool�� true�� �ٲ��ִ� �Լ�)�� �Ѵ�.
}

void MagicGirl::stockCount()
{
}

//void MagicGirl::render()
//{
////	if (_isAppear)
//	//{
//	//	draw();
//	//}
//}
//
//void MagicGirl::draw()
//{
//	//_img->aniRender(getMemDC(), _rc.left, _rc.top, _anim);
//}
