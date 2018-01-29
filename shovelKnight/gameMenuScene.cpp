#include "stdafx.h"
#include "gameMenuScene.h"
#include "gamePlayScene.h"

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
	for (int i = 0; i < MAXPLAYERLIST; ++i)
	{
		_plm[i] = new playerListMenu;
		_plm[i]->init();
	}
	
	//_plm->init(_vPList[_pSlotIdx].name, _vPList[_pSlotIdx].characterkind, _vPList[_pSlotIdx].hp, _vPList[_pSlotIdx].mana, _vPList[_pSlotIdx].money, _vPList[_pSlotIdx].suit, _vPList[_pSlotIdx].weapon);
	//ĳ���͸� �����ڴ� �޴� Ŭ������ �����Ҵ��Ѵ�. �� ��ü�� ���������� ĳ���� ���� �޴��� Ʋ�� �����ش�.
	_ccm = new createCharacterMenu;
	_ccm->init();

	//��ũ��Ʈ �׽�Ʈ ��
	_testScript = new image;
	_testScript = IMAGEMANAGER->addImage("scriptWindow", "./image/UI/Script_window.bmp", 0, 0, 800, 96, true, RGB(255, 0, 255));
	DIALOGUEMANAGER->setScriptNScriptWindow("this is test Script ", _testScript, 255, 255, 255);
	//INI ������ ���� �о����
	loadPlayerListData();

	return S_OK;
}
void gameMenuScene::update() 
{
	//Ÿ�� �ڽ��� �ִϷ����̹Ƿ� �������� �����ϱ�
	_animTarget->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);
	//Ÿ�� �ڽ��� ����Ű�� �����δ�(�¿�)
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		--_pSlotIdx;
		if (_pSlotIdx <= 0)	_pSlotIdx = 0;
		//DIALOGUEMANAGER->setScriptNScriptWindow("this is test Script "+_pSlotIdx, _testScript, 255, 255, 255);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		++_pSlotIdx;
		if (_pSlotIdx >= MAXPLAYERLIST - 1)	_pSlotIdx = MAXPLAYERLIST - 1;
		//DIALOGUEMANAGER->setScriptNScriptWindow("this is test Script 5", _testScript, 255, 255, 255);
	}

	//Ÿ�� �ڽ��� ���� ����Ű�� ����Ʈ�� ���� �������� ������ ĳ���� ����ȭ�� ��ü�� ������Ʈ
	if (_vPList[_pSlotIdx].hp < 0)
	{
		//_ccm->update();
	}
	//Ÿ�� �ڽ��� ���� ����Ű�� ����Ʈ�� ���� �����ϸ� �÷��̾� ������ �⤩������
	else
	{
		//plm �� ���� ������ �ʱ�ȭ ���� ���� ���
		if (_plm[_pSlotIdx]->getHP() < 0)
		{
			//�ʱ�ȭ�ϱ�
			_plm[_pSlotIdx]->init(_vPList[_pSlotIdx].name, _vPList[_pSlotIdx].characterkind, _vPList[_pSlotIdx].hp, _vPList[_pSlotIdx].maxHp, _vPList[_pSlotIdx].mana, _vPList[_pSlotIdx].money, _vPList[_pSlotIdx].suit, _vPList[_pSlotIdx].weapon);

		}
		else
		{
			//�� ������Ʈ������ ĳ���� �̹����� ������ ������ ���� (���� ĳ������ ������ ��¦��)
			_plm[_pSlotIdx]->update();
			
		}
	}

	//K ��ư�� ������ ���� �ε����� ĳ���͸� �����ϱ�(�⺻������ �����Ѵ�.)
	if (KEYMANAGER->isOnceKeyDown('K'))
	{
		//���� ������ ���Կ� ������ ���� ���� ĳ���͸� ���� �����Ѵ�.
		if (_vPList[_pSlotIdx].name[0] == '\0')
		{
			//���ο� �⺻ĳ���͸� �����ϰ� ini ���Ͽ� �����ϴ� �Լ��� ȣ��
			createNewDefaultCharacter();
			_plm[_pSlotIdx]->init(_vPList[_pSlotIdx].name, _vPList[_pSlotIdx].characterkind, _vPList[_pSlotIdx].hp, _vPList[_pSlotIdx].maxHp, _vPList[_pSlotIdx].mana, _vPList[_pSlotIdx].money, _vPList[_pSlotIdx].suit, _vPList[_pSlotIdx].weapon);
		}
		else
		{
			SCENEMANAGER->changeScene(_GPS->getSceneName());
			_GPS->setPlayerIdx(&_pSlotIdx);
		}
	}
	//DIALOGUEMANAGER->update();
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
		//�ʱ�ȭ �� ���� ���� ������ ������ �����Ͽ� �ʱ�ȭ�ϱ�
		if (!(_plm[_pSlotIdx]->getHP() < 0))
		{
			_plm[_pSlotIdx]->render(getMemDC());
		}
		//DIALOGUEMANAGER->render(getMemDC(), 0, 0, 800, 96);
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
		wsprintf(subjectName, "player%d", i);
		wsprintf(titleBody, "%d", i);
		//�÷��̾� ��ȣ �����ϱ�
		INIDATA->addData(subjectName, "playerNumber", titleBody);
		INIDATA->iniSave(fileName);
	}
}

void gameMenuScene::loadPlayerListData()
{
	char* fileName = "playerList";
	char subjectName[256];
	//ini ������ �������� ������ ���� �����
	if (access("./playerList.ini", 0) == -1)
	{
		makePlayerListData();
	}

	//���Ͽ� �ִ� �÷��̾ ���Ϳ� ���
	for (int i = 0; i < MAXPLAYERLIST; ++i)
	{
		playerList p;
		wsprintf(subjectName, "player%d", i);
	
		p.pNum = INIDATA->loadDataInterger(fileName, subjectName, "playerNumber");
		wsprintf(p.name, "%s", INIDATA->loadDataString(fileName, subjectName, "Name"));
		//p.name = INIDATA->loadDataString(fileName, subjectName, "Name");
		p.characterkind = INIDATA->loadDataInterger(fileName, subjectName, "CharacterKind");
		p.hp = INIDATA->loadDataInterger(fileName, subjectName, "HP");
		p.maxHp = INIDATA->loadDataInterger(fileName, subjectName, "MaxHP");
		p.money = INIDATA->loadDataInterger(fileName, subjectName, "Money");
		p.mana = INIDATA->loadDataInterger(fileName, subjectName, "Mana");
		p.suit = INIDATA->loadDataInterger(fileName, subjectName, "Suit");
		p.weapon = INIDATA->loadDataInterger(fileName, subjectName, "Weapon");

		_vPList.push_back(p);
	}

}

void gameMenuScene::createNewDefaultCharacter()
{
	
	//�⺻���� ������ ����ü��  �����ϰ�
	playerList p;
	wsprintf(p.name, "palyerNumber%d", _pSlotIdx);
	p.characterkind = 0;
	p.hp = 8;
	p.maxHp = 8;
	p.mana = 30;
	p.money = 1000;
	p.suit = 0;
	p.weapon = 0;
	//������ �ش� �ε����� �� ����ü �����͸� �����
	_vPList[_pSlotIdx] = p;
	//�׸��� INIDATA�� �����Ѵ�

	char* fileName = "playerList";
	char subjectName[256];
	wsprintf(subjectName, "player%d", _pSlotIdx);
	
	INIDATA->addData(subjectName, "Name", _vPList[_pSlotIdx].name);
	INIDATA->iniSave(fileName);
	addNsaveINTDataInINIFile(fileName, subjectName, "CharacterKind", _vPList[_pSlotIdx].characterkind);
	addNsaveINTDataInINIFile(fileName, subjectName, "HP", _vPList[_pSlotIdx].hp);
	addNsaveINTDataInINIFile(fileName, subjectName, "Mana", _vPList[_pSlotIdx].mana);
	addNsaveINTDataInINIFile(fileName, subjectName, "Money", _vPList[_pSlotIdx].money);
	addNsaveINTDataInINIFile(fileName, subjectName, "Suit", _vPList[_pSlotIdx].suit);
	addNsaveINTDataInINIFile(fileName, subjectName, "Weapon", _vPList[_pSlotIdx].weapon);
	
}
void gameMenuScene::addNsaveINTDataInINIFile(char* fileName, char subjectName[256], char title[256], int data)
{
	char str[128];
	wsprintf(str, "%d", data);
	INIDATA->addData(subjectName, title, str);
	INIDATA->iniSave(fileName);
}