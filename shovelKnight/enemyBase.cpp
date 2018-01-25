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


	return S_OK;
}

HRESULT enemyBase::init(string imgKeyString, char* imgFileName, float x, float y, int totalWidth, int totalHeight, int frameX, int frameY)
{
	_imgKeyString = imgKeyString;
	_imgFileName = imgFileName;
	_x = x;
	_y = y;

	_speed = 3.0f;
	_playerDistance = 0.0f;

	_img = IMAGEMANAGER->addFrameImage(_imgKeyString, _imgFileName, _x, _y, totalWidth, totalHeight, frameX, frameY, true, RGB(255, 0, 255));

	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

	_status = ENEMY_LEFT_STOP;

	_width = _img->getFrameWidth();
	_height = _img->getFrameHeight();


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
	//�ڽ�Ŭ������ �ִ� draw() �̴���, �ƴϸ� �θ�Ŭ������ �ִ� draw() ���� �ϳ��� ��µȴ�.
	//�ʿ��ϴٸ� �ڽ�Ŭ������ draw() �Լ����� �θ�Ŭ������ draw()�� ȣ���ϵ��� ����
	draw();

}

void enemyBase::draw()
{
	_img->aniRender(getMemDC(), _rc.left, _rc.top, _anim);
}

void enemyBase::move()
{

}

bool enemyBase::isPlayerFind(float playerX, float playerY, int distance)
{
	_playerDistance = getDistance(playerX, playerY, _x, _y);

	if (_playerDistance <= distance)
	{
		return true;
	}

	return false;
}

