#include"../HeadFolder/role.h"
#include"../HeadFolder/HurtPakge.h"
#include<iostream>
using namespace std;

HurtPakge Himeko::FisterSkill(HurtPakge& hurtPakge) {
	if (firstFlag && !hurtPakge.getResource()->getMember()) {
		this->addAttackDebuff(100);
		if (hurtPakge.getIsOutput())
			cout << getName() << "�������ܡ��氮������,�ԶԷ���ɵ��˺����100%" << endl;
	}
	firstFlag = 0;
	return hurtPakge;
}

HurtPakge Himeko::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && hurtPakge.getRound() % secondFlag == 0) {
		addAttack(getAttack());
		addAccuracy(-35);
		if (hurtPakge.getIsOutput())
			cout << getName() << "�������ܡ��ɱ������ѡ�,�������������������½���" << endl;
	}
	return hurtPakge;
}

HurtPakge Himeko::myRound(HurtPakge& hurtPakge) {
	FisterSkill(hurtPakge);
	SecondSkill(hurtPakge);
	hurtPakge = basicPakge(hurtPakge);
	return hurtPakge;
}

void Himeko::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}