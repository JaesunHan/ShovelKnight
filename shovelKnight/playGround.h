#pragma once
#include "gameNode.h"
#include "gameTitleScene.h"

class playGround : public gameNode
{
private:
	gameTitleScene * _GTS;
	string _gtsStr;

	

public:
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�



	playGround();
	~playGround();
};

