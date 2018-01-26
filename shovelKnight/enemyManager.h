#pragma once
#include "gameNode.h"
#include "minion1.h"

#include <vector>


class enemyManager 
{
private:
	typedef vector<minion1*>			vMinion1;
	typedef vector<minion1*>::iterator	viMinion1;

private:
	vMinion1	_vBeeto;
	viMinion1   _viBeeto;

public:
	enemyManager();
	~enemyManager();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	//========================================= Start �̴Ͼ� ���� ========================================
	//--------------------------------- beeto
	void setMinionBeeto(void);
	void removeMinionBeeto(int arrNum);

	//========================================== End �̴Ͼ� ���� =========================================


	//==================================== Start ������ ������ �ۼ��ϱ�===================================
	//------------------------------------------------------------------------ beeto
	vector<minion1*> getVBeeto() { return _vBeeto; }
	vector<minion1*>::iterator getVIBeeto() { return _viBeeto; }

	//===================================== End ������ ������ �ۼ��ϱ�====================================

};

