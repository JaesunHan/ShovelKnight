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
	//RECT temp;
	//RECT player;
	//RECT enemy;
	////�÷��̾�� ���� �浹
	//for (int i = 0; i != enemy.size(); ++i)
	//{
	//	for (int j = 0; j != player.size(); ++j)
	//	{
	//		if (IntersectRect(&temp, &player, &enemy))
	//		{
	//
	//
	//
	//			player[j]->Reaction(DAMAGE_MAX);
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
