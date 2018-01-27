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
	RECT enemy;

	for (int i = 0; i != _enemy->getVBeeto().size(); ++i)
	{
		if (_enemy->getVBeeto()[i]->getStatus() == ENEMY_LEFT_DEAD ||
			_enemy->getVBeeto()[i]->getStatus() == ENEMY_RIGHT_DEAD)
		{
			_skill->Fire(SKILL_FIRE_CENTER, SKILL_ENEMYDEADFX, _enemy->getVBeeto()[i]->getX(), _enemy->getVBeeto()[i]->getY());
			//_enemy->removeMinionBeeto(i);
		}
	}

	collisionPlayerMap();
	

	//collisionPlayerMap();

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

void gameCollision::collisionPlayerMap()
{
	HDC hdc = IMAGEMANAGER->findImage("bgMap")->getMemDC();

	RECT rc = _player->getPlayerRc();

	int probeX, probeY;

	probeY = rc.bottom - 1;

	for (probeX = rc.left + 1; probeX != rc.right - 1; ++probeX)
	{
		while (!ThisPixelIsMazen(hdc, probeX, probeY))
		{
			--probeY;
		}
	}
	if (probeY == rc.bottom - 1) return;

	_player->setY(_player->getY() + (probeY - rc.bottom));
	//_player->setPlayerState(,ONLAND,,,);
}
