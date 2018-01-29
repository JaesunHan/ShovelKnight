#pragma once
#include "enemyBase.h"

#define DRAGONSPEED 1
#define DRAGONHEADRECTX	 37.5
#define DRAGONHEADRECTY	 32
#define DRAGONTRUNKRECTX 25
#define DRAGONTRUNKRECTY 14.5


class boss1 : public enemyBase
{
private:
	int _movePatternCount;
	RECT _headRc;
	RECT _trunkRc;

	float _headX, _headY;
	float _trunkX, _trunkY;

public:
	boss1();
	~boss1();

	HRESULT init(float x, float y);
	void update();
	void render();
	void move();

	//�浹��Ʈ ����
	RECT getBoss1HeadRect() { return _headRc; }   //�Ӹ���Ʈ
	RECT getBoss1TrunkRect() { return _trunkRc; }  //���뷺Ʈ

};

