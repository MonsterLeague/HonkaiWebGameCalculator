#include "../HeadFolder/Role.h"
#include"../HeadFolder/HurtPakge.h"
#include<iostream>
using namespace std;

HurtPakge Theresa::FirstSkill(HurtPakge& hurtPakge) {
	int t = getRandNum() % 10;
	if (t <= 5 && t >= 3) {
		hurtPakge.setDeffenceDown(-5);
		if(hurtPakge.getIsOutput())
			cout << getName() << "�ͷż��ܡ�Ѫ�̴��һ�ɰ���,��ֵķ����½��ˣ�\n";
	}
	return hurtPakge;
}

HurtPakge Theresa::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && 0 == hurtPakge.getRound() % superFlag) {
		hurtPakge.init();
		hurtPakge.setPhyDamage(16);
		hurtPakge.setAttackNum(5);
		hurtPakge.setSuperSkillFlag(1);
		if(hurtPakge.getIsOutput())
			cout << getName() << "�����ˣ�ʹ���˼��ܡ��������ˡ���\n";
	}
	return hurtPakge;
}

void Theresa::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}

HurtPakge Theresa::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	return FirstSkill(hurtPakge);
}