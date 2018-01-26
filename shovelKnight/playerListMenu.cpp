#include "stdafx.h"
#include "playerListMenu.h"


playerListMenu::playerListMenu()
{
}


playerListMenu::~playerListMenu()
{

}

HRESULT playerListMenu::init()
{
	_imgKeyString = "playerListMenu";
	_imgFileName = "./image/title/profilePlayerList.bmp";
	menuBase::init(_imgKeyString, _imgFileName, 0, 0, WINSIZEX, WINSIZEY);
	//ĳ���͸� �ѷ��� Ÿ��Ʋ
	_characterTitle = IMAGEMANAGER->addImage("characterTitle", "./image/title/profileCharacterBox.bmp", 160, 180, 100, 100, true, RGB(255, 0, 255));

	return S_OK;
}

HRESULT playerListMenu::init(char name[128], int characterKind, int hp, int mana, int money, int suit, int weapon)
{
	//��׶��� �̹��� �ʱ�ȭ
	_imgKeyString = "playerListMenu";
	_imgFileName = "./image/title/profilePlayerList.bmp";
	menuBase::init(_imgKeyString, _imgFileName, 0, 0, WINSIZEX, WINSIZEY);
	//ĳ���͸� �ѷ��� Ÿ��Ʋ
	_characterTitle = IMAGEMANAGER->addImage("characterTitle", "./image/title/profileCharacterBox.bmp", 160, 180, 100, 100, true, RGB(255, 0, 255));

	//�Ű������� ���� �������� ������ ����
	wsprintf(_cName, "%s", name);
	_characterKind = characterKind;
	_hp.hp = hp;
	_mana.mana = mana;
	_money.money = money;
	
	//ĳ���� �̹��� �ʱ�ȭ �� �������� �̸� ����
	_imgKeyNFile[0].imageKeyStr = "ShovelKnightShine";
	_imgKeyNFile[0].imageFileName = "./image/shovelKnight/shovelKnightShine.bmp";
	_imgKeyNFile[0].totalWidth = 102;
	_imgKeyNFile[0].totalHeight = 62;
	_imgKeyNFile[0].frameX = 3;
	_imgKeyNFile[0].frameY = 2;
	//ĳ���� �̹����� �̹��� �Ŵ����� ���
	_characterImg = IMAGEMANAGER->addFrameImage(
		_imgKeyNFile[characterKind].imageKeyStr,
		_imgKeyNFile[characterKind].imageFileName,
		_imgKeyNFile[characterKind].totalWidth,
		_imgKeyNFile[characterKind].totalHeight,
		_imgKeyNFile[characterKind].frameX,
		_imgKeyNFile[characterKind].frameY,
		true, RGB(255, 0, 255));

	//���� ���̵� �ִϸ��̼� �����
	_characterAnim = new animation;
	_characterAnim->init(_characterImg->getWidth(), _characterImg->getHeight(), _characterImg->getFrameWidth(), _characterImg->getFrameHeight());
	_characterAnim->setPlayFrame(0, 3, false, true);
	//int arrIdleAnim[] = { 0, 1, 2 };
	//_characterAnim->setPlayFrame(arrIdleAnim, 3, true);
	_characterAnim->setFPS(1);
	_characterAnim->start();

	return S_OK;
}
void playerListMenu::update() 
{
	_characterAnim->frameUpdate(TIMEMANAGER->getElapsedTime() * 8);
}
void playerListMenu::release()
{

}
void playerListMenu::render(HDC hdc) 
{
	draw(hdc);
}
void playerListMenu::draw(HDC hdc)	  
{
	_menuImg->render(hdc, 0, 0);
	_characterTitle->render(hdc, _characterTitle->getX(), _characterTitle->getY());
	//ĳ���� ������ ������ �� ������ ���
	if (_hp.hp != 0)
	{
		//ĳ���� �̹����� �ִϷ����� �׸���
		_characterImg->aniRender(hdc,
			_characterTitle->getCenterX() - _characterImg->getFrameWidth(),
			_characterTitle->getCenterY() - _characterImg->getFrameHeight(),
			_characterAnim, 2);
		//ĳ������ �̸��� �ؽ�Ʈ�� ���
		TextOut(hdc, _menuImg->getWidth() / 3 * 1+20, _menuImg->getHeight() / 3 * 1+10, _cName, strlen(_cName));
		//hp ����ϱ�
		
	}
}
