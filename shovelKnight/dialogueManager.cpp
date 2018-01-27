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
	//��ũ��Ʈ�� ������ �׳� ������Ʈ �Լ��� ����
	if (_scriptStr == "")
	{
		return;
	}

	//���� �ð� �������� 
	if (getTime() % _dialogueTime == 0)
	{
		_cnt++;
	}
}
void dialogueManager::render(HDC hdc)
{
	SetTextColor(hdc, RGB(_r, _g, _b));
	RECT rcScriptArea = { _scriptwindow->getX(), _scriptwindow->getY(), _scriptwindow->getWidth(), _scriptwindow->getHeight() };
	DrawText(hdc, _scriptStr.c_str(), _cnt, &rcScriptArea, DT_SINGLELINE | DT_VCENTER);
}

void dialogueManager::setScriptNScriptWindow(string script, image* scriptWindow, int r, int g, int b)
{
	_cnt = 0;
	_scriptStr = script;
	_scriptwindow = scriptWindow;

	_r = r;
	_g = g;
	_b = b;
}

time_t dialogueManager::getTime()
{
	time_t timer;
	timer = time(NULL);//���� �ð��� �� ������ �д� �Լ�

	return timer;
}