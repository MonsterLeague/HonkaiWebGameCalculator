#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Durandal::FirstSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput())) {
		this->addAttack(3);
		if(hurtPakge.getIsOutput())
			cout << getName() << "发动技能「摸鱼的快乐」，攻击力提升了！" << endl;
	}
	return hurtPakge;
}

HurtPakge Durandal::SecondSkill(HurtPakge& hurtPakge) {
	if (hurtPakge.getSuperSkillFlag() > 0) {
		int num = getRandNum() % 100;
		if (num < 16) {
			hurtPakge.getEnemy()->addHP(-30);
			hurtPakge.init();
			hurtPakge.setPhyDamage(-1);
			if (hurtPakge.getIsOutput())
				cout << getName() << "发动技能「反弹！反弹无效！」，无效了对方的攻击，并给予对方30点伤害" << endl;
		}
	}
	return hurtPakge;
}

HurtPakge Durandal::myRound(HurtPakge& hurtPakge) {
	FirstSkill(hurtPakge);
	return basicPakge(hurtPakge);
}

void Durandal::enemyRound(HurtPakge& hurtPakge) {
	SecondSkill(hurtPakge);
	if (getHurt(hurtPakge) != -1)
		cal(hurtPakge);
	else
		hurtPakge.init();
}