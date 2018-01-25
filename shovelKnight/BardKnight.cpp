#include "stdafx.h"
#include "BardKnight.h"


BardKnight::BardKnight()
{
	//�����ڿ� �ʱ�ȭ
	//==========���� ���� ����===========//
	_bgmPrice = 100;								//���ü���� ����
	_effectSoundPrice = 500;						//����Ʈ���� ü���� ����


	//==========�ȷȴ��� Ȯ�ο� ������==========//
	_stock = 0;										//����̳� �������� �����ߴ��� Ȯ�� ����
	_isSellBgm = false;								//��� �ȷȴ���
	_isSellEffectSound = false;						//����Ʈ ���� �ȷȴ���


	//=========����Ŭ�����κ��� ������ ������ �ʱ�ȭ ==============//

	_imgKeyString = "BardKnightIDLE";				//�̹��� �Ŵ����� ����� �̹��� Ű��
	_imgFileName = ". / npc / bardKnight.bmp";		//�̹��� ���� �̸�(��� ����)`

	_img = IMAGEMANAGER->addFrameImage(_imgKeyString, _imgFileName, 1066, 42, 26, 1, true, RGB(255, 0, 255), false);											// NPC �̹���

	_img->setCenter(_x, _y);						//�̹��� ������ǥ�� ������ǥ ��´�. 
	_width = _img->getFrameWidth();					//����ũ��
	_height = _img->getFrameHeight();				//����ũ��
	_rc = RectMakeCenter(_x, _y, _width, _height);	//����NPC ��Ʈ
	_npcType = BARDKNIGHT;							//NPCŸ��

	_isCollision = false;							//�÷��̾�� �浹�ߴ°�? true : �׷���, false : �ƴϴ�

	int arrIDLE1[26];
	KEYANIMANAGER->addArrayFrameAnimation("�ٵ峪��Ʈ���̵�", "BardKnightIDLE", arrIDLE1, 26, 5, true);


	_anim = KEYANIMANAGER->findAnimation("�ٵ峪��Ʈ���̵�");		//NPC �ִϸ��̼�
}


BardKnight::~BardKnight()
{
}

void BardKnight::changeBGM()
{
	//fmod ���� ���ä�ιٲ�����
}

void BardKnight::changeEffectSound()
{
	//fmod ���� ����Ʈ ���� �ٲ�����
}
