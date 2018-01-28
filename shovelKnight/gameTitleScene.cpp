#include "stdafx.h"
#include "gameTitleScene.h"
#include "gameMenuScene.h"


gameTitleScene::gameTitleScene()
{
	_sceneName = "GameTitleScene";
}


gameTitleScene::~gameTitleScene()
{

}

HRESULT gameTitleScene::init()
{
	//_sceneName = "GameTitleScene";
	//���� �߰� -���� JH
	SOUNDMANAGER->addSound("MainTheme", "./sound/ost/Shovel Knight Soundtrack - 01 - Main Theme.mp3", true, true);
	SOUNDMANAGER->addSound("MainSelect", "./sound/EFFECTSOUND/selectSound.mp3", false, false);

	_titleBGImgKeyStr = "titleBackgroundImg";
	_titleBGImgFileName = "./image/title/titleMain.bmp";
	_backgroundImg = IMAGEMANAGER->addImage(_titleBGImgKeyStr, _titleBGImgFileName, 0,0,WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	_shovelImgKeyStr = "shovelFlag";
	_shovelImgFileName = "./image/title/shovel.bmp";
	_shovelImg = IMAGEMANAGER->addImage(_shovelImgKeyStr, _shovelImgFileName, 96, 20, true, RGB(255, 0, 255));
	_shovelW = _shovelImg->getWidth();		//96
	_shovelH = _shovelImg->getHeight();		//20
	
	//��Ʈ�Ǽ��� ũ�� : 22
	//�� ���� �޴��� ��ġ�� ���� ��Ʈ �ʱ�ȭ (���� ��ŸƮ, ����, �ɼ�, ���� ����)
	for (int i = 0; i < MAXBTN; ++i)
	{
		//232, 250 ����( right, top)
		_rcBtn[i] = RectMake(232, 250 + i * 22, 96, 22);
	}

	//ó������ ���ӽ�ŸƮ ��ư ���� ���� ���
	
	_shovelIdx = 0;

	//�� ��ũ��Ʈ ����
	setScript();

	_isOption = false;		//�ɼ� ���õƴ�? = �⺻ false by JH^_^
	_isTitleScene = true;	//Ÿ��Ʋ���϶��� �뷡������ ����
	_op = new optionMenu;
	_op->init();
	
	_sM = new soundMenu;
	_sM->init();


	_effectSoundVolume = 0.3f;
	_bgmSoundVolume = 0.3f;

	return S_OK;
}
void gameTitleScene::update() 
{
	//�ɼ��� ���õǾ����� ������Ʈ�� �սô�
	if (_isOption)
	{
		_op->update();
	}
	else
	{
		//Ÿ��Ʋ ���� ����� ���� �Լ� 
		soundPlay();
		//�� �̹����� �Ʒ��� �̵�
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			++_shovelIdx;
			if (_shovelIdx >= MAXBTN - 1)	_shovelIdx = MAXBTN - 1;
		}
		//���� �̵�
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			--_shovelIdx;
			if (_shovelIdx <= 0)	_shovelIdx = 0;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			//���� ��ŸƮ ��ư ����
			if (_shovelIdx == 0)
			{
				//���ý� �����׸����� ������ ���������� ���� �뷡 ���.
				_isTitleScene = false;
				SOUNDMANAGER->stop("MainTheme");
				//���ý� ���û��� �߰�
				if (!SOUNDMANAGER->isPlaySound("MainSelect"))
				{
					SOUNDMANAGER->play("MainSelect", _effectSoundVolume);
				}
				
				SCENEMANAGER->changeScene(_gms->getSceneName());
			}
			//�Ⱦ�����
			else if (_shovelIdx == 1)
			{
			}
			//�ɼ� ��ư ����
			else if (_shovelIdx == 2)
			{
				_isOption = true; // �ɼ� ��������! 
			}
			//�Ⱦ�����
			else if (_shovelIdx == 3)
			{
			}

		}
	}



}
void gameTitleScene::release()
{
	
}
void gameTitleScene::render() 
{

	draw();
}
void gameTitleScene::draw()	  
{
	//��׶��� �̹��� ���
	_backgroundImg->render(getMemDC(), 0, 0);
	//�� �̹����� ��µ� �� �ִ¤� ��ġ ��Ʈ ����ϱ�
	if (KEYMANAGER->isStayKeyDown('G'))
	{
		// �׽�Ʈ�� : ���̹����� �� ��Ʈ ������ ���
		for (int i = 0; i < MAXBTN; ++i)
		{
			Rectangle(getMemDC(), _rcBtn[i].left, _rcBtn[i].top, _rcBtn[i].right, _rcBtn[i].bottom);
		}
	}
	//�� ���
	_shovelImg->render(getMemDC(), _rcBtn[_shovelIdx].left, _rcBtn[_shovelIdx].top);
	
	
	//�ɼ��� ���õǾ����� ������ �սô�
	if (_isOption)
	{
		_op->render(getMemDC());
	}

}

void gameTitleScene::setScript()
{
	//������Ʈ 
	//black knight: I knew you'd show your face sooner or later. The cerulean coward!
	char* enemyName = "BlackKnight";
	char* iniFileName = "enemyScript";
	int tmp = INIDATA->loadDataInterger(iniFileName, enemyName, "enemyNum");
	//�̹� �����Ͱ� �����Ƿ� ini ������ ������ �ʴ´�.
	if (tmp != NULL)
	{
		return;
	}
	//�����Ͱ� �����Ƿ� ini ������ ������
	INIDATA->addData(enemyName, "enemyNum", "0");
	INIDATA->iniSave(iniFileName);
	INIDATA->addData(enemyName, "script", "black knight: I knew you'd show your face sooner or later. The cerulean coward!");
	INIDATA->iniSave(iniFileName);
	
}

void gameTitleScene::soundPlay()
{
	if(_isTitleScene)
	{
		if (!SOUNDMANAGER->isPlaySound("MainTheme"))
		{
			SOUNDMANAGER->play("MainTheme", _bgmSoundVolume, true);
		}
	}

}
