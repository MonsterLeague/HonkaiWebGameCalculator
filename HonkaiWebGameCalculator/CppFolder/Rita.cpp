#include "../HeadFolder/Role.h"
#include "../HeadFolder/HurtPakge.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Rita::FirstSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && 0 != hurtPakge.getRound() % secondFlag) {
		int atk = max(hurtPakge.getPhyDamage() - 3, 0);
		hurtPakge.setPhyDamage(atk);
		hurtPakge.setAttackDebuff(-4);
		cout << getName() << "ʹ���˼���Ů�͵����������Է�ʧȥ��ս�⣬�������½��ˣ�\n";
	}
	return hurtPakge;
}

HurtPakge Rita::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && 0 == hurtPakge.getRound() % secondFlag) {
		hurtPakge.getEnemy()->addHP(4);
		hurtPakge.setSkillable(false);
		if (!debuffFlag) {
			hurtPakge.setAttackDebuff(-60);
			debuffFlag = true;
		}
		cout << getName() << "ʹ���˼����������⣡�Է���ȫ������ˣ����ܶ������ˣ��˺�Ҳ�����ˣ�\n";
	}
	if (2 == hurtPakge.getRound() % secondFlag) {
		hurtPakge.setSkillable(true);
	}
	return hurtPakge;
}

HurtPakge Rita::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	return FirstSkill(hurtPakge);
}

void Rita::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}