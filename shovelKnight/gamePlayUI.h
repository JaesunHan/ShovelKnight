#pragma once
#include "graphicUI.h"

class gamePlayUI : public graphicUI
{
private:
	int _playerIdx;

	int _gold;
	int _mana;
	int _life;
	int _boss;


public:

	HRESULT init();
	void update();
	void release(HDC hdc);
	//	void render();
	void draw(HDC hdc);

	//================== Start ������ UI �� ����� ������ ���� �� ���͸� ȣ���Ѵ� ================
	void setPlayerIdx(int* idx) { _playerIdx = *idx; }
	//void setGold(int gold) { _gold = gold; }
	//void setItem(int item) { _item = item; }
	//void setLife(int life) { _life = life; }
	//void setBoss(int boss) { _boss = boss; }
	//================== End ������ UI �� ����� ������ ���� �� ���͸� ȣ���Ѵ� ==================

	gamePlayUI();
	~gamePlayUI();
};

