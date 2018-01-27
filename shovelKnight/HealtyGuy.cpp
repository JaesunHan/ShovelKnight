#include "stdafx.h"
#include "HealtyGuy.h"


HealtyGuy::HealtyGuy()
{

	
}


HealtyGuy::~HealtyGuy()
{
}

HRESULT HealtyGuy::init()
{
	//�����ڿ� �ʱ�ȭ
	//==========���� ���� ����===========//
	_chicken = 1000;								//���� ����
	_drgonTail = 4500;								//�벿�� ����


													//==========�ȷȴ��� Ȯ�ο� ������==========//
	_stock = 0;										//����̳� �������� �����ߴ��� Ȯ�� ����
	_isSellChicken = false;							//���� �ȷȴ���
	_isSellDragonTail = false;						//�벿�� �ȷȴ���


													//=========����Ŭ�����κ��� ������ ������ �ʱ�ȭ ==============//

	_imgKeyString = "HealtyGuyIdle";				//�̹��� �Ŵ����� ����� �̹��� Ű��
	_imgFileName = "./image/npc/healthGuyStand.bmp";		//�̹��� ���� �̸�(��� ����)`

	_img = IMAGEMANAGER->addFrameImage(_imgKeyString, _imgFileName, 70, 47, 2, 1, true, RGB(255, 0, 255), false);											// NPC �̹���

	_x = 220/2;
	_y = 280/2;


	_img->setCenter(_x, _y);						//�̹��� ������ǥ�� ������ǥ ��´�. 
	_width = _img->getFrameWidth();					//����ũ��
	_height = _img->getFrameHeight();				//����ũ��
	_rc = RectMakeCenter(_x, _y, _width, _height);	//����NPC ��Ʈ
	_npcType = HEALTYGUY;							//NPCŸ��



	_isCollision = false;							//�÷��̾�� �浹�ߴ°�? true : �׷���, false : �ƴϴ�
	_isAppear = false;								//�⺻���·� �ʿ��� �������� �ʴ´�.

	int arrIDLE1[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("�ｺ���̾��̵�", "HealtyGuyIdle", arrIDLE1, 2, 5, true);
	KEYANIMANAGER->start("�ｺ���̾��̵�");

	_anim = KEYANIMANAGER->findAnimation("�ｺ���̾��̵�");		//NPC �ִϸ��̼�

	return S_OK;
}

void HealtyGuy::sellHpItem()
{
}

//void HealtyGuy::render()
//{
//	//if (_isAppear)
//	//{
//	//	draw();
//	//}
//}
//
//void HealtyGuy::draw()
//{
//	//_img->aniRender(getMemDC(), _rc.left, _rc.top, _anim);
//}
