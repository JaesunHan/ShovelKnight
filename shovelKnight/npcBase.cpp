#include "stdafx.h"
#include "npcBase.h"


npcBase::npcBase()
{
}


npcBase::~npcBase()
{

}
//NPC ���� ������ �ٲ� �� init�� ��� 
//HRESULT npcBase::init(string imgKeyString, char* imgFileNmae, float x, float y, int totalWidth, int totalHeight, int frameX, int frameY, NPCTYPE npcType)
//{
//	_imgKeyString = imgKeyString;
//	_imgFileName = imgFileNmae;
//	_x = x;
//	_y = y;
//
//	_npcType = npcType;
//	
//	_img = IMAGEMANAGER->addFrameImage(_imgKeyString, _imgFileName, _x, _y, totalWidth, totalHeight, frameX, frameY, true, RGB(255, 0, 255));
//	_width = _img->getFrameWidth();
//	_height = _img->getFrameHeight();
//	_stock = 0;
//
//	return S_OK;
//}
//���ο� init
HRESULT npcBase::init()
{
	//��ǥ��, �̹��� �⺻������ �ƿ� NPC�� Ŭ�������� ���õǾ�������
	//���� �ҷ��ö��� NPCŸ���̶� _isAppear�� �޾Ƽ� �Ҽ� ���� ������. 
	//_isAppear = appaear;
	_minusMoney = 0;

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
	//draw();
}
void npcBase::draw()
{
	//_img->aniRender(getMemDC(), _rc.left, _rc.top, _anim);
	//CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim, _rc.left, _rc.top);
}

//void npcBase::collisionSignalFromCollisionManager(bool collision)
//{
//	//�ݸ��� �Ŵ������� �޾ƿ��°ɷ�. 
//	//�ݸ��� �Ŵ������� �̳Ѱ����� �޾ƿ���
//	//�ش� �̳Ѱ����� �浹�� Ȯ�εǸ� wŰ�� ���� ��ȭ�� ���������°����� �����Ұ�
//
//	if (collision)
//	{
//		isCollision();
//	}
//
//}

void npcBase::isCollision(bool collision)
{
}
