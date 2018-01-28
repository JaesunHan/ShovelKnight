#pragma once
#include "gameNode.h"

enum ITEM_STATS
{
	ITEM_STATS_STOP,
	ITEM_STATS_GRAVITY,
};

enum ITEM_FIRE
{
	ITEM_FIRE_CENTER,
	ITEM_FIRE_LEFT,
	ITEM_FIRE_RIGHT,
};

class itemBase
{
protected:
	FPOINT _pt;
	FPOINT _add;
	float _gravity;
	bool _isFire;
	ITEM_STATS _stats;
	char* _aniName;

	RECT _rc;
	image* _img;
	animation* _ani;
	int _imgWidth;
	int _imgHeight;


public:
	itemBase();
	~itemBase();

	virtual HRESULT init();
	virtual void release() = 0;
	virtual void update() = 0;
	virtual void render();

	virtual void reRect();
	virtual void eatItem();

	//==================================== Start ���� ���� �ۼ��ϱ�===================================
	//���� ���� ����
	inline FPOINT getCenter() { return _pt; }
	inline void setX(FPOINT pt) { _pt = pt; }

	//����ũ�� ���� ����
	inline int getWidth() { return _imgWidth; }
	inline void setWidth(int w) { _imgWidth = w; }

	//����ũ�� ���� ����
	inline int getHeight() { return _imgHeight; }
	inline void setHeight(int h) { _imgHeight = h; }

	//�����Ŀ� ���� ����
	inline FPOINT getAdd() { return _add; }
	inline void setAdd(FPOINT add) { _add = add; }

	//��Ʈ ����
	inline RECT getRect() { return _rc; }
	//==================================== End ���� ���� �ۼ��ϱ�===================================
};

