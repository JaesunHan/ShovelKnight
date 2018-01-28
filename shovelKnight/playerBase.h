#pragma once
#include "gameNode.h"
#define HIT_BOX_WIDTH 12
#define HIT_BOX_HEIGHT 25
#define ATTACK_DAMAGE_BOX_WIDTH 10
#define ATTACK_DAMAGE_BOX_HEIGHT 6
#define DOWNATTACK_DAMAGE_BOX_WIDTH 6
#define	DOWNATTACK_DAMAGE_BOX_HEIGHT 10
#define ACCELERATION 0.5f
#define MAXSPEED 1.5f
#define TIMECOUNT 0.07f
#define MAXATTITUDE 35
#define GRAVITY 0.1f
#define JUMPPOWER 3.0f
#define friction 0.5f
#define DELAYTIME 0.3f

enum PLAYER_SKILL
{
	SK_NULL,
	SK_FIREBALL
};


enum COLLISIONTYPE
{
	COLLISIONTYPE_NULL,
	COLLISIONTYPE_TOP,
	COLLISIONTYPE_BOTTOM,
	COLLISIONTYPE_LEFT,
	COLLISIONTYPE_RIGHT,
	COLLISIONTYPE_LEFT_BOTTOM,
	COLLISIONTYPE_RIGHT_BOTTOM
};


enum PLAYERDIRECTION
{
	PLAYERDIRECTION_RIGHT = 1,
	PLAYERDIRECTION_LEFT = -1
};
enum PLAYERDIRECTIONTB
{
	PLAYERDIRECTION_TOP = -1, 
	PLAYERDIRECTION_BOTTOM = 1
};

enum PLAYERSTATE
{
	PLAYERSTATE_ONLAND,
	PLAYERSTATE_INAIR,
	PLAYERSTATE_HANG
};

enum PLAYERACTION
{
	PLAYERACTION_IDLE,
	PLAYERACTION_MOVE,
	PLAYERACTION_ATTACK,
	PLAYERACTION_DOWNATTACK,
	PLAYERACTION_JUMP,
	PLAYERACTION_ROOTING,
	PLAYERACTION_DAMAGED,
	PLAYERACTION_DIE
};

enum COLLISION_PLAYER //�浹 ���
{
	COLLISION_PLAYER_NULL,
	COLLISION_PLAYER_OBJECT,
	COLLISION_PLAYER_ENEMY,
	COLLISION_PLAYER_GROUND,
	COLLISION_PLAYER_SHOVEL_OBJ,
	COLLISION_PLAYER_SHOVEL_ENEMY
};

enum COLLISION_TB //�浹����(����) ->������
{
	COLLISION_TB_NULL,
	COLLISION_TB_TOP,
	COLLISION_TB_BOTTOM
};

enum COLLISION_LR //�浹����(�¿�) ->������
{
	COLLISION_LR_NULL,
	COLLISION_LR_LEFT,
	COLLISION_LR_RIGHT
};

class playerBase : public gameNode
{
protected:
	image * _image;					//�÷��̾� �̹���
	PLAYERDIRECTION		_direction;				//�÷��̾� ����
	PLAYERDIRECTIONTB	_directionTB;			//
	PLAYERSTATE			_state;					//�÷��̾� ��ġ
	PLAYERACTION		_action;				//�÷��̾� ����
	COLLISION_PLAYER	_cPlayerTarget;			//�÷��̾� �浹
	COLLISION_TB		_cTB;					//�÷��̾� �浹����
	COLLISION_LR		_cLR;					//�÷��̾� �浹����
	COLLISIONTYPE		_cType;
	RECT				_rc;					//�÷��̾� ��Ʈ(�浹��Ʈ)
	char*				_characterName;			//ĳ���� ����
	int					_jumpCount;				//����ī��Ʈ
	int					_frameCount;			//������ī��Ʈ
	int					_currentFrameX;			//
	int					_currentFrameY;			//
	int					_currentSkill;			//���� ������ ��ų
	int					_skillUnlockLv;			//��ų �ر� �ܰ�
	int					_currentHP;				//���� ü��
	int					_maxHP;					//�ִ� ü��
	int					_currentMP;				//���� ����
	int					_money;					//�����ݾ�
	int					_maxMP;					//�ִ� ����
	int					_skill;					//��ų�ѹ�
	int					_alpha;					//���İ�
	float				_time;
	float				_startY;
	float				_x, _y;					//�̵���ǥ	
	float				_jumpPower;				//�����Ŀ�
	float				_gravity;				//�߷°�
	float				_moveSpeed;				//�̵��ӵ�
	float				_delay;
	bool				_rtBlock;				//������ ����
	bool				_ltBlock;				//���ʸ���
	bool				_isDamaged;				//�¾Ҵ���
	bool				_isJumping;
	bool				_skillUsed;				//��ų�ߵ��ߴ���
	bool				_isDead;				//�׾���?
	bool				_maxAti;
	float				probeY;

public:
	playerBase();
	~playerBase();

	virtual HRESULT init(float startX, float startY);
	virtual void release();
	virtual void update();
	virtual void render();

	void hitReAction();
	void attack(float fireX, float fireY, bool skillUsed);
	void move();
	void imageSetting();
	void collision();


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
	inline char* getName() { return _characterName; }
	inline void setName(char* name) { _characterName = name; }
	inline int getSkillUnlockLv() { return _skillUnlockLv; }
	inline void setSkillUnlockLv(int increaseLv) { _skillUnlockLv += increaseLv; }
	inline PLAYERSTATE getState() { return _state; }
	inline void setState(PLAYERSTATE state) { _state = state; }
	inline PLAYERACTION getAction() { return _action; }
	inline void setAction(PLAYERACTION action) { _action = action; }
	inline float getJumpPower() { return _jumpPower; }
	inline void setJumpPower(float jumpPower) { _jumpPower = jumpPower; }


	inline RECT getPlayerRc() { return _rc; }
	inline void setPlayerRc(RECT rc) { _rc = rc; }
	inline COLLISION_PLAYER getCollisionPlayer() { return _cPlayerTarget; }
	
};

