#pragma once
#define MAXBTN	4
#include "optionMenu.h"
class gameTitleScene
{
private : 
	image* _bachgroundImg;			//��׶��� �̹���
	image* _shovelImg;				//���̹���
	float _shovelX, _shovelY;		//�� �̹����� ����� ��ġ
		
	RECT _rcBtn[MAXBTN];			//���� ��ŸƮ, ����, �ɼ�, ���� ���� ��ư �ڸ��� ��Ʈ�� ���.

	menuBase* _option;				//�ɼ�
	menuBase* _soundset;			//���� ����




public:
	gameTitleScene();
	~gameTitleScene();
};

