#pragma once
#include "gameNode.h"
#define HIT_BOX_WIDTH 12
#define HIT_BOX_HEIGHT 25
#define ATTACK_DAMAGE_BOX_WIDTH 10
#define ATTACK_DAMAGE_BOX_HEIGHT 6
#define DOWNATTACK_DAMAGE_BOX_WIDTH 6
#define	DOWNATTACK_DAMAGE_BOX_HEIGHT 10
#define SPEED 4.0f
#define GRAVITY 0.2f
#define JUMPPOWER 6.0f

enum PLAYERDIRECTION
{
	RIGHT = 1,
	LEFT = -1
};

enum PLAYERSTATE
{
	ONLAND,
	INAIR,
	HANG
};

enum PLAYERACTION
{
	IDLE,
	MOVE,
	ATTACK,
	JUMP,
	ROOTING,
	DAMAGED,
	DIE
};

enum COLLISION_PLAYER
{
	CP_NULL,
	CP_OBJECT,
	CP_PLAYER_ENEMY_LEFT,
	CP_PLAYER_ENEMY_RIGHT,
	CP_PLAYER_
};



class playerBase : public gameNode
{
protected : 
	image*				_image;					//�÷��̾� �̹���
	PLAYERDIRECTION		_direction;				//�÷��̾� ����
	PLAYERSTATE			_state;					//�÷��̾� ��ġ
	PLAYERACTION		_action;				//�÷��̾� ����
	COLLISION_PLAYER	_cp;					//�÷��̾� �浹
	RECT				_rc;					//�÷��̾� ��Ʈ(�浹��Ʈ)
	int					_frameCount;			//������ī��Ʈ
	int					_currentFrameX;			//
	int					_currentFrameY;			//
	int					_currentHP;				//���� ü��
	int					_maxHP;					//�ִ� ü��
	int					_currentMP;				//���� ����
	int					_money;					//�����ݾ�
	int					_maxMP;					//�ִ� ����
	int					_skill;					//��ų�ѹ�
	int					_alpha;					//���İ�
	float				_x, _y;					//�̵���ǥ	
	float				_jumpPower;				//�����Ŀ�
	float				_gravity;				//�߷°�
	float				_moveSpeed;				//�̵��ӵ�
	bool				_rtBlock;				//������ ����
	bool				_ltBlock;				//���ʸ���
	bool				_isDamaged;				//�¾Ҵ���
	bool				_skillUsed;				//��ų�ߵ��ߴ���
	bool				_isDead;				//�׾���?

public:
	playerBase();
	~playerBase();

	virtual HRESULT init(float startX, float startY);
	virtual void release();
	virtual void update();
	virtual void render();

	void hitReAction(int num);
	void attack(float fireX, float fireY, bool skillUsed);
	void move();

	inline float getX() { return _x; }
	inline void setX(float x) { _x = x; }
	inline float getY() { return _y; }
	inline void setY(float y) { _y = y; }
	inline int	getMaxHP() { return _maxHP; }
	inline void setMaxHP(int increaseHP) { _maxHP += increaseHP; }
	inline int	getMaxMP() { return _maxMP; }
	inline void setMaxMP(int increaseMP) { _maxMP += increaseMP; }
	inline int	getMoney() { return _money; }
	inline void setMoney(int increaseMoney) { _money += increaseMoney; }


	inline RECT getPlayerRc() { return _rc; }
	inline COLLISION_PLAYER getCollisionPlayer() { return _cp; }
};

