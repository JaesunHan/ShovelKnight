#include "stdafx.h"
#include "BardKnight.h"


BardKnight::BardKnight()
{
	//�����ڿ� �ʱ�ȭ
	
}


BardKnight::~BardKnight()
{
}

HRESULT BardKnight::init()
{
	//==========���� ���� ����===========//
	_bgmPrice = 100;								//���ü���� ����
	_effectSoundPrice = 500;						//����Ʈ���� ü���� ����


	//==========�ȷȴ��� Ȯ�ο� ������==========//
	_stock = 0;										//����̳� �������� �����ߴ��� Ȯ�� ����
	_isSellBgm = false;								//��� �ȷȴ���
	_isSellEffectSound = false;						//����Ʈ ���� �ȷȴ���


	//=========����Ŭ�����κ��� ������ ������ �ʱ�ȭ ==============//

	_imgKeyString = "BardKnightIDLE";				//�̹��� �Ŵ����� ����� �̹��� Ű��
	_imgFileName = "./image/npc/bardKnight.bmp";		//�̹��� ���� �̸�(��� ����)`

	_img = IMAGEMANAGER->addFrameImage(_imgKeyString, _imgFileName, 1066, 42, 26, 1, true, RGB(255, 0, 255), false);		// NPC �̹���
	IMAGEMANAGER->addFrameImage("BardKnightJump", "./image/npc/bardKnight_jump.bmp", 798, 52, 14, 1, true, RGB(255, 0, 255), false);
	IMAGEMANAGER->addFrameImage("BardKnightPlaying", "./image/npc/bardKnight_playing.bmp", 720, 39, 16, 1, true, RGB(255, 0, 255), false);



	_x = 400 / 2;
	_y = 410 / 2;

	_img->setCenter(_x, _y);						//�̹��� ������ǥ�� ������ǥ ��´�. 
	_width = _img->getFrameWidth();					//����ũ��
	_height = _img->getFrameHeight();				//����ũ��
	_rc = RectMakeCenter(_x, _y, _width, _height);	//����NPC ��Ʈ
	_npcType = BARDKNIGHT;							//NPCŸ��

	_isCollision = false;							//�÷��̾�� �浹�ߴ°�? true : �׷���, false : �ƴϴ�
	_isAppear = true;								//�⺻���·� �ʿ��� �������� �ʴ´�.

	int arrIDLE1[26];
	for (int i = 0; i < 26; ++i)
	{
		arrIDLE1[i] = i;
	}
	KEYANIMANAGER->addArrayFrameAnimation("�ٵ峪��Ʈ���̵�", "BardKnightIDLE", arrIDLE1, 26, 6, true);
	KEYANIMANAGER->start("�ٵ峪��Ʈ���̵�");

	_anim = KEYANIMANAGER->findAnimation("�ٵ峪��Ʈ���̵�");		//NPC �ִϸ��̼�
	return S_OK;
}

void BardKnight::changeBGM()
{
	//fmod ���� ���ä�ιٲ�����
}

void BardKnight::changeEffectSound()
{
	//fmod ���� ����Ʈ ���� �ٲ�����
}



void BardKnight::render()
{
	if (_isAppear == true)
	{
		draw();
	}
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), CAMERAMANAGER->getX(_rc.left),
			CAMERAMANAGER->getY(_rc.top),
			CAMERAMANAGER->getX(_rc.right),
			CAMERAMANAGER->getY(_rc.bottom));
	}
}

void BardKnight::draw()
{
	//_img->aniRender(getMemDC(), _rc.left, _rc.top, _anim);
	CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim, _rc.left, _rc.top);
}

void BardKnight::update()
{
	npcBase::update();
}
