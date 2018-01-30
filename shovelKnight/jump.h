#pragma once
#include "gameNode.h"
#include "pixelCollision.h"

class jump : public gameNode
{
private:
	float _jumpPower;
	float _gravity;

	//�۶� ��ǥ
	float* _x;
	float* _y;

	//ó�� �پ����� ��ġ
	float _startX;
	float _startY;

	bool _isJumping;
	float _jumpHeight;

	//�ȼ� �ݸ���
	pixelCollision* _pixelC;

public:
	jump();
	~jump();

	HRESULT init();
	void release();
	void update();
	void render();

	void jumping(float* x, float* y, float power, float gravity);

	bool getIsJumping(void) { return _isJumping; }
	float getJumpHeight() { return _jumpHeight; }

};