#pragma once
class itemBase
{
protected:
	image * _img;				//������ �̹���
	string _imgKeyString;		//�̹����Ŵ����� ����� �̹��� Ű��
	char* _imgFileName;			//������ �̹��� ����(��� ����)

	float _x, _y;				//���� ��ǥ
	float _jumpPower;			//�������� ����ɶ� ���� �پ�ö��ٰ� ������
	float _itemGravity;			//�׷��ٸ� �߷��� ����Ǿ�� �����?
	int _width, _height;		//������ �浹 ��Ʈ �׸� �� �� ���μ��� ũ��

	RECT _rc;					//������ �浹 ��Ʈ

public:
	itemBase();
	~itemBase();

	virtual HRESULT init(string imgKeyString, char* imgFileName, float x, float y, int totalWidth, int totalHeight, int frameX, int frameY);
	virtual void update();
	virtual void release();
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
	//�����Ŀ� ���� ����
	inline float getJumpPower() { return _jumpPower; }	inline void setJumpPower(float jp) { _jumpPower = jp; }

	//��Ʈ ����
	inline RECT getRect() { return _rc; }
	//==================================== End ���� ���� �ۼ��ϱ�===================================
};

