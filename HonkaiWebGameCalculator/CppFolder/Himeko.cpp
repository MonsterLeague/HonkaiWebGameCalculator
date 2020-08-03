#include"../HeadFolder/role.h"
#include"../HeadFolder/HurtPakge.h"
#include<iostream>
using namespace std;

HurtPakge Himeko::FirstSkill(HurtPakge& hurtPakge) {
	if (firstFlag && !hurtPakge.getEnemy()->getMember()) {
		this->addAttackDebuff(100);
		if (hurtPakge.getIsOutput())
			cout << getName() << "发动技能「真爱不死」,对对方造成的伤害提高100%" << endl;
	}
	firstFlag = 0;
	return hurtPakge;
}

HurtPakge Himeko::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && hurtPakge.getRound() % secondFlag == 0) {
		addAttack(getAttack());
		addAccuracy(-35);
		if (hurtPakge.getIsOutput())
			cout << getName() << "发动技能「干杯，朋友」,攻击力翻倍但命中率下降了" << endl;
	}
	return hurtPakge;
}

HurtPakge Himeko::myRound(HurtPakge& hurtPakge) {
	FirstSkill(hurtPakge);
	SecondSkill(hurtPakge);
	hurtPakge = basicPakge(hurtPakge);
	return hurtPakge;
}

void Himeko::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}