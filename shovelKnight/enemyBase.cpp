#include "stdafx.h"
#include "enemyBase.h"


enemyBase::enemyBase()
{
}


enemyBase::~enemyBase()
{

}

HRESULT enemyBase::init(float x, float y)
{
	_jump = new jump;
	_jump->init();

	_pixelC = new pixelCollision;
	_pixelC->init(_rc, _x, _y);

	return S_OK;
}

HRESULT enemyBase::init(string imgKeyString, char* imgFileName, float x, float y, int totalWidth, int totalHeight, int frameX, int frameY)
{



	return S_OK;
}

void enemyBase::release()
{

}

void enemyBase::update()
{
	//�̵�
	move();

	//RECT update
	_rc = RectMakeCenter(_x, _y, _width, _height);



	KEYANIMANAGER->update();
}

void enemyBase::render()
{

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{		
		Rectangle(getMemDC(), CAMERAMANAGER->getX(_rc.left), CAMERAMANAGER->getY(_rc.top), 
			CAMERAMANAGER->getX(_rc.right), CAMERAMANAGER->getY(_rc.bottom));

		CAMERAMANAGER->renderMap(getMemDC(), IMAGEMANAGER->findImage("bgMap"));
	}

	//�ڽ�Ŭ������ �ִ� draw() �̴���, �ƴϸ� �θ�Ŭ������ �ִ� draw() ���� �ϳ��� ��µȴ�.
	//�ʿ��ϴٸ� �ڽ�Ŭ������ draw() �Լ����� �θ�Ŭ������ draw()�� ȣ���ϵ��� ����
	draw();

}

void enemyBase::draw()
{
	CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim, _rc.left, _rc.top);
}

void enemyBase::move()
{

}

//                           ���ʹ�X��ǥ   �����Ÿ�    
bool enemyBase::isPlayerFind(float enemyX, int distance)
{
	float playerDistance = fabs(enemyX - _getPlayerX);

	if (playerDistance <= distance)
	{
		return true;
	}

	return false;
}

