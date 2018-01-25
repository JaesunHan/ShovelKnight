#pragma once

#define BUFFER 128

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
	float getDistancePoint(POINT ptStart, POINT ptEnd);

	//FPT������ ����
	float getAnglePoint(POINT pt1, POINT pt2);

	//FPT������ �Ÿ�
	float getDistanceFPoint(FPOINT ptStart, FPOINT ptEnd);

	//FPT������ ����
	float getAngleFPoint(FPOINT pt1, FPOINT pt2);

	//FPT�� ���ȿ� ������
	BOOL PtInEll(RECT rc, FPOINT pt);

	BOOL PtinEll(RECT rc, POINT pt);

	//FPT�� �׸�ȿ� ������
	BOOL PtInRect(RECT rc, FPOINT pt);

	//FPT ����� ��ũ��
	FPOINT FPointMake(float x, float y);

	//��Ʈ left top�� FPT�� �����
	POINT PointMakeRect(RECT rc);

	//��Ʈ �߽ɿ� FPT�� �����
	POINT PointMakeRectCenter(RECT rc);

	//��Ʈ left top�� FPT�� �����
	FPOINT FPointMakeRect(RECT rc);

	//��Ʈ �߽ɿ� FPT�� �����
	FPOINT FPointMakeRectCenter(RECT rc);

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

	void PtMoveAngleSpeed(FPOINT& pt, float angle, float speed);

	void XYMoveAngleSpeed(float& x, float& y, float angle, float speed);

	// hdc, x��ǥ, y��ǥ, ǥ�����ؽ�Ʈ"", ǥ���Ұ�, ���ǥ�ÿ���		":"�� �ڵ����� ����
	void TTTextOut(HDC hdc, int x, int y, string str, int num, BOOL backGround = FALSE);

	//�ֿܼ�(float)
	void TTTextOut(string stri, float f);

	//�ֿܼ�(int)
	void TTTextOut(string stri, int d);

	//x, y �ȼ��� ��������?
	BOOL ThisPixelIsMazen(HDC hdc, int x, int y);

	//�� color�� ��������?
	BOOL ThisPixelIsMazen(COLORREF color);

	char* PTSTR_To_String(string str);
}

