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
			cout << getName() << "因为沉默无法释放技能" << endl;
		return hurtPakge;
	}
	if (secondFlag == 2) {
		hurtPakge.init();
		hurtPakge.setAttackNum(1);
		hurtPakge.setPhyDamage(18);
		hurtPakge.setAccuracyAffected(-25);
		cout << getName() << "释放技能形之笔墨，对对方造成18点伤害，并使对方命中率降低25%" << endl;
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