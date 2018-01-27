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
			_jumpPower = JUMPPOWER / 2;	//
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

