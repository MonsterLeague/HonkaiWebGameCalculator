#include"../HeadFolder/role.h"
#include"../HeadFolder/HurtPakge.h"
#include<iostream>
using namespace std;

HurtPakge Raven::FisterSkill(HurtPakge& hurtPakge) {
	if (firstFlag) {
		int num = getRandNum() % 100;
		if (hurtPakge.getResource()->getName() == "������" || num < 25)
			addAttackDebuff(25);
		if (hurtPakge.getIsOutput())
			cout << getName() << "�����˼��ܡ���������㡹,�Ե��˵��˺������25%" << endl;
	}
	firstFlag = 0;
	return hurtPakge;
}

HurtPakge Raven::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && hurtPakge.getRound() % secondFlag == 0) {
		hurtPakge.init();
		hurtPakge.setPhyDamage(16);
		hurtPakge.setAttackNum(7);
		if(hurtPakge.getIsOutput())
			cout << getName() << "�����˼��ܡ�����С����,�Ե������7�λ�����ֵΪ16���˺�" << endl;
	}
	return hurtPakge;
}

HurtPakge Raven::myRound(HurtPakge& hurtPakge) {
	FisterSkill(hurtPakge);
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	return hurtPakge;
}

void Raven::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}