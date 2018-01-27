#include "stdafx.h"
#include "dialogueManager.h"


dialogueManager::dialogueManager()
{
}


dialogueManager::~dialogueManager()
{
}

HRESULT dialogueManager::init(float dt, LANGUAGE lan)
{
	_dialogueTime = dt;
	_elapsedTime = 0;
	_language = lan;
	return S_OK;
}
HRESULT dialogueManager::init(float dt, int printLines, LANGUAGE lan)
{
	_dialogueTime = dt;
	_elapsedTime = 0;
	_printLinesNum = printLines;
	_language = lan;

	_length = new int[_printLinesNum];

	return S_OK;
}

void dialogueManager::release()
{
	SAFE_DELETE_ARRAY(_length);
}

void dialogueManager::update()
{
	_elapsedTime++;
	if (_elapsedTime % _dialogueTime == 0)
	{
		for (int i = 0; i < _printLinesNum; ++i)
		{
			if (i >= _vString.size()) break;
			if (_currentLine + i >= _vString.size()) break;
			if (_length[i] >= strlen(_vString[_currentLine + i].c_str())) continue;

			_length[i] += _language;
			if (_length[i] > strlen(_vString[_currentLine + i].c_str()))
				_length[i] = strlen(_vString[_currentLine + i].c_str());

			break;
		}
	}
}

void dialogueManager::render(HDC hdc)
{
	for (int i = 0; i < _printLinesNum; ++i)
	{
		if (i >= _vString.size()) break;
		if (_currentLine + i >= _vString.size()) break;

		TextOut(hdc, _startX, _startY + 20 * i, _vString[_currentLine + i].c_str(), _length[i]);
	}
}

void dialogueManager::loadingTextFile(const char* fileName)
{
	// �ϴ� ���� ����
	_vString.clear();

	// �� ó�� ������ �߰� �ϰ�
	_currentLine = 0;

	for (int i = 0; i < _printLinesNum; ++i)
		_length[i] = 0;

	// Text������ �о�ͼ� ���Ϳ� �־���
	_vString = TXTDATA->txtLoad(fileName);
}

//								  	    from��	    		to�� �ٲ���
void dialogueManager::replaceAll(const string from, const string to)
{
	for (int i = 0; i < _vString.size(); ++i)
	{
		size_t start_pos = 0; //stringó������ �˻�

		while ((start_pos = _vString[i].find(from, start_pos)) != std::string::npos)  //from�� ã�� �� ���� ������
		{
			_vString[i].replace(start_pos, from.length(), to);
			start_pos += to.length(); // �ߺ��˻縦 ���ϰ� from.length() > to.length()�� ��츦 ���ؼ�
		}
	}
}