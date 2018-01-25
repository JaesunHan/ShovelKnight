#pragma once
#include "gameNode.h"
#include "player1.h"

#define MAXPLAYERLIST 10

class gameMenuScene : public gameNode
{
private:
	string _sceneName;				//���Ŵ����� ����� �� �̸�

	image* _backgroundImg;			//��׶��� �̹���
	string _menuBGImgKeyStr;		//�̹��� �Ŵ����� ����� �޴��� ��׶��� �̹��� Ű��
	char* _menuBGImgFileName;		//�޴� �� ��׶��� ����

	vector<playerBase*> _vPList; 
	vector<playerBase*>::iterator _viPList;


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

