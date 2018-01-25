#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);

	_GTS = new gameTitleScene;
	//_gtsStr = "GameTitleScene";
	SCENEMANAGER->addScene(_GTS->getSceneName(), _GTS);

	_GMS = new gameMenuScene;
	SCENEMANAGER->addScene(_GMS->getSceneName(), _GMS);
	_GTS->setGameMenuSceneAddressLink(_GMS);

	SCENEMANAGER->changeScene(_GTS->getSceneName());
	//SCENEMANAGER->changeScene(_GTS->getSceneName());
	//_GTS->setGameMenuSceneAddressLink(_GMS);

	//_GTS->setSceneName(_gtsStr);
	/*SCENEMANAGER->changeScene(_GTS->getSceneName());*/

	//_GPS = new gamePlayScene;
	//SCENEMANAGER->addScene(_GPS->getSceneName(), _GPS);
	//SCENEMANAGER->changeScene(_GPS->getSceneName());

	
	return S_OK;
}

//�޸� ���� ����
void playGround::release(void)
{
	gameNode::release();

}

//����
void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();

		
}

//�׸��°�.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================== �� ���� �մ��� ���ÿ� =========================

	SCENEMANAGER->render();
	
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	TIMEMANAGER->render(getMemDC());

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc������ �׷��ش� 
}
