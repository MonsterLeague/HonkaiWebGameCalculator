#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include<iostream>
using namespace std;

HurtPakge Kiana::FirstSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && hurtPakge.getRound() % firstFlag == 0) {
		int def = hurtPakge.getEnemy()->getDefence();
		this->addAttack(def * 2);
		hurtPakge = basicPakge(hurtPakge);
		this->addAttack(-(def * 2));
		hurtPakge.setSuperSkillFlag(1);
		if (hurtPakge.getIsOutput())
			cout << getName() << "发动了技能「吃我一矛！」,本回合攻击力上升两倍对方的防御值" << endl;
		SecondSkill(hurtPakge);
	}
	else {
		hurtPakge = basicPakge(hurtPakge);
	}
	return hurtPakge;
}

HurtPakge Kiana::SecondSkill(HurtPakge& hurtPakge) {
	int num = getRandNum() % 100;
	if (num < 35) {
		setMovable(1);
		if (hurtPakge.getIsOutput())
			cout << getName() << "发动了被动技能「音浪~太强~」,下回合无法行动" << endl;
	}
	return hurtPakge;
}

HurtPakge Kiana::myRound(HurtPakge& hurtPakge) {
	hurtPakge = FirstSkill(hurtPakge);
	return hurtPakge;
}

void Kiana::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}