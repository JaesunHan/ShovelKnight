#include "stdafx.h"
#include "HealtyGuy.h"


HealtyGuy::HealtyGuy()
{

	
}


HealtyGuy::~HealtyGuy()
{
}

HRESULT HealtyGuy::init()
{
	npcBase::init();
	//생성자에 초기화
	//==========가격 세팅 변수===========//
	_chicken = 1000;								//칰힌 가격
	_drgonTail = 4500;								//용꼬리 가격


													//==========팔렸는지 확인용 변수들==========//
	_stock = 0;										//몇번이나 상점에서 구매했는지 확인 변수
	_isSellChicken = false;							//칰힌 팔렸는지
	_isSellDragonTail = false;						//용꼬리 팔렸는지


													//=========마더클래스로부터 가져온 변수들 초기화 ==============//

	_imgKeyString = "HealtyGuyIdle";				//이미지 매니저에 등록할 이미지 키갑
	_imgFileName = "./image/npc/healthGuyStand.bmp";		//이미지 파일 이름(경로 포함)`

	//NPC 이미지
	_img = IMAGEMANAGER->addFrameImage(_imgKeyString, _imgFileName, 70, 47, 2, 1, true, RGB(255, 0, 255), false);											// NPC 이미지
	IMAGEMANAGER->addFrameImage("HealtyGuyGood", "./image/npc/healthGuyGood1.bmp", 168, 90, 4, 1, true, RGB(255, 0, 255), false);
	IMAGEMANAGER->addFrameImage("HealtyGuyCook", "./image/npc/healthGuyBackCook.bmp", 897, 43, 23, 1, true, RGB(255, 0, 255), false);



	_x = 220/2;
	_y = 280/2;


	_img->setCenter(_x, _y);						//이미지 중점좌표로 중점좌표 잡는다. 
	_width = _img->getFrameWidth();					//가로크기
	_height = _img->getFrameHeight();				//세로크기
	_rc = RectMakeCenter(_x, _y, _width, _height);	//상점NPC 렉트
	_npcType = HEALTYGUY;							//NPC타입



	_isCollisionNpc = false;							//플레이어와 충돌했는가? true : 그렇다, false : 아니다
	_isCollisionPlayer = false;
	_isAppear = true;									//기본상태로 맵에서 등장하지 않는다.
	_textOut = false;

	int arrIDLE1[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("헬스가이아이들", "HealtyGuyIdle", arrIDLE1, 2, 2, true);
	
	int arrGood[4];
	for (int i = 0; i < 4; ++i)
	{
		arrGood[i] = i;
	}
	KEYANIMANAGER->addArrayFrameAnimation("헬스가이굿", "HealtyGuyGood", arrGood, 4, 3, true);
	

	_anim = KEYANIMANAGER->findAnimation("헬스가이아이들");		//NPC 애니메이션
	_anim2 = KEYANIMANAGER->findAnimation("헬스가이굿");

	KEYANIMANAGER->start("헬스가이아이들");
	KEYANIMANAGER->start("헬스가이굿");

	_testScript = new image;
	_testScript = IMAGEMANAGER->addImage("scriptWindow", "./image/UI/Script_window.bmp", 0, 0, 800, 96, true, RGB(255, 0, 255));
	DIALOGUEMANAGER->setScriptWindow(_testScript);


	_vDialog2.push_back("음식은 곧 체력이라고 친구!");
	_vDialog2.push_back("음식을 먹으려면 O키를, 아니면 P키를 누르게");
	_vDialog2.push_back("체력이 증가하는게 느껴지지 않는가. 하하하하!");

	//분기선택
	//_vDialog2.push_back("음식을 먹고 싶으면 언제든 말을 걸도록 하게!");

	_idx = 0;
	_branch1 = false;
	_branch2 = false;
	//_setMaxHp = 8;
	return S_OK;
}

void HealtyGuy::sellHpItem()
{
}



void HealtyGuy::isCollision(bool collision)
{
	if (_isAppear)
	{
		if (collision)
		{
			//텍스트 아웃으로 "너 이거 살래? Yes or No(bool값<-변수 하나 추가해야함 1.25)
			//아래는 Yes 선택했을때의 함수
			_isCollisionPlayer = collision;
			_textOut = true;
			
			_npcStatus = NPCTALK;
			//if (KEYMANAGER->isOnceKeyDown('O'))				//O눌렀을때
			//{
				//TTTextOut(300, 300, "으앙충돌", 0);
			//if (KEYMANAGER->isOnceKeyDown('2'))
			//{
			//	if (!_stock)					//한번도 상점에서 구매를 하지 않았으면(stock =0)
			//	{
			//		if (_money >= 1000)				//1000원보다 돈이 많다면
			//		{
			//			_minusMoney -= 1000;						//플레이어 골드에서 1000원을 감소하고
			//			//_setMaxHp += 2;
			//			_stock = 1;						//한번 구매했으니까 stock을 1로 반환해준다.
			//		}
			//		if (_money < 1000)						//플레이어 골드가 1000원보다 작다면
			//		{
			//			//str = str4;
			//		}


			//	}

			//	if (_stock == 1)							//한번도 상점에서 구매를 하지 않았으면
			//	{
			//		if (_money >= 3000)						//3000원보다 돈이 많다면
			//		{

			//			_minusMoney -= 3000;				//플레이어 골드에서 1000원을 감소하고
			//			//_setMaxHp += 2;
			//			_stock = 2;							//한번 구매했으니까 stock을 1로 반환해준다.
			//		}
			//		if (_money < 3000)						//플레이어 골드가 1000원보다 작다면
			//		{
			//			//str = str4;
			//		}

			//	}
			//	//}
			//	else
			//	{
			//		_textOut = false;
			//	}
			//}
			//if (KEYMANAGER->isOnceKeyDown('P'))
			//{

			//}
			////NO했을때는 텍스트 아웃으로
			////"어 그...그래? 안녕 ㅃㅃ " 다이얼로그 출력 ㅃㅃ
			////_isCollisionNpc == false;

		}
		
	}
}

void HealtyGuy::HealtyGuyImageControl()
{

	switch (_npcStatus)
	{
	case NPCIDLE:
		_anim = KEYANIMANAGER->findAnimation("헬스가이아이들");		//NPC 애니메이션
															//KEYANIMANAGER->start("매직걸아이들");
		break;

	case NPCTALK:
		_img = IMAGEMANAGER->findImage("HealtyGuyGood");
		_anim2 = KEYANIMANAGER->findAnimation("헬스가이굿");		//NPC 애니메이션
															//KEYANIMANAGER->start("매직걸인사");
		break;

	case NPCUNDERATTACKED:
		break;
	}

}

void HealtyGuy::render()
{
	if (_isAppear == true)
	{
		draw();

		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			Rectangle(getMemDC(), CAMERAMANAGER->getX(_rc.left),
				CAMERAMANAGER->getY(_rc.top),
				CAMERAMANAGER->getX(_rc.right),
				CAMERAMANAGER->getY(_rc.bottom));
		}
	}
	//콜리전 상태일때만 다이어로그 출력
	if (_dialogue)
	{
		DIALOGUEMANAGER->render(getMemDC(), 0, 0, 800, 96);
	}
	
	
	if (_textOut)
	{
		//TTTextOut(300, 300, "플레이어돈", _money);
		//TTTextOut(300, 200, "플레이어최대체력", _setMaxHp);
	}
}

void HealtyGuy::draw()
{
	//_img->aniRender(getMemDC(), _rc.left, _rc.top, _anim);
	switch (_npcStatus)
	{
	case NPCIDLE: CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim, _rc.left, _rc.top);
		break;
	case NPCTALK: CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim2, _rc.left, _rc.top-20);
		break;
	case NPCUNDERATTACKED:
		break;
	default: CAMERAMANAGER->aniRenderObject(getMemDC(), _img, _anim, _rc.left, _rc.top);
		break;
	}
}

void HealtyGuy::update()
{
	npcBase::update();
	HealtyGuyImageControl();

	//if ()



	//if (!_dialogue && _isCollisionPlayer)
	//{
	//	//인덱스값으로 다이얼로그 벡터에 있는 값을 빼낸다
	//
	//	DIALOGUEMANAGER->setScript(_vDialog2[_idx], 255, 255, 255);
	//
	//	_idx += 1;
	//
	//	if (_idx >= _vDialog.size())	_idx = 0;
	//	_dialogue = true;
	//	//	if (_idx >= _vDialog2.size())
	//
	//}
	//else if(!_isCollisionPlayer)
	//{
	//	_dialogue = false;
	//}

	if (KEYMANAGER->isOnceKeyDown('O'))
	{
	//DIALOGUEMANAGER->setScript(_vDialog[2], 255, 255, 255);
	}
	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		//DIALOGUEMANAGER->setScript(_vDialog2[0], 255, 255, 255);
	}

	
}