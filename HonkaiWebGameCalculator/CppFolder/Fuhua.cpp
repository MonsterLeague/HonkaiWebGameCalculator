#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Fuhua::FirstSkill(HurtPakge& hurtPakge) {
	hurtPakge.setEleDamage(hurtPakge.getPhyDamage());
	hurtPakge.setPhyDamage(0);
	if (firstFlag) {
		firstFlag = 0;
		if(hurtPakge.getIsOutput())
			cout << getName() << "�������ܡ�ƾ�񻯽�������ɵ��˺���ΪԪ���˺�" << endl;
	}
	return hurtPakge;
}

HurtPakge Fuhua::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && hurtPakge.getRound() % secondFlag == 0) {
		hurtPakge.init();
		hurtPakge.setAttackNum(1);
		hurtPakge.setPhyDamage(18);
		hurtPakge.setAccuracyAffected(-25);
		hurtPakge.setSuperSkillFlag(1);
		if (hurtPakge.getIsOutput())
			cout << getName() << "�������ܡ���֮��ī�����ԶԷ����18���˺�����ʹ�Է������ʽ���25%" << endl;
	}
	return hurtPakge;
}

void Fuhua::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}

HurtPakge Fuhua::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	return FirstSkill(hurtPakge);
}