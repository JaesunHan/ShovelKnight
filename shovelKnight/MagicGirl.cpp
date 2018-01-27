#include "stdafx.h"
#include "MagicGirl.h"


MagicGirl::MagicGirl()
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
	_imgFileName = ". / npc / magicGirl.bmp";		//�̹��� ���� �̸�(��� ����)`
		
	_img = IMAGEMANAGER->addFrameImage(_imgKeyString, _imgFileName, 420, 50, 12, 1, true, RGB(255,0,255), false);											// NPC �̹���

	_x = 220;
	_y = 280;

	_img->setCenter(_x, _y);						//�̹��� ������ǥ�� ������ǥ ��´�. 
	_width = _img->getFrameWidth();					//����ũ��
	_height = _img->getFrameHeight();				//����ũ��
	_rc = RectMakeCenter(_x, _y, _width, _height);	//����NPC ��Ʈ
	_npcType = MAGICGIRL;							//NPCŸ��

	_isCollision = false;							//�÷��̾�� �浹�ߴ°�? true : �׷���, false : �ƴϴ�

	_isAppear = false;								//�⺻���·� �ʿ��� �������� �ʴ´�.

	int arrIDLE1[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("�����ɾ��̵�", "magicGIRLIDLE", arrIDLE1, 12, 5, true);
	

	_anim = KEYANIMANAGER->findAnimation("�����ɾ��̵�");		//NPC �ִϸ��̼�
}


MagicGirl::~MagicGirl()
{
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

void MagicGirl::render()
{
	if (_isAppear)
	{
		draw();
	}
}

void MagicGirl::draw()
{
	_img->aniRender(getMemDC(), _rc.left, _rc.top, _anim);
}
