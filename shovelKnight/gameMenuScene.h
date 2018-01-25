#pragma once
#include "gameNode.h"

class gameMenuScene : public gameNode
{
private:
	string _sceneName;				//���Ŵ����� ����� �� �̸�

	image* _backgroundImg;			//��׶��� �̹���
	string _menuBGImgKeyStr;		//�̹��� �Ŵ����� ����� �޴��� ��׶��� �̹��� Ű��
	char* _menuBGImgFileName;		//�޴� �� ��׶��� ����


public:

	HRESULT init();
	void update();
	void release();
	void render();
	void draw();
	


	gameMenuScene();
	~gameMenuScene();
};

