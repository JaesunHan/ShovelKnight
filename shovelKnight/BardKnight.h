#pragma once
#include "npcBase.h"

//�ٵ峪��Ʈ -fmod�� ������ ��ƺ���
//======�ٵ峪��Ʈ���======================= 
//1. ������ ���� ��� 
//2. 100���� ����ϸ� �������-> 1�а� ��������� �ٸ� �������� �ٲ�
//3. 1000���� ����ϸ� �⺻ ���� ���� ȿ������ �ٲ� (Ÿ ���� ȿ�������� ex ��Ż������ ���ӽŰ�)
//3-1.fmod ����Ʈ ����� ����� ����(����Ŵ���?)�� �ٲ���. 
//3-2. getMoney�� ���� ���� �÷��̾��� ���� ���� �����Ǹ�ǰ�� ������ �� �Ѵ�.
//3-3. ���� �����ϸ� ������ ���� �ǻ� Ȯ��
//3-4. �����ǻ� Ȯ���� -> ��� ���� 
//3-5. fmod �Լ����� ��ȣ����Լ��� ���� �뷡 ������ ���غ���.
//4. [�̽��Ϳ���] ���ʹ����� ó�� ���� �÷��̾ ������ 3�� ������ ġ�� 
// ������ 3ȸ �ǰ��� "������ ������" �ָ��� ����� ����� 



class BardKnight :
	public npcBase
{
public:
	BardKnight();
	~BardKnight();



	//==========���� ���� ����===========//
	int _bgmPrice;									//����� ����
	int _effectSoundPrice;							//����Ʈ ���� ����  -> ���� ���常 
	int _idx;										//���ͻ��� �ε���
	

	//==========�ȷȴ��� Ȯ�ο� ������==========//
	int _stock;										//����̳� �������� �����ߴ��� Ȯ�� ����
	bool _isSellBgm;								//��� �ȷȴ���
	bool _isSellEffectSound;						//����Ʈ ���� �ȷȴ���
	//bool _isCollisionNpc;								//NPC�� �浹
	bool _isChange;						
	bool _textOut;									//�ؽ�Ʈ �ƿ� �׽�Ʈ��
	//==========��ų ����� ���� �Լ�===============//
	void changeBGM();								//��ų �Ĵ� �Լ�
	void changeEffectSound();
	virtual HRESULT init();
	virtual void render();
	virtual void draw();
	virtual void update();
	void bardKnightImageControl();

	virtual void isCollision(bool collision);
	void soundChange();
	
};

