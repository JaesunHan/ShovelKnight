#include "stdafx.h"
#include "gameCollision.h"


gameCollision::gameCollision()
{
}


gameCollision::~gameCollision()
{
}

HRESULT gameCollision::init()
{

	return S_OK;
}

void gameCollision::release()
{
}

void gameCollision::update()
{
	RECT temp;
	RECT player = { 0,0,0,0 }; //= _player->;
	HDC hdc = IMAGEMANAGER->findImage("bgMap")->getMemDC();
	RECT enemy;

	collisionPlayerMap(hdc, player);

	//�÷��̾�� ���� �浹
	//for (int i = 0; i != enemy.size(); ++i)
	//{
	//	for (int j = 0; j != player.size(); ++j)
	//	{
	//		if (IntersectRect(&temp, &player, &enemy))
	//		{
	//
	//
	//
	//			player			[j]->Reaction(DAMAGE_MAX);
	//			enemy[i]->Reaction(2);
	//		}
	//	}
	//}
	//�÷��̾�� ��ų�� �浹
	//���� ��ų�� �浹
	//�÷��̾�� item�� �浹

}

void gameCollision::render()
{
}

void gameCollision::collisionPlayerMap(HDC hdc, const RECT rc)
{
	ThisPixelIsMazen(hdc, 10, 10);
}
