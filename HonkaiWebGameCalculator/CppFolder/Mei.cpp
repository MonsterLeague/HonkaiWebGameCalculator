#include"../HeadFolder/Role.h"
#include"../HeadFolder/HurtPakge.h"
#include<iostream>
using namespace std;

HurtPakge Mei::FisterSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput())) {
		int num = getRandNum() % 100;
		if (num < 30) {
			hurtPakge.setMovable(1);
			if (hurtPakge.getIsOutput())
				cout << getName() << "发动了技能「崩坏世界的歌姬」,麻痹了对方一个回合" << endl;
		}
	}
	return hurtPakge;
}

HurtPakge Mei::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && hurtPakge.getRound() % secondFlag == 0) {
		hurtPakge.init();
		hurtPakge.setEleDamage(3);
		hurtPakge.setAttackNum(5);
		if (hurtPakge.getIsOutput())
			cout << getName() << "发动了技能「雷电家的龙女仆」,召唤俱利伽罗对对方造成5次3点无视防御的元素攻击" << endl;
	}
	return hurtPakge;
}

HurtPakge Mei::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	hurtPakge = FisterSkill(hurtPakge);
	return hurtPakge;
}

void Mei::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}