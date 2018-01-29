#pragma once
#include "graphicUI.h"
class gamePlayUI : public graphicUI
{
private:
	int _gold;
	int _item;
	int _life;
	int _boss;
public:

	HRESULT init();
	void update();
	void release();
//	void render();
	void draw(HDC hdc);

	//================== Start ������ UI �� ����� ������ ���� �� ���͸� ȣ���Ѵ� ================
	void setGold(int gold) { _gold = gold; }
	void setItem(int item) { _item = item; }
	void setLife(int life) { _life = life; }
	void setBoss(int boss) { _boss = boss; }
	//================== End ������ UI �� ����� ������ ���� �� ���͸� ȣ���Ѵ� ==================

	gamePlayUI();
	~gamePlayUI();
};

