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
	//ȭ������� ������� ����
	for (int i = 0; i < _vBeeto.size(); i++)
	{
		if (_vBeeto[i]->getRect().right < 200)
			removeMinionBeeto(i);
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
	//============================================================================ �� render end
}



//================================================================== �̴Ͼ� ���� start
//-------------------------------------------------------------- beeto
void enemyManager::setMinionBeeto(void)
{
	for (int i = 0; i < 5; ++i)
	{
		minion1* minion;
		minion = new minion1;

		minion->init(500 + (i * 50), 350 - (i * 50));

		_vBeeto.push_back(minion);
	}
}

void enemyManager::removeMinionBeeto(int arrNum)
{
	SAFE_DELETE(_vBeeto[arrNum]);
	_vBeeto.erase(_vBeeto.begin() + arrNum);
}
//--------------------------------------------------------------
//================================================================== �̴Ͼ� ���� end