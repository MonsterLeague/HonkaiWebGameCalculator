#include"../HeadFolder/role.h"
#include"../HeadFolder/HurtPakge.h"
#include<iostream>
using namespace std;

HurtPakge Raven::FirstSkill(HurtPakge& hurtPakge) {
	if (firstFlag) {
		int num = getRandNum() % 100;
		if (hurtPakge.getEnemy()->getName() == "琪亚娜" || num < 25)
			addAttackDebuff(25);
		if (hurtPakge.getIsOutput())
			cout << getName() << "发动了技能「不是针对你」,对敌人的伤害提高了25%" << endl;
	}
	firstFlag = 0;
	return hurtPakge;
}

HurtPakge Raven::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && hurtPakge.getRound() % secondFlag == 0) {
		hurtPakge.init();
		hurtPakge.setPhyDamage(16);
		hurtPakge.setAttackNum(7);
		hurtPakge.setSuperSkillFlag(1);
		if(hurtPakge.getIsOutput())
			cout << getName() << "发动了技能「别墅小岛」,对敌人造成7次基础数值为16的伤害" << endl;
	}
	return hurtPakge;
}

HurtPakge Raven::myRound(HurtPakge& hurtPakge) {
	FirstSkill(hurtPakge);
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	return hurtPakge;
}

void Raven::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}