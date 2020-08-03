#include "../HeadFolder/Role.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Theresa::FisterSkill(HurtPakge& hurtPakge) {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//�����������
	int t = rng() % 10;
	if (t <= 5 && t >= 3) {
		hurtPakge.setDeffenceDown(5);
		cout << getName() << "�ͷż���Ѫ�̴��һ�ɰ�����ֵķ����½��ˣ�\n";
	}
}

HurtPakge Theresa::SecondSkill(HurtPakge& hurtPakge) {
	if (isSkillable(hurtPakge.getIsOutput()) && 0 == hurtPakge.getRound() % superFlag) {
		hurtPakge.init();
		hurtPakge.setPhyDamage(16);
		hurtPakge.setAttackNum(5);
		cout << "����ɯ�����ˣ�ʹ�����������ˣ�\n";
	}
	return hurtPakge;
}

void Theresa::enemyRound(HurtPakge& hurtPakge) {
	getHurt(hurtPakge);
}

HurtPakge Theresa::myRound(HurtPakge& hurtPakge) {
	hurtPakge = basicPakge(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	return FisterSkill(hurtPakge);
}