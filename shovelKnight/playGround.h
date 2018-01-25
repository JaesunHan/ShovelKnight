#pragma once
#include "gameNode.h"
#include "gameTitleScene.h"
#include "gameMenuScene.h"

class playGround : public gameNode
{
private:
	gameTitleScene * _GTS;
	string _gtsStr;
	gameMenuScene * _GMS;
	string _gmsStr;
	

public:
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�



	playGround();
	~playGround();
};

