#pragma once
#include "gameNode.h"

#include "enemyManager.h"
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
	string _sceneName;				//씬매니저에 등록할 씬 이름

	enemyManager* _enemy;
	itemManager* _item;
	StoreManager* _Store;					//npcManager->StoreManager수정했습니다.^_^v -괴도재환 01.25
	skillManager* _skill;
	playerManager* _player;
	gameCollision* _gameCollision;
	stageManager* _stage;
	frontObjectManager* _object;
	gamePlayUI* _gamePlayUI;				//게임 플레이하는 동안 출력될 UI 

	playerList _playerInfo;

	int _selectPlayerIdx;
public:
	gamePlayScene();
	~gamePlayScene();

	//================================= Start 게터 세터 ============================
	inline string getSceneName() { return _sceneName; }
	inline void setSceneName(string sn) { _sceneName = sn; }
	//================================= End 게터 세터 ==============================

	//================================= Start 게임 메뉴씬으로부터 플레이어 정보 받아오기 ==================
	void setPlayerIdx(int* idx) { _selectPlayerIdx = *idx;  _gamePlayUI->setPlayerInfo(&_selectPlayerIdx); }
	//================================= End	게임 메뉴씬으로부터 플레이어 정보 받아오기 ====================

	HRESULT init();
	void release();
	void update();
	void render();

	void renderTestGround();
};

