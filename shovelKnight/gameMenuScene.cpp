#include "stdafx.h"
#include "gameMenuScene.h"


gameMenuScene::gameMenuScene()
{
	_sceneName = "GameMenuScene";
}


gameMenuScene::~gameMenuScene()
{

}


HRESULT gameMenuScene::init()
{
	_menuBGImgKeyStr = "menuBackgroundImg";
	_menuBGImgFileName = "./image/title/profileDefault.bmp";
	_backgroundImg = IMAGEMANAGER->addImage(_menuBGImgKeyStr, _menuBGImgFileName, 0, 0, WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	//INI ������ ���� �о����
	loadPlayerListData();

	for (int i = 0; i < MAXPLAYERLIST; ++i)
	{
		//214, 134
		//���� �ڽ��� �� ��ġ�� ��Ʈ�� �����س���
		_pNumberBox[i].numberBox = RectMakeCenter(210 + i * 40, 134, 28, 28);
		//��Ʈ �ڽ� �ȿ� �� �̹��� ���� �� �̹��� �Ŵ����� ����س���
		char nImagFileNmae[258];
		wsprintf(nImagFileNmae, "./image/title/number%d.bmp", i+1);
		char nImageKeyStr[128];
		wsprintf(nImageKeyStr, "number%d", i + 1);
		_pNumberBox[i].img = IMAGEMANAGER->addImage(nImageKeyStr, nImagFileNmae, 0, 0, 28, 28, true, RGB(255, 0, 255));
	}

	_targetImg = IMAGEMANAGER->addFrameImage("targetBox", "./image/title/selectBoxFrame.bmp", 0, 0, 80, 37, 2, 1, true, RGB(255, 0, 255));
	_animTarget = new animation;
	_animTarget->init(_targetImg->getWidth(), _targetImg->getHeight(), _targetImg->getFrameWidth(), _targetImg->getFrameHeight());

	_pSlotIdx = 0;

	return S_OK;
}
void gameMenuScene::update() 
{
	
}
void gameMenuScene::release()
{

}
void gameMenuScene::render() 
{
	draw();
}
void gameMenuScene::draw()	 
{
	//�⺻�̹��� ����
	_backgroundImg->render(getMemDC(), 0,0);
	for (int i = 0; i < MAXPLAYERLIST; ++i)
	{
		_pNumberBox[i].img->render(getMemDC(), _pNumberBox[i].numberBox.left, _pNumberBox[i].numberBox.top);
	}
}

void gameMenuScene::makePlayerListData()
{
	//���� ���鶧�� �÷��̾� ��ȣ�� ���ִ� ini �����͸� �����Ѵ�.
	char* fileName = "playerList";
	char subjectName[256];
	char titleBody[128];
	for (int i = 0; i < MAXPLAYERLIST; ++i)
	{
		wsprintf(subjectName, "palyer%d", i);
		wsprintf(titleBody, "%d", i);
		//�÷��̾� ��ȣ �����ϱ�
		INIDATA->addData(subjectName, "palyerNumber", titleBody);
		INIDATA->iniSave(fileName);
	}
}

void gameMenuScene::loadPlayerListData()
{
	char* fileName = "playerList";
	char subjectName[256];
	//playerNumber = 0, playerNumber = 1, .... 
	//playerNumber Ÿ��Ʋ�� �о�ͼ� 0 ���� ����Ǿ����� ������
	//���Ͽ� ������ �ƿ� ���� �Ŵϱ� �̶� ������ �����
	if (INIDATA->loadDataInterger(fileName, "player0", "playerNumebr") == NULL)
	{
		makePlayerListData();//���� ����� �Լ��� ȣ��
	}
	//���Ͽ� �ִ� �÷��̾ ���Ϳ� ���
	for (int i = 0; i < MAXPLAYERLIST; ++i)
	{
		playerList p;
		wsprintf(subjectName, "palyer%d", i);
	
		p.pNum = INIDATA->loadDataInterger(fileName, subjectName, "playerNumber");
		p.name = INIDATA->loadDataString(fileName, subjectName, "playerName");
		p.hp = INIDATA->loadDataInterger(fileName, subjectName, "HP");
		p.money = INIDATA->loadDataInterger(fileName, subjectName, "Money");
		p.mana = INIDATA->loadDataInterger(fileName, subjectName, "Mana");

		_vPList.push_back(p);
	}

}

