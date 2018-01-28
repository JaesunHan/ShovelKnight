#pragma once
#include "menuBase.h"
#include "soundMenu.h"

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
	image* _letterBoxEm;			//����ִ� �ڽ�
	image* _letterBoxEm2;			//����ִ� �ڽ�

	LETTERBOX _letterBoxEnum;			//����Ʈ ���͹ڽ� �̳������
	animation* _letterBoxAni;			//���͹ڽ� �ִ� 2����¥��
	animation* _letterBoxAni2;			//���͹ڽ� �ִ� 3����¥��
	animation* _letterBoxAni3;			//���͹ڽ� �ִ� 5����¥��


	soundMenu* _sm;

	RECT _rcOption[selectRect];			//�ڷ�, ����, ����, ����, �׷���, ������ ������ �����ϱ� ���� ��Ʈ�� ���.
	int _indexRc;						//�ε��� RC

	bool _isSoundMenu;					//����޴� �׸����


	HRESULT init();
	void update();
	void release();
	void render(HDC hdc);
	void draw(HDC hdc);

	void showLetterBox();
	
	
	inline bool getIsSoundMenu() { return _isSoundMenu; }

	optionMenu();
	~optionMenu();
};

