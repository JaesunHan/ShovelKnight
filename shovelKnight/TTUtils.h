#pragma once

#define MAPSIZEX 2982.f
#define MAPSIZEY 1687.f

#define SEC 72.f

#define SMALLX		WINSIZEX / MAPSIZEX 
#define SMALLY		WINSIZEY / MAPSIZEY 
#define BIGX		MAPSIZEX / WINSIZEX 
#define BIGY		MAPSIZEY / WINSIZEY

#define MAZEN COLORREF RGB(255,0,255)


namespace Ʈ��������
{
	typedef struct tagFloatPoint
	{
		float x;
		float y;
	} FPOINT;

	//��+�׸� �浹
	BOOL isCollisionEllRect(RECT& rcEll, RECT& rcRect);

	//��+�� �浹
	BOOL isCollisionEllEll(RECT& rcEll1, RECT& rcEll2);

	//FPT������ �Ÿ�
	float getDistancePoint(FPOINT ptStart, FPOINT ptEnd);

	//FPT������ ����
	float getAnglePoint(FPOINT pt1, FPOINT pt2);

	//FPT�� ���ȿ� ������
	BOOL PtInEll(RECT rc, FPOINT pt);

	//FPT�� �׸�ȿ� ������
	BOOL PtInRc(RECT rc, FPOINT pt);

	//FPT ����� ��ũ��
	FPOINT FPointMake(float x, float y);

	//��Ʈ left top�� FPT�� �����
	FPOINT PointMakeRect(RECT rc);

	//��Ʈ �߽ɿ� FPT�� �����
	FPOINT PointMakeRectCenter(RECT rc);

	//
	RECT RectMakePoint(FPOINT pt, float width, float height);

	RECT RectMakePointCenter(POINT pt, float width, float height);

	void RectangleMakeRect(HDC hdc, RECT rc);

	void EllipseMakeRect(HDC hdc, RECT rc);

	//��Ʈ ũ�� �޾ƿ���
	float getRectWidth(RECT rc);

	float getRectHeight(RECT rc);


	//Pt, width, height�� ��Ʈ left top �޾ƿ���

	//left
	float getRectLeft(FPOINT pt, float width);

	//top
	float getRectTop(FPOINT pt, float height);

	//FPOINT left top
	FPOINT getRectLeftTop(FPOINT pt, float width, float height);


	void PtMoveAngleSpeed(FPOINT& pt, float& angle, float& speed);

	void XYMoveAngleSpeed(float& x, float& y, float& angle, float& speed);

	// hdc, x��ǥ, y��ǥ, ǥ�����ؽ�Ʈ"", ǥ���Ұ�, ���ǥ�ÿ���		":"�� �ڵ����� ����
	void TTTextOut(HDC hdc, int x, int y, char* stri, float f, bool backGround);

	//x, y �ȼ��� ��������?
	BOOL ThisPixelIsMazen(HDC hdc, int x, int y);

	RECT RectMakeSmall(RECT rc);

	inline RECT RectMakeBig(RECT rc);

	inline FPOINT PointMakeSmall(FPOINT pt);

	inline FPOINT PointMakeBig(FPOINT pt);
}

