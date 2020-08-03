#include "../HeadFolder/Role.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Seele::FisterSkill(HurtPakge& hurtPakge) {
	if (0 == firstFlag) {
		firstFlag = 1;
		cout << getName() << "���һ���������ˣ���һ����QuQ�������������������½���\n";
	}
	else {
		firstFlag = 0;
		cout << "ӵ����������ɣ�ϣ����ϣ��ӵ�����Լ���������HP�ͷ����õ��˻ָ����������½���\n";
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
		mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());//�����������
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