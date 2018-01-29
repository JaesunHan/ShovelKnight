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
	_playerMeetNPC = false;
	_countDragonEffect = 0;
	_dragonTime = 0;

	_countDragonAttackEffect;
	_dragonAttackTime;

	return S_OK;
}

void gameCollision::release()
{
}

void gameCollision::update()
{
	enemyDead();
	if (KEYMANAGER->isOnceKeyDown('Q') || _playerMeetNPC) PlayerMeetNPC();
	PlayerAndEnemy();
	
	//collisionPlayerMapRight();
	//collisionPlayerMapLeft();
	//collisionPlayerMapDown(); 
	//collisionPlayerMapUp();
	//collisionPlayerInAir();

	//�÷��̾�� ��ų�� �浹	 
	//���� ��ų�� �浹
	//�÷��̾�� item�� �浹
	//�÷��̾�� ��ų�� �浹

}

void gameCollision::render()
{

}

void gameCollision::enemyDead()
{
	//���Ϳ� ���� �״°� �ٸ��Ƿ� ����ġ�� ����



	//�巡���� �Ӹ��� ����
	//�巹�� ������ ��������Ʈ ������, ī��Ʈ�� ����
	for (int i = 0; i != _enemy->getVEnemy().size(); ++i)
	{
		switch (_enemy->getVEnemy()[i]->getEnemyType())
		{
		case ENEMY_BEETO:
			if (_enemy->getVEnemy()[i]->getIsDeadVanish())
			{
				_skill->Fire(SKILL_FIRE_CENTER, SKILL_ENEMYDEADFX, _enemy->getVEnemy()[i]->getX(), _enemy->getVEnemy()[i]->getY());
			}
			break;
		case ENEMY_BLORB:
			if (_enemy->getVEnemy()[i]->getIsDeadVanish())
			{
				_skill->Fire(SKILL_FIRE_CENTER, SKILL_ENEMYDEADFX, _enemy->getVEnemy()[i]->getX(), _enemy->getVEnemy()[i]->getY());
			}
			break;
		case ELEMY_DRAKE:
			if (_enemy->getVEnemy()[i]->getIsDeadVanish())
			{
				_skill->Fire(SKILL_FIRE_CENTER, SKILL_ENEMYDEADFX, _enemy->getVEnemy()[i]->getX(), _enemy->getVEnemy()[i]->getY());
			}
			break;
		case ENEMY_SKELETON:
			if (_enemy->getVEnemy()[i]->getIsDeadVanish())
			{
				_skill->Fire(SKILL_FIRE_CENTER, SKILL_ENEMYDEADFX, _enemy->getVEnemy()[i]->getX(), _enemy->getVEnemy()[i]->getY());
			}
			break;
		case ENEMY_DRAGON:
			if (_enemy->getVEnemy()[i]->getStatus() == ENEMY_LEFT_DEAD ||
				_enemy->getVEnemy()[i]->getStatus() == ENEMY_RIGHT_DEAD ||
				_enemy->getVEnemy()[i]->getIsDeadVanish())
			{

				_dragonTime += TIMEMANAGER->getElapsedTime();

				while (_dragonTime > 0.2f)
				{
					_dragonTime -= 0.2f;
					++_countDragonEffect;

				}

				if (_countDragonEffect > 0)
				{
					RECT rc3 = _enemy->getVEnemy()[i]->getBoss1TrunkRect();
					_skill->Fire(SKILL_FIRE_CENTER, SKILL_ENEMYDEADFX,
						RND->getFromFloatTo(rc3.left, rc3.right),
						RND->getFromFloatTo(rc3.top, rc3.top + ((rc3.top + rc3.bottom) / 6)));
					--_countDragonEffect;
				}
			}
			if (_enemy->getVEnemy()[i]->getStatus() == ENEMY_LEFT_ATTACK)
			{
				_dragonAttackTime += TIMEMANAGER->getElapsedTime();

				if (_dragonAttackTime > 0.25f && _countDragonAttackEffect != 0)
				{
					if(_countDragonAttackEffect == 2) _skill->Fire(SKILL_FIRE_DRAGON, SKILL_BUBBLE, _enemy->getVEnemy()[i]->getX(), _enemy->getVEnemy()[i]->getY()+20);
					else _skill->Fire(SKILL_FIRE_DRAGON, SKILL_BUBBLE, _enemy->getVEnemy()[i]->getX(), _enemy->getVEnemy()[i]->getY());
					_countDragonAttackEffect--;
					_dragonAttackTime -= 0.25;
				}
			}
			else
			{
				_countDragonAttackEffect = 3;
				_dragonAttackTime = 0;
			}
			break;
		case ENEMY_BLACKKNIGHT:
			if (_enemy->getVEnemy()[i]->getStatus() == ENEMY_LEFT_DEAD ||
				_enemy->getVEnemy()[i]->getStatus() == ENEMY_RIGHT_DEAD ||
				_enemy->getVEnemy()[i]->getIsDeadVanish())
			{
				
				_skill->Fire(SKILL_FIRE_CENTER, SKILL_ENEMYDEADFX, _enemy->getVEnemy()[i]->getX(), _enemy->getVEnemy()[i]->getY());
			}
			break;
		}
	}
}

void gameCollision::PlayerMeetNPC()
{
	RECT temp;
	for (int i = 0; i != _store->getVNpc().size(); ++i)
	{

		//_store->getVNpc()[i]->setSkillUnlockLv(_player->getSkillUnlockLv());
		_player->setSkillUnlockLv(_store->getVNpc()[i]->getSkillUnlockLv());

		_store->getVNpc()[i]->setMoney(_player->getMoney());
		_player->setMoney(_store->getVNpc()[i]->getMinusMoney());
		_store->getVNpc()[i]->setMinusMoney(0);

		_player->setMaxHP(_store->getVNpc()[i]->getMaxHp());
		_store->getVNpc()[i]->setMaxHp(0);
		


		if (IntersectRect(
			&temp, 
			&_player->getPlayerRC(), 
			&_store->getVNpc()[i]->getRect()))

		{
			_store->getVNpc()[i]->isCollision(true);
			_playerMeetNPC = true;
		}
		else
		{
			_store->getVNpc()[i]->isCollision(false);
			_playerMeetNPC = false;
		}
	}
}

void gameCollision::PlayerAndEnemy()
{
	for (int i = 0; i != _enemy->getVEnemy().size(); ++i)
	{
		_enemy->getVEnemy()[i]->getPlayerX(_player->getX());
		_enemy->getVEnemy()[i]->getPlayerStatus(_player->getPlayerAction());

		RECT temp;

		if (IntersectRect(&temp, &_player->getPlayerRC(), &_enemy->getVEnemy()[i]->getRect()))
		{
			_player->setDamagePlayer();
		}
		if (_enemy->getVEnemy()[i]->getEnemyType() == ENEMY_DRAGON &&
			IntersectRect(&temp, &_player->getAttackRC(), &_enemy->getVEnemy()[i]->getBoss1TrunkRect()))
		{
			_player->setDamagePlayer();
		}

		if (_enemy->getVEnemy()[i]->getEnemyType() == ENEMY_DRAGON)
		{
			if (IntersectRect(&temp, &_player->getAttackRC(), &_enemy->getVEnemy()[i]->getBoss1TrunkRect()))
			{
				_player->setPlayerReaction();
			}
			if (IntersectRect(&temp, &_player->getAttackRC(), &_enemy->getVEnemy()[i]->getRect()))
			{
				_player->setPlayerReaction();
				_enemy->getVEnemy()[i]->setEnemyDamage();
			}
		}
		else if (_enemy->getVEnemy()[i]->getEnemyType() == ENEMY_SKELETON)
		{
			if (IntersectRect(&temp, &_player->getAttackRC(), &_enemy->getVEnemy()[i]->getRect()))
			{
				_enemy->getVEnemy()[i]->setEnemyDamage();
				_player->setPlayerReaction();
			}
		}
		else
		{
			if (IntersectRect(&temp, &_player->getAttackRC(), &_enemy->getVEnemy()[i]->getRect()))
			{
				_enemy->getVEnemy()[i]->setEnemyDamage();
				_player->setPlayerReaction();
			}
		}

		
	}
}

void gameCollision::EnemyAction()
{

}

void gameCollision::PlayerAndSkill()
{
}
