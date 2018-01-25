#pragma once
#include "gameNode.h"
#include "player1.h"

#define MAXPLAYERLIST 10

struct playerList
{
	int pNum;
	image* img;
	char* name;
	int hp;
	int mana;
	int money;
};

struct playerNumberBox
{
	RECT numberBox;
	float x;
	float y;
	image* img;
};

class gameMenuScene : public gameNode
{
private:
	string _sceneName;						//���Ŵ����� ����� �� �̸�

	image* _backgroundImg;					//��׶��� �̹���
	string _menuBGImgKeyStr;				//�̹��� �Ŵ����� ����� �޴��� ��׶��� �̹��� Ű��
	char* _menuBGImgFileName;				//�޴� �� ��׶��� ����

	vector<playerList> _vPList; 
	vector<playerList>::iterator _viPList;

	playerNumberBox _pNumberBox[MAXPLAYERLIST];

	//���� ������ ������ ǥ���ϴ� Ÿ���̹���
	image* _targetImg;
	animation* _animTarget;

	int _pSlotIdx;

public:

	HRESULT init();
	void update();
	void release();
	void render();
	void draw();


	
	//======================= Start ���� ���� =============================
	string getSceneName() { return _sceneName; }
	
	//======================= End ���� ���� ===============================

	void makePlayerListData();
	//�÷��̾� ����Ʈ�� ��� ini ������ �ִ��� �˻��Ͽ� ������ ������ �о���� ����� �ϴ� �Լ�
	void loadPlayerListData();

	gameMenuScene();
	~gameMenuScene();
};

