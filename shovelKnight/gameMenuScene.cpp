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

	loadPlayerListData();

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
	_backgroundImg->render(getMemDC(), 0,0);
}

void gameMenuScene::makePlayerListData()
{
	char* fileName = "playerList";
	char subjectName[256];
	char titleBody[128];
	for (int i = 0; i < MAXPLAYERLIST; ++i)
	{
		wsprintf(subjectName, "palyer%d", i);
		wsprintf(titleBody, "%d", i);
		//��ȣ �����ϱ�
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
		makePlayerListData();
	}
	for (int i = 0; i < MAXPLAYERLIST; ++i)
	{
		playerBase* p1 = new player1;
		wsprintf(subjectName, "palyer%d", i);
		INIDATA->loadDataInterger(fileName, subjectName, "Name");
		
	}

}

