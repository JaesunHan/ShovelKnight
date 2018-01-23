#pragma once
class npcBase
{
protected:
	image* _img;			// NPC �̹���
	string _imgKeyString;	//�̹��� �Ŵ����� ����� �̹��� Ű��
	char* _imgFileName;		//�̹��� ���� �̸�(��� ����)
	animation* _anim;		//NPC �ִϸ��̼�
	float _x, _y;			//������ǥ
	int _width, _height;	//�浹 ��Ʈ�� ���� �� �� ���� ���� ũ��
	
	RECT _rc;				//�浹������ ��Ʈ

	bool _isCollision;		//�÷��̾�� �浹�ߴ°�? true : �׷���, false : �ƴϴ�

public:
	npcBase();
	~npcBase();

	virtual HRESULT init(string imgKeyString, char* imgFileNmae, float x, float y, int totalWidth, int totalHeight, int frameXx, int frameY);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();

	//==================================== Start ���� ���� �ۼ��ϱ�===================================
	//����X ���� ����
	inline float getX() { return _x; }		inline void setX(float x) { _x = x; }
	//����Y ���� ����
	inline float getY() { return _y; }		inline void setY(float y) { _y = y; }
	//����ũ�� ���� ����
	inline int getWidth() { return _width; }	inline void setWidth(int w) { _width = w; }
	//����ũ�� ���� ����
	inline int getHeight() { return _height; }	inline void setHeight(int h) { _height = h; }
	
	//��Ʈ ����
	inline RECT getRect() { return _rc; }
	//==================================== End ���� ���� �ۼ��ϱ�===================================
};

