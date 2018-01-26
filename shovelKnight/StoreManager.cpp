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
	
	TextOut(getMemDC(), 55, 100, str1, strlen(str1));
	TextOut(getMemDC(), 55, 100, str2, strlen(str2));
	TextOut(getMemDC(), 55, 100, str3, strlen(str3));
}

void StoreManager::playerCollisionNpc(vector<npcBase*>::iterator temp)
{
	//�ݸ��� �Ŵ������� �޾ƿ��°ɷ�. 
	//�ݸ��� �Ŵ������� �̳Ѱ����� �޾ƿ���
	//�ش� �̳Ѱ����� �浹�� Ȯ�εǸ� wŰ�� ���� ��ȭ�� ���������°����� �����Ұ�
	_isCollisionNpc == true;

}

void StoreManager::sellPlayerSkill(vector<npcBase*>::iterator temp)
{
	if (_isCollisionNpc == true)
	{
		if ((*temp)->getNpcType() == MAGICGIRL)	//NPCŸ���� �������϶�
		{
			if ((*temp)->getStock() == 0)		//�ѹ��� ���Ÿ� ��������  (stock�� ����Ƚ�� ����)
			{
				//�ؽ�Ʈ �ƿ����� "�� �̰� �췡? Yes or No(bool��<-���� �ϳ� �߰��ؾ��� 1.25)
				//�Ʒ��� Yes ������������ �Լ�
				sprintf(str1, "Welcome, Welcome My friend");
				sprintf(str2, "you wanna buy some weed?:P");
				sprintf(str3, "if u OK press 'O', or not press 'P'");
				

				if (KEYMANAGER->isOnceKeyDown('O'));				//O��������
				{
					if ((*temp)->getStock() == 0)					//�ѹ��� �������� ���Ÿ� ���� �ʾ�����
					{
						if (_pm->getMoney() >= 1000)					//�÷��̾� ��尡 1000������ ũ�ٸ�
						{
							_pm->setMoney(-1000);						//�÷��̾� ��忡�� 1000���� �����ϰ� 
							_pm->setMaxHP(+1);							//maxHP�� 1 �����ش�.
							(*temp)->setStock(1);						//�ѹ� ���������ϱ� stock�� 1�� ��ȯ���ش�.
						}
						if (_pm->getMoney() < 1000)						//�÷��̾� ��尡 1000������ �۴ٸ�
						{
							sprintf(str4, "get the fuck off!!!!");
						}
					}


					if ((*temp)->getStock() == 1)						//�������� ���Ű� 2ȸ���ϋ�
					{
						if (_pm->getMoney() >= 3000)					//�÷��̾� ��尡 1000������ ũ�ٸ�
						{
							_pm->setMoney(-3000);						//�÷��̾� ��忡�� 1000���� �����ϰ� 
							_pm->setMaxHP(+1);							//maxHP�� 1 �����ش�.
							(*temp)->setStock(2);						//stock�� 2�� ��ȯ���ش�.
						}
						if (_pm->getMoney() < 3000)						//�÷��̾� ��尡 3000������ �۴ٸ�
						{
							sprintf(str4, "get the fuck off!!!!");
						}
					}
				}
			}
			

			//NO�������� �ؽ�Ʈ �ƿ�����
			//"�� ��...�׷�? �ȳ� ���� " ���̾�α� ��� ����
			_isCollisionNpc == false;
		}
	}
}

void StoreManager::SellPlayerHp(vector<npcBase*>::iterator temp)
{
	if ((*temp)->getNpcType() == HEALTYGUY)	//NPCŸ���� �������϶�
	{
		if ((*temp)->getStock() == 0)		//�ѹ��� ���Ÿ� ��������  (stock�� ����Ƚ�� ����)
		{
			//�ؽ�Ʈ �ƿ����� "�� �̰� �췡? Yes or No(bool��<-���� �ϳ� �߰��ؾ��� 1.25)
			//�Ʒ��� Yes ������������ �Լ�
			sprintf(str1, "Welcome, Welcome My friend");
			sprintf(str2, "you wanna buy some weed?:P");
			sprintf(str3, "if u OK press 'O', or not press 'P'");


			if (KEYMANAGER->isOnceKeyDown('O'));				//O��������
			{
				if ((*temp)->getStock() == 0)					//�ѹ��� �������� ���Ÿ� ���� �ʾ�����
				{
					if (_pm->getMoney() >= 1000)					//�÷��̾� ��尡 1000������ ũ�ٸ�
					{
						_pm->setMoney(-1000);						//�÷��̾� ��忡�� 1000���� �����ϰ� 
						_pm->setMaxHP(+1);							//maxHP�� 1 �����ش�.
						(*temp)->setStock(1);						//�ѹ� ���������ϱ� stock�� 1�� ��ȯ���ش�.
					}
					if (_pm->getMoney() < 1000)						//�÷��̾� ��尡 1000������ �۴ٸ�
					{
						sprintf(str4, "get the fuck off!!!!");
					}
				}


				if ((*temp)->getStock() == 1)						//�������� ���Ű� 2ȸ���ϋ�
				{
					if (_pm->getMoney() >= 3000)					//�÷��̾� ��尡 1000������ ũ�ٸ�
					{
						_pm->setMoney(-3000);						//�÷��̾� ��忡�� 1000���� �����ϰ� 
						_pm->setMaxHP(+1);							//maxHP�� 1 �����ش�.
						(*temp)->setStock(2);						//stock�� 2�� ��ȯ���ش�.
					}
					if (_pm->getMoney() < 3000)						//�÷��̾� ��尡 3000������ �۴ٸ�
					{
						sprintf(str4, "get the fuck off!!!!");
					}
				}
			}
		}
		//NO�������� �ؽ�Ʈ �ƿ�����
		//"�� ��...�׷�? �ȳ� ���� " ���̾�α� ��� ����
		_isCollisionNpc == false;
	}
}

void StoreManager::sellGameBgm(vector<npcBase*>::iterator temp)
{
	if ((*temp)->getNpcType() == HEALTYGUY)	//NPCŸ���� �������϶�
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
		if ((*temp)->getStock() == 1) //2ȸ�� �����϶� 
		{
			_pm->getMoney() > 3000;
		}

		//NO�������� �ؽ�Ʈ �ƿ�����
		//"�� ��...�׷�? �ȳ� ���� " ���̾�α� ��� ����
		_isCollisionNpc == false;
	}

}


