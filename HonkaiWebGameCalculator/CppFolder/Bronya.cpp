#include"../HeadFolder/role.h"
#include"../HeadFolder/HurtPakge.h"
#include <cmath>
#include<random>
#include<chrono>
using namespace std;

HurtPakge Bronya::FisterSkill(HurtPakge& hurtPakge) {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//随机数生成器
	int t = rng() % 20;
	if (t >= 8 && t <= 10) {//15%概率
		hurtPakge.setPhyDamage(0);
		hurtPakge.setEleDamage(0);
	}
	return hurtPakge;
}

HurtPakge Bronya::SecondSkill(HurtPakge& hurtPakge) {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//随机数生成器
	if (this->superFlag == 2) {
		int hurt = rng() % 100 + 1;
		hurtPakge = HurtPakge(hurt, 0);
		superFlag = 0;
	}
	else this->superFlag++;
	return hurtPakge;
}

HurtPakge Bronya::myRound(HurtPakge& hurtPakge) {
	HurtPakge hurtPakge = HurtPakge(this->getAttack(), 0);
	hurtPakge = SecondSkill(hurtPakge);
	this->setSpeed(0);
	return hurtPakge;
}

void Bronya::enemyRound(HurtPakge& hurtPakge) {
	hurtPakge = FisterSkill(hurtPakge);
	int hurt = hurtPakge.getEleDamage() + (hurtPakge.getPhyDamage() - this->getDefence());
	this->getHurt(hurt);
	this->setSpeed(100);
}