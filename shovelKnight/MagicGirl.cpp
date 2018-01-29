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
	npcBase::init();
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
	_npcStatus = NPCIDLE;							//NPC���� �⺻�� IDLE
	_isCollisionNpc = false;						//�÷��̾�� �浹�ߴ°�? true : �׷���, false : �ƴϴ�

	_isAppear = true;								//�⺻���·� �ʿ��� �����Ѵ�.
	//_showshowshowshow = 0;
	//KEYANIMANAGER->addDefaultFrameAnimation("�����ɾ��̵�", "magicGIRLIDLE", 6, false, true);
	int arrIDLE1[46];
	for (int i = 0; i < 46; ++i)
	{
		arrIDLE1[i] = i;
	}
	KEYANIMANAGER->addArrayFrameAnimation("�����ɾ��̵�", "magicGIRLIDLE", arrIDLE1, 46, 3, true);
	
	int arrBow[6];
	for (int i = 0; i < 6; ++i)
	{
		arrBow[i] = i;
	}
	KEYANIMANAGER->addArrayFrameAnimation("�������λ�", "magicGirlBow", arrBow, 6, 3, true);


	_anim = KEYANIMANAGER->findAnimation("�����ɾ��̵�");		//NPC �ִϸ��̼�
	_anim2 = KEYANIMANAGER->findAnimation("�������λ�");
	KEYANIMANAGER->start("�����ɾ��̵�");
	KEYANIMANAGER->start("�������λ�");

	_textOut = false;
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



void MagicGirl::isCollision(bool collision)
{
	if (_isAppear)
	{
		if (collision)
		{
			
			////���̾�α׷� 
			////���������� �°� ȯ����	
			////�ʰ� ��� �ִ� ��ų�� ���̾�̾� 
			////�췡?
			//if (_buyYesorNo == true)
			//{
			_textOut = true;
			//	_npcStatus = NPCTALK;
			//	if (KEYMANAGER->isOnceKeyDown('O'))				//��ٰ� ������
			//	{
					if (!_stock)					//�ѹ��� �������� ���Ÿ� ���� �ʾ�����
					{
						if (_skillUnlockLv == 0)			//�÷��̾� ��ų�� 0(����)�� �ִٸ�
						{
							if (_money >= 1000)				//1000������ ���� ���ٸ�
							{
								_minusMoney -= 1000;						//�÷��̾� ��忡�� 1000���� �����ϰ�
								_skillUnlockLv += 1;						//�÷��̾� ��ų�� 1�� �ٲ��ش� (���̾)
								_stock = 1;									//�ѹ� ���������ϱ� stock�� 1�� ��ȯ���ش�.
							}
							if (_money < 1000)						//�÷��̾� ��尡 1000������ �۴ٸ�
							{
								//���̾�α׷� �� ���� �����ϳ�?	
								
							}
						}

					}
				}
			}
			if (KEYMANAGER->isOnceKeyDown('P'))
			{
				//NO�������� �ؽ�Ʈ �ƿ�����
				//"�� ��...�׷�? �ȳ� ���� " ���̾�α� ��� ����
			}
			
			else
			{
				_textOut = false;
			}
		//}
	//}
}

void MagicGirl::magicGirlImageControl()
{

	switch (_npcStatus)
	{
	case NPCIDLE:
		_anim = KEYANIMANAGER->findAnimation("�����ɾ��̵�");		//NPC �ִϸ��̼�
															//KEYANIMANAGER->start("�����ɾ��̵�");
		break;

	case NPCTALK:
		_img = IMAGEMANAGER->findImage("magicGirlBow");
		_anim2 = KEYANIMANAGER->findAnimation("�������λ�");		//NPC �ִϸ��̼�
															//KEYANIMANAGER->start("�������λ�");
		break;

	case NPCUNDERATTACKED:
		break;
	}

}

void MagicGirl::render()
{
	if (_isAppear==true)
	{
		draw();
	
		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			Rectangle(getMemDC(), CAMERAMANAGER->getX(_rc.left),
				CAMERAMANAGER->getY(_rc.top),
				CAMERAMANAGER->getX(_rc.right),
				CAMERAMANAGER->getY(_rc.bottom));
		}
	}
	if (_textOut)
	{
		TTTextOut(500, 400, "�����ɿ����÷��̾", _money);
		TTTextOut(500, 300, "��ų", _skillUnlockLv);
	}
}

void MagicGirl::draw()
{
	//_img->aniRender(getMemDC(), _rc.left, _rc.top, _anim);
	switch (_npcStatus)
	{
	case NPCIDLE: CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim, _rc.left, _rc.top);
		break;
	case NPCTALK: CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim2, _rc.left, _rc.top);
		break;
	case NPCUNDERATTACKED:
		break;
	default: CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim, _rc.left, _rc.top);
		break;
	}
	
	
}

void MagicGirl::update()
{
	npcBase::update();
	magicGirlImageControl();
}
