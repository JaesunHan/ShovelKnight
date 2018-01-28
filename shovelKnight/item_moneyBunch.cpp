#include "stdafx.h"
#include "item_moneyBunch.h"


item_moneyBunch::item_moneyBunch()
{
}


item_moneyBunch::~item_moneyBunch()
{
}

HRESULT item_moneyBunch::init()
{
	_imgName = "image/item/moneyBunch";
	char* str = new char[strlen(_imgName) + 5];
	sprintf(str, "%s%s", _imgName, ".bmp");

	_img = IMAGEMANAGER->addFrameImage(_imgName, str, 114, 29, 3, 1);

	return S_OK;
}

void item_moneyBunch::release()
{
}

void item_moneyBunch::update()
{
	if (_petrol)
	{
		_add.y += 0.1f;
	}
	else
	{
		_add.y -= 0.1f;
	}

	_pt.y += _add.y;
}