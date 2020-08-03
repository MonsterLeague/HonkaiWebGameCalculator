#include "../HeadFolder/Role.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Seele::FirstSkill(HurtPakge& hurtPakge) {
	if (0 == firstFlag) {
		firstFlag = 1;
		if(hurtPakge.getIsOutput())
			cout << getName() << "大吼一声：“拜托了，另一个我QuQ”,发动了技能「我 换 我 自 己」,里人格登场了!\n";
	}
	else {
		firstFlag = 0;
		if (hurtPakge.getIsOutput())
			cout << getName() << "“拥抱你的力量吧，希儿！”,希儿发动了技能「我 换 我 自 己」,表人格登场了!\n";
	}
	return hurtPakge;
}

HurtPakge Seele::SecondSkill(HurtPakge& hurtPakge) {
	if (1 == firstFlag) {
		addAttack(10);
		addDefence(-5);
		if (hurtPakge.getIsOutput())
			cout << getName() << "里人格发动了技能「拜托了另一个我」,攻击力上升,但防御下降了\n";
	}
	else if (0 == firstFlag) {
		addAttack(-10);
		addDefence(5);
		int hpAdd = 1 + getRandNum() % 15;
		addHP(hpAdd);
		if (hurtPakge.getIsOutput())
			cout << getName() << "表人格发动了技能「拜托了另一个我」，HP和防御得到了恢复，攻击力下降了\n";
	}
	return hurtPakge;
}

HurtPakge Seele::myRound(HurtPakge& hurtPakge) {
	FirstSkill(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	hurtPakge = basicPakge(hurtPakge);
	return hurtPakge;
}

void Seele::enemyRound(HurtPakge& hurtPakge) {
	cal(hurtPakge);
}