#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Fuhua::FisterSkill(HurtPakge& hurtPakge) {
	hurtPakge.setEleDamage(hurtPakge.getPhyDamage());
	return hurtPakge;
}

HurtPakge Fuhua::SecondSkill(HurtPakge& hurtPakge) {
	if (getSkillable() != 0) {
		secondFlag++;
		setSkillable(getSkillable() - 1);
		if (hurtPakge.getIsOutput())
			cout << getName() << "��Ϊ��Ĭ�޷��ͷż���" << endl;
		return hurtPakge;
	}
	if (secondFlag == 2) {
		hurtPakge.init();
		hurtPakge.setAttackNum(1);
		hurtPakge.setPhyDamage(18);
		hurtPakge.setAccuracyAffected(-25);
		cout << getName() << "�ͷż�����֮��ī���ԶԷ����18���˺�����ʹ�Է������ʽ���25%" << endl;
		secondFlag = 0;
	}
	else
		secondFlag++;
	return hurtPakge;
}

void Fuhua::enemyRound(HurtPakge& hurtPakge) {
	getHurt(hurtPakge);
}

HurtPakge Fuhua::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	return FisterSkill(hurtPakge);
}