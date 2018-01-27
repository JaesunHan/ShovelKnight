#pragma once
#include "menuBase.h"
enum LETTERBOX
{
	LETTERBACK,					//�ڷ�
	LETTERGAME,					//����
	LETTERCONTROL,				//����
	LETTERSOUND,				//����
	LETTERGRAPHIC,				//�׷���
	LETTERDATADELETE,			//�����ͻ���
	LETTEREND
};

#define selectRect	6


class optionMenu : public menuBase
{
public:

	image* _letter2Box;				//���� 2���ڽ�
	image* _letter3Box;				//���� 3���ڽ�
	image* _letter5Box;				//���� 5���ڽ�
	image* _letterBox;				//����ִ� �ڽ�

	LETTERBOX _letterBoxEnum;			//����Ʈ ���͹ڽ� �̳������
	animation* _letterBoxAni;

	RECT _rcOption[selectRect];			//�ڷ�, ����, ����, ����, �׷���, ������ ������ �����ϱ� ���� ��Ʈ�� ���.
	int _indexRc;						//�ε��� RC

	HRESULT init();
	void update();
	void release();
	void render(HDC hdc);
	void draw(HDC hdc);

	void showLetterBox();
	


	optionMenu();
	~optionMenu();
};

