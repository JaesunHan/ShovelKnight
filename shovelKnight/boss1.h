#pragma once
#include "enemyBase.h"

#define DRAGONSPEED 1
#define DRAGONHEADRECTX	 37.5
#define DRAGONHEADRECTY	 32
#define DRAGONTRUNKRECTX 25
#define DRAGONTRUNKRECTY 14.5
#define DELAYTIME	30  //피격후 쿨타임
#define HITCOUNT	10	//피격상태 유지 카운트
#define DEADCOUNT	30	//데드상태 유지 카운트

class boss1 : public enemyBase
{
private:
	int _movePatternCount;


	float _headX, _headY;
	float _trunkX, _trunkY;

public:
	boss1();
	~boss1();

	HRESULT init(float x, float y);
	HRESULT init(float x, float y, int patternType);
	void update();
	void render();
	void move();
	void draw();

	inline void enemyInitSet();
	inline void enemyPattern(int _patternTypeNum);
};

