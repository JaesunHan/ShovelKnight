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
	_imgFileName = "./image/npc/magicGirlFull.bmp";		//�̹��� ���� �̸�(��� ����)
		
	//npc�̹���
	_img = IMAGEMANAGER->addFrameImage(_imgKeyString, _imgFileName, 1610, 50, 46, 1, true, RGB(255,0,255), false);											// NPC �̹���
	IMAGEMANAGER->addFrameImage("magicGirlBow", "./image/npc/magicGirlThankYou.bmp", 186, 53, 6, 1, true, RGB(255, 0, 255), false);

	_x = 633/2;
	_y = 280/2;

	_img->setCenter(_x, _y);						//�̹��� ������ǥ�� ������ǥ ��´�. 
	_width = _img->getFrameWidth();					//����ũ��
	_height = _img->getFrameHeight();				//����ũ��
	_rc = RectMakeCenter(_x, _y, _width, _height);	//����NPC ��Ʈ
	_npcType = MAGICGIRL;							//NPCŸ��

	_isCollision = false;							//�÷��̾�� �浹�ߴ°�? true : �׷���, false : �ƴϴ�

	_isAppear = true;								//�⺻���·� �ʿ��� �����Ѵ�.
	_showshowshowshow = 0;
	//KEYANIMANAGER->addDefaultFrameAnimation("�����ɾ��̵�", "magicGIRLIDLE", 6, false, true);
	int arrIDLE1[46];
	for (int i = 0; i < 46; ++i)
	{
		arrIDLE1[i] = i;
	}
	KEYANIMANAGER->addArrayFrameAnimation("�����ɾ��̵�", "magicGIRLIDLE", arrIDLE1, 46, 3, true);
	

	_anim = KEYANIMANAGER->findAnimation("�����ɾ��̵�");		//NPC �ִϸ��̼�
	KEYANIMANAGER->start("�����ɾ��̵�");
	return S_OK;
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
	if (_isAppear==true)
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

void MagicGirl::draw()
{
	//_img->aniRender(getMemDC(), _rc.left, _rc.top, _anim);
	CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim, _rc.left, _rc.top);
}

void MagicGirl::update()
{
	npcBase::update();
	int a;
	if (_isCollision)
	{
		a = 1;
	}
	else
	{
		a = 0;
	}
	
	
}
