#pragma once
#include "gameNode.h"
#define HIT_BOX_WIDTH 12
#define HIT_BOX_HEIGHT 25
#define ATTACK_DAMAGE_BOX_WIDTH 10
#define ATTACK_DAMAGE_BOX_HEIGHT 6
#define DOWNATTACK_DAMAGE_BOX_WIDTH 6
#define	DOWNATTACK_DAMAGE_BOX_HEIGHT 10
#define SPEED 4.0f
#define GRAVITY 0.01f
#define JUMPPOWER 0.1f

enum PLAYER_SKILL
{
	SK_NULL,
	SK_FIREBALL
};


enum COLLISIONTYPE
{
	CT_NULL,
	CT_TOP,
	CT_BOTTOM,
	CT_LEFT,
	CT_RIGHT,
	CT_LEFT_BOTTOM,
	CT_RIGHT_BOTTOM
};


enum PLAYERDIRECTION
{
	PD_RIGHT = 1,
	PD_LEFT = -1
};

enum PLAYERSTATE
{
	ONLAND,
	INAIR,
	HANG
};

enum PLAYERACTION
{
	PR_IDLE,
	PR_MOVE,
	PR_ATTACK,
	PR_JUMP,
	PR_ROOTING,
	PR_DAMAGED,
	PR_DIE
};

enum COLLISION_PLAYER //�浹 ���
{
	CP_NULL,
	CP_OBJECT,
	CP_ENEMY,
	CP_GROUND,
	CP_SHOVEL_OBJ,
	CP_SHOVEL_ENEMY

};

enum COLLISION_TB //�浹����(����) ->������
{
	TB_NULL,
	TB_TOP,
	TB_BOTTOM
};

enum COLLISION_LR //�浹����(�¿�) ->������
{
	LR_NULL,
	LR_LEFT,
	LR_RIGHT
};

class playerBase : public gameNode
{
protected : 
	image*				_image;					//�÷��̾� �̹���
	PLAYERDIRECTION		_direction;				//�÷��̾� ����
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
	float				_x, _y;					//�̵���ǥ	
	float				_jumpPower;				//�����Ŀ�
	float				_gravity;				//�߷°�
	float				_moveSpeed;				//�̵��ӵ�
	bool				_rtBlock;				//������ ����
	bool				_ltBlock;				//���ʸ���
	bool				_isDamaged;				//�¾Ҵ���
	bool				_skillUsed;				//��ų�ߵ��ߴ���
	bool				_isDead;				//�׾���?
	int					probeY;

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
	inline void setPlayerState(PLAYERDIRECTION pd, PLAYERSTATE ps, PLAYERACTION pa, COLLISION_PLAYER cp, COLLISIONTYPE ct)
	{
		_direction = pd;
		_state = ps;
		_action = pa;
		_cPlayerTarget = cp;
		_cType = ct;
	}

	inline RECT getPlayerRc() { return _rc; }
	inline void setPlayerRc(RECT rc) { _rc = rc; }
	inline COLLISION_PLAYER getCollisionPlayer() { return _cPlayerTarget; }
	
};

