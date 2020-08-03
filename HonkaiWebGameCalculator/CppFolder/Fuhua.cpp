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
			cout << getName() << "发动技能「凭神化剑」，造成的伤害均为元素伤害" << endl;
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
			cout << getName() << "发动技能「形之笔墨」，对对方造成18点伤害，并使对方命中率降低25%" << endl;
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