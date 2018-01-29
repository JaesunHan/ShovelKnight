#pragma once
#include "gameNode.h"
#include "gameTitleScene.h"
#include "gameMenuScene.h"
#include "gamePlayScene.h"

class playGround : public gameNode
{
private:
	gameTitleScene * _GTS;
	string _gtsStr;
	gameMenuScene * _GMS;
	string _gmsStr;
	gamePlayScene * _GPS;
	string _gpsStr;
	

public:
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�
	void addSound();				//���� �߰�


	playGround();
	~playGround();
};

