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

	_isCollisionNpc = false;						//�÷��̾�� �浹�ߴ°�? true : �׷���, false : �ƴϴ�
	_isAppear = true;								//�⺻���·� �ʿ��� �������� �ʴ´�.

	int arrIDLE1[26];
	for (int i = 0; i < 26; ++i)
	{
		arrIDLE1[i] = i;
	}										
	KEYANIMANAGER->addArrayFrameAnimation("�ٵ峪��Ʈ���̵�", "BardKnightIDLE", arrIDLE1, 26, 6, true);


	int arrJump[14];
	for (int i = 0; i < 14; ++i)
	{
		arrJump[i] = i;
	}
	KEYANIMANAGER->addArrayFrameAnimation("�ٵ峪��Ʈ����", "BardKnightJump", arrJump, 14, 6, true);
	
	//�׽�Ʈ��
	_anim = KEYANIMANAGER->findAnimation("�ٵ峪��Ʈ���̵�");		//NPC �ִϸ��̼�
	_anim2 = KEYANIMANAGER->findAnimation("�ٵ峪��Ʈ����");		//NPC �ִϸ��̼�
	KEYANIMANAGER->start("�ٵ峪��Ʈ���̵�");
	KEYANIMANAGER->start("�ٵ峪��Ʈ����");
	

	_testScript = new image;
	_testScript = IMAGEMANAGER->addImage("scriptWindow", "./image/UI/Script_window.bmp", 0, 0, 800, 96, true, RGB(255, 0, 255));
	DIALOGUEMANAGER->setScriptWindow(_testScript);
	
	

	//_testScript1 = new image;
	//_testScript1 = IMAGEMANAGER->addImage("scriptWindow", "./image/UI/Script_window.bmp", 0, 0, 800, 96, true, RGB(255, 0, 255));
	//DIALOGUEMANAGER->setScript("����� OŰ�� �Ȼ���� KŰ��������",255,255,255);
	
	_isCollisionPlayer = false;
	
	_vDialog.push_back("������ ���� ��ħ, ���´ٸ� ���� �ٵ峪��Ʈ ��������� �ٲٰڳ�?"); //0��
	_vDialog.push_back("�ٲٷ��� OŰ�� �ȹٲٷ��� PŰ��������");//1��
	_vDialog.push_back("��������� �ٲ��ְڳ�");//2��
	
	//�б⼱��
	_vDialog2.push_back("��������� �ٲٰ� ������ ������ ���� �ɵ��� �ϰ�");//0��
	

	_idx = 0;
	_isChange = false;
	_textOut = false;
	_isReturn = false;
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


void BardKnight::isCollision(bool collision)
{
	if (_isAppear)
	{
		if (collision)
		{
			_isCollisionPlayer = collision;
			
			//_idx = 0;
		
			//if (_isReturn)
			//{
			//	DIALOGUEMANAGER->setScript(_vDialog[_idx], 255, 255, 255);
			//}
			//soundChange();
			//�ؽ�Ʈ �ƿ����� "�� �̰� �췡? Yes or No(bool��<-���� �ϳ� �߰��ؾ��� 1.25)
			//�Ʒ��� Yes ������������ �Լ�
			//_textOut = true;
			
			_npcStatus = NPCTALK;

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
		else
		{
			_textOut = false;
			_isCollisionPlayer = false;
		}
	}
}

void BardKnight::soundChange()
{
	if (_isChange)
	{
		SOUNDMANAGER->stop("GamePlayBGM");
		if (!SOUNDMANAGER->isPlaySound("BardKnightChange1"))
		{
			SOUNDMANAGER->play("BardKnightChange1", 0.3f);

		}
	}
}

void BardKnight::bardKnightImageControl()
{

	switch (_npcStatus)
	{
	case NPCIDLE:
		_anim = KEYANIMANAGER->findAnimation("�ٵ峪��Ʈ���̵�");		//NPC �ִϸ��̼�

		break;

	case NPCTALK:
		_img = IMAGEMANAGER->findImage("BardKnightJump");
		_anim2 = KEYANIMANAGER->findAnimation("�ٵ峪��Ʈ����");		//NPC �ִϸ��̼�

		break;

	case NPCUNDERATTACKED:
		break;
	}

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

		

		//�ݸ��� ������ ���� ���̾�α� ���
		if (_isCollisionPlayer)
		{
			DIALOGUEMANAGER->render(getMemDC(), 0, 0, 800, 96);
		}
		


		if (_textOut == true)
		{
			//TTTextOut(500, 100, "�ٵ峪��Ʈ�����÷��̾", _money);
			
		}
	}
}

void BardKnight::draw()
{
	//_img->aniRender(getMemDC(), _rc.left, _rc.top, _anim);
	switch (_npcStatus)
	{
	case NPCIDLE: CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim, _rc.left, _rc.top);
		break;
	case NPCTALK: CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim2, _rc.left, _rc.top-10);
		break;
	case NPCUNDERATTACKED:
		break;
	default: CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim, _rc.left, _rc.top);
		break;
	}
	
}



void BardKnight::update()
{
	npcBase::update();
	bardKnightImageControl();
	//�ݸ��� ������ ���� ������Ʈ ����.
	if(_isCollisionPlayer)
	{
		DIALOGUEMANAGER->update();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN) && _isCollisionPlayer)
	{
		//�ε��������� ���̾�α� ���Ϳ� �ִ� ���� ������
	
			DIALOGUEMANAGER->setScript(_vDialog[_idx], 255, 255, 255);
			
			_idx += 1;
			

		
		if (_idx >= _vDialog.size())	_idx = 0;
	//	if (_idx >= _vDialog2.size())  
	}

	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		soundChange();
		_branch1 = true;
		_branch2 = false;
	}
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		_branch2 = true;
		_branch1 = false;
	}

	if (_branch1)
	{
		_isChange = true;
		DIALOGUEMANAGER->setScript(_vDialog[2], 255, 255, 255);
		_branch1 = false;
		
		
	}
	if (_branch2)
	{
		DIALOGUEMANAGER->setScript(_vDialog2[0], 255, 255, 255);
		_branch2 = false;
	}
}