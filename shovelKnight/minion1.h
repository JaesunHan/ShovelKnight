#pragma once
#include "enemyBase.h"

#define BEETOSPEED 1
#define DELAYTIME 70   //�ǰ��� ��Ÿ��
#define HITCOUNT  10   //�ǰݻ��� ���� ī��Ʈ
#define DEADCOUNT 20   //������� ���� ī��Ʈ


class minion1 : public enemyBase
{
private:



public:
	minion1();
	~minion1();

	HRESULT init(float x, float y);
	HRESULT init(float x, float y, int patternType);
	void update();
	void move();

	inline void enemyInitSet();
	inline void enemyPattern(int _patternTypeNum);
};

