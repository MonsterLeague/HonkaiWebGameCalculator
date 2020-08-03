#include"../HeadFolder/Role.h"
#include"../HeadFolder/HurtPakge.h"
#include <cmath>
#include<random>
#include<chrono>
using namespace std;

HurtPakge Bronya::FisterSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput())) {
		mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//随机数生成器
		int t = rng() % 8;
		if (t <= 5 && t >= 4) {

		}
	}
}

HurtPakge Bronya::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && 0 == hurtPakge.getRound() % secondFlag) {
		mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//随机数生成器
		int eleDamage = rng() % 100 + 1;
		hurtPakge.setEleDamage(eleDamage);
	}
	else;
	return hurtPakge;
}

HurtPakge Bronya::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	return FisterSkill(hurtPakge);
}

void Bronya::enemyRound(HurtPakge& hurtPakge) {
	getHurt(hurtPakge);
}