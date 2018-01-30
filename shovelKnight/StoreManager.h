#pragma once
#include "gameNode.h"
#include "MagicGirl.h"
#include "HealtyGuy.h"
#include "BardKnight.h"
#include <vector>

#define NPCNUM 3


//enum STORESTATUS
//{
//	STORECOLLISION,
//	ENDSTORESTATUS
//};

//��ȣ������ ���� ��������
class playerManager;

class StoreManager : public gameNode
{
private:
	typedef vector<npcBase*> vNPC;
	typedef vector<npcBase*>::iterator viNPC;


private:
	vNPC _vNpc;									//npc����
	viNPC _viNpc;								//npc�������ͷ�����

	playerManager* _pm;							//�÷��̾�Ŵ��� �Ҵ�
	//
	//
	//
	//bool _isCollisionNpc;						//NPC�� �浹�ߴ�
	//int _showshowshowshow;						//�浹�ߴ��� ������ ����
	//char str1[128];
	//char str2[128];
	//char str3[128];
	//char str4[128];
	//char str5[128];

public:
	StoreManager();
	~StoreManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	//void playerCollisionNpc(vector<npcBase*>::iterator temp);					//NPC�� �浹����
	//void sellPlayerSkill(vector<npcBase*>::iterator temp);						//�÷��̾� ��ų�Ǹ�
	//void SellPlayerHp(vector<npcBase*>::iterator temp);							//�÷��̾� �ִ�ü�� �߰��Ǹ�
	//void sellGameBgm(vector<npcBase*>::iterator temp);							//BGM�Ǹ�
	//����� �Ŵ������� �־�� �ϴ� �Լ�
	//1. �÷��̾�� NPC���� ��Ʈ�浹�� �Ǿ�����
	//2. ��Ʈ�浹�� WŰ�� ��ȣ�ۿ�
	//3. ��ȣ�ۿ�� � NPC�� ��ȣ�ۿ��ϴ��� üũ(2������ ��Ʈ�浹�� NPCŸ�� �޾ƿͼ� �NPC���� üũ)
	//4. �ش� NPC�� �����Լ� ȣ��
	//5. ��� üũ(���Ű������� Ȯ��)
	//6. üũ�ܰ� ������ ���Ű����ϸ� ����, 
	//

	//���� ���Լ�
	vector <npcBase*> getVNpc() { return _vNpc; }
	vector <npcBase*>::iterator getViNpc() { return _viNpc; }

	//�÷��̾� �� �޸� ��巹�� ��ũ
	inline void playerSetMMemoryAddressLink(playerManager* pm) { _pm = pm; }
};

