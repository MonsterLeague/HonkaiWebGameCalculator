#include "../HeadFolder/Role.h"
#include"../HeadFolder/HurtPakge.h"
#include<iostream>
using namespace std;

HurtPakge Theresa::FirstSkill(HurtPakge& hurtPakge) {
	int t = getRandNum() % 10;
	if (t <= 5 && t >= 3) {
		hurtPakge.setDeffenceDown(5);
		if(hurtPakge.getIsOutput())
			cout << getName() << "释放技能「血犹大第一可爱」,奇怪的防御下降了！\n";
	}
}

HurtPakge Theresa::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && 0 == hurtPakge.getRound() % superFlag) {
		hurtPakge.init();
		hurtPakge.setPhyDamage(16);
		hurtPakge.setAttackNum(5);
		hurtPakge.setSuperSkillFlag(1);
		if(hurtPakge.getIsOutput())
			cout << getName() << "生气了！使用了技能「在线踢人」！\n";
	}
	return hurtPakge;
}

void Theresa::enemyRound(HurtPakge& hurtPakge) {
	getHurt(hurtPakge);
}

HurtPakge Theresa::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	return FirstSkill(hurtPakge);
}