#pragma once
#include "enemyBase.h"

#define BLORBSPEED 1
#define DELAYTIME 70  //�ǰ��� ��Ÿ��
#define HITCOUNT  10  //�ǰݻ��� ���� ī��Ʈ
#define DEADCOUNT 10  //������� ���� ī��Ʈ

class minion2 : public enemyBase
{
private:
	int _jumpTime;


public:
	minion2();
	~minion2();

	HRESULT init(float x, float y);
	HRESULT init(float x, float y, int patternType);
	void update();
	void move();
	void draw();

	inline void enemyInitSet();
	inline void enemyPattern(int _patternTypeNum);
};

