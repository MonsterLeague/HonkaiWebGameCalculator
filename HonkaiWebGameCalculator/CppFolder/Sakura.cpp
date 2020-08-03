#include "../HeadFolder/Role.h"
#include <cmath>
#include<random>
#include<chrono>
using namespace std;

HurtPakge Sakura::FisterSkill(HurtPakge& hurtPakge) {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//随机数生成器
	if (isSkillable(hurtPakge.getIsOutput())) {
		int t = rng() % 10;
		if (t <= 5 && t >= 3)
			addHP(25);
	}
	else;
	return hurtPakge;
}

HurtPakge Sakura::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && 0 == hurtPakge.getRound() % superFlag) {
		hurtPakge.init();
		hurtPakge.setEleDamage(25);
	}
	else;
	return hurtPakge;
}

HurtPakge Sakura::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	return FisterSkill(hurtPakge);
}

void Sakura::enemyRound(HurtPakge& hurtPakge) {
	getHurt(hurtPakge);
}