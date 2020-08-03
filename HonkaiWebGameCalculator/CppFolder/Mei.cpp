#include"../HeadFolder/Role.h"
#include"../HeadFolder/HurtPakge.h"
#include<iostream>
using namespace std;

HurtPakge Mei::FirstSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput())) {
		int num = getRandNum() % 100;
		if (num < 30) {
			hurtPakge.setMovable(1);
			if (hurtPakge.getIsOutput())
				cout << getName() << "�����˼��ܡ���������ĸ輧��,����˶Է�һ���غ�" << endl;
		}
	}
	return hurtPakge;
}

HurtPakge Mei::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && hurtPakge.getRound() % secondFlag == 0) {
		hurtPakge.init();
		hurtPakge.setEleDamage(3);
		hurtPakge.setAttackNum(5);
		hurtPakge.setSuperSkillFlag(1);
		if (hurtPakge.getIsOutput())
			cout << getName() << "�����˼��ܡ��׵�ҵ���Ů�͡�,�ٻ�����٤�޶ԶԷ����5��3�����ӷ�����Ԫ�ع���" << endl;
	}
	return hurtPakge;
}

HurtPakge Mei::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	hurtPakge = FirstSkill(hurtPakge);
	return hurtPakge;
}

void Mei::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}