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
void dialogueManager::render(HDC hdc, float x, float y, int width , int height)
{
	if (_scriptStr == "")
	{
		return;
	}
	_scriptwindow->render(hdc, x, y);
	SetTextColor(hdc, RGB(_r, _g, _b));
	RECT rcScriptArea = { x+150, y, width, height };
	if (_cnt >= strlen (_scriptStr))	_cnt = strlen(_scriptStr);
	DrawText(hdc, _scriptStr, _cnt, &rcScriptArea, DT_SINGLELINE | DT_VCENTER);
}

void dialogueManager::setScriptNScriptWindow(string script, image* scriptWindow, int r, int g, int b)
{
	_cnt = 0;
	
	wsprintf(_scriptStr, "%s", script.c_str());
	_scriptwindow = scriptWindow;

	_r = r;
	_g = g;
	_b = b;
}

void dialogueManager::setScript(string script, int r, int g, int b)
{
	_cnt = 0;

	wsprintf(_scriptStr, "%s", script.c_str());
	
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