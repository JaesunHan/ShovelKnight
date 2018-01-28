#include "stdafx.h"
#include "soundMenu.h"


soundMenu::soundMenu()
{
}


soundMenu::~soundMenu()
{

}

HRESULT soundMenu::init()
{
	_imgKeyString = "option_Sound";
	_imgFileName = "./image/title/option_Sound.bmp";
	menuBase::init(_imgKeyString, _imgFileName, WINSIZEX / 2 - 534 / 2, WINSIZEY / 2 - 320 / 2, 534, 320);

	//���� 2���ڽ�
	_soundLetter2Box = IMAGEMANAGER->addFrameImage("����2���ڹڽ�", "./image/title/2letterSelectBox.bmp", 120, 36, 2, 1, true, RGB(255, 0, 255), false);			
	//���� 3���ڽ�
	_soundLetter4Box = IMAGEMANAGER->addFrameImage("����4���ڹڽ�", "./image/title/4letterSelectBox.bmp", 185, 39, 2, 1, true, RGB(255, 0, 255), false);
	//���� 5���ڽ�
	_soundLetter5Box = IMAGEMANAGER->addFrameImage("����5���ڹڽ�", "./image/title/5letterSelectBox.bmp", 267, 39, 2, 1, true, RGB(255, 0, 255), false);
	//���� 10���ڽ�
	_soundLetter10Box = IMAGEMANAGER->addFrameImage("����10���ڹڽ�", "./image/title/10letterSelectBox.bmp", 500, 42, 2, 1, true, RGB(255, 0, 255), false);
	

	_effectSoundRectButtonX = 525;
	_bgmSoundRectButtonX = 525;
	//����� ��Ʈ����=============
	_rcEffectVolume = RectMake(525, 179, 101, 6);				//����Ʈ������ ��Ʈ
	_rcEffectVolumeButton = RectMake(_effectSoundRectButtonX, 173, 6, 20);				//����Ʈ������ ��ư ��Ʈ
	_bmgVolume = RectMake(525, 209, 100, 6);					//����������� ��Ʈ
	_bgmVolumeButton = RectMake(_bgmSoundRectButtonX, 204, 6, 20);				//����������� ��ư ��Ʈ
	//������ �̹��� ����===================
	_effectVolumeButton = IMAGEMANAGER->addImage("����Ʈ�����ٹ�ư", "./image/title/soundBar.bmp", 4, 12, true, RGB(255, 0, 255), false);	//����Ʈ������ ��ư �̹���
	_bgmVolumeButtonimg = IMAGEMANAGER->addImage("����������ٹ�ư", "./image/title/soundBar.bmp", 4, 12, true, RGB(255, 0, 255), false);	//����������� ��ư �̹���

	
	//232, 250 ����( right, top)
	_rcSound[0] = RectMake(144, 130 , 48, 28);
	_rcSound[1] = RectMake(144, 164,  48, 28);
	_rcSound[2] = RectMake(144, 198, 48, 28);
	_rcSound[3] = RectMake(144, 232, 48, 28);

	_soundLetterBoxEm = IMAGEMANAGER->findImage("����2���ڹڽ�");
	_soundLetterBoxEm2 = IMAGEMANAGER->findImage("����4���ڹڽ�");
	_soundLetterBoxEm3 = IMAGEMANAGER->findImage("����5���ڹڽ�");
	_soundLetterBoxEm4 = IMAGEMANAGER->findImage("����10���ڹڽ�");
	
	_indexSoundRc = 0;
	
	int soundLetter2Move[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("����2���ڹڽ�������", "����2���ڹڽ�", soundLetter2Move, 2, 3, true);
	int soundLetter4Move[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("����4���ڹڽ�������", "����4���ڹڽ�", soundLetter4Move, 2, 3, true);
	int soundLetter5Move[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("����5���ڹڽ�������", "����5���ڹڽ�", soundLetter5Move, 2, 3, true);
	int soundLetter10Move[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("����10���ڹڽ�������", "����10���ڹڽ�", soundLetter10Move, 2, 3, true);

	//���͹ڽ� �ִ� 2����¥��
	_soundLetterBoxAni = KEYANIMANAGER->findAnimation("����2���ڹڽ�������");
	KEYANIMANAGER->start("����2���ڹڽ�������");
	//���͹ڽ� �ִ� 3����¥��
	_soundLetterBoxAni2 = KEYANIMANAGER->findAnimation("����4���ڹڽ�������");
	KEYANIMANAGER->start("����4���ڹڽ�������");
	//���͹ڽ� �ִ� 5����¥��
	_soundLetterBoxAni3 = KEYANIMANAGER->findAnimation("����5���ڹڽ�������");
	KEYANIMANAGER->start("����5���ڹڽ�������");
	//���͹ڽ� �ִ� 10����¥��
	_soundLetterBoxAni4 = KEYANIMANAGER->findAnimation("����10���ڹڽ�������");
	KEYANIMANAGER->start("����10���ڹڽ�������");




	return S_OK;
}
void soundMenu::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (_indexSoundRc == 3) _indexSoundRc = 0;
		else _indexSoundRc++;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_indexSoundRc == 0) _indexSoundRc = 3;
		else _indexSoundRc--;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if (_indexSoundRc == 1)
		{
			if (_effectSoundRectButtonX > 525)
			{
				_effectSoundRectButtonX -= 10;
			}
		}
		if (_indexSoundRc == 2)
		{
			if (_bgmSoundRectButtonX > 525)
			{
				_bgmSoundRectButtonX -= 10;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if (_indexSoundRc == 1)
		{
			if (_effectSoundRectButtonX < 625)
			{
				_effectSoundRectButtonX += 10;
			}
		}
		if (_indexSoundRc == 2)
		{
			if (_bgmSoundRectButtonX < 625)
			{
				_bgmSoundRectButtonX += 10;
			}
		}
	}
	
	_rcEffectVolumeButton = RectMake(_effectSoundRectButtonX, 173, 6, 20);				//����Ʈ������ ��ư ��Ʈ
	_bgmVolumeButton = RectMake(_bgmSoundRectButtonX, 204, 6, 20);				//����������� ��ư ��Ʈ
}
void soundMenu::release()
{

}
void soundMenu::render(HDC hdc)
{
	draw(hdc);
}
void soundMenu::draw(HDC hdc)
{
	_menuImg->render(hdc, WINSIZEX / 2 - 534 / 2, WINSIZEY / 2 - 320 / 2);
	
	_effectVolumeButton->render(hdc, _effectSoundRectButtonX, 175);
	_bgmVolumeButtonimg->render(hdc, _bgmSoundRectButtonX, 206);

	if (KEYMANAGER->isStayKeyDown('G'))
	{
		// �׽�Ʈ�� : �����޴� ��Ʈ ���
		for (int i = 0; i < selectRect; ++i)
		{
			Rectangle(hdc, _rcSound[i].left, _rcSound[i].top, _rcSound[i].right, _rcSound[i].bottom);
		}
		Rectangle(hdc, _rcEffectVolume.left, _rcEffectVolume.top, _rcEffectVolume.right, _rcEffectVolume.bottom);
		Rectangle(hdc, _bmgVolume.left, _bmgVolume.top, _bmgVolume.right, _bmgVolume.bottom);
		Rectangle(hdc, _rcEffectVolumeButton.left, _rcEffectVolumeButton.top, _rcEffectVolumeButton.right, _rcEffectVolumeButton.bottom);
		Rectangle(hdc, _bgmVolumeButton.left, _bgmVolumeButton.top, _bgmVolumeButton.right, _bgmVolumeButton.bottom);
	}
	
	
	TTTextOut(300, 10, "_indexSoundRc", _indexSoundRc);
	
	if (_indexSoundRc == 0 )
	{
		_soundLetterBoxEm->aniRender(hdc, _rcSound[0].left - 5, _rcSound[0].top + _indexSoundRc * 32, _soundLetterBoxAni);
	}
	if (_indexSoundRc == 1)
	{
		_soundLetterBoxEm2->aniRender(hdc, _rcSound[0].left - 5, _rcSound[0].top + _indexSoundRc * 32, _soundLetterBoxAni2);
	}
	if (_indexSoundRc == 2)
	{
		_soundLetterBoxEm3->aniRender(hdc, _rcSound[0].left - 5, _rcSound[0].top + _indexSoundRc * 32, _soundLetterBoxAni3);
	}
	if (_indexSoundRc == 3)
	{
		_soundLetterBoxEm4->aniRender(hdc, _rcSound[0].left - 5, _rcSound[0].top + _indexSoundRc * 32, _soundLetterBoxAni4);
	}


}