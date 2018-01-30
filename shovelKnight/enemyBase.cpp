#include "stdafx.h"
#include "enemyBase.h"


enemyBase::enemyBase()
{
}


enemyBase::~enemyBase()
{

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

		Rectangle(getMemDC(), CAMERAMANAGER->getX(_attackRc.left), CAMERAMANAGER->getY(_attackRc.top),
			CAMERAMANAGER->getX(_attackRc.right), CAMERAMANAGER->getY(_attackRc.bottom));
	}

	//�ڽ�Ŭ������ �ִ� draw() �̴���, �ƴϸ� �θ�Ŭ������ �ִ� draw() ���� �ϳ��� ��µȴ�.
	//�ʿ��ϴٸ� �ڽ�Ŭ������ draw() �Լ����� �θ�Ŭ������ draw()�� ȣ���ϵ��� ����
	draw();

	//TTTextOut(CAMERAMANAGER->getX(_rc.left), CAMERAMANAGER->getY(_y - 10), "��Ʈ", _isHit);
	//TTTextOut(CAMERAMANAGER->getX(_rc.left), CAMERAMANAGER->getY(_y - 20), "����", _status);
	//TTTextOut(CAMERAMANAGER->getX(_rc.left), CAMERAMANAGER->getY(_rc.bottom + 5), "��ǥ", _rc.bottom);
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
	//�Ÿ����
	float playerDistance = enemyX - _getPlayerX;

	//���ʹ� ���⼳��
	if (playerDistance >= 0) _direction = false;
	else _direction = true;

	playerDistance = fabs(playerDistance);  //���밪

	if (playerDistance <= distance)
	{
		return true;
	}

	return false;
}

void enemyBase::attackCollisionRect()
{

}