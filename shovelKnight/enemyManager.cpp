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
	_enemyIsOn = true;

	//�� ����
	if (_enemyIsOn)
	{
		setEnemy(ENEMY_BEETO, 200, 200);
		setEnemy(ENEMY_BLORB, 300, 200);
		setEnemy(ELEMY_DRAKE, 400, 150);
		setEnemy(ENEMY_DRAGON, 500, 200);
	}


	return S_OK;
}

void enemyManager::release()
{

}

void enemyManager::update()
{
	//============================================================================ �� move start
	//-------------------------------------------------------------- �̴Ͼ� beeto
	for (_viEnemy = _vEnemy.begin(); _viEnemy != _vEnemy.end(); ++_viEnemy)
	{

		(*_viEnemy)->update();
	
	}

	//���� TEST
	//for (int i = 0; i < _vDragon.size(); i++)
	//{
	//	if (KEYMANAGER->isOnceKeyDown('K'))
	//	{
	//		if (_vDragon[i]->getStatus() == ENEMY_LEFT_MOVE)
	//		{
	//			_vDragon[i]->setStatus(ENEMY_LEFT_DEAD);
	//		}
	//		else if (_vDragon[i]->getStatus() == ENEMY_RIGHT_MOVE)
	//		{
	//			_vDragon[i]->setStatus(ENEMY_RIGHT_DEAD);
	//		}
	//	}
	//	//�׾����� ���Ϳ��� �����
	//	if (_vDragon[i]->getIsDeadVanish() == true)
	//	{
	//		removeBossDragon(i);
	//	}
	//}
	//ȭ������� ������� ����
	//for (int i = 0; i < _vDragon.size(); i++)
	//{
	//	if (_vDragon[i]->getRect().right < 0)
	//		removeBossDragon(i);
	//}
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
	for (int i = 0; i < 2; ++i)
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
	
				//minion = new minion4;
				//minion->init(enemyX, enemyY);

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
}

void enemyManager::removeEnemy(int arrNum)
{
	SAFE_DELETE(_vEnemy[arrNum]);
	_vEnemy.erase(_vEnemy.begin() + arrNum);
}

//======================================================================================== ���ʹ� ���� end