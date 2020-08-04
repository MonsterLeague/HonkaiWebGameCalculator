#include "../HeadFolder/Role.h"
#include "../HeadFolder/HurtPakge.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Rozaliya::FirstSkill(HurtPakge& hurtPakge) {
	if (superFlag == 0) {
		superFlag = 1;
		setHp(20);
		if (hurtPakge.getIsOutput())
			cout << getName() << "�������ܡ�96������֮ˮ��,HP�ظ���20��" << endl;
	}
	return hurtPakge;
}

HurtPakge Rozaliya::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && superFlag == 1) {
		superFlag = 2;
		hurtPakge.init();
		int num = getRandNum() % 100;
		hurtPakge.setSuperSkillFlag(1);
		if (num < 50) hurtPakge.setPhyDamage(233);
		else hurtPakge.setPhyDamage(50);
		if(hurtPakge.getIsOutput())
			cout << getName() << "�������ܡ�������ǰɡ�,�ԶԷ����" << hurtPakge.getPhyDamage() << "���˺���" << endl;
	}
	else {
		if (hurtPakge.getIsOutput())
			cout << getName() << "A�˳�ȥ���ԶԷ����" << hurtPakge.getPhyDamage() << "���˺���" << endl;
	}
	return hurtPakge;
}

HurtPakge Rozaliya::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	return SecondSkill(hurtPakge);
}

void Rozaliya::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
	if (getHP() == 0) FirstSkill(hurtPakge);
}