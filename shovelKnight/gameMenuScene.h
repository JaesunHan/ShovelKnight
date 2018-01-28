#pragma once
#include "gameNode.h"
#include "player1.h"
#include "playerListMenu.h"
#include "createCharacterMenu.h"

#define MAXPLAYERLIST 10

class gamePlayScene;
struct playerList
{
	int pNum;			//����Ǿ� �ִ� ĳ���ͽ��� ��ȣ
	image* img;			//ĳ���� �̹���
	int characterkind;	//ĳ���� ���� : 0���� ����
	TCHAR name[128];			//ĳ������ �г�
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
	playerListMenu* _plm[MAXPLAYERLIST];
	//ĳ���� �������� ���ڴ� �޴� (���ӿ���  "ó������"��� �ߴ� �޴� ���ϴ� ����)
	createCharacterMenu* _ccm;

	image* _testScript;

	//�÷��� �׶��尡 ������ �ִ� �����ä����� ���� ������ ������ ����
	gamePlayScene* _GPS;
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

	//���ο� ĳ���͸� �����ؼ� ini ������ ���Ͽ������ϴ� �Լ�
	void createNewDefaultCharacter();
	//��Ʈ���� ini ���Ͽ� �����ϱ� ���� �Լ�
	//							������ ini�����̸�, ������Ʈ ����,			Ÿ��Ʋ,			������ ��Ʈ�� ������
	void addNsaveINTDataInINIFile(char* fileName, char subjectName[256], char title[256], int data);

	//�÷��� �׶��尡 ������ �ִ� �����÷��̾��� ���� ��������
	void setGamePlaySceneAdressLink(gamePlayScene* gps) { _GPS = gps; }

	gameMenuScene();
	~gameMenuScene();
};

