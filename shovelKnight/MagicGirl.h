#pragma once
#include "npcBase.h"

//��ų �ִ¾�
//======magicGirl���======================= 
//1. ��ų�Ǹ� ��� -> �÷��̾� ��ų �߰� -> ��ų�Ŵ������� false���� true�� �ٲ���
//2. ��ų ù����(���̾-��Ī) 1000, �ι��� ����(������Ʈ-��Ī)3000, ������ ���� (���׿�-��Ī) 6000
//3. �÷��̾�� ��ȣ�ۿ����� �������� ��Ʈ�� �÷��̾� ��Ʈ�� �浹������ (InterSectRect ���) W Ű ������ ��ȭ�ϴ� ������ ��ȣ�ۿ�
//3-1. _player->getRect()�� ���� ��Ʈ�� �޾ƿ� ��ȣ�ۿ��� ���� ��Ʈ�� �޾ƿ���, _player->getMoeny�� ���� ���� �޾ƿ´�.(�÷��̾�Ŵ���)
//3-2. getMoney�� ���� ���� �÷��̾��� ���� ���� �����Ǹ�ǰ�� ������ �� �Ѵ�.
//3-3. ���� �����ϸ� ������ ���� �ǻ� Ȯ��
//3-4. �����ǻ� Ȯ���� -> ��� ���� 
//3-5. setFireBall()����� ���Լ��� ���� false���� true�� �ٲ��ش�.
//3-6. stock()�Լ��� ���� ����Ƚ�� +1 -> ����Ƚ�� ������ ������ ù��° �ι�° ����° ��������. 
//3-7. ����Ƚ���� ���� ���� �÷��̾��� ���Ž�ų ��ȭ 
//3-8. ���� ���� �����ϸ� [�θ���� �Ⱥ�]�� ������ ��ȭ ���̾�α� ����.
//4. [�̽��Ϳ���] ���ʹ����� ó�� ���� �÷��̾ ������ 3�� ������ ġ�� 
// ������ 3ȸ �ǰ��� "������ ������" �ָ��� ����� ����� 

class MagicGirl :
	public npcBase
{
public:
	MagicGirl();
	~MagicGirl();
	virtual HRESULT init();
	virtual void render();
	virtual void draw();
	virtual void update();

	//==========���� ���� ����===========//
	int _fireBallPrice;								//�󸶿� �Ȱ��� ���� ���ÿ�
	int _thunderBoltPrice;							//�����Ʈ �󸶴�
	int _bubblePrice;								//����ų �󸶴�
	int _idx;										//���ͻ��� �ε���
	//==========�ȷȴ��� Ȯ�ο� ������==========//
	int _stock;										//����̳� �������� �����ߴ��� Ȯ�� ����
	bool _isSellFireBall;							//���̾ �ȷȴ���
	bool _isSellThunderBolt;						//�����Ʈ �ȷȴ���
	bool _isSellBubble;								//����ų �ȷȴ���
	//bool _isCollisionNpc;								//NPC�� �浹
	bool _textOut;									//�ؽ�Ʈ �ƿ� �׽�Ʈ��
	int _count;										//ī��Ʈ üũ��
	//==========��ų ����� ���� �Լ�===============//
	void sellSkill();								//��ų �Ĵ� �Լ� 
	void stockCount();								//���忡 ���� �Ǹ��ϴ� ��ų ���� �Լ�
	void magicGirlImageControl();							//npc�̹��� ��Ʈ�� �Լ�

	virtual void isCollision(bool collision);
	
	//virtual void render();
	//virtual void draw();

};

