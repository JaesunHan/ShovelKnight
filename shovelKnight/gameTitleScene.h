#pragma once

#include "optionMenu.h"
#include "gameNode.h"

#define MAXBTN	4

class gameTitleScene : public gameNode	
{
private : 
	image* _backgroundImg;			//��׶��� �̹���
	string _titleBGImgKeyStr;		//�̹��� �Ŵ����� ����� Ÿ��Ʋ �� ��׶��� �̹��� Ű��
	char* _titleBGImgFileName;		//Ÿ��Ʋ �� ��׶��� ����	
	image* _shovelImg;				//���̹���
	string _shovelImgKeyStr;		//�̹��� �Ŵ����� ����� �� �̹��� Ű��
	char* _shovelImgFileName;		//�� �̹��� ���� �̸�
	float _shovelX, _shovelY;		//�� �̹����� ����� ��ġ(����)
	int _shovelW, _shovelH;			//�� �̹����� ���� ���� ũ�� -> ��Ʈ ���鶧 ����� ����
		
	RECT _rcBtn[MAXBTN];			//���� ��ŸƮ, ����, �ɼ�, ���� ���� ��ư �ڸ��� ��Ʈ�� ���.
	int _shovelIdx;

	menuBase* _option;				//�ɼ�
	menuBase* _soundset;			//���� ����

	bool _isOption;					//�ɼ��� �����ϸ� �ɼǸ޴� ��� ( true : ���, false : ��� ����)
	bool _isSound;					//�������� �����ϸ� ���� �޴� ��� ( true : ���, false : ��� ����)

public:

	HRESULT init();
	void update();
	void release();
	void render();
	void draw();


	gameTitleScene();
	~gameTitleScene();
};

