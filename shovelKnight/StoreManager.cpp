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
		//NPC���͸� ������Ʈ���� ��� ���ٰ�


		//if (playerCollisionNpc) // �浹������? <- collision�Ŵ������� �޾Ƽ� ������.
		//{
			sellPlayerSkill(_viNpc);		//��ų���ΰ��� ��ȣ�ۿ�
			SellPlayerHp(_viNpc);			//ü�»��ΰ��� ��ȣ�ۿ�
			sellGameBgm(_viNpc);			//���ǻ��ΰ��� ��ȣ�ۿ�
		//}
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

void StoreManager::playerCollisionNpc(vector<npcBase*>::iterator temp)
{
	//�ݸ��� �Ŵ������� �޾ƿ��°ɷ�. 
	

}

void StoreManager::sellPlayerSkill(vector<npcBase*>::iterator temp)
{
	if ((*temp)->getNpcType() == MAGICGIRL)	//NPCŸ���� �������϶�
	{
		if ((*temp)->getStock() == 0)		//�ѹ��� ���Ÿ� ��������  (stock�� ����Ƚ�� ����)
		{
			//�ؽ�Ʈ �ƿ����� "�� �̰� �췡? Yes or No(bool��<-���� �ϳ� �߰��ؾ��� 1.25)
			//�Ʒ��� Yes ������������ �Լ�
			_pm->getMoney() > 1000;
			//�÷��̾ �°���ؼ� ��� �����ϰ� 
			//�ش� ��ų Ű�� �޾Ƽ� 
			//������ true�� �ٲ��ش�.
			(*temp)->setStock(1);			//�ѹ� ���������ϱ� stock�� 1�� ��ȯ���ش�.
		}
		if ((*temp)->getStock() == 1) 
		{
			_pm->getMoney() > 3000;
		}
	}
	
}

void StoreManager::SellPlayerHp(vector<npcBase*>::iterator temp)
{
	if ((*temp)->getStock() == 0)
	{
		//�ؽ�Ʈ �ƿ����� "
	}
}

void StoreManager::sellGameBgm(vector<npcBase*>::iterator temp)
{
}


