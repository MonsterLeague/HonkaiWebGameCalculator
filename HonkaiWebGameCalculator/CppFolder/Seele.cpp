#include "../HeadFolder/Role.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Seele::FisterSkill(HurtPakge& hurtPakge) {
	if (0 == firstFlag) {
		firstFlag = 1;
		cout << getName() << "大吼一声：拜托了，另一个我QuQ，攻击上升，但防御下降了\n";
	}
	else {
		firstFlag = 0;
		cout << "拥抱你的力量吧，希儿！希儿拥抱了自己的力量，HP和防御得到了恢复，但攻击下降了\n";
	}
	return hurtPakge;
}

HurtPakge Seele::SecondSkill(HurtPakge& hurtPakge) {
	if (1 == firstFlag) {
		addAttack(10);
		addDefence(-5);
	}
	else if (0 == firstFlag) {
		addAttack(-10);
		addDefence(5);
		mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//随机数生成器
		int hpAdd = 1 + rng() % 15;
		addHP(hpAdd);
	}
	return hurtPakge;
}

HurtPakge Seele::myRound(HurtPakge& hurtPakge) {
	FisterSkill(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	hurtPakge = basicPakge(hurtPakge);
	return hurtPakge;
}

void Seele::enemyRound(HurtPakge& hurtPakge) {
	getHurt(hurtPakge);
}