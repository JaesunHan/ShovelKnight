#include "stdafx.h"
#include "boss1.h"


boss1::boss1()
{
}


boss1::~boss1()
{
}

HRESULT boss1::init(float x, float y)
{
	_enemyType = ENEMY_DRAGON;

	_x = x;
	_y = y;
	_speed = 0.0f;

	_img = IMAGEMANAGER->addFrameImage("dragon", ".//image//monster//bubbleDragon.bmp", _x, _y, 1074, 356, 6, 4, true, RGB(255, 0, 255));

	//�̹��� ��Ʈ
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	//�浹�� ��Ʈ
	_headRc = RectMakeCenter(_x - DRAGONHEADRECTX, _y + DRAGONHEADRECTY, 40, 25);
	_trunkRc = RectMakeCenter(_x + DRAGONTRUNKRECTX, _y + DRAGONTRUNKRECTY, 85, 60);

	_status = ENEMY_LEFT_IDLE;

	//========================================================================================= ���ϸ��̼�

	int leftStop[] = { 0, 1, 2, 3, 4, 5 };
	KEYANIMANAGER->addArrayFrameAnimation("dragonLeftStop", "dragon", leftStop, 6, 6, true);

	int leftForwardMove[] = { 6, 7, 8, 9, 10, 11 };
	KEYANIMANAGER->addArrayFrameAnimation("dragonLeftForwardMove", "dragon", leftForwardMove, 6, 6, false);

	int leftBackMove[] = { 12, 13, 14, 15, 16, 17 };
	KEYANIMANAGER->addArrayFrameAnimation("dragonLeftBackMove", "dragon", leftBackMove, 6, 6, false);

	int leftHit[] = { 18, 19, 20 };
	KEYANIMANAGER->addArrayFrameAnimation("dragonLeftHit", "dragon", leftHit, 3, 4, false);

	int leftAttack[] = { 21, 22, 23 };
	KEYANIMANAGER->addArrayFrameAnimation("dragonLeftAttack", "dragon", leftAttack, 3, 4, false);

	//=========================================================================================

	_width = _img->getFrameWidth();
	_height = _img->getFrameHeight();
	_isDead = false;
	_isDeadVanish = false;
	_vanishTime = 1;
	_directionCount = 1;
	_direction = false;
	_movePatternCount = 1;
	_playerFind = false;
	_enemyHp = 7;
	_isHit = false;
	_previousStatus = _status;

	_anim = KEYANIMANAGER->findAnimation("dragonLeftStop");


	return S_OK;
}

void boss1::update()
{

	ENEMYSTATUS previousStatus = _status; //���� ���ʹ� ���� ����


	//���°��� ���� ���ϸ��̼� �� ������
	move();

	//�÷��̾ �����Ÿ� ������ ������
	if (isPlayerFind(_x, 200)) _playerFind = true;
	_direction = false;  //����ó��: ���� ������ ��������

	//���� ������ ����
	if (_playerFind) //�÷��̾ �߰��ϸ�
	{
		_directionCount++;

		switch (_directionCount)
		{
			case 100:
				_status = ENEMY_LEFT_MOVE;
			break;
			case 200:
				_status = ENEMY_LEFT_ATTACK;
			break;
			case 250:
				_status = ENEMY_LEFT_BACK_MOVE;
			break;
			case 350:
				_status = ENEMY_LEFT_ATTACK;
				_directionCount = 1;
			break;
		}

		
		//�ǰݻ����� ��� �������·� ����
		if (_status == ENEMY_LEFT_HIT || _status == ENEMY_RIGHT_HIT)
		{
			if (!_anim->isPlay())_status = previousStatus;		
		}
	}


	//������ ����
	if (_isHit)
	{
		_enemyHp--;
		_isHit = false;
	}

	//hp=0�ϰ�� ���� ����
	if (_enemyHp <= 0)
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

void boss1::render()
{

	draw();

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		//�Ӹ� ��Ʈ
		Rectangle(getMemDC(), CAMERAMANAGER->getX(_headRc.left), CAMERAMANAGER->getY(_headRc.top),
			CAMERAMANAGER->getX(_headRc.right), CAMERAMANAGER->getY(_headRc.bottom));
		//���� ��Ʈ
		Rectangle(getMemDC(), CAMERAMANAGER->getX(_trunkRc.left), CAMERAMANAGER->getY(_trunkRc.top),
			CAMERAMANAGER->getX(_trunkRc.right), CAMERAMANAGER->getY(_trunkRc.bottom));

	}
	
}


void boss1::move()
{
	//���°��� ���� ���ϸ��̼� �� ������
	switch (_status)
	{
		case ENEMY_LEFT_IDLE:
			
			_anim = KEYANIMANAGER->findAnimation("dragonLeftStop");
			if (!_anim->isPlay()) _anim->start();


		break;
		case ENEMY_LEFT_MOVE:
			_direction = false;  //������ �����̴� ����

			_anim = KEYANIMANAGER->findAnimation("dragonLeftForwardMove");
			if (!_anim->isPlay()) _anim->start();


			_speed = DRAGONSPEED;
			_x -= _speed;
		break;
		case ENEMY_LEFT_BACK_MOVE:
			_direction = true;  //�ڷ� �����̴� ����

			_anim = KEYANIMANAGER->findAnimation("dragonLeftBackMove");
			if (!_anim->isPlay()) _anim->start();


			_speed = DRAGONSPEED;
			_x += _speed;
		break;
		case ENEMY_LEFT_ATTACK:

			_anim = KEYANIMANAGER->findAnimation("dragonLeftAttack");
			if (!_anim->isPlay()) _anim->start();


		break;
		case ENEMY_LEFT_HIT:

			_anim = KEYANIMANAGER->findAnimation("dragonLeftHit");
			if (!_anim->isPlay()) _anim->start();

			if (_direction)
			{
				_x += _speed;
			}
			else
			{
				_x -= _speed;
			}


		break;
		case ENEMY_LEFT_DEAD:

			//_anim = KEYANIMANAGER->findAnimation("");

			//���ϸ��̼�
			if (!_anim->isPlay() && !_isDead)
			{
				_anim->start();
				_isDead = true;
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
	}


	//��Ʈ��ġ update
	_rc = RectMakeCenter(_x, _y, _width, _height);
	_headRc = RectMakeCenter(_x - DRAGONHEADRECTX, _y + DRAGONHEADRECTY, 40, 25);
	_trunkRc = RectMakeCenter(_x + DRAGONTRUNKRECTX, _y + DRAGONTRUNKRECTY, 85, 60);
}
