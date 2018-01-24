#pragma once
#define HIT_BOX_WIDTH 12
#define HIT_BOX_HEIGHT 25
#define ATTACK_DAMAGE_BOX_WIDTH 10
#define ATTACK_DAMAGE_BOX_HEIGHT 6
#define DOWNATTACK_DAMAGE_BOX_WIDTH 6
#define	DOWNATTACK_DAMAGE_BOX_HEIGHT 10

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
	ROOTING,
	DAMAGED,
	DIE
};

enum COLLISION_PLAYER
{
	CP_NULL,
	CP_OBJECT,
	CP_ENEMY_SIDE,
	CP_ENEMY_TOP
};



class playerBase
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
	bool				_rtBlock;				//������ ����
	bool				_ltBlock;				//���ʸ���
	bool				_isDamaged;				//�¾Ҵ���
	bool				_skillUsed;				//��ų�ߵ��ߴ���
	bool				_isDead;				//�׾���?

public:
	playerBase();
	~playerBase();

	virtual HRESULT init(float startX, float startY, string imageName);
	virtual void release();
	virtual void update();
	virtual void render();

	void hitReAction(int num);
	void attack(float fireX, float fireY, bool skillUsed);



	inline int	getMaxHP() { return _maxHP; }
	inline void setMaxHP(int increaseHP) { _maxHP += increaseHP; }
	inline int	getMaxMP() { return _maxMP; }
	inline void setMaxMP(int increaseMP) { _maxMP += increaseMP; }
	inline int	getMoney() { return _money; }
	inline void setMoney(int increaseMoney) { _money += increaseMoney; }


	inline RECT getPlayerRc() { return _rc; }
	inline COLLISION_PLAYER getCollisionPlayer() { return _cp; }

};

