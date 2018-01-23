#pragma once
#define GRAVITY	0.9f

//���ʹ��� ���´� �� �κ� ���� ����� �����!
enum ENEMYSTATUS
{

};

class enemyBase
{
protected:
	image * _img;			//����� �̹���
	animation* _anim;		//����� �ִϸ��̼�
	string _imgKeyString;	//�̹��� �Ŵ����� ����� �̹��� Ű��

	ENEMYSTATUS _status;	//���ʹ� ����

	char* _imgFileName;		//�̹��� ���� �̸�(��� ����)
	float _x, _y;			//���� ������ǥ
	float _jumpPower;		//���� �Ŀ�
	float _gravity;			//������ �߷�
	int _width, _height;	//���� ����, ���� ũ��(��Ʈ�� ���� �� ����� ���μ���ũ���̴�.)

	RECT _rc;				//Ȥ�� ����ϰԵ����� �� ��Ʈ(�浹��)
	
public:
	enemyBase();
	~enemyBase();

	//					�̹����Ŵ����� ����� Ű��, ���� �̸�,		����� �ʱ� ��ġ x,y
	virtual HRESULT init(string imgKeyString, char* imgFileName, float x, float y, int totalWidth, int totalHeight, int frameX, int frameY);
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
	//�����Ŀ� ���� ����
	inline float getJumpPower() { return _jumpPower; }	inline void setJumpPower(float jp) { _jumpPower = jp; }

	//��Ʈ ����
	inline RECT getRect() { return _rc; }

	//==================================== End ���� ���� �ۼ��ϱ�===================================


};

