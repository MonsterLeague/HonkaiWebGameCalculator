#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Durandal::FisterSkill(HurtPakge& hurtPakge) {
	this->addAttack(3);
	cout << getName() << "�������ܡ�����Ŀ��֡��������������ˣ�" << endl;
}

HurtPakge Durandal::SecondSkill(HurtPakge& hurtPakge) {
	if (getHurt(hurtPakge) >= getHP()) {

	}
}

HurtPakge Durandal::myRound(HurtPakge& hurtPakge) {
	
}

void Durandal::enemyRound(HurtPakge& hurtPakge) {
	
}