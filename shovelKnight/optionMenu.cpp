#include "stdafx.h"
#include "optionMenu.h"


optionMenu::optionMenu()
{
}


optionMenu::~optionMenu()
{

}


HRESULT optionMenu::init()
{
	//�̹��� �ʱ�ȭ 
	_imgKeyString = "option_main";
	_imgFileName = "./image/title/option_main.bmp";
	menuBase::init(_imgKeyString, _imgFileName, WINSIZEX/2 - 534/2, WINSIZEY/2 - 320/2, 534, 320);
	
	//���ڸ� ���δ� ���ùڽ� ����
	_letter2Box = IMAGEMANAGER->addFrameImage("2���ڹڽ�", "./image/title/2letterSelectBox.bmp", 120, 36, 2, 1, true, RGB(255, 0, 255), false);
	_letter3Box = IMAGEMANAGER->addFrameImage("3���ڹڽ�", "./image/title/3letterSelectBox.bmp", 286, 67, 2, 1, true, RGB(255, 0, 255), false);
	_letter5Box = IMAGEMANAGER->addFrameImage("5���ڹڽ�", "./image/title/5letterSelectBox.bmp", 464, 67, 2, 1, true, RGB(255, 0, 255), false);

	//�ɼ� �������� ��Ʈ ���ô�
	//�ڷ�, ����, ���� ->�α��ڿ��� 0,1,2 ��Ʈ�� 48,28 �������
	for (int i = 0; i < 3; ++i)
	{
		//232, 250 ����( right, top)
		_rcOption[i] = RectMake(144, 130 + i * 34, 48, 28);
	}

	//����, �׷��� -> �����ڿ��� ��ư 63, 28 �������
	for (int i = 3; i < 5; ++i)
	{
		_rcOption[i] = RectMake(144, 232 + (i - 3) * 34, 63, 28);
	}

	//������ ����(5����) ��Ʈ 
	_rcOption[5] = RectMake(144, 297, 115, 28);

	_letterBoxEnum = LETTERBACK;

	_letterBox = IMAGEMANAGER->findImage("2���ڹڽ�");
	_indexRc = 0;

	//�ִϸ��̼� ���� 
	int letter2Move[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("2���ڹڽ�������", "2���ڹڽ�", letter2Move, 2, 3, true);

	_letterBoxAni = KEYANIMANAGER->findAnimation("2���ڹڽ�������");

	return S_OK;
}
void optionMenu::update() 
{
	


}
void optionMenu::release()
{

}
void optionMenu::render(HDC hdc)
{
	draw(hdc);
	
	_letterBox->aniRender(hdc, _rcOption[0].left-5, _rcOption[0].top, _letterBoxAni);
	
}
void optionMenu::draw(HDC hdc)
{
	_menuImg->render(hdc, WINSIZEX / 2 - 534 / 2, WINSIZEY / 2 - 320 / 2);
	
	if (KEYMANAGER->isStayKeyDown('G'))
	{
		// �׽�Ʈ�� : �����޴� ��Ʈ ���
		for (int i = 0; i < selectRect; ++i)
		{
			Rectangle(hdc, _rcOption[i].left, _rcOption[i].top, _rcOption[i].right, _rcOption[i].bottom);
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		
	}
}

void optionMenu::showLetterBox()
{
	switch (_letterBoxEnum)
	{
	default: _letterBox = IMAGEMANAGER->findImage("2���ڹڽ�");
		break;

	}
}

