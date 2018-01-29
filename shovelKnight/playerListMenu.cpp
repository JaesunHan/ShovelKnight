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

HRESULT playerListMenu::init(char name[128], int characterKind, int hp, int maxHp, int mana, int money, int suit, int weapon)
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
	_hp.maxHp = maxHp;
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
	_characterAnim->setFPS(1);
	_characterAnim->start();

	//HP ��¿� ���� �̹��� 3�� : Ǯ HP, ���� HP, ��Ƽ HP
	_emptyHP = IMAGEMANAGER->addImage("emptyHPBlock", "./image/UI/Hud_empty.bmp", 16, 16, true, RGB(255, 0, 255));
	_fullHP = IMAGEMANAGER->addImage("fullHPBlock", "./image/UI/Hud_hpFull.bmp", 16, 16, true, RGB(255, 0, 255));
	_halfHP = IMAGEMANAGER->addImage("halfHPBlock", "./image/UI/Hud_hpHalf.bmp", 16, 16, true, RGB(255, 0, 255));

	//���� ��¿� ���� �̹��� �� �ؽ�Ʈ
	_mana.manaImg = IMAGEMANAGER->addImage("manaImage", "./image/UI/Hud_mana.bmp", 12, 20, true, RGB(255, 0, 255));
	wsprintf(_mana.manaText, "%d", _mana.mana);

	//���� ��¿� ���� �̹����� �ؽ�Ʈ
	_money.moneyImg = IMAGEMANAGER->addImage("moneyImage", "./image/UI/Hud_gold.bmp", 18, 12, true, RGB(255, 0, 255));
	wsprintf(_money.moneyText, "%d", _money.money);

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
		//======================== Start ĳ������ �̸��� �ؽ�Ʈ�� ���======================================
		TextOut(hdc, _menuImg->getWidth() / 3 * 1+20, _menuImg->getHeight() / 3 * 1+10, _cName, strlen(_cName));
		//======================== End ĳ������ �̸��� �ؽ�Ʈ�� ���======================================

		//======================== Start hp ����ϱ� ===================================================
		//�⺻���� ��� N�� ���
		for (int i = 0; i < _hp.maxHp /2 ; ++i)
		{
			_emptyHP->render(hdc, _menuImg->getWidth() / 3 * 1 + 20 + 16 * i, _menuImg->getHeight() / 3 * 1 + 35);
		}
		for (int i = 0; i < _hp.hp / 2; ++i)
		{
			_fullHP->render(hdc, _menuImg->getWidth() / 3 * 1 + 20 + 16 * i, _menuImg->getHeight() / 3 * 1 + 35);
		}
		if (_hp.hp % 2 == 1)
		{
			_halfHP->render(hdc, _menuImg->getWidth() / 3 * 1 + 20 + 16 * (_hp.hp / 2), _menuImg->getHeight() / 3 * 1 + 35);
		}
		//======================== End hp ����ϱ� ===================================================

		//======================== Start Mana ����ϱ� ===============================================
		_mana.manaImg->render(hdc, _menuImg->getWidth() / 3 * 1 + 20, _menuImg->getHeight() / 3 * 1 + 60);
		TextOut(hdc, _menuImg->getWidth() / 3 * 1 + 40 + _mana.manaImg->getWidth(), _menuImg->getHeight() / 3 * 1 + 60, _mana.manaText, strlen(_mana.manaText));
		//======================== End Mana ����ϱ� =================================================

		//======================== Start Money ����ϱ� ==============================================
		_money.moneyImg->render(hdc, _menuImg->getWidth() / 3 * 1 + 20, _menuImg->getHeight() / 3 * 1 + 85);
		TextOut(hdc, _menuImg->getWidth() / 3 * 1 + 40 + _money.moneyImg->getWidth(), _menuImg->getHeight() / 3 * 1 + 85, _money.moneyText, strlen(_money.moneyText));
		//======================== End Money ����ϱ� ================================================


	}
}
