#pragma once
#include "gameNode.h"
#include "jump.h"
#include "pixelCollision.h"

#define GRAVITY	0.9f

//���ʹ��� ���´� �� �κ� ���� ����� �����!
enum ENEMYSTATUS
{
	ENEMY_LEFT_IDLE,
	ENEMY_RIGHT_IDLE,
	ENEMY_LEFT_MOVE,
	ENEMY_RIGHT_MOVE,
	ENEMY_LEFT_BACK_MOVE,
	ENEMY_LEFT_JUMP,
	ENEMY_RIGHT_JUMP,
	ENEMY_LEFT_ATTACK,
	ENEMY_RIGHT_ATTACK,
	ENEMY_LEFT_JUMP_ATTACK,
	ENEMY_RIGHT_JUMP_ATTACK,
	ENEMY_LEFT_HIT,
	ENEMY_RIGHT_HIT,
	ENEMY_LEFT_DEAD,
	ENEMY_RIGHT_DEAD
};

enum ENEMYTYPE
{
	ENEMY_BEETO,
	ENEMY_BLORB,
	ELEMY_DRAKE,
	ENEMY_SKELETON,
	ENEMY_DRAGON,
	ENEMY_BLACKKNIGHT
};


class enemyBase : public gameNode
{
protected:
	image * _img;				//����� �̹���
	animation* _anim;			//����� �ִϸ��̼�
	string _imgKeyString;		//�̹��� �Ŵ����� ����� �̹��� Ű��

	ENEMYSTATUS _status;		//���ʹ� ����


	char* _imgFileName;			//�̹��� ���� �̸�(��� ����)
	float _x, _y;				//���� ������ǥ
	float _gravity;				//������ �߷�
	int _width, _height;		//���� ����, ���� ũ��(��Ʈ�� ���� �� ����� ���μ���ũ���̴�.)
	float _angle;               //�̵� ����

	float _getPlayerX;             //�÷��̾� x��ǥ get
	int _playerStatus;          //�÷��̾� ����
	float _speed;				//���ǵ�
	bool _isDead;				//�׾����� ����
	bool _isDeadVanish;			//�װ� ���Ϳ��� ���� �Ұ�
	int _vanishTime;			//�׾����� ��������� ����Ÿ�� ī��Ʈ
	bool _direction;            //����
	bool _isJump;               //��������
	int _jumpCount;             //����ī��Ʈ
	int _directionCount;        //������ȯ ī��Ʈ
	bool _isHit;                //�÷��̾� ���� �浹
	int _enemyHp;               //�� ü��

	ENEMYTYPE _enemyType;       //���ʹ�Ÿ��


	RECT _rc;					//Ȥ�� ����ϰԵ����� �� ��Ʈ(�浹��)

	jump* _jump;                //�׼�: ����
	pixelCollision* _pixelC;    //�׼�: �ȼ��浹

public:
	enemyBase();
	~enemyBase();

	//					�̹����Ŵ����� ����� Ű��, ���� �̸�,		����� �ʱ� ��ġ x,y
	virtual HRESULT init(string imgKeyString, char* imgFileName, float x, float y, int totalWidth, int totalHeight, int frameX, int frameY);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void draw();

	virtual HRESULT init(float x, float y) = 0;
	virtual void move() = 0;
	bool isPlayerFind(float enemyX, int distance);

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
	/*inline float getJumpPower() { return _jumpPower; }	inline void setJumpPower(float jp) { _jumpPower = jp; }*/

	//��Ʈ ����
	inline RECT getRect() { return _rc; }

	//�� ���� ������ & ������
	ENEMYSTATUS getStatus() { return _status; }   	
	void setStatus(ENEMYSTATUS status) { _status = status; }
	bool getIsDeadVanish() { return _isDeadVanish; }					//�װ� ������� �Ұ�
	ENEMYTYPE getEnemyType() { return _enemyType; }						//���׹�Ÿ��

	//�÷��̾� ���� ������
	void getPlayerX(float playerX) { _getPlayerX = playerX; }			//�÷��̾� X    get
	void getPlayerStatus(int status) { _playerStatus = status; }        //�÷��̾� ���� get

	//������ ������
	void setEnemyDamage(bool damage) { _isHit = damage; }

	//==================================== End ���� ���� �ۼ��ϱ�===================================


};

