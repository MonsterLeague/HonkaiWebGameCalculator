#include "../HeadFolder/Role.h"
#include <cmath>
#include<random>
#include<chrono>
#include<iostream>
using namespace std;

HurtPakge Seele::FirstSkill(HurtPakge& hurtPakge) {
	if (0 == firstFlag) {
		firstFlag = 1;
		if(hurtPakge.getIsOutput())
			cout << getName() << "���һ�����������ˣ���һ����QuQ��,�����˼��ܡ��� �� �� �� ����,���˸�ǳ���!\n";
	}
	else {
		firstFlag = 0;
		if (hurtPakge.getIsOutput())
			cout << getName() << "��ӵ����������ɣ�ϣ������,ϣ�������˼��ܡ��� �� �� �� ����,���˸�ǳ���!\n";
	}
	return hurtPakge;
}

HurtPakge Seele::SecondSkill(HurtPakge& hurtPakge) {
	if (1 == firstFlag) {
		addAttack(10);
		addDefence(-5);
		if (hurtPakge.getIsOutput())
			cout << getName() << "���˸񷢶��˼��ܡ���������һ���ҡ�,����������,�������½���\n";
	}
	else if (0 == firstFlag) {
		addAttack(-10);
		addDefence(5);
		int hpAdd = 1 + getRandNum() % 15;
		addHP(hpAdd);
		if (hurtPakge.getIsOutput())
			cout << getName() << "���˸񷢶��˼��ܡ���������һ���ҡ���HP�ͷ����õ��˻ָ����������½���\n";
	}
	return hurtPakge;
}

HurtPakge Seele::myRound(HurtPakge& hurtPakge) {
	FirstSkill(hurtPakge);
	hurtPakge = SecondSkill(hurtPakge);
	hurtPakge = basicPakge(hurtPakge);
	return hurtPakge;
}

void Seele::enemyRound(HurtPakge& hurtPakge) {
	getHurt(hurtPakge);
}