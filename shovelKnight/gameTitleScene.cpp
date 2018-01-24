#include "stdafx.h"
#include "gameTitleScene.h"


gameTitleScene::gameTitleScene()
{
}


gameTitleScene::~gameTitleScene()
{

}

HRESULT gameTitleScene::init()
{
	_titleBGImgKeyStr = "titleBackgroundImg";
	_titleBGImgFileName = "./image/title/titleMain.bmp";
	_backgroundImg = IMAGEMANAGER->addImage(_titleBGImgKeyStr, _titleBGImgFileName, 0,0,WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	
	_shovelImgKeyStr = "shovelFlag";
	_shovelImgFileName = "./image/title/shovel.bmp";
	_shovelImg = IMAGEMANAGER->addImage(_shovelImgKeyStr, _shovelImgFileName, 96, 20, true, RGB(255, 0, 255));
	_shovelW = _shovelImg->getWidth();		//96
	_shovelH = _shovelImg->getHeight();		//20
	
	//��Ʈ�Ǽ��� ũ�� : 22
	//�� ���� �޴��� ��ġ�� ���� ��Ʈ �ʱ�ȭ (���� ��ŸƮ, ����, �ɼ�, ���� ����)
	for (int i = 0; i < MAXBTN; ++i)
	{
		//364, 270 ����( right, top)
		_rcBtn[i] = RectMake(268, 270 + i * 22, 96, 22);
	}

	//ó������ ���ӽ�ŸƮ ��ư ���� ���� ���
	//_shovelX = _rcBtn[0].left + (_rcBtn[0].right - _rcBtn[0].left) / 2;
	//_shovelY = _rcBtn[0].top + (_rcBtn[0].bottom - _rcBtn[0].top) / 2;
	_shovelIdx = 0;
	return S_OK;
}
void gameTitleScene::update() 
{
	//�� �̹����� �Ʒ��� �̵�
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		++_shovelIdx;
		if (_shovelIdx >= MAXBTN-1)	_shovelIdx = MAXBTN - 1;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		--_shovelIdx;
		if (_shovelIdx <= 0)	_shovelIdx = 0;
	}
}
void gameTitleScene::release()
{

}
void gameTitleScene::render() 
{

	draw();
}
void gameTitleScene::draw()	  
{
	//��׶��� �̹��� ���
	_backgroundImg->render(getMemDC(), 0, 0);
	//�� �̹����� ��µ� �� �ִ¤� ��ġ ��Ʈ ����ϱ�
	if (KEYMANAGER->isStayKeyDown('G'))
	{
		for (int i = 0; i < MAXBTN; ++i)
		{
			Rectangle(getMemDC(), _rcBtn[i].left, _rcBtn[i].top, _rcBtn[i].right, _rcBtn[i].bottom);
		}
	}
	_shovelImg->render(getMemDC(), _rcBtn[_shovelIdx].left, _rcBtn[_shovelIdx].top);
	


}
