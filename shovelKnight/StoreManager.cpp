#include "stdafx.h"
#include "StoreManager.h"
#include "playerManager.h" //穿号識情 伯希督析 識情


StoreManager::StoreManager()
{
}


StoreManager::~StoreManager()
{
}

HRESULT StoreManager::init()
{
	return S_OK;
}

void StoreManager::release()
{

}

void StoreManager::update()
{
	for (_viNpc = _vNpc.begin(); _viNpc != _vNpc.end(); ++_viNpc)
	{
		//NPC困斗研 穣汽戚闘拭辞 域紗 宜陥亜


		//if (playerCollisionNpc) // 中宜梅生檎? <- collision古艦煽拭辞 閤焼辞 宜鍵陥.
		//{
			sellPlayerSkill(_viNpc);		//什迭雌昔引税 雌硲拙遂
			SellPlayerHp(_viNpc);			//端径雌昔引税 雌硲拙遂
			sellGameBgm(_viNpc);			//製焦雌昔引税 雌硲拙遂
		//}
		(*_viNpc)->update();
	}
	
	
}

void StoreManager::render()
{
	for (_viNpc = _vNpc.begin(); _viNpc != _vNpc.end(); ++_viNpc)
	{
		(*_viNpc)->render();
	}
}

void StoreManager::playerCollisionNpc(vector<npcBase*>::iterator temp)
{
	//紬軒穿 古艦煽拭辞 閤焼神澗杏稽. 
	//紬軒穿 古艦煽拭辞 戚角葵生稽 閤焼神壱
	//背雁 戚角葵生稽 中宜戚 溌昔鞠檎 w徹研 喚君 企鉢亜 亜管背走澗依生稽 姥薄拝依
	

}

void StoreManager::sellPlayerSkill(vector<npcBase*>::iterator temp)
{
	if ((*temp)->getNpcType() == MAGICGIRL)	//NPC展脊戚 古送杏析凶
	{
		if ((*temp)->getStock() == 0)		//廃腰亀 姥古研 照梅生檎  (stock戚 姥古判呪 痕呪)
		{
			//努什闘 焼数生稽 "格 戚暗 詞掘? Yes or No(bool葵<-痕呪 馬蟹 蓄亜背醤敗 1.25)
			//焼掘澗 Yes 識澱梅聖凶税 敗呪
			_pm->getMoney() > 1000;
			//巴傾戚嬢拭 実茨球背辞 茨球 託姶馬壱 
			//背雁 什迭 徹葵 閤焼辞 
			//実生稽 true稽 郊蚊層陥.
			(*temp)->setStock(1);			//廃腰 姥古梅生艦猿 stock聖 1稽 鋼発背層陥.
		}
		if ((*temp)->getStock() == 1) 
		{
			_pm->getMoney() > 3000;
		}

		//NO梅聖凶澗 努什闘 焼数生稽
		//"嬢 益...益掘? 照括 ここ " 陥戚杖稽益 窒径 ここ

	}
	
}

void StoreManager::SellPlayerHp(vector<npcBase*>::iterator temp)
{
	if ((*temp)->getNpcType() == HEALTYGUY)	//NPC展脊戚 古送杏析凶
	{
		if ((*temp)->getStock() == 0)		//廃腰亀 姥古研 照梅生檎  (stock戚 姥古判呪 痕呪)
		{
			//努什闘 焼数生稽 "格 戚暗 詞掘? Yes or No(bool葵<-痕呪 馬蟹 蓄亜背醤敗 1.25)
			//焼掘澗 Yes 識澱梅聖凶税 敗呪
			_pm->getMoney() > 1000;
			//巴傾戚嬢拭 実茨球背辞 茨球 託姶馬壱 
			//背雁 什迭 徹葵 閤焼辞 
			//実生稽 true稽 郊蚊層陥.
			(*temp)->setStock(1);			//廃腰 姥古梅生艦猿 stock聖 1稽 鋼発背層陥.
		}
		if ((*temp)->getStock() == 1) //2噺託 姥古析凶 
		{
			_pm->getMoney() > 3000;
		}

		//NO梅聖凶澗 努什闘 焼数生稽
		//"嬢 益...益掘? 照括 ここ " 陥戚杖稽益 窒径 ここ

	}
}

void StoreManager::sellGameBgm(vector<npcBase*>::iterator temp)
{
	if ((*temp)->getNpcType() == HEALTYGUY)	//NPC展脊戚 古送杏析凶
	{
		if ((*temp)->getStock() == 0)		//廃腰亀 姥古研 照梅生檎  (stock戚 姥古判呪 痕呪)
		{
			//努什闘 焼数生稽 "格 戚暗 詞掘? Yes or No(bool葵<-痕呪 馬蟹 蓄亜背醤敗 1.25)
			//焼掘澗 Yes 識澱梅聖凶税 敗呪
			_pm->getMoney() > 1000;
			//巴傾戚嬢拭 実茨球背辞 茨球 託姶馬壱 
			//背雁 什迭 徹葵 閤焼辞 
			//実生稽 true稽 郊蚊層陥.
			(*temp)->setStock(1);			//廃腰 姥古梅生艦猿 stock聖 1稽 鋼発背層陥.
		}
		if ((*temp)->getStock() == 1) //2噺託 姥古析凶 
		{
			_pm->getMoney() > 3000;
		}

		//NO梅聖凶澗 努什闘 焼数生稽
		//"嬢 益...益掘? 照括 ここ " 陥戚杖稽益 窒径 ここ

	}

}


