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
	npcBase::init();
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

	_isCollisionNpc = false;							//�÷��̾�� �浹�ߴ°�? true : �׷���, false : �ƴϴ�
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

	_isChange = false;
	_textOut = false;						//�׽�Ʈ��
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

		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			Rectangle(getMemDC(), CAMERAMANAGER->getX(_rc.left),
				CAMERAMANAGER->getY(_rc.top),
				CAMERAMANAGER->getX(_rc.right),
				CAMERAMANAGER->getY(_rc.bottom));
		}
	}
	if (_textOut==true)
	{
		TTTextOut(500, 100, "�ٵ峪��Ʈ�����÷��̾", _money);
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

void BardKnight::isCollision(bool collision)
{
	if (collision)
	{
		
		//soundChange();
		//�ؽ�Ʈ �ƿ����� "�� �̰� �췡? Yes or No(bool��<-���� �ϳ� �߰��ؾ��� 1.25)
		//�Ʒ��� Yes ������������ �Լ�
		char* str1 = "Welcome, Welcome My friend";
		char* str2 = "you wanna buy some weed?:P";
		char* str3 = "if u OK press 'O', or not press 'P'";
		char* str4 = "get the fuck off!!!!";

		////init
		//int stats = 0;
		//
		//char* str = str1;
		//if(strlen(str)==strlen(str1) && stats = 0) str = str2;
		////


		TTTextOut(500, 300, "�����浹1", 0);
		
		_textOut = true;
		_isChange = true;
		soundChange();
		//if (KEYMANAGER->isOnceKeyDown('O'))				//O��������
		//{
		//	//TTTextOut(300, 300, "�����浹", 0);
		//	if (!_stock)					//�ѹ��� �������� ���Ÿ� ���� �ʾ�����
		//	{
		//		if (_money >= 1000)				//1000������ ���� ���ٸ�
		//			{
		//				_minusMoney -= 1000;			//�÷��̾� ��忡�� 1000���� �����ϰ�
		//				_stock = 1;						//�ѹ� ���������ϱ� stock�� 1�� ��ȯ���ش�.
		//			}
		//			if (_money < 1000)						//�÷��̾� ��尡 1000������ �۴ٸ�
		//			{
		//				//str = str4;
		//			}
		//		}

		//	}

		//	if (_stock == 1)							//�ѹ��� �������� ���Ÿ� ���� �ʾ�����
		//	{
		//		if (_skillUnlockLv == 1)					//�÷��̾� ��ų�� 1, ���̾�̶�� 
		//		{
		//			if (_money >= 3000)					//3000������ ���� ���ٸ�
		//			{
		//				_minusMoney -= 3000;						//�÷��̾� ��忡�� 3000���� �����ϰ� 
		//				_skillUnlockLv += 1;					//�÷��̾� ��ų�� 2�� �ٲ��ش� (������Ʈ)
		//				_stock = 2;						//�ѹ� ���������ϱ� stock�� 1�� ��ȯ���ش�.
		//			}
		//			if (_money < 3000)						//�÷��̾� ��尡 3000������ �۴ٸ�
		//			{
		//				//str = str4;
		//			}
		//		}
		//	}
		//}

		//if (KEYMANAGER->isOnceKeyDown('P'))
		//{

		//}
		////NO�������� �ؽ�Ʈ �ƿ�����
		////"�� ��...�׷�? �ȳ� ���� " ���̾�α� ��� ����
		////_isCollisionNpc == false;



	}
}

void BardKnight::soundChange()
{
	SOUNDMANAGER->stop("GamePlayBGM");
	if (!SOUNDMANAGER->isPlaySound("BardKnightChange1"))
	{
		SOUNDMANAGER->play("BardKnightChange1", 0.3f);
		
	}
}
