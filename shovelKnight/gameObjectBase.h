#pragma once
#include "gameNode.h"

class gameObjectBase:public gameNode
{
protected:
	float _x, _y;			//��ǥ(�»�)
	int _dur;				//������
	bool _isDelete;			//�����ִ���
	int _currentFrameX;		//������
	int _currentFrameY;		//
	bool _isOn;				//üũ����Ʈ ��������
	bool _isCheck;			//üũ �Ϸ�
	image* _image;			//�̹���
	RECT _rc;				//
	COLORREF _color;		//�ȼ��ڽ� �÷�

public:
	gameObjectBase();
	~gameObjectBase();

	virtual HRESULT init(float x, float y);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void settingObj(float x, float y,int dur, bool isDelete, COLORREF color);
	virtual void durAct();
	virtual void collisionBox();

	inline bool getDelete(){ return _isDelete; }

	inline int getDur() { return _dur; }
	inline void setDur(int decreaseDur) { _dur -= decreaseDur; }

	inline float getX() { return _x; }
	inline float getY() { return _y; }
};

