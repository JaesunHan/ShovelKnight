#include "stdafx.h"
#include "cameraManager.h"


cameraManager::cameraManager()
{
}


cameraManager::~cameraManager()
{

}

HRESULT cameraManager::init(void)
{
	return S_OK;
}

void cameraManager::release(void)
{

}

//������ �Ǵ� ��׶��� ���� (�ϴ�, ����, �� ������)
void cameraManager::renderBackground(HDC hdc, image* img)
{
	GdiTransparentBlt(hdc, 
		0, 0, WINSIZEX, WINSIZEY, 
		img->getMemDC(), 
		0, 0, 
		img->getWidth(), img->getHeight(), 
		RGB(255, 0, 255));
}

void cameraManager::renderBackground(HDC hdc, image* img, int camNum)
{
	for (_viMulticam = _vMulticam.begin(); _viMulticam != _vMulticam.end(); ++_viMulticam)
	{
		if (_viMulticam->camNum == camNum)
		{
			GdiTransparentBlt(hdc,
				_viMulticam->destX, _viMulticam->destY, _viMulticam->width, _viMulticam->width * WINSIZEY / WINSIZEX,
				img->getMemDC(),
				0, 0,
				img->getWidth(), img->getHeight(),
				RGB(255, 0, 255));

			break;
		}
	}
}

//�÷��̾ �̵��ϴ� �� ����
void cameraManager::renderMap(HDC hdc, image* img)
{
	if (_width >= img->getWidth())
	{
		_width = img->getWidth();
		_height = _width * WINSIZEY / WINSIZEX;
	}
	if (_height >= img->getHeight())
	{
		_height = img->getHeight();
		_width = _height * WINSIZEX / WINSIZEY;
	}
	if (_focusX <= _width / 2) _focusX = _width / 2;
	if (_focusX >= img->getWidth() - _width / 2) _focusX = img->getWidth() - _width / 2;
	if (_focusY <= _height / 2) _focusY = _height / 2;
	if (_focusY >= img->getHeight() - _height / 2) _focusY = img->getHeight() - _height / 2;
	GdiTransparentBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, img->getMemDC(), _focusX - _width / 2, _focusY - _height / 2, _width, _height, RGB(255, 0, 255));
}

void cameraManager::renderMap(HDC hdc, image* img, int camNum)
{
	if (_width >= img->getWidth())
	{
		_width = img->getWidth();
		_height = _width * WINSIZEY / WINSIZEX;
	}
	if (_height >= img->getHeight())
	{
		_height = img->getHeight();
		_width = _height * WINSIZEX / WINSIZEY;
	}
	if (_focusX <= _width / 2) _focusX = _width / 2;
	if (_focusX >= img->getWidth() - _width / 2) _focusX = img->getWidth() - _width / 2;
	if (_focusY <= _height / 2) _focusY = _height / 2;
	if (_focusY >= img->getHeight() - _height / 2) _focusY = img->getHeight() - _height / 2;
	for (_viMulticam = _vMulticam.begin(); _viMulticam != _vMulticam.end(); ++_viMulticam)
	{
		if (_viMulticam->camNum == camNum)
		{
			GdiTransparentBlt(hdc,
				_viMulticam->destX, _viMulticam->destY, _viMulticam->width, _viMulticam->width * WINSIZEY / WINSIZEX,
				img->getMemDC(),
				_focusX - _width / 2,
				_focusY - _height / 2,
				_width, _height,
				RGB(255, 0, 255));

			break;
		}
	}
}

//�ʿ� �ѷ����� ������Ʈ�� ����
void cameraManager::renderObject(HDC hdc, image* img, float destX, float destY)
{
	GdiTransparentBlt
	(hdc,
		(destX - _focusX + _width / 2) * WINSIZEX / _width,
		(destY - _focusY + _height / 2) * WINSIZEY / _height,
		img->getWidth() * WINSIZEX / _width,
		img->getHeight() * WINSIZEY / _height,
		img->getMemDC(),
		0, 0,
		img->getWidth(),
		img->getHeight(),
		RGB(255, 0, 255));
}

//�ʿ� �ѷ����� ������Ʈ�� ����						  �ѷ����� ��ġ X, Y			�Ѹ� �̹��� ��ǥ X, Y  �̹��� ����, ���� ũ�� 
void cameraManager::renderObject(HDC hdc, image* img, float destX, float destY, int sourX, int sourY, int width, int height)
{
	GdiTransparentBlt
	(hdc,
		(destX - _focusX + _width / 2) * WINSIZEX / _width,
		(destY - _focusY + _height / 2) * WINSIZEY / _height,
		width * WINSIZEX / _width,
		height * WINSIZEY / _height,
		img->getMemDC(),
		sourX, sourY,
		width,
		height,
		RGB(255, 0, 255));
}

void cameraManager::renderObject(HDC hdc, image* img, int camNum, float destX, float destY)
{
	for (_viMulticam = _vMulticam.begin(); _viMulticam != _vMulticam.end(); ++_viMulticam)
	{
		if (_viMulticam->camNum == camNum)
		{
			GdiTransparentBlt
			(hdc,
				_viMulticam->destX + (destX - _focusX + _width / 2) * (_viMulticam->width) / _width,
				_viMulticam->destY + (destY - _focusY + _height / 2) * (_viMulticam->width * WINSIZEY / WINSIZEX) / _height,
				img->getWidth() * (_viMulticam->width) / _width,
				img->getHeight() * (_viMulticam->width * WINSIZEY / WINSIZEX) / _height,
				img->getMemDC(),
				0, 0,
				img->getWidth(),
				img->getHeight(),
				RGB(255, 0, 255));
		}
	}
}

void cameraManager::frameRenderObject(HDC hdc, image* img, float destX, float destY, int currentFrameX, int currentFrameY)
{
	img->setFrameX(currentFrameX);
	img->setFrameY(currentFrameY);

	GdiTransparentBlt
	(hdc,
		(destX - _focusX + _width / 2) * WINSIZEX / _width,
		(destY - _focusY + _height / 2) * WINSIZEY / _height,
		img->getFrameWidth() * WINSIZEX / _width,
		img->getFrameHeight() * WINSIZEY / _height,
		img->getMemDC(),
		currentFrameX * img->getFrameWidth(), 
		currentFrameY * img->getFrameHeight(),
		img->getFrameWidth(),
		img->getFrameHeight(),
		RGB(255, 0, 255));
}

void cameraManager::aniRenderObject(HDC hdc, image* img, animation* ani, float destX, float destY)
{
	GdiTransparentBlt
	(hdc,
		(destX - _focusX + _width / 2) * WINSIZEX / _width,
		(destY - _focusY + _height / 2) * WINSIZEY / _height,
		ani->getFrameWidth() * WINSIZEX / _width,
		ani->getFrameHeight() * WINSIZEY / _height,
		img->getMemDC(),
		ani->getFramePos().x, ani->getFramePos().y,
		ani->getFrameWidth(),
		ani->getFrameHeight(),
		RGB(255, 0, 255));
}

void cameraManager::aniRenderObject(HDC hdc, image* img, int camNum, animation* ani, float destX, float destY)
{
	for (_viMulticam = _vMulticam.begin(); _viMulticam != _vMulticam.end(); ++_viMulticam)
	{
		if (_viMulticam->camNum == camNum)
		{
			GdiTransparentBlt
			(hdc,
				_viMulticam->destX + (destX - _focusX + _width / 2) * (_viMulticam->width) / _width,
				_viMulticam->destY + (destY - _focusY + _height / 2) * (_viMulticam->width * WINSIZEY / WINSIZEX) / _height,
				ani->getFrameWidth() * (_viMulticam->width) / _width,
				ani->getFrameHeight() * (_viMulticam->width * WINSIZEY / WINSIZEX) / _height,
				img->getMemDC(),
				ani->getFramePos().x, ani->getFramePos().y,
				ani->getFrameWidth(),
				ani->getFrameHeight(),
				RGB(255, 0, 255));
		}
	}
}

//��Ŀ�� �ϳ� ���
void cameraManager::setSingleFocus(float x, float y) 
{
	_focusX = x; 
	_focusY = y; 
	_width = WINSIZEX;
	_height = WINSIZEY;
}

//��Ŀ�� �ϳ� ��� + ī�޶� ���� ũ��
void cameraManager::setSingleFocus(float x, float y, float width)
{
	_focusX = x; 
	_focusY = y; 
	_width = width; 
	_height = width * WINSIZEY / WINSIZEX;
}

//��Ŀ�� �ΰ� ���					��Ŀ�� ��ǥ 1,		��Ŀ�� ��ǥ2,		��Ŀ�� ��ǥ �¿� ���� ����(1�϶� WINSIZEX��ŭ�� ������ ���´�.)
void cameraManager::setDoubleFocus(float x1, float y1, float x2, float y2, float blankRatio)
{
	if (x1 >= x2)
	{
		_width = (x1 - x2) + (WINSIZEX * blankRatio);
	}
	else if (x2 >= x1)
	{
		_width = (x2 - x1) + (WINSIZEX * blankRatio);
	}
	_height = _width * WINSIZEY / WINSIZEX;
	_focusX = (x1 + x2) / 2;
	_focusY = (y1 + y2) / 2;
}

void cameraManager::setMulticam(int camNum, float destX, float destY, float width)
{
	tagMULTICAM temp;
	temp.camNum = camNum;
	temp.destX = destX;
	temp.destY = destY;
	temp.width = width;
	_vMulticam.push_back(temp);
}

//ī�޶� ���� x��ǥ ��ȯ
float cameraManager::getX(float x)
{
	return (x - _focusX + _width / 2) * WINSIZEX / _width;
}

//ī�޶� ���� y��ǥ ��ȯ
float cameraManager::getY(float y)
{
	return (y - _focusY + _height / 2) * WINSIZEY / _height;
}

//ī�޶� ���� ���콺 x��ǥ ��ȯ
float cameraManager::getMousePointX(float mousePtX)
{
	return (_focusX - _width / 2 + mousePtX * _width / WINSIZEX);
}

//ī�޶� ���� ���콺 y��ǥ ��ȯ
float cameraManager::getMousePointY(float mousePtY)
{
	return (_focusY - _height / 2 + mousePtY * _height / WINSIZEY);
}