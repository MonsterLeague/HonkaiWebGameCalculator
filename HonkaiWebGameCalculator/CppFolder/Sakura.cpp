#include "../HeadFolder/Role.h"
#include<iostream>
using namespace std;

HurtPakge Sakura::FirstSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput())) {
		int t = getRandNum() % 10;
		if (t <= 5 && t >= 3) {
			addHP(25);
			if (hurtPakge.getIsOutput())
				cout << getName << "发动了技能「八重樱的饭团」,卡莲吃下了混着八重樱妹汁的饭团,hp上升了!" << endl;
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
			cout << getName << "发动了技能「卡莲的饭团」,巨大的饭团对敌人造成了成吨的伤害!" << endl;
	}
	return hurtPakge;
}

HurtPakge Sakura::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	return FirstSkill(hurtPakge);
}

void Sakura::enemyRound(HurtPakge& hurtPakge) {
	getHurt(hurtPakge);
}