#define _CRT_SECURE_NO_WARNINGS
#define BATTLETIMES 10000
#include <iostream>
#include <conio.h>
#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include<random>
#include<chrono>
using namespace std;
HurtPakge hurtPakge;
bool outputFlag;

template<class T1, class T2>
void Round(T1* x, T2* y) {
	if (x->getMoveable()) {
		if (outputFlag)
			cout << x->getName() << "�����˻غϣ�\n";
		x->setMoveable(0);
	}
	else {
		hurtPakge.init();
		y->emenyRound(x->myRound(hurtPakge));
	}
	x->setSpeed(0);
	y->setSpeed(100);
	x->roundEnd();
}

template<class T1, class T2>
bool BattleSimulate(T1* x, T2* y) {
	int round = 0;
	hurtPakge.initRound();
	while (true) {
		if (round++ % 2 == 0)
			hurtPakge.addRound();
		if (x->getHP() <= 0) return false;
		if (y->getHP() <= 0) return true;
		if (x->getSpeed() >= y->getSpeed()) Round(x, y);
		else Round(y, x);
	}
}

void TitleDisp() {
	cout << "******************************************************************\n"
		"*                                                                *\n"
		"*                     �ıı���ҳ�ģ����                       *\n"
		"*                                                                *\n"
		"******************************************************************\n";
	cout << endl;
}
void RoleMenu() {
	roles.push_back(Theresa());
	roles.push_back(Bronya());
	roles.push_back(Fuhua());
	roles.push_back(Rozaliya());
	roles.push_back(Sakura());
	roles.push_back(Seele());
	cout << "����ɯ��1	������櫣�2	������3		������櫣�4	\n"
			"ӣ����5		ϣ����6	\n";
	cout << endl;
}

vector<Role> roles;

int main() {
	int winTimes1, winTimes2;
	int select1, select2;
	char isContinue;
	while (true) {
		//��ʼ��
		TitleDisp();RoleMenu();
		winTimes1 = 0; winTimes2 = 0;
		cout << "			ѡ���ɫ1:";
		cin >> select1;
		cout << "			ѡ���ɫ2:";
		cin >> select2;
		cout << "��սģ�⣺1		����ģ�⣺0" << endl;
		cout << "			ѡ��ģʽ:";
		cin >> outputFlag;
		hurtPakge.setIsOutput(outputFlag);
		Role *role1 = &roles[select1 - 1];
		Role *role2 = &roles[select2 - 1];
		//ս��ģ��
		int n = 10000;
		if (outputFlag) n = 1;
		for (int i = 1;i <= n;i++) {
			role1->init();
			role2->init();
			if(i%100 == 0)
				cout << ">";
			if (BattleSimulate(role1, role2)) winTimes1++;
			else winTimes2++;
		}
		if (!outputFlag) {
			//ʤ�������
			cout << "\n			  ģ��ս������" << n << endl;
			cout << "\n		      ��ɫ1��ʤ����Ϊ" << winTimes1 << endl;
			cout << "\n		      ��ɫ2��ʤ����Ϊ" << winTimes2 << endl;
		}
		//ѭ������/����
		cout << "\n�����밴y�������˳�\n";
		isContinue = _getch();
		if (isContinue == 'y' || isContinue == 'Y');
		else break;
		system("cls");
	}
	return 0;
}