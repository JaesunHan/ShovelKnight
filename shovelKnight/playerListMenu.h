#pragma once
#include "menuBase.h"
class playerListMenu : public menuBase
{
	//플레이어의 정보를 보여주는 메뉴(UI)
	
public:
	HRESULT init();
	void update();
	void release();
	void render(HDC hdc);
	void draw(HDC hdc);

	playerListMenu();
	~playerListMenu();
};

