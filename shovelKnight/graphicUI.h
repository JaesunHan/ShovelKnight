#pragma once
#include "gameNode.h"
class graphicUI : gameNode
{
protected:
	image * _uiBackImg;		//UI ���� �̹���
public:
	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
	virtual void draw();

	graphicUI();
	~graphicUI();
};

