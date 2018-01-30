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
	ENEMY_LEFT_SMILE,
	ENEMY_RIGHT_SMILE,
	ENEMY_LEFT_MOVE,
	ENEMY_RIGHT_MOVE,
	ENEMY_LEFT_BACK_MOVE,
	ENEMY_RIGHT_BACK_MOVE,
	ENEMY_LEFT_JUMP,
	ENEMY_RIGHT_JUMP,
	ENEMY_LEFT_ATTACK,
	ENEMY_RIGHT_ATTACK,
	ENEMY_LEFT_JUMP_ATTACK,
	ENEMY_RIGHT_JUMP_ATTACK,
	ENEMY_LEFT_FIRE_ATTACK,
	ENEMY_RIGHT_FIRE_ATTACK,
	ENEMY_LEFT_HIT,
	ENEMY_RIGHT_HIT,
	ENEMY_LEFT_DEAD,
	ENEMY_RIGHT_DEAD,
	ENEMY_LEFT_JUMP_DEAD,
	ENEMY_RIGHT_JUMP_DEAD
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

enum PATTERNTYPE
{
	ENEMY_BASIC,
	ENEMY_PATROL,
	ENEMY_LEFT_FOWARD,
	ENEMY_RIGHT_FOWARD
};

class enemyBase : public gameNode
{
protected:
	image * _img;					//����� �̹���
	animation* _anim;				//����� �ִϸ��̼�
	string _imgKeyString;			//�̹��� �Ŵ����� ����� �̹��� Ű��

	ENEMYSTATUS _status;			//���ʹ� ����
	ENEMYSTATUS _previousStatus;    //���ʹ� ��������
	ENEMYTYPE _enemyType;			//���ʹ�Ÿ��

	RECT _attackRect;               //���� ��Ʈ
	RECT _rc;						//Ȥ�� ����ϰԵ����� �� ��Ʈ(�浹��)
	RECT _ImageRc;                  //����1�̹�����Ʈ
	RECT _trunkRc;                  //����1�浹��Ʈ: ����

	char* _imgFileName;				//�̹��� ���� �̸�(��� ����)
	float _x, _y;					//���� ������ǥ
	float _gravity;					//������ �߷�
	int _width, _height;			//���� ����, ���� ũ��(��Ʈ�� ���� �� ����� ���μ���ũ���̴�.)
	float _angle;					//�̵� ����
	int _enemyHp;					//�� ü��
	float _speed;					//�� ���ǵ�
	bool _direction;				//�� ����

	float _getPlayerX;				//�÷��̾� x��ǥ get
	int _playerStatus;				//�÷��̾� ����
	bool _playerFind;				//�÷��̾� �߰�

	bool _isDead;					//�׾����� ����
	bool _isDeadVanish;				//�װ� ���Ϳ��� ���� �Ұ�
	int _vanishTime;				//�׾����� ��������� ����Ÿ�� ī��Ʈ

	bool _isJump;					//��������
	int _jumpCount;					//����ī��Ʈ

	int _directionCount;			//������ȯ ī��Ʈ
	bool _isCountStop;				//����ī��Ʈ ����

	bool _isAttack;					//attack ����
	bool _isHit;					//�÷��̾� ���� �浹
	bool _isHitDelayTime;           //hit �����ð� �Ұ�
	int _delayCount;                //hit �����ð� ī��Ʈ

	int _patternTypeNum;            //����Ÿ��
	int _frameCount;                //���º� ������ ī��Ʈ

	bool _isDialogueEnd;
	bool _isAniPlayEnd;
	int _patternTrun;
	int _patternCount;
	bool _isFight;

	

	jump* _jump;					//�׼�: ����
	pixelCollision* _pixelC;		//�׼�: �ȼ��浹

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
	virtual HRESULT init(float x, float y, int patternType) = 0;
	virtual void enemyInitSet() = 0;
	virtual void enemyPattern(int _patternTypeNum) = 0;
	virtual void move() = 0;
	virtual void attackCollisionRect();

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
	int getEnemyHp() { return _enemyHp; }
	void setEnemyDamage() { _isHit = true; }

	//�浹��Ʈ ����
	RECT getBoss1TrunkRect() { return _trunkRc; }  //���뷺Ʈ

	//==================================== End ���� ���� �ۼ��ϱ�===================================


};

