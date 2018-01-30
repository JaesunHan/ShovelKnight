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
	npcBase::init();
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

	//NPC �̹���
	_img = IMAGEMANAGER->addFrameImage(_imgKeyString, _imgFileName, 70, 47, 2, 1, true, RGB(255, 0, 255), false);											// NPC �̹���
	IMAGEMANAGER->addFrameImage("HealtyGuyGood", "./image/npc/healthGuyGood1.bmp", 168, 90, 4, 1, true, RGB(255, 0, 255), false);
	IMAGEMANAGER->addFrameImage("HealtyGuyCook", "./image/npc/healthGuyBackCook.bmp", 897, 43, 23, 1, true, RGB(255, 0, 255), false);



	_x = 220/2;
	_y = 280/2;


	_img->setCenter(_x, _y);						//�̹��� ������ǥ�� ������ǥ ��´�. 
	_width = _img->getFrameWidth();					//����ũ��
	_height = _img->getFrameHeight();				//����ũ��
	_rc = RectMakeCenter(_x, _y, _width, _height);	//����NPC ��Ʈ
	_npcType = HEALTYGUY;							//NPCŸ��



	_isCollisionNpc = false;							//�÷��̾�� �浹�ߴ°�? true : �׷���, false : �ƴϴ�
	_isAppear = true;									//�⺻���·� �ʿ��� �������� �ʴ´�.
	_textOut = false;

	int arrIDLE1[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("�ｺ���̾��̵�", "HealtyGuyIdle", arrIDLE1, 2, 2, true);
	
	int arrGood[4];
	for (int i = 0; i < 4; ++i)
	{
		arrGood[i] = i;
	}
	KEYANIMANAGER->addArrayFrameAnimation("�ｺ���̱�", "HealtyGuyGood", arrGood, 4, 3, true);
	

	_anim = KEYANIMANAGER->findAnimation("�ｺ���̾��̵�");		//NPC �ִϸ��̼�
	_anim2 = KEYANIMANAGER->findAnimation("�ｺ���̱�");

	KEYANIMANAGER->start("�ｺ���̾��̵�");
	KEYANIMANAGER->start("�ｺ���̱�");


	_setMaxHp = 8;
	return S_OK;
}

void HealtyGuy::sellHpItem()
{
}



void HealtyGuy::isCollision(bool collision)
{
	if (_isAppear)
	{
		if (collision)
		{
			//�ؽ�Ʈ �ƿ����� "�� �̰� �췡? Yes or No(bool��<-���� �ϳ� �߰��ؾ��� 1.25)
			//�Ʒ��� Yes ������������ �Լ�
		
			_textOut = true;
			
			_npcStatus = NPCTALK;
			//if (KEYMANAGER->isOnceKeyDown('O'))				//O��������
			//{
				//TTTextOut(300, 300, "�����浹", 0);
			if (KEYMANAGER->isOnceKeyDown('2'))
			{
				if (!_stock)					//�ѹ��� �������� ���Ÿ� ���� �ʾ�����(stock =0)
				{
					if (_money >= 1000)				//1000������ ���� ���ٸ�
					{
						_minusMoney -= 1000;						//�÷��̾� ��忡�� 1000���� �����ϰ�
						//_setMaxHp += 2;
						_stock = 1;						//�ѹ� ���������ϱ� stock�� 1�� ��ȯ���ش�.
					}
					if (_money < 1000)						//�÷��̾� ��尡 1000������ �۴ٸ�
					{
						//str = str4;
					}


				}

				if (_stock == 1)							//�ѹ��� �������� ���Ÿ� ���� �ʾ�����
				{
					if (_money >= 3000)						//3000������ ���� ���ٸ�
					{

						_minusMoney -= 3000;				//�÷��̾� ��忡�� 1000���� �����ϰ�
						//_setMaxHp += 2;
						_stock = 2;							//�ѹ� ���������ϱ� stock�� 1�� ��ȯ���ش�.
					}
					if (_money < 3000)						//�÷��̾� ��尡 1000������ �۴ٸ�
					{
						//str = str4;
					}

				}
				//}
				else
				{
					_textOut = false;
				}
			}
			if (KEYMANAGER->isOnceKeyDown('P'))
			{

			}
			//NO�������� �ؽ�Ʈ �ƿ�����
			//"�� ��...�׷�? �ȳ� ���� " ���̾�α� ��� ����
			//_isCollisionNpc == false;

		}
		
	}
}

void HealtyGuy::HealtyGuyImageControl()
{

	switch (_npcStatus)
	{
	case NPCIDLE:
		_anim = KEYANIMANAGER->findAnimation("�ｺ���̾��̵�");		//NPC �ִϸ��̼�
															//KEYANIMANAGER->start("�����ɾ��̵�");
		break;

	case NPCTALK:
		_img = IMAGEMANAGER->findImage("HealtyGuyGood");
		_anim2 = KEYANIMANAGER->findAnimation("�ｺ���̱�");		//NPC �ִϸ��̼�
															//KEYANIMANAGER->start("�������λ�");
		break;

	case NPCUNDERATTACKED:
		break;
	}

}

void HealtyGuy::render()
{
	if (_isAppear == true)
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
		TTTextOut(300, 300, "�÷��̾", _money);
		TTTextOut(300, 200, "�÷��̾��ִ�ü��", _setMaxHp);
	}
}

void HealtyGuy::draw()
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

void HealtyGuy::update()
{
	npcBase::update();
	HealtyGuyImageControl();
}