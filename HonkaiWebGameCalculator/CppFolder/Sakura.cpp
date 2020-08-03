#include "../HeadFolder/Role.h"
#include<iostream>
using namespace std;

HurtPakge Sakura::FirstSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput())) {
		int t = getRandNum() % 10;
		if (t <= 5 && t >= 3) {
			addHP(25);
			if (hurtPakge.getIsOutput())
				cout << getName() << "�����˼��ܡ�����ӣ�ķ��š�,���������˻��Ű���ӣ��֭�ķ���,hp������!" << endl;
		}
	}
	return hurtPakge;
}

HurtPakge Sakura::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && 0 == hurtPakge.getRound() % superFlag) {
		hurtPakge.init();
		hurtPakge.setEleDamage(25);
		hurtPakge.setSuperSkillFlag(1);
		if(hurtPakge.getIsOutput())
			cout << getName() << "�����˼��ܡ������ķ��š�,�޴�ķ��ŶԵ�������˳ɶֵ��˺�!" << endl;
	}
	return hurtPakge;
}

HurtPakge Sakura::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	return FirstSkill(hurtPakge);
}

void Sakura::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}