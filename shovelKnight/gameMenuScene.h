#pragma once
#include "gameNode.h"
#include "player1.h"
#include "playerListMenu.h"
#include "createCharacterMenu.h"

#define MAXPLAYERLIST 10

struct playerList
{
	int pNum;			//����Ǿ� �ִ� ĳ���ͽ��� ��ȣ
	image* img;			//ĳ���� �̹���
	int characterkind;	//ĳ���� ���� : 0���� ����
	char name[128];			//ĳ������ �г�
	int hp;				//HP
	int mana;			//����
	int money;			//������ �ִ� ��
	int suit;			//0 ���� �⺻��Ʈ
	int weapon;			//0 ���� �⺻����(��)
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
	//���� ������ ���� ���ؽ�
	int _pSlotIdx;
	//�÷��̾� ����Ʈ ������ ����ִ� �迭
	playerList _pList[MAXPLAYERLIST];

	//�÷��̾� ������ �����ִ� �޴�
	playerListMenu* _plm;
	//ĳ���� �������� ���ڴ� �޴� (���ӿ���  "ó������"��� �ߴ� �޴� ���ϴ� ����)
	createCharacterMenu* _ccm;
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

