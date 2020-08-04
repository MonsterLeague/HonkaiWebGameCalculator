#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Durandal::FirstSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput())) {
		this->addAttack(3);
		if(hurtPakge.getIsOutput())
			cout << getName() << "�������ܡ�����Ŀ��֡��������������ˣ�" << endl;
	}
	return hurtPakge;
}

HurtPakge Durandal::SecondSkill(HurtPakge& hurtPakge) {
	if (hurtPakge.getSuperSkillFlag() > 0) {
		int num = getRandNum() % 100;
		if (num < 16) {
			hurtPakge.getEnemy()->addHP(-30);
			hurtPakge.init();
			hurtPakge.setPhyDamage(-1);
			if (hurtPakge.getIsOutput())
				cout << getName() << "�������ܡ�������������Ч��������Ч�˶Է��Ĺ�����������Է�30���˺�" << endl;
		}
	}
	return hurtPakge;
}

HurtPakge Durandal::myRound(HurtPakge& hurtPakge) {
	FirstSkill(hurtPakge);
	return basicPakge(hurtPakge);
}

void Durandal::enemyRound(HurtPakge& hurtPakge) {
	SecondSkill(hurtPakge);
	if (getHurt(hurtPakge) != -1)
		cal(hurtPakge);
	else
		hurtPakge.init();
}