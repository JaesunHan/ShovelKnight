#include "stdafx.h"
#include "StoreManager.h"
#include "playerManager.h" //���漱�� ������� ����


StoreManager::StoreManager()
{
}


StoreManager::~StoreManager()
{
}

HRESULT StoreManager::init()
{
	return S_OK;
}

void StoreManager::release()
{
}

void StoreManager::update()
{
	for (_viNpc = _vNpc.begin(); _viNpc != _vNpc.end(); ++_viNpc)
	{
		(*_viNpc)->update();
	}
	
}

void StoreManager::render()
{
	for (_viNpc = _vNpc.begin(); _viNpc != _vNpc.end(); ++_viNpc)
	{
		(*_viNpc)->render();
	}
}

void StoreManager::playerCollisionNpc()
{
	//�ݸ��� �Ŵ������� �޾ƿ��°ɷ�. 


}

void StoreManager::sellPlayerSkill()
{
	
}

void StoreManager::SellPlayerHp()
{
}

void StoreManager::sellGameBgm()
{
}

void StoreManager::sellEffectSound()
{
}
