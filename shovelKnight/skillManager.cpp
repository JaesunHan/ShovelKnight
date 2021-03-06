#include "stdafx.h"
#include "skillManager.h"


skillManager::skillManager()
{
}


skillManager::~skillManager()
{
}

HRESULT skillManager::init()
{
	for (int i = 0; i < EFFECTNUM; ++i)
	{
		skillBase* sk;
		switch (i)
		{
		case SKILL_TYPE_BUBBLE:
			sk = new skill_Bubble;
			break;
		case SKILL_TYPE_DARKKNIGHT_FIREBALL:
			sk = new skill_darkKnight_fireBall;
			break;
		case SKILL_TYPE_DIRTBLOCKFX:
			sk = new skill_dirtBlockFx;
			break;
		case SKILL_TYPE_FIREBALL:
			sk = new skill_fireBall;
			break;
		case SKILL_TYPE_ENEMYDEADFX:
			sk = new skill_enemyDeadFx;
			break;
		}
		sk->init();
	}

	return S_OK;
}

void skillManager::release()
{
	viSkill iter;

	if (_vSkill.size())
	{
		for (iter = _vSkill.begin(); iter != _vSkill.end();)
		{
			(*iter)->release();
		}
	}
}

void skillManager::update()
{
	if (_vSkill.size())	
	{
		for (int i = 0; i != _vSkill.size();)
		{
		
			if (_vSkill[i]->getIsFire())
			{
				_vSkill[i]->update();
				++i;
			}
			else
			{
				_vSkill.erase(_vSkill.begin() + i);
			}
		
			if (!_vSkill.size()) break;
		}

		//viSkill iter = _vSkill.begin();
		//
		//vector<viSkill> vErase;
		//
		//for (; _vSkill.size() != 0;)
		//{
		//	if (iter == _vSkill.end()) break;
		//
		//	if ((*iter)->getIsFire())
		//	{
		//		(*iter)->update();
		//		++iter;
		//	}
		//	else
		//	{
		//		(*iter) = _vSkill.erase(iter);
		//		//vErase.push_back(iter);
		//	}
		//}
		//{
		//	for (; 0 != vErase.size();)
		//	{
		//		_vSkill.erase(vErase[0]);
		//		vErase.erase(vErase.begin());
		//	}
		//	vErase.clear();
		//}

	}
}

void skillManager::render()
{
	viSkill iter;

	if (_vSkill.size())
	{
		for (iter = _vSkill.begin(); iter != _vSkill.end(); ++iter)
		{
			(*iter)->render();
		}
	}
}

void skillManager::Fire(SKILL_FIRE chartype, SKILL_TYPE skill, float x, float y)
{
	skillBase* sk;
	switch (skill)
	{
	case SKILL_TYPE_BUBBLE:
		sk = new skill_Bubble;
		break;
	case SKILL_TYPE_DARKKNIGHT_FIREBALL:
		sk = new skill_darkKnight_fireBall;
		break;
	case SKILL_TYPE_DIRTBLOCKFX:
		sk = new skill_dirtBlockFx;
		break;
	case SKILL_TYPE_FIREBALL:
		sk = new skill_fireBall;
		break;
	case SKILL_TYPE_ENEMYDEADFX:
		sk = new skill_enemyDeadFx;
		break;
	}

	sk->fire(chartype, x, y);

	_vSkill.push_back(sk);
}
/*

if (KEYMANAGER->isOnceKeyDown('Z'))
{
Fire(SKILL_FIRE_CENTER, SKILL_TYPE_FIREBALL, WINSIZEX / 2, WINSIZEY / 2);
}
*/