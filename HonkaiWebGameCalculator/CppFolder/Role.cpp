#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;

string Role::getName() {
	return name;
}

HurtPakge Role::basicPakge(HurtPakge& hurtPakge) {
	hurtPakge.init();
	hurtPakge.setResource(this);
	hurtPakge.setPhyDamage(attack*(float)(attackDebuff/100.0));
	hurtPakge.setAttackNum(1);
	return hurtPakge;
}

int Role::getHurt(HurtPakge& hurtPakge) {
	int hurt = 0;
	for (int i = 0;i < hurtPakge.getAttackNum;i++) {
		if (hurtPakge.getResource()->isAccuracy())
			hurt += (hurtPakge.getEleDamage() + max(0, (hurtPakge.getPhyDamage() - this->getDefence())));
	}
	return hurt;
}

void Role::cal(HurtPakge& hurtPakge) {
	int hurt = getHurt(hurtPakge);
	this->hp = std::max(0, this->hp - hurt);
	if(hurtPakge.getIsOutput()) 
		cout << getName() << "受到了" << hurt << "点伤害！目前的HP为" << hp << endl;
	if (hurtPakge.getSkillable() == 1) {
		setSkillable(hurtPakge.getSkillable());
		if (hurtPakge.getIsOutput()) 
			cout << getName() << "被沉默了！" << endl;
	}
	if (hurtPakge.getMovable() == 1) {
		setMovable(hurtPakge.getMovable());
		if (hurtPakge.getIsOutput()) 
			cout << getName() << "下回合无法行动！" << endl;
	}
	if (hurtPakge.getAccuracyAffected() != 0) {
		addAccuracy(hurtPakge.getAccuracyAffected());
		if (hurtPakge.getIsOutput()) 
			cout << getName() << "的命中率增加了" << hurtPakge.getAccuracyAffected() << "%" << endl;
	}
	if (hurtPakge.getAttackDebuff()) {
		addAttackDebuff(hurtPakge.getAttackDebuff());
		if (hurtPakge.getIsOutput()) 
			cout << getName() << "的攻击力永久增加了" << hurtPakge.getAttackDebuff() << "%" << endl;
	}
	if (hurtPakge.getAttackDown()) {
		addAttack(hurtPakge.getAttackDown());
		if (hurtPakge.getIsOutput())
			cout << getName() << "的攻击力增加了" << hurtPakge.getAttackDown() << "点" << endl;
	}
	if (hurtPakge.getDeffenceDown()) {
		addAttack(hurtPakge.getDeffenceDown());
		if (hurtPakge.getIsOutput())
			cout << getName() << "的防御力增加了" << hurtPakge.getDeffenceDown() << "点" << endl;
	}
}

void Role::getBurnHurt() {
	if (this->burnTimes) {
		this->hp -= this->burnHurt;
		this->burnTimes--;
	}
}

unsigned int Role::getRandNum() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return rng();
}

void Role::addHP(int blood) {
	this->hp = max(0, min(maxHP, hp + blood));
}

void Role::addAttack(int effect) {
	this->attack = max(0, attack + effect);
}

void Role::addDefence(int effect) {
	this->defence = max(0, defence + effect);
}

bool Role::isAccuracy() {
	int r = getRandNum() % 100;
	if (r < accuracy) return true;
	else return false;
}

void Role::addAccuracy(int effect) {
	accuracy = max(0, min(100, accuracy + effect));
}

void Role::addAttackDebuff(int effect) {
	attackDebuff += effect;
}