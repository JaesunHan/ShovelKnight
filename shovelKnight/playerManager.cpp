#include "stdafx.h"
#include "playerManager.h"
#include "stageManager.h"
#include "gameCollision.h"
#include "skillManager.h"
#include "frontObjectManager.h"
#include "gamePlayUI.h"

playerManager::playerManager()
{
}


playerManager::~playerManager()
{
}

HRESULT playerManager::init()
{
	_p1 = new player1;
	_p1->init();
	_p1->setSMMemoryAddressLink(_SM);
	_p1->setGameCollisinMemoryAddressLink(_GC);
	_p1->setSkillManagerMemoryAddressLink(_skillM);
	_p1->setGamePlayUIMemoryAddressLink(_GPU);
	_p1->setFrontObjectManagerMemoryAddressLink(_FOM);

	//_p1->setPlayerHp(_GPU->getLife());
	//_p1->setPlayerMaxHP(_GPU->getMaxLife());
	//_p1->setPlayerMP(_GPU->getMana());
	//_p1->setMoney(_GPU->getGold());

	return S_OK;
}

void playerManager::release()
{
}

void playerManager::update()
{
	_p1->update();
	_p1->setPlayerHp(_GPU->getLife());
	_p1->setPlayerMaxHP(_GPU->getMaxLife());
	_p1->setPlayerMP(_GPU->getMana());
	_p1->setMoney(_GPU->getGold());
}

void playerManager::render()
{
	_p1->render();
}
