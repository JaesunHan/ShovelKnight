#include "stdafx.h"
#include "jump.h"


jump::jump()
{
}
jump::~jump()
{
}



HRESULT jump::init()
{
	_isJumping = _jumpPower = _gravity = 0;

	return S_OK;
}

void jump::release()
{

}

void jump::update()
{
	//��ȣ�� ������ �ʾ����� ������� �ʰ� �Ѵ�
	if (!_isJumping) return;

	*_y -= _jumpPower;
	_jumpPower -= _gravity;

	//�ϴ��� ó�� �� ��ġ���� ��������~
	if (_startY < *_y)
	{
		_isJumping = false;
		*_y = _startY;
	}
}

void jump::render()
{

}

//�ܺο��� ��ȣ�� �� �Լ�
void jump::jumping(float* x, float* y, float power, float gravity)
{
	//�����ϰ� ������ �ǵ帮�� �� ��
	if (_isJumping) return;

	_isJumping = true;

	_x = x;
	_y = y;

	_startX = *x;
	_startY = *y;

	_gravity = gravity;
	_jumpPower = power;
}
