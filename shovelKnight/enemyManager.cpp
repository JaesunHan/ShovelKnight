#include "stdafx.h"
#include "enemyManager.h"


enemyManager::enemyManager()
{
	
}
enemyManager::~enemyManager()
{
}


HRESULT enemyManager::init()
{
	//==================================== ���ʹ� �������� ���� �ʱ�ȭ
	for (int i = 0; i < 4; ++i)
	{
		_enemyIsOn[i] = false;
	}
	_stagSetNum = 99;
	//====================================

	_stagSetNum = 2;
	//==================================== �� ����
	stageEnemySet(_stagSetNum);
	//====================================

	return S_OK;
}

void enemyManager::release()
{

}

void enemyManager::update()
{
	//============================================================================ �� respawn
	//if ()
	//{
	//	stageEnemySet(_stagSetNum);
	//}


	//============================================================================ �� ī�޶� �ƿ� �Ҹ�
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		if (_vEnemy[i]->getRect().right < 0)
			removeEnemy(i);
	}



	//============================================================================ �� move start
	//-------------------------------------------------------------- ���ʹ� ����� ����
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		//�׾����� ���Ϳ��� �����
		if (_vEnemy[i]->getIsDeadVanish() == true)
		{
			removeEnemy(i);
		}
	}

	//-------------------------------------------------------------- ���ʹ� update
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{

		(*_viEnemy)->update();
	
	}
	//-------------------------------------------------------------- 
	//============================================================================ �� move end
}

void enemyManager::render()
{
	//============================================================================ �� render start

	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{

		(*_viEnemy)->render();

	}

	//============================================================================ �� render end
}



//======================================================================================== ���ʹ� ���� start
//                          ���׹� ����          X��ǥ         Y��ǥ        
void enemyManager::setEnemy(ENEMYTYPE enemyType, float enemyX, float enemyY)
{
	enemyBase* minion;

	switch (enemyType)
	{
		case ENEMY_BEETO:

			minion = new minion1;
			minion->init(enemyX, enemyY);

		break;
		case ENEMY_BLORB:

			minion = new minion2;
			minion->init(enemyX, enemyY);
		
		break;
		case ELEMY_DRAKE:

			minion = new minion3;
			minion->init(enemyX, enemyY);

		break;
		case ENEMY_SKELETON:

			minion = new skeleton;
			minion->init(enemyX, enemyY);

		break;
		case ENEMY_DRAGON:

			minion = new boss1;
			minion->init(enemyX, enemyY);

		break;
		case ENEMY_BLACKKNIGHT:

			//minion = new boss2;
			//minion->init(enemyX, enemyY);

		break;
	}


	_vEnemy.push_back(minion);

}

void enemyManager::removeEnemy(int arrNum)
{
	SAFE_DELETE(_vEnemy[arrNum]);
	_vEnemy.erase(_vEnemy.begin() + arrNum);
}

void enemyManager::stageEnemySet(int stageNum)
{ 
	//����ó��
	if (stageNum >= 10) return;

	//���� �������� ���ʹ� �� on
	_enemyIsOn[stageNum - 2] = true;

	if (_enemyIsOn[0]) 		//stage1
	{
		setEnemy(ENEMY_BEETO, 300, 200);
		setEnemy(ENEMY_BLORB, 350, 200);
		setEnemy(ELEMY_DRAKE, 300, 150);
		setEnemy(ENEMY_SKELETON, 350, 120);
		setEnemy(ENEMY_DRAGON, 400, 179.5);
	}
	if (_enemyIsOn[1])  //stage2
	{
		setEnemy(ELEMY_DRAKE, 400, 150);
		setEnemy(ENEMY_SKELETON, 350, 120);
	}
	if (_enemyIsOn[2])  //stage3
	{
		setEnemy(ENEMY_DRAGON, 400, 179.5);
	}
	if (_enemyIsOn[3])  //stage3
	{
		setEnemy(ENEMY_DRAGON, 400, 179.5);
	}
}

//======================================================================================== ���ʹ� ���� end