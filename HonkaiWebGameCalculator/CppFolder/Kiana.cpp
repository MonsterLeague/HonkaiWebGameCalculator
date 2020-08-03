#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include<iostream>
using namespace std;

HurtPakge Kiana::FirstSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && hurtPakge.getRound() % firstFlag == 0) {
		int def = hurtPakge.getEnemy()->getDefence();
		this->addAttack(def * 2);
		hurtPakge = basicPakge(hurtPakge);
		this->addAttack(-(def * 2));
		hurtPakge.setSuperSkillFlag(1);
		if (hurtPakge.getIsOutput())
			cout << getName() << "�����˼��ܡ�����һì����,���غϹ��������������Է��ķ���ֵ" << endl;
		SecondSkill(hurtPakge);
	}
	else {
		hurtPakge = basicPakge(hurtPakge);
	}
	return hurtPakge;
}

HurtPakge Kiana::SecondSkill(HurtPakge& hurtPakge) {
	int num = getRandNum() % 100;
	if (num < 35) {
		setMovable(1);
		if (hurtPakge.getIsOutput())
			cout << getName() << "�����˱������ܡ�����~̫ǿ~��,�»غ��޷��ж�" << endl;
	}
	return hurtPakge;
}

HurtPakge Kiana::myRound(HurtPakge& hurtPakge) {
	hurtPakge = FirstSkill(hurtPakge);
	return hurtPakge;
}

void Kiana::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}