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
	_isOptionRender = false;// �ʱ�ȭ�� false�ؾ� ������.
	//�̹��� �ʱ�ȭ 
	_imgKeyString = "option_main";
	_imgFileName = "./image/title/option_main.bmp";
	menuBase::init(_imgKeyString, _imgFileName, WINSIZEX/2 - 534/2, WINSIZEY/2 - 320/2, 534, 320);
	
	//���ڸ� ���δ� ���ùڽ� ����
	_letter2Box = IMAGEMANAGER->addFrameImage("2���ڹڽ�", "./image/title/2letterSelectBox.bmp", 120, 36, 2, 1, true, RGB(255, 0, 255), false);
	_letter3Box = IMAGEMANAGER->addFrameImage("3���ڹڽ�", "./image/title/3letterSelectBox.bmp", 165, 39, 2, 1, true, RGB(255, 0, 255), false);
	_letter5Box = IMAGEMANAGER->addFrameImage("5���ڹڽ�", "./image/title/5letterSelectBox.bmp", 267, 39, 2, 1, true, RGB(255, 0, 255), false);

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
	_letterBoxEm = IMAGEMANAGER->findImage("3���ڹڽ�");
	_letterBoxEm2 = IMAGEMANAGER->findImage("5���ڹڽ�");

	_indexRc = 0;

	//�ִϸ��̼� ���� 
	int letter2Move[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("2���ڹڽ�������", "2���ڹڽ�", letter2Move, 2, 3, true);

	int letter3Move[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("3���ڹڽ�������", "3���ڹڽ�", letter3Move, 2, 3, true);

	int letter5Move[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("5���ڹڽ�������", "5���ڹڽ�", letter5Move, 2, 3, true);


	_letterBoxAni = KEYANIMANAGER->findAnimation("2���ڹڽ�������");
	//_letterBoxAni2 = KEYANIMANAGER->findAnimation
	KEYANIMANAGER->start("2���ڹڽ�������");

	_letterBoxAni2 = KEYANIMANAGER->findAnimation("3���ڹڽ�������");
	KEYANIMANAGER->start("3���ڹڽ�������");
	_letterBoxAni3 = KEYANIMANAGER->findAnimation("5���ڹڽ�������");
	KEYANIMANAGER->start("5���ڹڽ�������");

	_sm = new soundMenu;
	_sm->init();
	_isSoundMenu = false;

	//_isOptionRender = true;
	return S_OK;
}

void optionMenu::update() 
{	//�ɼ��� ���õǾ����� ������Ʈ�� �մϴ�.
	if (_sm->getIsOptionRender())
	{
		_sm->update();
	}
	else
	{
		_sm->setIsOptionRender(false);
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			if (_indexRc == 5) _indexRc = 0;
			else _indexRc++;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			if (_indexRc == 0) _indexRc = 5;
			else _indexRc--;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			if (_indexRc == 0)
			{
				_isOptionRender = false;
			}
			if (_indexRc == 3)
			{
				_isSoundMenu = true;
				_sm->setIsOptionRender(true);
			}
		}
	}
	switch (_indexRc)
	{
	case 0: case 1: case 2:
		//letterBox = ;
		break;
	case 3: case 4:
		//_letterBox = ;
		break;
	case 5:
		//_letterBox = ;
		break;
	}


}
void optionMenu::release()
{

}
void optionMenu::render(HDC hdc)
{

		draw(hdc);
	
	

	
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
	
	//TTTextOut(300, 10, "_indexRC", _indexRc);
	if (_indexRc >= 0 && _indexRc <= 2)
	{
		_letterBox->aniRender(hdc, _rcOption[0].left - 5, _rcOption[0].top + _indexRc * 32, _letterBoxAni);
	}
	if (_indexRc >= 3 && _indexRc <= 4)
	{
		_letterBoxEm->aniRender(hdc, _rcOption[0].left - 5, _rcOption[0].top + _indexRc * 32, _letterBoxAni2);
	}
	if (_indexRc == 5)
	{
		_letterBoxEm2->aniRender(hdc, _rcOption[0].left - 5, _rcOption[0].top + _indexRc * 32, _letterBoxAni3);
	}

	if (_sm->getIsOptionRender())
	{
		_sm->render(hdc);
	}
	
	//if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	//{
	//	_letterBox->aniRender(hdc, _rcOption[1].left - 5, _rcOption[1].top, _letterBoxAni);
	//}
}

void optionMenu::showLetterBox()
{
	switch (_letterBoxEnum)
	{
		default: _letterBox = IMAGEMANAGER->findImage("2���ڹڽ�");
		break;

	}
}

