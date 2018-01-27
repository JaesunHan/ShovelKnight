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
	setMinionBeeto();
	setMinionBlorb();
	setMinionDrake();


	return S_OK;
}

void enemyManager::release()
{

}

void enemyManager::update()
{
	//============================================================================ �� move start
	//-------------------------------------------------------------- �̴Ͼ� beeto
	for (_viBeeto = _vBeeto.begin(); _viBeeto != _vBeeto.end(); ++_viBeeto)
	{

		(*_viBeeto)->update();
	
	}
	//���� TEST
	for (int i = 0; i < _vBeeto.size(); i++)
	{
		if (_vBeeto[i]->getRect().right < 200)
		{
			if (_vBeeto[i]->getStatus() == ENEMY_LEFT_MOVE)
			{
				_vBeeto[i]->setStatus(ENEMY_LEFT_DEAD);
			}
			else if (_vBeeto[i]->getStatus() == ENEMY_RIGHT_MOVE)
			{
				_vBeeto[i]->setStatus(ENEMY_RIGHT_DEAD);
			}
		}
		//�׾����� ���Ϳ��� �����
		if (_vBeeto[i]->getIsDeadVanish() == true)
		{
			removeMinionBeeto(i);
		}
	}
	//ȭ������� ������� ����
	for (int i = 0; i < _vBeeto.size(); i++)
	{
		if (_vBeeto[i]->getRect().right < 0)
			removeMinionBeeto(i);
	}
	//-------------------------------------------------------------- 

	//-------------------------------------------------------------- �̴Ͼ� blorb
	for (_viBlorb = _vBlorb.begin(); _viBlorb != _vBlorb.end(); ++_viBlorb)
	{

		(*_viBlorb)->update();

	}
	//���� TEST
	for (int i = 0; i < _vBlorb.size(); i++)
	{
		if (_vBlorb[i]->getRect().right < 200)
		{
			if (_vBlorb[i]->getStatus() == ENEMY_LEFT_MOVE)
			{
				_vBlorb[i]->setStatus(ENEMY_LEFT_DEAD);
			}
			else if (_vBlorb[i]->getStatus() == ENEMY_RIGHT_MOVE)
			{
				_vBlorb[i]->setStatus(ENEMY_RIGHT_DEAD);
			}
		}
		//�׾����� ���Ϳ��� �����
		if (_vBlorb[i]->getIsDeadVanish() == true)
		{
			removeMinionBlorb(i);
		}
	}
	//ȭ������� ������� ����
	for (int i = 0; i < _vBlorb.size(); i++)
	{
		if (_vBlorb[i]->getRect().right < 0)
			removeMinionBlorb(i);
	}
	//-------------------------------------------------------------- 

	//-------------------------------------------------------------- �̴Ͼ� drake
	for (_viDrake = _vDrake.begin(); _viDrake != _vDrake.end(); ++_viDrake)
	{

		(*_viDrake)->update();

	}
	//���� TEST
	for (int i = 0; i < _vDrake.size(); i++)
	{
		if (KEYMANAGER->isOnceKeyDown('K'))
		{
			if (_vDrake[i]->getStatus() == ENEMY_LEFT_MOVE)
			{
				_vDrake[i]->setStatus(ENEMY_LEFT_DEAD);
			}
			else if (_vDrake[i]->getStatus() == ENEMY_RIGHT_MOVE)
			{
				_vDrake[i]->setStatus(ENEMY_RIGHT_DEAD);
			}
		}
		//�׾����� ���Ϳ��� �����
		if (_vDrake[i]->getIsDeadVanish() == true)
		{
			removeMinionBlorb(i);
		}
	}
	//ȭ������� ������� ����
	for (int i = 0; i < _vDrake.size(); i++)
	{
		if (_vDrake[i]->getRect().right < 0)
			removeMinionBlorb(i);
	}
	//-------------------------------------------------------------- 
	//============================================================================ �� move end
}

void enemyManager::render()
{
	//============================================================================ �� render start
	//-------------------------------------------------------------- �̴Ͼ� beeto
	for (_viBeeto = _vBeeto.begin(); _viBeeto != _vBeeto.end(); ++_viBeeto)
	{

		(*_viBeeto)->render();

	}
	//--------------------------------------------------------------

	//-------------------------------------------------------------- �̴Ͼ� blorb
	for (_viBlorb = _vBlorb.begin(); _viBlorb != _vBlorb.end(); ++_viBlorb)
	{

		(*_viBlorb)->render();

	}
	//--------------------------------------------------------------

	//-------------------------------------------------------------- �̴Ͼ� drake
	for (_viDrake = _vDrake.begin(); _viDrake != _vDrake.end(); ++_viDrake)
	{

		(*_viDrake)->render();

	}
	//--------------------------------------------------------------
	//============================================================================ �� render end
}



//================================================================== �̴Ͼ� ���� start
//-------------------------------------------------------------- beeto
void enemyManager::setMinionBeeto(void)
{
	for (int i = 0; i < 2; ++i)
	{
		minion1* minion;
		minion = new minion1;

		minion->init(900 + i * 200, 200 - 13);

		_vBeeto.push_back(minion);
	}
}

void enemyManager::removeMinionBeeto(int arrNum)
{
	SAFE_DELETE(_vBeeto[arrNum]);
	_vBeeto.erase(_vBeeto.begin() + arrNum);
}
//--------------------------------------------------------------

//-------------------------------------------------------------- blorb
void enemyManager::setMinionBlorb(void)
{
	for (int i = 0; i < 2; ++i)
	{
		minion2* minion;
		minion = new minion2;

		minion->init(800 + i * 200, 180);

		_vBlorb.push_back(minion);
	}
}

void enemyManager::removeMinionBlorb(int arrNum)
{
	SAFE_DELETE(_vBlorb[arrNum]);
	_vBlorb.erase(_vBlorb.begin() + arrNum);
}
//--------------------------------------------------------------

//-------------------------------------------------------------- drake
void enemyManager::setMinionDrake(void)
{
	for (int i = 0; i < 1; ++i)
	{
		minion3* minion;
		minion = new minion3;

		minion->init(1470, 130);

		_vDrake.push_back(minion);
	}
}

void enemyManager::removeMinionDrake(int arrNum)
{
	SAFE_DELETE(_vDrake[arrNum]);
	_vDrake.erase(_vDrake.begin() + arrNum);
}
//--------------------------------------------------------------
//================================================================== �̴Ͼ� ���� end