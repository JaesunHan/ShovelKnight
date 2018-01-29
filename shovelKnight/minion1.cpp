#include "stdafx.h"
#include "minion1.h"


minion1::minion1()
{
}


minion1::~minion1()
{
}


HRESULT minion1::init(float x, float y)
{
	_enemyType = ENEMY_BEETO;

	_x = x;
	_y = y;
	_speed = 0.0f;

	_img = IMAGEMANAGER->addFrameImage("beeto", ".//image//monster//Beeto.bmp", _x, _y, 104, 64, 4, 4, true, RGB(255, 0, 255));

	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

	_status = ENEMY_LEFT_MOVE;

	//========================================================================================= ���ϸ��̼�

	int rightStop[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("beetoRightStop", "beeto", rightStop, 1, 10, false);

	int leftStop[] = { 4 };
	KEYANIMANAGER->addArrayFrameAnimation("beetoLeftStop", "beeto", leftStop, 1, 10, false);

	int rightMove[] = { 0, 1, 2, 3 };
	KEYANIMANAGER->addArrayFrameAnimation("beetoRightMove", "beeto", rightMove, 4, 4, true);
	
	int leftMove[] = { 4, 5, 6, 7 };
	KEYANIMANAGER->addArrayFrameAnimation("beetoLeftMove", "beeto", leftMove, 4, 4, true);

	int rightDead[] = { 8, 9 };
	KEYANIMANAGER->addArrayFrameAnimation("beetoRightDead", "beeto", rightDead, 2, 3, false);

	int leftDead[] = { 12, 13 };
	KEYANIMANAGER->addArrayFrameAnimation("beetoLeftDead", "beeto", leftDead, 2, 3, false);

	//=========================================================================================

	_width = _img->getFrameWidth();
	_height = _img->getFrameHeight();
	_isDead = false;
	_isDeadVanish = false;
	_vanishTime = 1;
	_direction = false;
	_gravity = 0.0f;
	_isJump = false;
	_jumpCount = 1;
	_enemyHp = 1;
	_isHit = false;
	_previousStatus = _status;

	_anim = KEYANIMANAGER->findAnimation("beetoLeftMove");

	_jump = new jump;
	_jump->init();

	_pixelC = new pixelCollision;
	_pixelC->init(_rc, _x, _y);

	return S_OK;
}

void minion1::update()
{
	//============================================================ �ǰ� �׽�Ʈ
	//if (KEYMANAGER->isOnceKeyDown('P'))
	//{
	//	_isHit = true;
	//}
	//============================================================


	if (_status != ENEMY_LEFT_HIT && _status != ENEMY_RIGHT_HIT)
	{
		_previousStatus = _status; //���� ���ʹ� ���� ����
	}

	//���°��� ���� ���ϸ��̼� �� ������
	move();


	//============================================================= �ȼ��浹: �ٴ��浹	
	_pixelC->pixelCollisonY(_rc);  //�ٴڻ��� ����

	if (_pixelC->getIsGround())     //���°��� ���� ���׹� ��������
	{
		_gravity = 0.0f;
		_y = _pixelC->getProbeY();
	}
	else
	{
		if (!_isJump && !_isDead) _gravity += 0.1f;
		else _gravity = 0.0f;
	}
	//�߷�����
	_y += _gravity;
	//============================================================= �ȼ��浹: ��
	_pixelC->pixelCollisonX(_rc, _direction);  //�� ����


	if (_pixelC->getDirectionChange())  //���� �ε�ġ��
	{
		if (_direction)  //�����°� �������̸�
		{
			_status = ENEMY_RIGHT_MOVE;
		}
		else            //�����°� �����̸�
		{
			_status = ENEMY_LEFT_MOVE;
		}

		_pixelC->setDirectionChange(false);  //�ʱ�ȭ
	}
	//=============================================================


	//������ ����
	if (_isHit)
	{
		if (_direction)  //�����°� �������̸�
		{
			_status = ENEMY_RIGHT_HIT;
		}
		else            //�����°� �����̸�
		{
			_status = ENEMY_LEFT_HIT;
		}

		_enemyHp--;
		_isHit = false;
	}



	//hp=0�ϰ�� ���� ����
	if (_enemyHp <= 0)
	{
		if (_playerStatus == 3) //�÷��̾ ���������� ���
		{
			if (_direction)
			{
				_status = ENEMY_RIGHT_JUMP_DEAD;
			}
			else
			{
				_status = ENEMY_LEFT_JUMP_DEAD;
			}
		}
		else //�÷��̾ �ٴڿ��� ������ ���
		{
			if (_direction)
			{
				_status = ENEMY_RIGHT_DEAD;
			}
			else
			{
				_status = ENEMY_LEFT_DEAD;
			}
		}

	}

}


void minion1::move()
{
	//���°��� ���� ���ϸ��̼� �� ������
	switch (_status)
	{
		case ENEMY_LEFT_MOVE:
			_direction = false;

			_anim = KEYANIMANAGER->findAnimation("beetoLeftMove");
			if (!_anim->isPlay()) _anim->start();

			_speed = BEETOSPEED;
			_x -= _speed;
		break;
		case ENEMY_RIGHT_MOVE:
			_direction = true;

			_anim = KEYANIMANAGER->findAnimation("beetoRightMove");
			if (!_anim->isPlay()) _anim->start();

			_speed = BEETOSPEED;
			_x += _speed;
		break;
		case ENEMY_LEFT_DEAD:
			_anim = KEYANIMANAGER->findAnimation("beetoLeftDead");

			//���ϸ��̼�
			if (!_anim->isPlay() && !_isDead)
			{
				_anim->start();
				_isDead = true;
				_jump->jumping(&_x, &_y, 8.0f, 0.9f);
			}

			//������: �ڷ� �����ϸ鼭 �ױ�
			if (_isDead && _jump->getIsJumping() == true)
			{
				_speed = BEETOSPEED;
				_x += _speed;
				_jump->update();
			}
			//���Ϳ��� ���� �Ұ� ����
			if (_isDead && _jump->getIsJumping() == false)
			{
				_vanishTime++;
				if (_vanishTime % 20 == 0)
				{
					_isDeadVanish = true;
					_vanishTime = 1;
				}
			}
		break;
		case ENEMY_RIGHT_DEAD:
			_anim = KEYANIMANAGER->findAnimation("beetoRighttDead");

			//���ϸ��̼�
			if (!_anim->isPlay() && !_isDead)
			{
				_anim->start();
				_isDead = true;
				_jump->jumping(&_x, &_y, 15.0f, 0.4f);
			}

			//������: �ڷ� �����ϸ鼭 �ױ�
			if (_isDead && _jump->getIsJumping() == true)
			{
				_speed = BEETOSPEED;
				_x -= _speed;
				_jump->update();
			}

			//���Ϳ��� ���� �Ұ� ����
			if (_isDead && _jump->getIsJumping() == false)
			{
				_vanishTime++;
				if (_vanishTime % 20 == 0)
				{
					_isDeadVanish = true;
					_vanishTime = 1;
				}
			}
		break;
		case ENEMY_LEFT_JUMP_DEAD: ENEMY_RIGHT_JUMP_DEAD:
			if (_direction)
			{
				_anim = KEYANIMANAGER->findAnimation("beetoRightDead");
			}
			else
			{
				_anim = KEYANIMANAGER->findAnimation("beetoLeftDead");
			}
			

			//���ϸ��̼�
			if (!_anim->isPlay() && !_isDead)
			{
				_anim->start();
				_isDead = true;
			}

			//���Ϳ��� ���� �Ұ� ����
			if (_isDead)
			{
				_vanishTime++;
				if (_vanishTime % 20 == 0)
				{
					_isDeadVanish = true;
					_vanishTime = 1;
				}
			}
		break;
	}


	//�������� �ʱ�ȭ
	if (!_jump->getIsJumping()) _isJump = false;

	//��Ʈ��ġ update
	_rc = RectMakeCenter(_x, _y, _width, _height);
}


