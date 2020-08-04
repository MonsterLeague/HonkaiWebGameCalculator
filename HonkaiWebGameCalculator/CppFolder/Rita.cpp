#include "../HeadFolder/Role.h"
#include "../HeadFolder/HurtPakge.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Rita::FirstSkill(HurtPakge& hurtPakge) {
	int r = getRandNum() % 100;
	if (isSkillable(hurtPakge.getIsOutput()) && r < 35) {
		int atk = max(hurtPakge.getPhyDamage() - 3, 0);
		hurtPakge.setPhyDamage(atk);
		hurtPakge.setAttackDown(-4);
		if(hurtPakge.getIsOutput())
			cout << getName() << "ʹ���˼��ܡ�Ů�͵������������Է�ʧȥ��ս�⣬�������½��ˣ�\n";
	}
	return hurtPakge;
}

HurtPakge Rita::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && 0 == hurtPakge.getRound() % secondFlag) {
		hurtPakge.init();
		hurtPakge.getEnemy()->addHP(4);
		hurtPakge.setSkillable(2);
		if (!debuffFlag) {
			hurtPakge.setAttackDebuff(-60);
			debuffFlag = true;
		}
		if(hurtPakge.getIsOutput())
			cout << getName() << "ʹ���˼��ܡ��������⡹���Է���ȫ������ˣ����ܶ������ˣ��˺�Ҳ�����ˣ�\n";
	}
	return hurtPakge;
}

HurtPakge Rita::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	if (hurtPakge.getPhyDamage() != 0)
		hurtPakge = FirstSkill(hurtPakge);
	return hurtPakge;
}

void Rita::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}