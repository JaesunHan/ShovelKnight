#pragma once
#include "gameNode.h"

#include "enemyManager.h"
#include "gameObjectManager.h"
#include "itemManager.h"
#include "StoreManager.h"
#include "skillManager.h"
#include "playerManager.h"
#include "stageManager.h"
#include "frontObjectManager.h"

#include "gameCollision.h"

#include "gameMenuScene.h"

#include "gamePlayUI.h"


class gamePlayScene : public gameNode
{
private:
	string _sceneName;				//���Ŵ����� ����� �� �̸�

	enemyManager* _enemy;
	gameObjectManager* _gameObject;
	itemManager* _item;
	StoreManager* _Store;					//npcManager->StoreManager�����߽��ϴ�.^_^v -������ȯ 01.25
	skillManager* _skill;
	playerManager* _player;
	gameCollision* _gameCollision;
	stageManager* _stage;
	frontObjectManager* _object;
	gamePlayUI* _gamePlayUI;				//���� �÷����ϴ� ���� ��µ� UI 

	playerList _playerInfo;

	int _selectPlayerIdx;
public:
	gamePlayScene();
	~gamePlayScene();

	//================================= Start ���� ���� ============================
	inline string getSceneName() { return _sceneName; }
	inline void setSceneName(string sn) { _sceneName = sn; }
	//================================= End ���� ���� ==============================

	//================================= Start ���� �޴������κ��� �÷��̾� ���� �޾ƿ��� ==================
	void setPlayerIdx(int* idx) { _selectPlayerIdx = *idx;  _gamePlayUI->setPlayerInfo(&_selectPlayerIdx); }
	//================================= End	���� �޴������κ��� �÷��̾� ���� �޾ƿ��� ====================

	HRESULT init();
	void release();
	void update();
	void render();

	void renderTestGround();
};

