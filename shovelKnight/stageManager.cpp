#include "stdafx.h"
#include "stageManager.h"
#include "playerManager.h"
#include <vector>


stageManager::stageManager()
{
}


stageManager::~stageManager()
{

}


HRESULT stageManager::init()
{
	_x = 200;
	_y = 150;
	_mapLoaded = false;
	_transition = false;
	_mapNum = 1;
	_loopX1 = 0;
	_loopX2 = 100;
	for (int j = 0; j < 4; ++j)
	{
		_mapTransition[j].rc.left = 0;
		_mapTransition[j].rc.top = 0;
		_mapTransition[j].rc.right = 0;
		_mapTransition[j].rc.bottom = 0;
	}
	return S_OK;
}

void stageManager::release()
{

}

void stageManager::update()	
{
	loadData();
	_loopX1 += 1;

	for (int i = 0; i < 4; ++i)
	{
		RECT temp;
		if (IntersectRect(&temp, &_PM->getPlayerRc(), &_mapTransition[i].rc))
		{
			_transition = true;
			_transitionNum = i;
		}
	}
	

}

void stageManager::render()	
{
	IMAGEMANAGER->findImage("layer1")->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), _loopX1, 0);
	IMAGEMANAGER->findImage("layer2")->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY), _loopX2, 0);
	CAMERAMANAGER->renderMap(getMemDC(), IMAGEMANAGER->findImage("bgMap"));
	if (_transition == false) renderTiles();
	//TTTextOut(getMemDC(), _ptMouse.x, _ptMouse.y - 40, "���콺X", CAMERAMANAGER->getMousePointX(_ptMouse.x) / 16, false);
	//TTTextOut(getMemDC(), _ptMouse.x, _ptMouse.y - 20, "���콺Y", CAMERAMANAGER->getMousePointY(_ptMouse.y) / 16, false);
	//CAMERAMANAGER->renderTile(getMemDC(), IMAGEMANAGER->findImage("tile1"), 0, 13, 10, 14, 16);
}

void stageManager::loadData()
{
	if (_mapLoaded == false)
	{
		TCHAR key[255];
		TCHAR directory[255];
		char mapName[128];
		wsprintf(mapName, "map00%d", _mapNum);
		char iniDir[128];
		wsprintf(iniDir, ".\\map00%d.ini", _mapNum);
		char txtDir[128];
		wsprintf(txtDir, "map00%d.txt", _mapNum);
		int maxLayer = INIDATA->loadDataInterger(mapName, "imageTotal", "maxNum");
		int maxTile = INIDATA->loadDataInterger(mapName, "tileTotal", "maxNum");
		int maxTransition = INIDATA->loadDataInterger(mapName, "transitionTotal", "maxNum");
		_maxFrameImage = INIDATA->loadDataInterger(mapName, "frameIamgeTotal", "maxNum");

		if (maxLayer > 0)
		{
			for (int i = 0; i < maxLayer; ++i)
			{
				char bgImage[128];
				wsprintf(bgImage, "bgImage%d", i + 1);
				GetPrivateProfileString(_T(bgImage), _T("key"), NULL, key, 255, _T(iniDir));
				GetPrivateProfileString(_T(bgImage), _T("directory"), NULL, directory, 255, _T(iniDir));
				if (IMAGEMANAGER->findImage(key)) IMAGEMANAGER->deleteImage(key);
				IMAGEMANAGER->addImage(key, directory,
					INIDATA->loadDataInterger(mapName, bgImage, "width"),
					INIDATA->loadDataInterger(mapName, bgImage, "height"),
					true, RGB(255, 0, 255), false);
			}
		}

		char mapImage[128];
		wsprintf(mapImage, "mapImage");
		GetPrivateProfileString(_T(mapImage), _T("key"), NULL, key, 255, _T(iniDir));
		GetPrivateProfileString(_T(mapImage), _T("directory"), NULL, directory, 255, _T(iniDir));
		_transverseTileNum = INIDATA->loadDataInterger(mapName, mapImage, "transverseNum");
		_verticalTileNum = INIDATA->loadDataInterger(mapName, mapImage, "verticalNum");
		if (IMAGEMANAGER->findImage(key)) IMAGEMANAGER->deleteImage(key);
		IMAGEMANAGER->addImage(key, directory,
			INIDATA->loadDataInterger(mapName, mapImage, "width"),
			INIDATA->loadDataInterger(mapName, mapImage, "height"),
			true, RGB(255, 0, 255), false);

		for (int i = 0; i < maxTile; ++i)
		{
			char tile[128];
			wsprintf(tile, "tile%d", i + 1);
			GetPrivateProfileString(_T(tile), _T("key"), NULL, key, 255, _T(iniDir));
			GetPrivateProfileString(_T(tile), _T("directory"), NULL, directory, 255, _T(iniDir));
			if (IMAGEMANAGER->findImage(key)) IMAGEMANAGER->deleteImage(key);
			IMAGEMANAGER->addImage(key, directory,
				INIDATA->loadDataInterger(mapName, tile, "width"),
				INIDATA->loadDataInterger(mapName, tile, "height"),
				true, RGB(255, 0, 255), false);
		}

		//for (int i = 0; i < _maxFrameImage; ++i)
		//{
		//	char frameImage[128];
		//	wsprintf(frameImage, "frameImage%d", i + 1);
		//	GetPrivateProfileString(_T(frameImage), _T("key"), NULL, key, 255, _T(iniDir));
		//	GetPrivateProfileString(_T(frameImage), _T("directory"), NULL, directory, 255, _T(iniDir));
		//	if (IMAGEMANAGER->findImage(key)) IMAGEMANAGER->deleteImage(key);
		//	IMAGEMANAGER->addFrameImage(key, directory,
		//		INIDATA->loadDataInterger(mapName, frameImage, "width"),
		//		INIDATA->loadDataInterger(mapName, frameImage, "height"),
		//		INIDATA->loadDataInterger(mapName, frameImage, "frameX"),
		//		INIDATA->loadDataInterger(mapName, frameImage, "frameY"),
		//		true, RGB(255, 0, 255), false);
		//}

		for (int j = 0; j < 4; ++j)
		{
			_mapTransition[j].rc.left = 0;
			_mapTransition[j].rc.top = 0;
			_mapTransition[j].rc.right = 0;
			_mapTransition[j].rc.bottom = 0;
		}
		for (int i = 0; i < maxTransition; ++i)
		{
			char transit[128];
			wsprintf(transit, "transition%d", i + 1);
			_mapTransition[i].rc.left = INIDATA->loadDataInterger(mapName, transit, "left");
			_mapTransition[i].rc.top = INIDATA->loadDataInterger(mapName, transit, "top");
			_mapTransition[i].rc.right = INIDATA->loadDataInterger(mapName, transit, "right");
			_mapTransition[i].rc.bottom = INIDATA->loadDataInterger(mapName, transit, "bottom");
			_mapTransition[i].mapNum = INIDATA->loadDataInterger(mapName, transit, "mapNum");
			_mapTransition[i].direction = INIDATA->loadDataInterger(mapName, transit, "direction");
		}

		arrElements vTemp = TXTDATA->txtLoad(txtDir);
		for (int i = 0; i < vTemp.size(); ++i)
		{
			_vTileNum.push_back(atoi(vTemp[i].c_str()));
		}

		_mapLoaded = true;
	}
}

void stageManager::renderTiles()
{
	for (int i = 0; i < _transverseTileNum; ++i)						//�� ���� Ÿ�� ����
	{
		for (int j = 0; j < _verticalTileNum; ++j)						//�� ���� Ÿ�� ����
		{
			if (_vTileNum[(i * _verticalTileNum) + j] == 0) continue;
			if ((_vTileNum[(i * _verticalTileNum) + j] / 10000) == 1)
			{
				CAMERAMANAGER->renderTile(getMemDC(), IMAGEMANAGER->findImage("tile1"), i, j,
					(_vTileNum[(i * _verticalTileNum) + j] / 100) % 100,
					_vTileNum[(i * _verticalTileNum) + j] % 100, 16);
			}
		}
	}
}

void stageManager::transition()
{
	if (_transition == true)
	{
		TCHAR key[255];
		TCHAR directory[255];
		char mapName[128];
		wsprintf(mapName, "map00%d", _mapTransition[_transitionNum].mapNum);
		char iniDir[128];
		wsprintf(iniDir, ".\\map00%d.ini", _mapTransition[_transitionNum].mapNum);
		char txtDir[128];
		wsprintf(txtDir, "map00%d.txt", _mapTransition[_transitionNum].mapNum);
		int maxLayer = INIDATA->loadDataInterger(mapName, "imageTotal", "maxNum");
		int maxTile = INIDATA->loadDataInterger(mapName, "tileTotal", "maxNum");
		int maxFrameImage = INIDATA->loadDataInterger(mapName, "frameIamgeTotal", "maxNum");

		for (int i = 0; i < maxLayer; ++i)
		{
			char bgImage[128];
			wsprintf(bgImage, "bgImage%d", i + 1);
			char tempLayer[128];
			wsprintf(tempLayer, "tempLayer%d", i + 1);
			GetPrivateProfileString(_T(bgImage), _T("directory"), NULL, directory, 255, _T(iniDir));
			if (IMAGEMANAGER->findImage(tempLayer)) IMAGEMANAGER->deleteImage(tempLayer);
			IMAGEMANAGER->addImage(tempLayer, directory,
				INIDATA->loadDataInterger(mapName, bgImage, "width"),
				INIDATA->loadDataInterger(mapName, bgImage, "height"),
				true, RGB(255, 0, 255), false);
		}

		IMAGEMANAGER->deleteImage("bgMap");
		IMAGEMANAGER->addImage("bgMap", ".\\image\\stage\\transitionMap.bmp", 400, 240, true, RGB(255, 0, 255), false);

		for (int i = 0; i < maxTile; ++i)
		{
			char tile[128];
			wsprintf(tile, "tile%d", i + 1);
			char tempTile[128];
			wsprintf(tempTile, "tempTile%d", i + 1);
			GetPrivateProfileString(_T(tile), _T("directory"), NULL, directory, 255, _T(iniDir));
			if (IMAGEMANAGER->findImage(tempTile)) IMAGEMANAGER->deleteImage(tempTile);
			IMAGEMANAGER->addImage(tempTile, directory,
				INIDATA->loadDataInterger(mapName, tile, "width"),
				INIDATA->loadDataInterger(mapName, tile, "height"),
				true, RGB(255, 0, 255), false);
		}

		for (int i = 0; i < _maxFrameImage; ++i)
		{
			KEYANIMANAGER->deleteOne("frameBG");
			char frameImage[128];
			wsprintf(frameImage, "frameImage%d", i + 1);
			GetPrivateProfileString(_T(frameImage), _T("key"), NULL, key, 255, _T(iniDir));
			GetPrivateProfileString(_T(frameImage), _T("directory"), NULL, directory, 255, _T(iniDir));
			if (IMAGEMANAGER->findImage(key)) IMAGEMANAGER->deleteImage(key);
			_frameImage = IMAGEMANAGER->addFrameImage(key, directory,
				INIDATA->loadDataInterger(mapName, frameImage, "width"),
				INIDATA->loadDataInterger(mapName, frameImage, "height"),
				INIDATA->loadDataInterger(mapName, frameImage, "frameX"),
				INIDATA->loadDataInterger(mapName, frameImage, "frameY"),
				true, RGB(255, 0, 255), false);
			KEYANIMANAGER->addDefaultFrameAnimation("frameBG", key, 5, false, true);
			KEYANIMANAGER->start("frameBG");
		}
		
	}
}