#pragma once
#include "gameNode.h"
#include "minion1.h"
#include "minion2.h"
#include "minion3.h"
#include "boss1.h"


#include <vector>


class enemyManager 
{
private:
	typedef vector<enemyBase*>				vEnemy1;
	typedef vector<enemyBase*>::iterator	viEnemy1;

private:
	vEnemy1		_vEnemy;
	viEnemy1	_viEnemy;

	bool _enemyIsOn;

public:
	enemyManager();
	~enemyManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	//�̴Ͼ� ����&�Ҹ� ������
	void setEnemyIsOn(bool isOn) { _enemyIsOn = isOn; }

	//========================================= Start �̴Ͼ� ���� ========================================

	void setEnemy(ENEMYTYPE enemyType, float enemyX, float enemyY);
	void removeEnemy(int arrNum);

	//========================================== End �̴Ͼ� ���� =========================================


	//==================================== Start ������ ������ �ۼ��ϱ�===================================

	vector<enemyBase*> getVEnemy() { return _vEnemy; }
	vector<enemyBase*>::iterator getVIEnemy() { return _viEnemy; }

	//===================================== End ������ ������ �ۼ��ϱ�====================================

};

