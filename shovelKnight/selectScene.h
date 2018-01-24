#pragma once
#define IMAGEWIDTH 550

#include "gameNode.h"
#include "button.h"

struct character
{
	image* image;
	int  x;
	int  y;
	bool isSelect;
};


class selectScene : public gameNode
{
private:
	character characterSelect[3];
	int _selectX, _selectY;
	bool _selectMoveLeft;
	bool _selectMoveRight;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	//�������� �Ǿ��־ static���� �����(�ݹ��Լ��� ���� �Լ�)
	static void cbSceneChange();


	selectScene();
	~selectScene();
};

