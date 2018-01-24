#pragma once
class menuBase
{
protected:
	image * _menuImg;		//�޴� �̹���
	string _imgKeyString;	//�̹��� �Ŵ����� ����� �̹��� Ű��
	char* _imgFileName;		//�޴� �̹��� ���� �̸�(��� ����)
	float _x, _y;			//�޴� �� ����� �߾���ǥ
	int _width, _height;	//�޴��� ���μ��� ũ��
	
public:
	virtual HRESULT init();
	virtual HRESULT init(string imgKeyString, char* imgFileNmae, float x, float y, int imgWidth, int imgHeight);
	virtual void update();
	virtual void release();
	virtual void render();
	virtual void draw(HDC hdc);

	menuBase();
	~menuBase();
};

