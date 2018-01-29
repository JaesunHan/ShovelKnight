#include "stdafx.h"
#include "playGround.h"




void playGround::addSound()
{
	SOUNDMANAGER->addSound("GamePlayBGM", "./sound/ost/Shovel Knight Soundtrack - 04 - Strike the Earth! (Plains of Passage).mp3", true, true);
	SOUNDMANAGER->addSound("BardKnightChange1", "./sound/ost/Shovel Knight Soundtrack - 05 - The Rival (Black Knight - First Battle).mp3", true, true);
	SOUNDMANAGER->addSound("BardKnightChange2", "./sound/ost/Shovel Knight Soundtrack - 06 - For Shovelry! (Boss Victory).mp3", true, true);
	SOUNDMANAGER->addSound("BardKnightChange3", "./sound/ost/Shovel Knight Soundtrack - 17 - The Local Happenstance (Village Basement).mp3", true, true);

	//==========================����Ʈ ���� ����==============================================/

	//========���� ���û���=========//
	SOUNDMANAGER->addSound("������߻����", "./sound/EFFECTSOUND/blackKnightAirAttackSound.mp3", false, false);
	SOUNDMANAGER->addSound("������", "./sound/EFFECTSOUND/blackKnightDialogSound.mp3", false, false);
	SOUNDMANAGER->addSound("������ǳ", "./sound/EFFECTSOUND/blackKnightJangPung.mp3", false, false);
	SOUNDMANAGER->addSound("�������", "./sound/EFFECTSOUND/blackKnightJangPung.mp3", false, false);
	SOUNDMANAGER->addSound("���簡�����̱���", "./sound/EFFECTSOUND/defeatSound.mp3", false, false);
	SOUNDMANAGER->addSound("��ǳ�ݻ�", "./sound/EFFECTSOUND/reflectJangPung.mp3", false, false);
	SOUNDMANAGER->addSound("���絵��������", "./sound/EFFECTSOUND/runawaySound.mp3", false, false);
	SOUNDMANAGER->addSound("������������¼Ҹ�", "./sound/EFFECTSOUND/setBlackKnightHealthSound.mp3", false, false);
	SOUNDMANAGER->addSound("�����ȭ", "./sound/EFFECTSOUND/shovelKnightDialogSound.mp3", false, false);

	//========���ʹ� ���� ����========//

	SOUNDMANAGER->addSound("���ǰ�ջ�", "./sound/EFFECTSOUND/dragonBubbleShootSound.mp3", false, false);
	SOUNDMANAGER->addSound("���̵�", "./sound/EFFECTSOUND/dragonMove.mp3", false, false);
	SOUNDMANAGER->addSound("���ǰݽ�", "./sound/EFFECTSOUND/dragonUnderAttacked.mp3", false, false);
	SOUNDMANAGER->addSound("���̶�������������", "./sound/EFFECTSOUND/DropJewelEatSound.mp3", false, false);
	SOUNDMANAGER->addSound("��������¼Ҹ�", "./sound/EFFECTSOUND/blackKnightJangPung.mp3", false, false);
	SOUNDMANAGER->addSound("�����ǰݽ�", "./sound/EFFECTSOUND/monsterAttackedSound.mp3", false, false);
	SOUNDMANAGER->addSound("��������", "./sound/EFFECTSOUND/monsterExplosionSound.mp3", false, false);
	SOUNDMANAGER->addSound("�ٴ��ذ�", "./sound/EFFECTSOUND/skeletonThrowSound.mp3", false, false);
	SOUNDMANAGER->addSound("����������", "./sound/EFFECTSOUND/slimeJumpSound.mp3", false, false);

	//=========���� ���� ����===========//
	SOUNDMANAGER->addSound("ü��Ǯ����", "./sound/EFFECTSOUND/fullHeartSound.mp3", false, false);
	SOUNDMANAGER->addSound("��������", "./sound/EFFECTSOUND/DieSound.mp3", false, false);
	SOUNDMANAGER->addSound("������߻����", "./sound/EFFECTSOUND/ShovelAirAttackSound.mp3", false, false);
	SOUNDMANAGER->addSound("�����Ϲݰ���", "./sound/EFFECTSOUND/shovelAttSound.mp3", false, false);
	SOUNDMANAGER->addSound("���纸��������", "./sound/EFFECTSOUND/shovelingSound.mp3", false, false);
	SOUNDMANAGER->addSound("�����ǰ�", "./sound/EFFECTSOUND/underAttack.mp3", false, false);
	SOUNDMANAGER->addSound("������������������", "./sound/EFFECTSOUND/jumpSound.mp3", false, false);
	SOUNDMANAGER->addSound("�������", "./sound/EFFECTSOUND/knightEnter.mp3", false, false);


	//=========�ΰ��� ����Ʈ����=========//
	SOUNDMANAGER->addSound("���ߺ���������", "./sound/EFFECTSOUND/jewelEatSound.mp3", false, false);
	SOUNDMANAGER->addSound("���͵������������", "./sound/EFFECTSOUND/jewelMonsterDropSound.mp3", false, false);
	SOUNDMANAGER->addSound("����������������", "./sound/EFFECTSOUND/jewelsSound.mp3", false, false);
	SOUNDMANAGER->addSound("�װ��������޸����ָӴϵ���", "./sound/EFFECTSOUND/DieAfterSound(��ã�ƶ����).mp3", false, false);
	SOUNDMANAGER->addSound("����", "./sound/EFFECTSOUND/explosion.mp3", false, false);
	SOUNDMANAGER->addSound("���̺�", "./sound/EFFECTSOUND/SaveSound.mp3", false, false);
	
	
	
	//==========�ɼ�â ����Ʈ����===========//
	
	SOUNDMANAGER->addSound("����Ʈ���弱��", "./sound/EFFECTSOUND/effectSoundSelect.mp3", false, false);
	SOUNDMANAGER->addSound("�ɼǴݱ�", "./sound/EFFECTSOUND/optionClose.mp3", false, false);
	SOUNDMANAGER->addSound("�ɼǿ����̱�", "./sound/EFFECTSOUND/optionMove.mp3", false, false);
	SOUNDMANAGER->addSound("�ɼǿ���", "./sound/EFFECTSOUND/optionOpen.mp3", false, false);
	SOUNDMANAGER->addSound("�ɼǼ���", "./sound/EFFECTSOUND/optionSelect.mp3", false, false);
	SOUNDMANAGER->addSound("Ÿ��Ʋ����Ʈ", "./sound/EFFECTSOUND/selectSound.mp3", false, false);
	SOUNDMANAGER->addSound("����簢��������", "./sound/EFFECTSOUND/strawCrashSound.mp3", false, false);
	
	
	
	
}