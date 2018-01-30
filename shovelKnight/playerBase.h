#pragma once
#include "gameNode.h"
#define HIT_BOX_WIDTH 12
#define HIT_BOX_HEIGHT 25
#define ATTACK_DAMAGE_BOX_WIDTH 10
#define ATTACK_DAMAGE_BOX_HEIGHT 6
#define DOWNATTACK_DAMAGE_BOX_WIDTH 6
#define	DOWNATTACK_DAMAGE_BOX_HEIGHT 10
#define SPEED 1.7f
#define GRAVITY 0.2f
#define JUMPPOWER 3.0f

enum PLAYER_SKILL
{
	SK_NULL,
	SK_FIREBALL
};

enum PLAYERDIRECTION
{
	RIGHT,
	LEFT
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
	HANGING,
	ROOTING,
	DAMAGED,
	DIE
};

class stageManager;
class gameCollision;
class skillManager;
class gamePlayUI;
class frontObjectManager;

class playerBase : public gameNode
{
protected : 
	PLAYERDIRECTION		_direction;				//�÷��̾� ����
	PLAYERSTATE			_state;					//�÷��̾� ��ġ
	PLAYERACTION		_action;				//�÷��̾� ����
	RECT _playerRC;					
	RECT _attackRC;
	char*				_characterName;			//ĳ���� ����
	int	_frameX = 0;	
	int _shineFrameX = 0;						//������ �־� �T���⸸�� ���� ������
	int _counter = 0;
	int _jumpCounter = 0;
	int _shineCounter = 0;						//������ ���� �����⸸�� ���� ī����
	int _invincibilityCounter = 0;
	int	_currentSkill = 0;			//���� ������ ��ų
	int					_currentHP;				//���� ü��
	int					_maxHP;					//�ִ� ü��
	int					_currentMP;				//���� ����
	int					_maxMP;					//�ִ� ����
	int	_money = 40000;							//�����ݾ�
	int					_skill;					//��ų�ѹ�
	int					_alpha;					//���İ�
	float				_x, _y;					//�̵���ǥ	
	float				_jumpPower;				//�����Ŀ�
	float				_gravity;				//�߷°�
	float				_moveSpeed;				//�̵��ӵ�
	bool _rtBlock = false;				
	bool _ltBlock = false;				
	bool _rtMoving = false;
	bool _ltMoving = false;
	bool _jumpKeyDown = false;
	bool _isAttacking = false;
	bool _downwardThrust = false;
	bool _shine = false;
	bool _pause = false;
	bool _isDamaged = false;				//�¾Ҵ���
	bool				_skillUsed;				//��ų�ߵ��ߴ���
	bool				_isDead;				//�׾���?
	bool _invincibility = false;
	bool _fireBall = false;	//���̾ ��ų

	stageManager* _SM;
	gameCollision* _GC;
	skillManager* _skillM;
	gamePlayUI* _GPU;
	frontObjectManager* _FOM;

public:
	playerBase();
	~playerBase();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void control();
	void physics();
	void pixelCollision();
	void hangPixelDetect();
	bool hangPixelDetectUp();
	void hangPixelDetectDown();
	void frameCounter(float frameMax, float counterMax);
	void invincibilityCount();
	void attackReaction();
	void setDamagePlayer();
	void setPlatformMovementLR(int speed);


	inline float getPlayerX() { return _x; }
	inline void setPlayerX(float x) { _x = x; }
	inline float getPlayerY() { return _y; }
	inline void setPlayerY(float y) { _y = y; }
	inline void setPlayerHp(int maxHp) { _currentHP = maxHp; }
	inline int	getPlayerMaxHP() { return _maxHP; }
	inline void setPlayerMaxHP(int increaseHP) { _maxHP += increaseHP; }
	inline int	getPlayerMaxMP() { return _maxMP; }
	inline void setPlayerMaxMP(int increaseMP) { _maxMP += increaseMP; }
	inline int	getMoney() { return _money; }
	inline void setMoney(int increaseMoney) { _money += increaseMoney; }
	inline char* getName() { return _characterName; }
	inline void setName(char* name) { _characterName = name; }
	inline void setSkillUnlockLv(int skillLv) 
	{ 
		int skillLevel = skillLv; 
		switch (skillLevel)
		{
		case(1):
			_fireBall = true;
			break;
		}
	}
	inline void setSMMemoryAddressLink(stageManager* sm) { _SM = sm; }
	inline void setGameCollisinMemoryAddressLink(gameCollision* gc) { _GC = gc; }
	inline void setSkillManagerMemoryAddressLink(skillManager* skillm) { _skillM = skillm; }
	inline void setGamePlayUIMemoryAddressLink(gamePlayUI* gpu) { _GPU = gpu; }
	inline void setFrontObjectManagerMemoryAddressLink(frontObjectManager* fom) { _FOM = fom; }
	inline void setPause(bool pause) { _pause = pause; }
	inline RECT getPlayerRC() { return _playerRC; }
	inline RECT getAttackRC() { return _attackRC; }
	//IDLE = 0, MOVE = 1, ATTACK = 2, JUMP = 3, ROOTING = 4, DAMAGED = 5, DIE = 6
	inline int getPlayerAction() { return _action; }
	inline void setAttackReaction() 
	{
		if (_downwardThrust == true)
		{
			_jumpPower = 4;
			_jumpCounter = 30;
		}
		else
		{
			if (_direction == RIGHT)
			{
				_x -= 2;
			}
			else if (_direction == LEFT)
			{
				_x += 2;
			}
		}
	}
	
};

