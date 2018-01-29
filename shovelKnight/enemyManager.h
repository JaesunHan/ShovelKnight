#pragma once
#include "gameNode.h"
#include "minion1.h"
#include "minion2.h"
#include "minion3.h"
#include "skeleton.h"
#include "boss1.h"
#include "bossBlackKnight.h"

#include <vector>


class enemyManager 
{
private:
	typedef vector<enemyBase*>				vEnemy1;
	typedef vector<enemyBase*>::iterator	viEnemy1;

private:
	vEnemy1		_vEnemy;
	viEnemy1	_viEnemy;

	bool _enemyIsOn[4];
	int _stagSetNum;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();


	void stageEnemySet(int stageNum); 	//�ش� ���������� ���ʹ� ����


	//���ʹ� ����&�Ҹ� ������
	void setStageEnemyOn(int stageNum) { _stagSetNum = stageNum; }

	//========================================= Start �̴Ͼ� ���� ========================================

	void setEnemy(ENEMYTYPE enemyType, float enemyX, float enemyY);
	void setEnemy(ENEMYTYPE enemyType, float enemyX, float enemyY, int patternType);
	void removeEnemy(int arrNum);

	//========================================== End �̴Ͼ� ���� =========================================


	//==================================== Start ������ ������ �ۼ��ϱ�===================================

	vector<enemyBase*> getVEnemy() { return _vEnemy; }
	vector<enemyBase*>::iterator getVIEnemy() { return _viEnemy; }

	//===================================== End ������ ������ �ۼ��ϱ�====================================

};

