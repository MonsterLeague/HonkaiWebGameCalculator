#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Durandal::FisterSkill(HurtPakge& hurtPakge) {
	this->addAttack(3);
	cout << getName() << "发动技能「摸鱼的快乐」，攻击力提升了！" << endl;
}

HurtPakge Durandal::SecondSkill(HurtPakge& hurtPakge) {
	if (getHurt(hurtPakge) >= getHP()) {

	}
}

HurtPakge Durandal::myRound(HurtPakge& hurtPakge) {
	
}

void Durandal::enemyRound(HurtPakge& hurtPakge) {
	
}