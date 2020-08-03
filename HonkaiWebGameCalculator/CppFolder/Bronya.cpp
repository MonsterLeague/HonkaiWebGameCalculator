#include"../HeadFolder/Role.h"
#include"../HeadFolder/HurtPakge.h"
#include<iostream>
using namespace std;

HurtPakge Bronya::FirstSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput())) {
		int t = getRandNum() % 8;
		if (t <= 5 && t >= 4) {
			firstFLag->cal(hurtPakge);
			hurtPakge.init();
			hurtPakge.setAttackNum(4);
			hurtPakge.setPhyDamage(12);
			if (hurtPakge.getIsOutput())
				cout << getName() << "�����˼��ܡ���ʹ�ع���,�Ե��������4�λ�����ֵΪ12���˺�!" << endl;
		}
	}
	return hurtPakge;
}

HurtPakge Bronya::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && 0 == hurtPakge.getRound() % secondFlag) {
		hurtPakge.init();
		int eleDamage = getRandNum() % 100 + 1;
		hurtPakge.setEleDamage(eleDamage);
		hurtPakge.setSuperSkillFlag(1);
		if (hurtPakge.getIsOutput())
			cout << getName() << "�����˼��ܡ�Ħ�аݿ��գ���,��Ħ�г���ѹ�˶���!" << endl;
	}
	return hurtPakge;
}

HurtPakge Bronya::myRound(HurtPakge& hurtPakge) {
	firstFLag = hurtPakge.getEnemy();
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	hurtPakge = FirstSkill(hurtPakge);
	return hurtPakge;
}

void Bronya::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}