#pragma once
#include "menuBase.h"
#define MAXHPIMAGE 4
#define MAXCHARACTERKIND	1	//ĳ���� ���� �ִ� �
//HP ���� ����ü
struct tagHPImage
{
	image* hpFull[MAXHPIMAGE];		//2ĭ¥�� �̹���
	image* hpHalf[MAXHPIMAGE];		//��ĭ¥�� �̹���
	int hp;
	float x, y; 
};
//���� ���� ����ü
struct tagMana
{
	image* manaImg;
	int mana;
	float x, y;
};
//�ڱ� ���� ����ü
struct tagMoney
{
	image* moneyImg;
	int money;
	float x, y;
};
//ĳ���� �̹��� ����� �� ����� �̹��� KeyString �� �̹��� File Name �� �����ϱ� ���ϰ� �ϱ� ���� ����ü
struct tagImageKeyNFileName
{
	string imageKeyStr;
	char* imageFileName;
	int totalWidth, totalHeight;
	int frameX, frameY;
};


class playerListMenu : public menuBase
{
	//�÷��̾��� ������ �����ִ� �޴�(UI)

	//ĳ���͸� �ѷ��� Ʋ �̹���
	image* _characterTitle;


	//ĳ���� �̹���			//�ִϸ��̼�
	image* _characterImg;	animation* _characterAnim;
	//�̹��� ����� �� �� �̹��� Ű���� ���� �̸�
	tagImageKeyNFileName _imgKeyNFile[MAXCHARACTERKIND];	//�̸� ĳ���� �������� �̹��� Ű���� �����̸��� �����ص���
	//ĳ���� ����(0 �� : ����)
	int _characterKind;
	//ĳ���� �̹����� ����� ��ġ
	float _characterX, _characterY;
	//ĳ������ ���μ��� ũ��
	int _characterW, _characterH;
	//ĳ���� �̸� �� ������ ����
	TCHAR _cName[128];
	//ü�� �̹���
	tagHPImage _hp;
	//���� �̹��� �� ��ġ
	tagMana _mana;
	//�� �ڱ� �̹��� �� ��ġ
	tagMoney _money;
	//�� ���	-> ������ �Ⱦ���
	image* _suit;
	//�� ����	-> ������ �Ⱦ���
	image* _weapon;
	

public:
	HRESULT init();
	HRESULT init(char* name, int characterKind, int hp, int mana, int money, int suit, int weapon);
	void update();
	void release();
	void render(HDC hdc);
	void draw(HDC hdc);

	int getHP() { return _hp.hp; }
	playerListMenu();
	~playerListMenu();
};

