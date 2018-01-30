#pragma once
#include "gameNode.h"

enum NPCTYPE			//NPC Ÿ��
{
	MAGICGIRL,			//��������
	HEALTYGUY,			//ü�»���
	BARDKNIGHT,			//���ǻ���
	ENDNPCTYPE
};


enum NPCSTATUS			//NPC ����
{
	NPCIDLE,				//������
	NPCTALK,				//��ȭ����(�÷��̾�� ��ȣ����)
	NPCUNDERATTACKED,		//���ݴ��ϴ� ����(�÷��̾ ����������)//�̽��Ϳ��׷� ���߿� ������.
	ENDNPCSTATUS
};
//==========================NPC�� � ����� �־�� �ұ� ����� ��������ϴ�.==============================
//1. npcŸ��
//2. npc����
//3. npc�̹��� ���� 
//4. npc��ȭ ���̾�α�
//5. npc��ȭ �� ���� ���� ��� 
//======healthGuy���======================= 
//5-1. ���� ��� -> �÷��̾� �ִ�ü���� �÷��ִ� �߰�� -> �÷��̾��� �ִ�ü�� ������ �޾ƿͼ� +1 �������
//5-2. �߰�� �����ϸ� ��� ����. ó���� 1000��� , �ι�°�� 4500���, 3��°�� 10000���
//======magicgirl���=======================
//5-3. ���̾ ��ų -> �÷��̾� ��ų���� �� �۾����� fireball ��ų ����
//5-4. �������� ���̾� ���� �����ϸ� ��Ʈ�������� fireball�� �÷��̾�� ����
//6. �̽��Ϳ��� - ���ʹ�����ó�� ���� �÷��̾ ���ο��� ���ݽ� 3������ �ǰݴ��ϸ� 3ȸ ���Ŀ��� "������ �����" �ϰ� ������� ���
//7. �̰� ��� ��������.....


class npcBase : public gameNode
{
protected:
	image* _img;			// NPC �̹���
	image* _img2;			// NPC �̹���2
	string _imgKeyString;	//�̹��� �Ŵ����� ����� �̹��� Ű��
	char* _imgFileName;		//�̹��� ���� �̸�(��� ����)
	animation* _anim;		//NPC �ִϸ��̼�
	animation* _anim2;		//npc �̸ֹ��̼�2

	float _x, _y;			//������ǥ
	int _width, _height;	//�浹 ��Ʈ�� ���� �� �� ���� ���� ũ��
	
	RECT _rc;				//����NPC ��Ʈ
	NPCTYPE _npcType;		//NPCŸ��
	NPCSTATUS _npcStatus;	//npc�������ͽ�

	bool _isCollisionNpc;		//�÷��̾�� �浹�ߴ°�? true : �׷���, false : �ƴϴ�
	bool _isAppear;			//�����Ҷ���? �ƴϴ�? (�ʿ��� �����ϴ��� �ƴ��� üũ)


	int _stock;				//��� �����ߴ��� Ȯ���ϴ� ����
	bool _buyYesorNo;		//���� �������� �췡����?
	bool _isReturn;			//���� ��������

	//===============���̾�α� ����==================//
	image* _testScript;		
	image* _testScript1;
	image* _testScript2;
	image* _testScript3;
	image* _testScript4;
	image* _testScript5;


	//===========���̾�α׿� ���� ����===============//
	typedef vector<string> vDialog;
	typedef vector<string>::iterator viDialog;

	vDialog _vDialog;									//npc����
	viDialog _viDialog;									//npc�������ͷ�����

public:
	npcBase();
	~npcBase();

	//virtual HRESULT init(string imgKeyString, char* imgFileNmae, float x, float y, int totalWidth, int totalHeight, int frameXx, int frameY, NPCTYPE npctype);
	virtual HRESULT init();
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

	//NPCŸ�� ����
	inline NPCTYPE getNpcType() { return _npcType; }

	//���庯�� ���� (��������Ƚ��)
	inline int getStock() { return _stock; }
	void setStock(int stock) { _stock = stock; }

	//���庯�� ���Լ� 
	inline void setAppear(bool isAppear) { _isAppear = isAppear; }

	//�浹�߳� ���Լ�
	//void setIsCollision(bool isCollision) { _isCollisionNpc = isCollision; }

	virtual void isCollision(bool collision) = 0;
	bool getIsCollisionNPC() { return _isCollisionNpc; }


	//===========================================�����մϴ�========================================

	int _skillUnlockLv;
	int getSkillUnlockLv() { return _skillUnlockLv; }
	void setSkillUnlockLv(int asd) { _skillUnlockLv = asd; }


	int _money;
	void setMoney(int asd) { _money = asd; }

	//������
	int _minusMoney;
	int getMinusMoney() { return _minusMoney; }
	void setMinusMoney(int minusMoney) { _minusMoney = minusMoney; }


	//ü�»��ο� ü�°ټ�
	int _setMaxHp;
	void setMaxHp(int setMaxHp) { _setMaxHp = setMaxHp; }
	int getMaxHp() { return _setMaxHp; }

	


	//==================================== End ���� ���� �ۼ��ϱ�===================================
};

