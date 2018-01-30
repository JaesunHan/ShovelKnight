#pragma once
#include "enemyBase.h"

#define BLACKKNIGHTSPEED 2
#define DELAYTIME 50  //�ǰ��� ��Ÿ��
#define HITCOUNT  30  //�ǰݻ��� ���� ī��Ʈ
#define DEADCOUNT 50  //������� ���� ī��Ʈ

class bossBlackKnight : public enemyBase
{
private:


public:
	bossBlackKnight();
	~bossBlackKnight();

	virtual HRESULT init(float x, float y);
	virtual HRESULT init(float x, float y, int patternType);
	virtual void update();
	virtual void move();
	virtual void draw();

	inline void enemyInitSet();
	inline void enemyPattern(int _patternTypeNum);
};
