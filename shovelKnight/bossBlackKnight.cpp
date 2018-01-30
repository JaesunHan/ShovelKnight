#include "stdafx.h"
#include "bossBlackKnight.h"


bossBlackKnight::bossBlackKnight()
{
}
bossBlackKnight::~bossBlackKnight()
{
}

void bossBlackKnight::enemyInitSet()
{
	_enemyType = ENEMY_BLACKKNIGHT;

	_speed = BLACKKNIGHTSPEED;

	_img = IMAGEMANAGER->addFrameImage("darkKnight", ".//image//monster//darkKnight.bmp", _x, _y, 532, 602, 7, 14, true, RGB(255, 0, 255));

	_status = ENEMY_LEFT_IDLE;

	//========================================================================================= ���ϸ��̼�

	int rightIdle[] = { 89, 90 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightRightIdle", "darkKnight", rightIdle, 2, 3, true);

	int leftIdle[] = { 96, 97 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightLeftIdle", "darkKnight", leftIdle, 2, 3, true);

	int rightSmile[] = { 18, 19 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightRightSmile", "darkKnight", rightSmile, 2, 3, false);

	int leftSmile[] = { 25, 26 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightLeftSmile", "darkKnight", leftSmile, 2, 3, false);

	int rightMove[] = { 0, 1, 2, 3, 4, 5 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightRightMove", "darkKnight", rightMove, 6, 7, true);

	int leftMove[] = { 7, 8, 9, 10, 11, 12 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightLeftMove", "darkKnight", leftMove, 6, 7, true);

	int rightAttack[] = { 14, 15, 16, 17 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightRightAttack", "darkKnight", rightAttack, 4, 5, false);

	int leftAttack[] = { 21, 22, 23, 24 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightLeftAttack", "darkKnight", leftAttack, 4, 5, false);

	int rightJumpAttack[] = { 28, 29, 30, 31, 32 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightRightJumpAttack", "darkKnight", rightJumpAttack, 5, 6, false);

	int leftJumpAttack[] = { 35, 36, 37, 38, 39 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightLeftJumpAttack", "darkKnight", leftJumpAttack, 5, 6, false);

	int rightBackMove[] = { 46 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightRightBackMove", "darkKnight", rightBackMove, 1, 10, false);

	int leftBackMove[] = { 53 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightLeftBackMove", "darkKnight", leftBackMove, 1, 10, false);

	int rightAttackFire[] = { 42, 43, 44, 45  };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightRightAttackFire", "darkKnight", rightAttackFire, 4, 5, false);

	int leftAttackFire[] = { 49, 50, 51, 52 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightLeftAttackFire", "darkKnight", leftAttackFire, 4, 5, false);

	int rightHit[] = { 70, 71, 72, 73, 74, 75, 76 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightRightHit", "darkKnight", rightHit, 7, 5, false);

	int leftHit[] = { 77, 78, 79, 80, 81, 82, 83 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightLeftHit", "darkKnight", leftHit, 7, 5, false);

	int rightDead[] = { 84, 85, 86, 87, 88 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightRightDead", "darkKnight", rightDead, 5, 6, false);

	int leftDead[] = { 91, 92, 93, 94, 95 };
	KEYANIMANAGER->addArrayFrameAnimation("darkKnightLeftDead", "darkKnight", leftDead, 5, 6, false);

	//=========================================================================================

	_width = 18;
	_height = 35;
	_isDead = false;
	_isDeadVanish = false;
	_vanishTime = 1;
	_direction = false;
	_gravity = 0.0f;
	_directionCount = 1;
	_enemyHp = 12;
	_isHit = false;
	_isCountStop = false;
	_playerFind = false;
	_isAttack = false;
	_frameCount = 1;
	_isDialogueEnd = false;
	_isAniPlayEnd = false;
	_patternTrun = 0;
	_jumpCount = 4;
	_patternCount = 0;
	_isFight = false;
	_previousStatus = _status;

	_rc = RectMakeCenter(_x, _y, _width, _height);
	_anim = KEYANIMANAGER->findAnimation("darkKnightLeftIdle");

	_pixelC = new pixelCollision;
	_pixelC->init(_rc, _x, _y);

	_jump = new jump;
	_jump->init();
}


HRESULT bossBlackKnight::init(float x, float y)
{
	_x = x;
	_y = y;
	_patternTypeNum = ENEMY_BASIC;
	enemyInitSet();

	return S_OK;
}


HRESULT bossBlackKnight::init(float x, float y, int patternType)
{
	_x = x;
	_y = y;
	_patternTypeNum = patternType;

	enemyInitSet();

	return S_OK;
}


void bossBlackKnight::update()					 
{

	//���°��� ���� ���ϸ��̼� �� ������
	move();


	//PATTERN TEST
	if (KEYMANAGER->isOnceKeyDown('O'))	_isDialogueEnd = true;

	//���̾�αװ� ������
	if (_isDialogueEnd && !_isFight)
	{
		_status = ENEMY_LEFT_SMILE;
		_isFight = true;
	}


	//���� ������ ����
	if (_isDialogueEnd && _isFight)	enemyPattern(_patternTypeNum);



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
			_status = ENEMY_LEFT_MOVE;
		}
		else            //�����°� �����̸�
		{
			_status = ENEMY_RIGHT_MOVE;
		}

		_pixelC->setDirectionChange(false);  //�ʱ�ȭ
	}
	//=============================================================


	//������ ����
	if (_isHit && !_isHitDelayTime)
	{
		_enemyHp--;
		_isHitDelayTime = true;

		if (_direction)
		{
			_status = ENEMY_RIGHT_HIT;
		}
		else
		{
			_status = ENEMY_LEFT_HIT;
		}
	}

	if (_isHitDelayTime)
	{
		_delayCount++;

		if (_delayCount % DELAYTIME == 0)
		{
			_isHitDelayTime = false;
			_isHit = false;
		}
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

void bossBlackKnight::draw()
{
	
	CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim, _rc.left - 29, _rc.top - 6);
	
    TTTextOut(CAMERAMANAGER->getX(_rc.left), CAMERAMANAGER->getY(_y - 30), "����", _patternTrun);
	TTTextOut(CAMERAMANAGER->getX(_rc.left), CAMERAMANAGER->getY(_y - 20), "����ī��Ʈ", _patternCount);
	TTTextOut(CAMERAMANAGER->getX(_rc.left), CAMERAMANAGER->getY(_y - 10), "����ī��Ʈ", _jumpCount);

}

void bossBlackKnight::move()
{
	//���°��� ���� ���ϸ��̼� �� ������
	switch (_status)
	{
		case ENEMY_LEFT_IDLE:
			_direction = false;

			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightLeftIdle");
			if (!_anim->isPlay()) _anim->start();

			if (_frameCount % 30 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_RIGHT_IDLE:
			_direction = true;

			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightRightIdle");
			if (!_anim->isPlay()) _anim->start();

			if (_frameCount % 30 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_LEFT_SMILE:
			_direction = false;

			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightLeftSmile");
			if (!_anim->isPlay()) _anim->start();

			if (_frameCount % 90 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_RIGHT_SMILE:
			_direction = true;

			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightRightSmile");
			if (!_anim->isPlay()) _anim->start();

			if (_frameCount % 90 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_LEFT_MOVE:
			_direction = false;

			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightLeftMove");
			if (!_anim->isPlay()) _anim->start();


			if (_rc.left > 5)
			{
				_speed = BLACKKNIGHTSPEED;
				_x -= _speed;
			}

			if (_frameCount % 10 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_RIGHT_MOVE:
			_direction = true;

			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightRightMove");
			if (!_anim->isPlay()) _anim->start();

			if (_rc.right < WINSIZEX - 5)
			{
				_speed = BLACKKNIGHTSPEED;
				_x += _speed;
			}

			if (_frameCount % 10 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_LEFT_BACK_MOVE:
			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightLeftBackMove");
			if (!_anim->isPlay())
			{
				_anim->start();
				_jump->jumping(&_x, &_y, 3.0f, 0.7f);
			}

			//������: �ڷ� ����
			if (_jump->getIsJumping())
			{
				if (_rc.left > 10)
				{
					_speed = BLACKKNIGHTSPEED * 3;
					_speed -= 0.4;
					_x += _speed;
				}
				_jump->update();
			}

			if (_frameCount % 10 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_RIGHT_BACK_MOVE:
			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightRightBackMove");
			if (!_anim->isPlay())
			{
				_anim->start();
				_jump->jumping(&_x, &_y, 3.0f, 0.7f);
			}

			//������: �ڷ� ����
			if (_jump->getIsJumping())
			{
				if (_rc.right < WINSIZEX - 10)
				{
					_speed = BLACKKNIGHTSPEED * 3;
					_speed -= 0.4;
					_x -= _speed;
				}
				_jump->update();
			}

			if (_frameCount % 10 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_LEFT_ATTACK:
			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightLeftAttack");
			if (!_anim->isPlay()) _anim->start();

			if (_frameCount % 30 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_RIGHT_ATTACK:
			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightRightAttack");
			if (!_anim->isPlay()) _anim->start();

			if (_frameCount % 30 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_LEFT_JUMP_ATTACK:
			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightLeftJumpAttack");
			if (!_anim->isPlay())
			{
				_anim->start();
				_jump->jumping(&_x, &_y, 12.0f, 0.7f);
			}

			//������: �ڷ� ����
			if (_jump->getIsJumping())
			{
				_jump->update();
			}

			//������: ����
			if (_frameCount % 5 == 0)
			{
				if (_rc.left > 10)
				{
					_speed = BLACKKNIGHTSPEED;
					_speed -= 0.4;
					_x -= _speed;
				}
			}


			if (_frameCount % 50 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
				_jumpCount--;
				_status = ENEMY_LEFT_IDLE;
			}

			cout << _frameCount << endl;
		break;
		case ENEMY_RIGHT_JUMP_ATTACK:
			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightRightJumpAttack");
			if (!_anim->isPlay())
			{
				_anim->start();
				_jump->jumping(&_x, &_y, 12.0f, 0.7f);
			}

			//������: ����
			if (_jump->getIsJumping())
			{
				_jump->update();
			}

			//������: ����
			if (_frameCount % 5 == 0)
			{
				if (_rc.right < WINSIZEX - 10)
				{
					_speed = BLACKKNIGHTSPEED;
					_speed -= 0.4;
					_x += _speed;
				}
			}

			if (_anim->getNowPlayIndex() == 0 && _jump->getJumpPower() <= 2)
			{
				_anim->pause();
			}
			switch (_anim->getNowPlayIndex())
			{
				case 0:  //���� 

				break;
				case 1:

				break;
				case 2:

				break;
				case 3:

				break;
				case 4:

				break;
			}

			cout << _jump->getJumpPower() << endl;

			if (_frameCount % 50 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
				_jumpCount--;
				_status = ENEMY_RIGHT_IDLE;
			}
		break;
		case ENEMY_LEFT_FIRE_ATTACK:
			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightLeftAttackFire");
			if (!_anim->isPlay()) _anim->start();

			if (_frameCount % 30 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_RIGHT_FIRE_ATTACK:
			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightRightAttackFire");
			if (!_anim->isPlay()) _anim->start();

			if (_frameCount % 30 == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_RIGHT_HIT:
			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightRightHit");
			if (!_anim->isPlay())
			{
				_anim->start();
				_jump->jumping(&_x, &_y, 2.0f, 0.7f);
			}
	
			//������: �ڷ� �����ϸ鼭 �ױ�
			if (_jump->getIsJumping())
			{
				_speed = BLACKKNIGHTSPEED * 3;
				_speed -= 0.4;
				_x -= _speed;
				_jump->update();
			}

			
			if (_frameCount % HITCOUNT == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_LEFT_HIT:
			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightLeftHit");
			if (!_anim->isPlay())
			{
				_anim->start();
				_jump->jumping(&_x, &_y, 2.0f, 0.7f);
			}

			//������: �ڷ� �����ϸ鼭 �ױ�
			if (_jump->getIsJumping())
			{
				_speed = BLACKKNIGHTSPEED * 3;
				_speed -= 0.4;
				_x += _speed;
				_jump->update();
			}


			if (_frameCount % HITCOUNT == 0)
			{
				_isAniPlayEnd = true;
				_frameCount = 1;
			}
		break;
		case ENEMY_LEFT_DEAD:
			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightLeftDead");

			//���ϸ��̼�
			if (!_anim->isPlay() && !_isDead)
			{
				_anim->start();
				_isDead = true;
				_jump->jumping(&_x, &_y, 4.0f, 0.7f);
			}

			//������: �ڷ� �����ϸ鼭 �ױ�
			if (_isDead && _jump->getIsJumping() == true)
			{
				_speed = BLACKKNIGHTSPEED * 3;
				_x += _speed;
				_jump->update();
			}
			//���Ϳ��� ���� �Ұ� ����
			if (_isDead && _jump->getIsJumping() == false)
			{
				_vanishTime++;
				if (_vanishTime % DEADCOUNT == 0)
				{
					_isDeadVanish = true;
					_vanishTime = 1;
					_isAniPlayEnd = true;
					_frameCount = 1;
				}
			}
			

		break;
		case ENEMY_RIGHT_DEAD:
			_frameCount++;
			_anim = KEYANIMANAGER->findAnimation("darkKnightRightDead");

			//���ϸ��̼�
			if (!_anim->isPlay() && !_isDead)
			{
				_anim->start();
				_isDead = true;
				_jump->jumping(&_x, &_y, 4.0f, 0.7f);
			}

			//������: �ڷ� �����ϸ鼭 �ױ�
			if (_isDead && _jump->getIsJumping() == true)
			{
				_speed = BLACKKNIGHTSPEED * 3;
				_x -= _speed;
				_jump->update();
			}

			//���Ϳ��� ���� �Ұ� ����
			if (_isDead && _jump->getIsJumping() == false)
			{
				_vanishTime++;
				if (_vanishTime % DEADCOUNT == 0)
				{
					_isDeadVanish = true;
					_isAniPlayEnd = true;
					_vanishTime = 1;
					_frameCount = 1;
				}
			}

		break;
	}

	//�������� �ʱ�ȭ
	if (!_jump->getIsJumping()) _isJump = false;

	//��Ʈ��ġ update
	_rc = RectMakeCenter(_x, _y, _width, _height);
}

void bossBlackKnight::enemyPattern(int _patternTypeNum)
{
	switch (_patternTypeNum)
	{
		case ENEMY_BASIC:
			if (_isAniPlayEnd)  //������ ������
			{
				if(isPlayerFind(_x, 100)); //�÷��̾���� �Ÿ� �� ���� Ž��
			
				switch (_patternTrun)  //���� ���� ������
				{
					case 0:
						if (_direction)
						{
							_status = ENEMY_RIGHT_MOVE;
						}
						else
						{
							_status = ENEMY_LEFT_MOVE;
						}

						if (isPlayerFind(_x, 70))
						{
							_patternTrun = 1;
							_patternCount++;
						}

					break;
					case 1:
						if (isPlayerFind(_x, 60))
						{
							if (_direction)
							{
								_status = ENEMY_RIGHT_ATTACK;
							}
							else
							{
								_status = ENEMY_LEFT_ATTACK;
							}
						}
						else
						{
							if (_direction)
							{
								_status = ENEMY_RIGHT_MOVE;
							}
							else
							{
								_status = ENEMY_LEFT_MOVE;
							}
						}

						if (isPlayerFind(_x, 150))
						{
							if (_playerStatus == 2)
							{
								_patternTrun = 2;
								_patternCount++;
							}
						}
	
					break;
					case 2:

						if (_direction)
						{
							_status = ENEMY_RIGHT_BACK_MOVE;
						}
						else
						{
							_status = ENEMY_LEFT_BACK_MOVE;
						}


						if (_patternCount > 7)
						{
							_patternTrun = 6;
							_patternCount++;
						}
						else
						{
							_patternTrun = 3;
							_patternCount++;
						}

					break;
					case 3:

						if (_direction)
						{
							_status = ENEMY_RIGHT_SMILE;
						}
						else
						{
							_status = ENEMY_LEFT_SMILE;
						}


						_patternTrun = 4;
						_patternCount++;
					
					break;
					case 4:

						if (_jumpCount <= 0)
						{
							_patternTrun = 6;
							_patternCount++;

							_jumpCount = 4;
						}
						else
						{
							if (_direction)
							{
								if (_status == ENEMY_RIGHT_IDLE)
								{
									if (isPlayerFind(_x, 200))
									{
										_status = ENEMY_RIGHT_MOVE;
									}
								}
								else
								{
									_status = ENEMY_RIGHT_JUMP_ATTACK;
								}
							}
							else
							{
								if (_status == ENEMY_RIGHT_IDLE)
								{
									if (isPlayerFind(_x, 200))
									{
										_status = ENEMY_LEFT_MOVE;
									}
								}
								else
								{
									_status = ENEMY_LEFT_JUMP_ATTACK;
								}
								
							}
						}

					break;
					case 5:
	

					break;
					case 6:
						if (_direction)
						{
							_status = ENEMY_RIGHT_FIRE_ATTACK;
						}
						else
						{
							_status = ENEMY_LEFT_FIRE_ATTACK;
						}

						_patternTrun = 0;
						_patternCount = 0;
					break;
				}

				_isAniPlayEnd = false;
				
			}
		break;
		case ENEMY_PATROL:

		break;
		case ENEMY_LEFT_FOWARD:

		break;
		case ENEMY_RIGHT_FOWARD:

		break;
	}
}