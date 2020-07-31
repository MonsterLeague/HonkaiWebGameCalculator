#include "role.h"
#include <cmath>
#include<random>
#include<chrono>
using namespace std;

HurtPakge Theresa::passiveSkill(HurtPakge hurtPakge) {
	hurtPakge.setEleDamage(ceil((double)hurtPakge.getEleDamage()*0.5));
	return hurtPakge;
}

HurtPakge Theresa::superSkill(HurtPakge hurtPakge) {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//�����������
	if (superFlag) {
		int hurt = 0;
		for (int i = 0;i < 4;i++) {
			hurt += rng() % 16 + 1;
		}
		hurtPakge.setEleDamage(hurt);
		hurtPakge.setPhyDamage(0);
		superFlag = 0;
	}
	else superFlag++;
	return hurtPakge;
}

HurtPakge Theresa::myRound() {
	HurtPakge hurtPakge = HurtPakge(this->getAttack(), 0);
	HurtPakge superHurt = superSkill(hurtPakge);
	if (!(this->getSkillable())) hurtPakge = superHurt;
	this->setSkillable(0);
	this->setSpeed(0);
	if(this)
	return hurtPakge;
}

void Theresa::enemyRound(HurtPakge hurtPakge) {
	hurtPakge = passiveSkill(hurtPakge);
	int hurt = hurtPakge.getEleDamage() + (hurtPakge.getPhyDamage() - this->getDefence());
	this->getHurt(hurt);
	this->setSpeed(100);
}