#include "stdafx.h"
#include "playerBase.h"

void playerBase::hitReAction()
{
	//�÷��̾�� ���� �浹�� Ȯ���ؼ� �浹 ����, �浹����� �����Ѵ�
	//switch ()			
	//{										
	//case CT_NULL:							//�浹���� �ʾ�����
	//	_cPlayerTarget = CP_NULL;			//�÷��̾�� �浹���� �ʾҴ�
	//	break;								//
	//case CT_TOP:							//�÷��̾��� ž�� �׶����� ���� �浹
	//	_cPlayerTarget = CP_GROUND;			//�浹����� �׶���
	//	_cLR = LR_NULL;						//�浹����(�¿�) ����
	//	_cTB = TB_BOTTOM;					//�浹����(����) ����� �Ʒ���
	//	break;								//
	//case CT_BOTTOM:							//�÷��̾��� ���Ұ� �׶����� ž �浹
	//	_cPlayerTarget = CP_GROUND;			//�浹����� �׶���
	//	_cLR = LR_NULL;						//�浹����(�¿�) ����
	//	_cTB = TB_TOP;						//�浹����(����) ����� ����
	//	break;								//
	//case CT_LEFT:							//�÷��̾��� ���ʰ� �׶����� ������ �浹
	//	_cPlayerTarget = CP_GROUND;			//�浹����� �׶���
	//	_cLR = LR_RIGHT;					//�浹����(�¿�) ����� ������
	//	_cTB = TB_NULL;						//�浹����(����) ����
	//	break;								//
	//case CT_RIGHT:							//�÷��̾��� �����ʰ� �׶����� ���� �浹
	//	_cPlayerTarget = CP_GROUND;			//�浹����� �׶���
	//	_cLR = LR_LEFT;						//�浹����(�¿�) 
	//	_cTB = TB_NULL;						//�浹����(����) 
	//	break;								//
	//case CT_LEFT_BOTTOM:					//�÷��̾��� ���ʾƷ��� �׶��� �浹
	//	_cPlayerTarget = CP_GROUND;			//�浹����� �׶���
	//	_cLR = LR_RIGHT;					//�浹����(�¿�) ����� ������
	//	_cTB = TB_TOP;						//�浹����(����) 
	//	break;								//
	//case CT_RIGHT_BOTTOM:					//�÷��̾��� �����ʾƷ��� �׶��� �浹
	//	_cPlayerTarget = CP_GROUND;			//�浹����� �׶���
	//	_cLR = LR_LEFT;						//�浹����(�¿�) 
	//	_cTB = TB_BOTTOM;					//�浹����(����) 
	//	break;								//
	//}

	//������ ���, ���⿡ ���� �������� �����Ѵ�

	

	switch (_cPlayerTarget)
	{
	case COLLISION_PLAYER_NULL:							//�浹�� ����� ����
		break;
	case COLLISION_PLAYER_OBJECT:						//������Ʈ�� �浹������(������Ʈ�� ĳ����)
	break;
	case COLLISION_PLAYER_ENEMY:						//���� �浹������
		break;						
	case COLLISION_PLAYER_GROUND:						//���� �浹������
		_state = PLAYERSTATE_ONLAND;
		_action = PLAYERACTION_IDLE;
		break;
	case COLLISION_PLAYER_SHOVEL_OBJ:					//
	break;						
	case COLLISION_PLAYER_SHOVEL_ENEMY:				//
	break;							
	}										
}											

