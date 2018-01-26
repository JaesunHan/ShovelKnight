#include "stdafx.h"
#include "playerBase.h"


playerBase::playerBase()
{
}


playerBase::~playerBase()
{

}

HRESULT playerBase::init(float startX, float startY)
{

	//_image = IMAGEMANAGER->findImage(imageName);
	_x = startX;
	_y = startY;
	_isDead = false;
	_isDamaged = false;
	_currentHP = _maxHP = 8;
	_currentMP = _maxMP = 30;
	_skill = NULL;
	_skillUsed = false;
	_action = PR_IDLE;
	_state = INAIR;
	_direction = PD_RIGHT;
	_moveSpeed = SPEED;
	_gravity = GRAVITY;
	_jumpPower = JUMPPOWER;
	_jumpCount = 0;
	_rc = RectMake(_x - HIT_BOX_WIDTH / 2, _y - HIT_BOX_HEIGHT, HIT_BOX_WIDTH, HIT_BOX_HEIGHT);

	return S_OK;
}
void playerBase::release()
{

}
void playerBase::update() 
{
	move();
	collisionPlayerMap();
	hitReAction();
	CAMERAMANAGER->setSingleFocus(_x, _y, 800);
}
void playerBase::render() 
{
	HDC hdc = getMemDC();
	Rectangle(hdc,
		CAMERAMANAGER->getX(_rc.left),
		CAMERAMANAGER->getY(_rc.top),
		CAMERAMANAGER->getX(_rc.right),
		CAMERAMANAGER->getY(_rc.bottom));
	TTTextOut(hdc, 300, 10, "top", _rc.top);
	TTTextOut(hdc, 300, 25, "bottom", _rc.bottom);
	TTTextOut(hdc, 300, 40, "left", _rc.left);
	TTTextOut(hdc, 300, 55, "right", _rc.right);
	TTTextOut(hdc, 300, 70, "state", _state);
	TTTextOut(hdc, 400, 10, "action", _action);
	TTTextOut(hdc, 400, 25, "�浹", collisionPlayerMap());

}
//�浹�� ���� ������ ���� 
void playerBase::hitReAction()
{
	//�÷��̾�� ���� �浹�� Ȯ���ؼ� �浹 ����, �浹����� �����Ѵ�
	switch (collisionPlayerMap())			
	{										
	case CT_NULL:							//�浹���� �ʾ�����
		_cPlayerTarget = CP_NULL;			//�÷��̾�� �浹���� �ʾҴ�
		break;								//
	case CT_TOP:							//�÷��̾��� ž�� �׶����� ���� �浹
		_cPlayerTarget = CP_GROUND;			//�浹����� �׶���
		_cLR = LR_NULL;						//�浹����(�¿�) ����
		_cTB = TB_BOTTOM;					//�浹����(����) ����� �Ʒ���
		break;								//
	case CT_BOTTOM:							//�÷��̾��� ���Ұ� �׶����� ž �浹
		_cPlayerTarget = CP_GROUND;			//�浹����� �׶���
		_cLR = LR_NULL;						//�浹����(�¿�) ����
		_cTB = TB_TOP;						//�浹����(����) ����� ����
		break;								//
	case CT_LEFT:							//�÷��̾��� ���ʰ� �׶����� ������ �浹
		_cPlayerTarget = CP_GROUND;			//�浹����� �׶���
		_cLR = LR_RIGHT;					//�浹����(�¿�) ����� ������
		_cTB = TB_NULL;						//�浹����(����) ����
		break;								//
	case CT_RIGHT:							//�÷��̾��� �����ʰ� �׶����� ���� �浹
		_cPlayerTarget = CP_GROUND;			//�浹����� �׶���
		_cLR = LR_LEFT;						//�浹����(�¿�) 
		_cTB = TB_NULL;						//�浹����(����) 
		break;								//
	case CT_LEFT_BOTTOM:					//�÷��̾��� ���ʾƷ��� �׶��� �浹
		_cPlayerTarget = CP_GROUND;			//�浹����� �׶���
		_cLR = LR_RIGHT;					//�浹����(�¿�) ����� ������
		_cTB = TB_TOP;						//�浹����(����) 
		break;								//
	case CT_RIGHT_BOTTOM:					//�÷��̾��� �����ʾƷ��� �׶��� �浹
		_cPlayerTarget = CP_GROUND;			//�浹����� �׶���
		_cLR = LR_LEFT;						//�浹����(�¿�) 
		_cTB = TB_BOTTOM;					//�浹����(����) 
		break;								//
	}

	//������ ���, ���⿡ ���� �������� �����Ѵ�
	switch (_cPlayerTarget)					
	{										
		case CP_NULL:						//�浹�� ����� ����
			_state = INAIR;					// �浹�� ����� ������ ���߿� �ִ°�
		break;								
		case CP_OBJECT:						//������Ʈ�� �浹������(������Ʈ�� ĳ����)
		{									
			switch (_cLR)					//�¿� ����
			{								
				case LR_LEFT:				//����� ���ʿ��� �浹������
				_rtBlock = true;			//�÷��̾��� �������� ������(�÷��̾�� ���������� ��������)
				break;						
				case LR_RIGHT:				//����� �����ʿ��� �浹������
				_ltBlock = true;			//�÷��̾��� ������ ������
				break;						
			}								
			switch (_cTB)					//���Ϲ���
			{								
				case TB_TOP:				//����� ���ʿ��� �浹������
				_jumpPower = JUMPPOWER;		//�����Ŀ��� ������Ų��
				_state = ONLAND;			//�÷��̾��� ��ġ�� ��������ִ�
				if (_action == PR_JUMP) PR_IDLE;		//�÷��̾ �����ϰ������� �⺻���·� ������
				break;						
				case TB_BOTTOM:				//����� �Ʒ��ʿ��� �浹������
				_jumpPower = 0;				//�����Ŀ��� 0���� �ؼ� ���̻� ���� �ö��� ���ϰ��Ѵ�.
				break;						
			}								
		}									
		break;								
		case CP_ENEMY:						//���� �浹������
											//
		break;								//
		case CP_GROUND:						//���� �浹������
		{									//
			switch (_cLR)					//���� �¿�
			{								//
				case LR_NULL:				//�¿찡 �շ��������
				_rtBlock = false;			//
				_ltBlock = false;			//
				break;						//
				case LR_LEFT:				//�������� ����������
				_rtBlock = true;			//
				break;						//
				case LR_RIGHT:				//������ ����������
				_ltBlock = true;			//
				break;						//
			}								//
			switch (_cTB)					//���Ʒ� �浹
			{								//
				case TB_TOP:				//���� ž�� �浹������
				_jumpPower = JUMPPOWER;		//�����Ŀ��� ������Ų��
				_state = ONLAND;
				_y = probeY;
				if (_action == PR_JUMP) _action = PR_IDLE;
				break;						//
				case TB_BOTTOM:				//
				_jumpPower = 0;				//
				break;						//
			}								//
		}									
		case CP_SHOVEL_OBJ:					//
		{									//
			switch (_cTB)					//
			{								//
			case TB_TOP:					//
				_jumpPower = JUMPPOWER/2;	//
				break;						//
			}								//
		}									//
			break;							//
		case CP_SHOVEL_ENEMY:				//
		{									//
			switch (_cTB)					//
			{								//
				case TB_TOP:				//
				_jumpPower = JUMPPOWER / 2;	//
				break;						//
			}								//
			switch (_cLR)					//
			{								//
			case LR_LEFT:					//
				break;						//
			case LR_RIGHT:					//
				break;						//
			}								//
		}									//
			break;							//
											//
	}										//
}											//

void playerBase::attack(float fireX, float fireY, bool skillUsed)
{

}
void playerBase::move()
{

	if (KEYMANAGER->isStayKeyDown('W'))
	{
		if (_state == HANG) _action = PR_MOVE;
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		if (_state == HANG) _action = PR_MOVE;
		if (_state == INAIR) _action = PR_ATTACK;
	}
	if (KEYMANAGER->isOnceKeyUp('S'))
	{
		if (_state == INAIR) _action = PR_ATTACK;
		if (_state == HANG)_action = PR_IDLE;
	}
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_direction = PD_LEFT;
		_action = PR_MOVE;
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_action = PR_IDLE;
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_direction = PD_RIGHT;
		_action = PR_MOVE;
	}
	if (KEYMANAGER->isOnceKeyUp('D'))
	{
		_action = PR_IDLE;
	}	

	if (KEYMANAGER->isOnceKeyDown('K'))
	{
		_action = PR_ATTACK;
	}
	if (KEYMANAGER->isStayKeyDown('J'))
	{
		_action = PR_JUMP;
		_jumpPower = JUMPPOWER;
	}

	//�¿� �̵��κ�
	if (_action == PR_MOVE)
	{
		_x += _moveSpeed*_direction;
	}
	//���� �̵��κ�
	if (_action == PR_JUMP || _state == INAIR)
	{
		_y -= _jumpPower;
		_jumpPower -= _gravity;
		
		if (_jumpPower < 0) _currentFrameX = 1;
		else _currentFrameX = 0;
	}


	_rc = RectMake(_x - HIT_BOX_WIDTH / 2, _y - HIT_BOX_HEIGHT, HIT_BOX_WIDTH, HIT_BOX_HEIGHT);
}


int playerBase::collisionPlayerMap()
{
	HDC hdc = IMAGEMANAGER->findImage("bgMap")->getMemDC();

	RECT rc = _rc;

	int probeX, probeY2, probeY3;
	bool ltBlock, rtBlock;

	ltBlock = false;
	rtBlock = false;
	
	POINT probePoint[9];
	bool collisionCheck[9];
	

	for (int i = 0; i < 9; ++i)
	{
		probePoint[i] = PointMake(_x + (i % 3 * HIT_BOX_WIDTH / 2 - HIT_BOX_WIDTH / 2), _y + (i % 3 * HIT_BOX_HEIGHT / 2 - HIT_BOX_HEIGHT / 2));
		collisionCheck[i] = false;
	}


	probeY = rc.bottom;
	
	
	
	for (probeX = rc.left; probeX != rc.right; ++probeX)
	{
		while (!ThisPixelIsMazen(hdc, probeX, probeY)) //�������� ����Ÿ(���)�� �ƴҋ� ->�浹������
		{
			--probeY;									
		}
	}
	

	//�浹 ������ ���ϴ�

	/*for (int i = 0; i < 9; ++i)
	{
		while (ThisPixelIsMazen(hdc, probePoint[i].x, probePoint[i].y,RGB(0,255,0)))
		{
			collisionCheck[i] = true;
		}
	}*/

	
	if (KEYMANAGER->isStayKeyDown('Y')) return CT_BOTTOM;
	else return CT_NULL;
	
}
