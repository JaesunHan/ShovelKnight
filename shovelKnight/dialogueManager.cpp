#include "stdafx.h"
#include "dialogueManager.h"


dialogueManager::dialogueManager()
{
}


dialogueManager::~dialogueManager()
{
}

HRESULT dialogueManager::init(float dt)
{
	
	_dialogueTime = dt;		//�� �ð��� ���� ��µǴ� �ð� �����̴�

	_elapsedTime = 0;
	//_language = lan;

	return S_OK;
}

void dialogueManager::release()
{

}
void dialogueManager::update()
{
	if (_scriptStr == "")
	{
		return;
	}
	if (getTime() % _dialogueTime)
	{

	}
}
void dialogueManager::render(HDC hdc)
{

}

void dialogueManager::setScriptNScriptWindow(string script, image* scriptWindow)

{

}

time_t dialogueManager::getTime()
{
	time_t timer;
	timer = time(NULL);//���� �ð��� �� ������ �д� �Լ�

	return timer;
}