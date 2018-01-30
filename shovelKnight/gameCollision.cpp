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

	_countDarkknightEffect = 0;
	_darkknightTime = 0;
	_countDarkknightAttackEffect;
	_darkknightAttackTime;

	return S_OK;
}

void gameCollision::release()
{
}

void gameCollision::update()
{
	enemyDeadAndAttack();
	//if (KEYMANAGER->isOnceKeyDown('Q') || _playerMeetNPC) 
	PlayerMeetNPC();
	PlayerAndEnemy();
	PlayerAndSkill();

	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		_skill->Fire(SKILL_FIRE_DARKKNIGHT_LEFT, SKILL_TYPE_DARKKNIGHT_FIREBALL, WINSIZEX / 2 - 30, WINSIZEY / 2 - 30);

	}
	
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

void gameCollision::enemyDeadAndAttack()
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
				_skill->Fire(SKILL_FIRE_CENTER, SKILL_TYPE_ENEMYDEADFX, _enemy->getVEnemy()[i]->getX(), _enemy->getVEnemy()[i]->getY());
			}
			break;
		case ENEMY_BLORB:
			if (_enemy->getVEnemy()[i]->getIsDeadVanish())
			{
				_skill->Fire(SKILL_FIRE_CENTER, SKILL_TYPE_ENEMYDEADFX, _enemy->getVEnemy()[i]->getX(), _enemy->getVEnemy()[i]->getY());
			}
			break;
		case ELEMY_DRAKE:
			if (_enemy->getVEnemy()[i]->getIsDeadVanish())
			{
				_skill->Fire(SKILL_FIRE_CENTER, SKILL_TYPE_ENEMYDEADFX, _enemy->getVEnemy()[i]->getX(), _enemy->getVEnemy()[i]->getY());
			}
			break;
		case ENEMY_SKELETON:
			if (_enemy->getVEnemy()[i]->getIsDeadVanish())
			{
				_skill->Fire(SKILL_FIRE_CENTER, SKILL_TYPE_ENEMYDEADFX, _enemy->getVEnemy()[i]->getX(), _enemy->getVEnemy()[i]->getY());
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
					_skill->Fire(SKILL_FIRE_CENTER, SKILL_TYPE_ENEMYDEADFX,
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
					if (_countDragonAttackEffect == 2)
					{
						_skill->Fire(SKILL_FIRE_DRAGON_LEFT, SKILL_TYPE_BUBBLE, _enemy->getVEnemy()[i]->getX(), _enemy->getVEnemy()[i]->getY() + 20);
						_skill->getVSkill()[_skill->getVSkill().size() - 1]->setPlusSaveX(-20);
					}
					else _skill->Fire(SKILL_FIRE_DRAGON_LEFT, SKILL_TYPE_BUBBLE, _enemy->getVEnemy()[i]->getX(), _enemy->getVEnemy()[i]->getY());
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
				_darkknightTime += TIMEMANAGER->getElapsedTime();

				while (_darkknightTime > 0.2f)
				{
					_darkknightTime -= 0.2f;
					++_countDarkknightEffect;
				}

				if (_countDarkknightEffect > 0)
				{
					RECT rc3 = _enemy->getVEnemy()[i]->getRect();
					_skill->Fire(SKILL_FIRE_CENTER, SKILL_TYPE_ENEMYDEADFX,
						RND->getFromFloatTo(rc3.left, rc3.right),
						RND->getFromFloatTo(rc3.top, rc3.top + ((rc3.top + rc3.bottom) / 6)));
					--_countDarkknightEffect;
				}
			}

			if (_enemy->getVEnemy()[i]->getStatus() == ENEMY_LEFT_ATTACK)
			{
				_darkknightAttackTime += TIMEMANAGER->getElapsedTime();

				if (_darkknightAttackTime > 1.f && _countDarkknightAttackEffect != 0)
				{

					_skill->Fire(SKILL_FIRE_DARKKNIGHT_LEFT, SKILL_TYPE_DARKKNIGHT_FIREBALL,
						_enemy->getVEnemy()[i]->getX(),
						_enemy->getVEnemy()[i]->getY());
					_countDarkknightAttackEffect--;
					_darkknightAttackTime -= 1.f;
				}
			}
			else if (_enemy->getVEnemy()[i]->getStatus() == ENEMY_RIGHT_ATTACK)
			{
				_darkknightAttackTime += TIMEMANAGER->getElapsedTime();

				if (_darkknightAttackTime > 1.f && _countDarkknightAttackEffect != 0)
				{

					_skill->Fire(SKILL_FIRE_DARKKNIGHT_RIGHT, SKILL_TYPE_DARKKNIGHT_FIREBALL,
						_enemy->getVEnemy()[i]->getX(),
						_enemy->getVEnemy()[i]->getY());
					_countDarkknightAttackEffect--;
					_darkknightAttackTime -= 1.f;
				}
			}
			else
			{
				_countDarkknightAttackEffect = 1;
				_darkknightAttackTime = 0;
			}
			break;
		}
	}
}

void gameCollision::PlayerMeetNPC()
{
	RECT temp;
	for (int i = 0; i < _store->getVNpc().size(); ++i)
	{

		//_store->getVNpc()[i]->setSkillUnlockLv(_player->getSkillUnlockLv());
		//layer->setSkillUnlockLv(_store->getVNpc()[i]->getSkillUnlockLv());

		//_store->getVNpc()[i]->setMoney(_player->getMoney());
		//_player->setMoney(_store->getVNpc()[i]->getMinusMoney());
		//_store->getVNpc()[i]->setMinusMoney(0);

		//_store->getVNpc()[i]->setMaxHp(0);
		//_player->setMaxHP(_store->getVNpc()[i]->getMaxHp()+2);
		

		/*bool interRect = IntersectRect(
			&temp,
			&_player->getPlayerRC(),
			&_store->getVNpc()[i]->getRect());
		bool checkcollision = (_store->getVNpc()[i]->getIsCollisionNPC());*/
		if (IntersectRect(
			&temp, 
			&_player->getPlayerRC(), 
			&_store->getVNpc()[i]->getRect()) && !(_store->getVNpc()[i]->getIsCollisionNPC()) )

		{
			_store->getVNpc()[i]->isCollision(true);
			_playerMeetNPC = true;

			//�ｺ����
			if (_store->getVNpc()[i]->getNpcType() == HEALTYGUY)
			{
				//�������� 1000������ ũ��
				if (_player->getMoney() >= 1000)
				{
					//1000�� �����ϰ� 
					_player->setMoney(-1000);
					//TTTextOut(400, 400, "�÷��̾", _player->getMoney());
					//�ִ�ü�� 2����
					_player->setMaxHP(2);
					_player->setHP(_player->getMaxHP());
					//TTTextOut(400, 500, "�÷��̾�ü��", _player->getMaxHP());
				}
				if (_player->getMoney() < 1000)
				{
				
				}
			}

			//������ 
			if (_store->getVNpc()[i]->getNpcType() == MAGICGIRL)
			{
				if (_player->getMoney() >= 1000)
				{
					_player->setMoney(-1000);
					_player->setSkillUnlockLv(1);
				}
				if (_player->getMoney() < 1000)
				{

				}
			}

			//�ٵ峪��Ʈ
			if (_store->getVNpc()[i]->getNpcType() == BARDKNIGHT)
			{
				if (_player->getMoney() >= 1000)
				{
					_player->setMoney(-1000);
				}

			}
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
	if (_skill->getVSkill().size())
	{
		for (int i = 0; i != _skill->getVSkill().size(); ++i)
		{
			RECT rc;
			if (_skill->getVSkill()[i]->getIsHavePlayer() == SKILL_DAMAGE_PLAYER
				|| _skill->getVSkill()[i]->getIsHavePlayer() == SKILL_DAMAGE_PLAYER_AND_ENEMY)
			{
				if (IntersectRect(
					&rc,
					&_player->getPlayerRC(),
					&_skill->getVSkill()[i]->getRect()))
				{
					if (_skill->getVSkill()[i]->getSkillType() == SKILL_TYPE_BUBBLE)
					{
						_skill->getVSkill()[i]->goOut(_skill->getVSkill()[i]);
						_player->setDamagePlayer();
					}
					else
					{
						_skill->getVSkill()[i]->isOut(_skill->getVSkill()[i]);
						_player->setDamagePlayer();
					}
				}

				if (IntersectRect(
					&rc,
					&_player->getAttackRC(),
					&_skill->getVSkill()[i]->getRect()))
				{
					if (_skill->getVSkill()[i]->getSkillType() == SKILL_TYPE_BUBBLE)
					{
						_skill->getVSkill()[i]->goOut(_skill->getVSkill()[i]);
					}
					else if (_skill->getVSkill()[i]->getSkillType() == SKILL_TYPE_DARKKNIGHT_FIREBALL)
					{
						_skill->getVSkill()[i]->setIsHavePlayer(SKILL_DAMAGE_ENEMY);
						_skill->getVSkill()[i]->setIsRight(!_skill->getVSkill()[i]->getIsRight());
						_skill->getVSkill()[i]->goLoop(_skill->getVSkill()[i]);
					}
				}
			}

			for (int j = 0; j != _enemy->getVEnemy().size(); ++j)
			{
				if ((_skill->getVSkill()[i]->getIsHavePlayer() == SKILL_DAMAGE_ENEMY
					|| _skill->getVSkill()[i]->getIsHavePlayer() == SKILL_DAMAGE_PLAYER_AND_ENEMY))
				{
					if (IntersectRect(&rc, &_enemy->getVEnemy()[j]->getRect(), &_skill->getVSkill()[i]->getRect()))
					{
						_skill->getVSkill()[i]->goOut(_skill->getVSkill()[i]);
						_enemy->getVEnemy()[i]->setEnemyDamage();
					}
				}

			}


		}
	}
}
