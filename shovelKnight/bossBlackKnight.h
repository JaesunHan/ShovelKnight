#pragma once
#include "enemyBase.h"

#define BLACKKNIGHTSPEED 2
#define DELAYTIME 70  //�ǰ��� ��Ÿ��
#define HITCOUNT  10  //�ǰݻ��� ���� ī��Ʈ
#define DEADCOUNT 50  //������� ���� ī��Ʈ

class bossBlackKnight : public enemyBase
{


public:
	bossBlackKnight();
	~bossBlackKnight();

	HRESULT init(float x, float y);
	HRESULT init(float x, float y, int patternType);
	void update();
	void move();
	void draw();

	inline void enemyInitSet();
	inline void enemyPattern(int _patternTypeNum);
};

