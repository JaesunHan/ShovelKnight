#pragma once
#include "enemyBase.h"

#define DRAKESPEED 2.0f
#define DELAYTIME 30  //�ǰ��� ��Ÿ��
#define HITCOUNT  10  //�ǰݻ��� ���� ī��Ʈ
#define DEADCOUNT 10  //������� ���� ī��Ʈ


class minion3 : public enemyBase
{
private:
	bool _isHitPlay;

public:
	minion3();
	~minion3();


	HRESULT init(float x, float y);
	HRESULT init(float x, float y, int patternType);
	void update();
	void move();
	void draw();

	inline void enemyInitSet();
	inline void enemyPattern(int _patternTypeNum);
};

