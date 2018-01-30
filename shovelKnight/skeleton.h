#pragma once
#include "enemyBase.h"

#define SKELETONSPEED 2.0f
#define DELAYTIME 60  //�ǰ��� ��Ÿ��
#define HITCOUNT  10  //�ǰݻ��� ���� ī��Ʈ
#define DEADCOUNT 20  //������� ���� ī��Ʈ

class skeleton : public enemyBase
{
private:


public:
	skeleton();
	~skeleton();

	HRESULT init(float x, float y);
	HRESULT init(float x, float y, int patternType);
	void update();
	void move();
	void draw();

	inline void enemyInitSet();
	inline void enemyPattern(int _patternTypeNum);
	virtual void attackCollisionRect();
};

