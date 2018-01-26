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
	_animTarget->setPlayFrame(0, 2, false, true);
	_animTarget->setFPS(1);
	_animTarget->start();

	_pSlotIdx = 0;

//	//�÷��̾� ����Ʈ�� �����ִ� �޴� Ŭ������ �����Ҵ��Ѵ�  �� ��ü�� ���������� �÷��̾��Ʈ�޴��� Ʋ�� �����ش�.
//	_plm = new playerListMenu;
//	_plm->init();
	_plm = new playerListMenu;
	_plm->init();
	//_plm->init(_vPList[_pSlotIdx].name, _vPList[_pSlotIdx].characterkind, _vPList[_pSlotIdx].hp, _vPList[_pSlotIdx].mana, _vPList[_pSlotIdx].money, _vPList[_pSlotIdx].suit, _vPList[_pSlotIdx].weapon);
	//ĳ���͸� �����ڴ� �޴� Ŭ������ �����Ҵ��Ѵ�. �� ��ü�� ���������� ĳ���� ���� �޴��� Ʋ�� �����ش�.
	_ccm = new createCharacterMenu;
	_ccm->init();


	//INI ������ ���� �о����
	loadPlayerListData();

	return S_OK;
}
void gameMenuScene::update() 
{
	_animTarget->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		--_pSlotIdx;
		if (_pSlotIdx <= 0)	_pSlotIdx = 0;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		++_pSlotIdx;
		if (_pSlotIdx >= MAXPLAYERLIST - 1)	_pSlotIdx = MAXPLAYERLIST - 1;
	}

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

	//Ÿ�� �ڽ��� ���� ����Ű�� ����Ʈ�� ���� �������� ������ ĳ���� ����ȭ���� �������
	if (_vPList[_pSlotIdx].hp == 0)
	{
		_ccm->render(getMemDC()); 
	}
	//Ÿ�� �ڽ��� ���� ����Ű�� ����Ʈ�� ���� �����ϸ� �÷��̾� ������ �⤩������
	else 
	{	
		//�÷��̾� ����Ʈ�� �����ִ� �޴� Ŭ������ ������ �����Ҵ��Ѵ�
		//if (_plm)
		//{
		//	_plm = new playerListMenu;
		//	_plm->init(_vPList[_pSlotIdx].name, _vPList[_pSlotIdx].characterkind, _vPList[_pSlotIdx].hp, _vPList[_pSlotIdx].mana, _vPList[_pSlotIdx].money, _vPList[_pSlotIdx].suit, _vPList[_pSlotIdx].weapon);
		//}
		//_plm = new playerListMenu;
		//�ʱ�ȭ �� ���� ���� ������ ������ �����Ͽ� �ʱ�ȭ�ϱ�
		if(_plm->getHP() < 0)
		{
			_plm->init(_vPList[_pSlotIdx].name, _vPList[_pSlotIdx].characterkind, _vPList[_pSlotIdx].hp, _vPList[_pSlotIdx].mana, _vPList[_pSlotIdx].money, _vPList[_pSlotIdx].suit, _vPList[_pSlotIdx].weapon);
		}
		else 
		{
			_plm->render(getMemDC());
		}
	}
	//�÷��̾��Ʈ �Ѹӹ� Ÿ�� �ڽ��� �׻� �������� ����ϱ�
	for (int i = 0; i < MAXPLAYERLIST; ++i)
	{
		_pNumberBox[i].img->render(getMemDC(), _pNumberBox[i].numberBox.left, _pNumberBox[i].numberBox.top);
	}
	_targetImg->aniRender(getMemDC(),
		_pNumberBox[_pSlotIdx].numberBox.left + (_pNumberBox[_pSlotIdx].numberBox.right - _pNumberBox[_pSlotIdx].numberBox.left) / 2 - _targetImg->getFrameWidth() / 2,
		_pNumberBox[_pSlotIdx].numberBox.top + (_pNumberBox[_pSlotIdx].numberBox.bottom - _pNumberBox[_pSlotIdx].numberBox.top) / 2 - _targetImg->getFrameHeight() / 2, 
		_animTarget);


}

void gameMenuScene::makePlayerListData()
{
	//���� ���鶧�� �÷��̾� ��ȣ�� ���ִ� ������ ini �����͸� �����Ѵ�.
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
		p.characterkind = INIDATA->loadDataInterger(fileName, subjectName, "CharacterKind");
		p.hp = INIDATA->loadDataInterger(fileName, subjectName, "HP");
		p.money = INIDATA->loadDataInterger(fileName, subjectName, "Money");
		p.mana = INIDATA->loadDataInterger(fileName, subjectName, "Mana");
		p.suit = INIDATA->loadDataInterger(fileName, subjectName, "Suit");
		p.weapon = INIDATA->loadDataInterger(fileName, subjectName, "Weapon");

		_vPList.push_back(p);
	}

}

