#include "../HeadFolder/Role.h"
#include "../HeadFolder/HurtPakge.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Rozaliya::FirstSkill(HurtPakge& hurtPakge) {
	if (superFlag == 0) {
		superFlag = 1;
		setHp(20);
		if (hurtPakge.getIsOutput())
			cout << getName() << "发动技能「96度生命之水」,HP回复至20！" << endl;
	}
	return hurtPakge;
}

HurtPakge Rozaliya::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && superFlag == 1) {
		superFlag = 2;
		hurtPakge.init();
		int num = getRandNum() % 100;
		hurtPakge.setSuperSkillFlag(1);
		if (num < 50) hurtPakge.setPhyDamage(233);
		else hurtPakge.setPhyDamage(50);
		if(hurtPakge.getIsOutput())
			cout << getName() << "发动技能「变成星星吧」,对对方造成" << hurtPakge.getPhyDamage() << "点伤害！" << endl;
	}
	else {
		if (hurtPakge.getIsOutput())
			cout << getName() << "A了出去！对对方造成" << hurtPakge.getPhyDamage() << "点伤害！" << endl;
	}
	return hurtPakge;
}

HurtPakge Rozaliya::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	return SecondSkill(hurtPakge);
}

void Rozaliya::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
	if (getHP() == 0) FirstSkill(hurtPakge);
}