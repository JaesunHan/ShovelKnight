#include "stdafx.h"
#include "npcBase.h"


npcBase::npcBase()
{
}


npcBase::~npcBase()
{

}

HRESULT npcBase::init(string imgKeyString, char* imgFileNmae, float x, float y, int totalWidth, int totalHeight, int frameX, int frameY, NPCTYPE npcType)
{
	_imgKeyString = imgKeyString;
	_imgFileName = imgFileNmae;
	_x = x;
	_y = y;

	_npcType = npcType;
	
	_img = IMAGEMANAGER->addFrameImage(_imgKeyString, _imgFileName, _x, _y, totalWidth, totalHeight, frameX, frameY, true, RGB(255, 0, 255));
	_width = _img->getFrameWidth();
	_height = _img->getFrameHeight();


	return S_OK;
}
void npcBase::release()
{

}
void npcBase::update() 
{
	_rc = RectMakeCenter(_x, _y, _width, _height);
}
void npcBase::render() 
{
	//�ڽ�Ŭ������ �ִ� draw() �̴���, �ƴϸ� �θ�Ŭ������ �ִ� draw() ���� �ϳ��� ��µȴ�.
	//�ʿ��ϴٸ� �ڽ�Ŭ������ draw() �Լ����� �θ�Ŭ������ draw()�� ȣ���ϵ��� ����
	draw();
}
void npcBase::draw()
{

}