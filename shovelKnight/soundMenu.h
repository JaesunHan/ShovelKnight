#pragma once
#include "menuBase.h"

#define selectRect	4

class soundMenu : public menuBase
{
public:


	image* _soundLetter2Box;				//���� 2���ڽ�
	image* _soundLetter4Box;				//���� 3���ڽ�
	image* _soundLetter5Box;				//���� 5���ڽ�
	image* _soundLetter10Box;				//���� 10���ڽ�
	image* _soundLetterBoxEm;				//����ִ� �ڽ�
	image* _soundLetterBoxEm2;				//����ִ� �ڽ�
	image* _soundLetterBoxEm3;				//����ִ� �ڽ�
	image* _soundLetterBoxEm4;				//����ִ� �ڽ�

	
	animation* _soundLetterBoxAni;			//���͹ڽ� �ִ� 2����¥��
	animation* _soundLetterBoxAni2;			//���͹ڽ� �ִ� 3����¥��
	animation* _soundLetterBoxAni3;			//���͹ڽ� �ִ� 5����¥��
	animation* _soundLetterBoxAni4;			//���͹ڽ� �ִ� 10����¥��



	RECT _rcSound[selectRect];				//�ڷ�, ����, ����, ����, �׷���, ������ ������ �����ϱ� ���� ��Ʈ�� ���.
	int _indexSoundRc;						//�ε��� RC

	
	RECT _rcEffectVolume;					//����Ʈ������ ��Ʈ
	RECT _rcEffectVolumeButton;				//����Ʈ������ ��ư ��Ʈ
	RECT _bmgVolume;						//����������� ��Ʈ
	RECT _bgmVolumeButton;					//����������� ��ư ��Ʈ
	image* _effectVolumeButton;				//����Ʈ������ ��ư �̹���
	image* _bgmVolumeButtonimg;				//����������� ��ư �̹���

	int _effectSoundRectButtonX;			//����Ʈ�����ưX��ǥ
	int _bgmSoundRectButtonX;				//���������ưX��ǥ

	float _effectVol;						//����Ʈ ����
	float _bgmVol;							//����� ����

	float _eV;								//����Ʈ ���� ���
	float _bV;								//����� ���� ���

	HRESULT init();
	void update();
	void release();
	void render(HDC hdc);
	void draw(HDC hdc);
	void effectVolumeControl();					//����Ʈ������Ʈ��
	void bgmVolumeControl();					//�����������Ʈ��


	soundMenu();
	~soundMenu();
};

