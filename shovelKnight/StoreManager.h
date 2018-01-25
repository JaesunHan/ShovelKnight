#pragma once
#include "gameNode.h"
#include "MagicGirl.h"
#include "HealtyGuy.h"
#include "BardKnight.h"
#include <vector>

//��ȣ������ ���� ��������
class playerManager;

class StoreManager
{
private:
	typedef vector<npcBase*> vNPC;
	typedef vector<npcBase*>::reverse_iterator viNPC;


private:
	vNPC _vNpc;									//npc����
	viNPC _viNpc;								//npc�������ͷ�����

	playerManager* _pm;							//�÷��̾�Ŵ��� �Ҵ�

public:
	StoreManager();
	~StoreManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

