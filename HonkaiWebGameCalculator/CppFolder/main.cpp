#define _CRT_SECURE_NO_WARNINGS
#define BATTLETIMES 10000
#include <iostream>
#include <conio.h>
#include "../HeadFolder/role.h"
#include "../HeadFolder/HurtPakge.h"
#include<random>
#include<chrono>
using namespace std;

template<class T1, class T2>
bool  BattleSimulate(T1* x, T2* y) {
	while (true) {
		if (x->getHP() <= 0) return false;
		if (y->getHP() <= 0) return true;
		if (x->getSpeed() >= y->getSpeed()) y->enemyRound(x->thisRound());
		else x->enemyRound(y->thisRound());
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
		HurtPakge hurtpakge;
		TitleDisp();RoleMenu();
		winTimes1 = 0; winTimes2 = 0;
		cout << "			ѡ���ɫ1:";
		cin >> select1;
		cout << "			ѡ���ɫ2:";
		cin >> select2;
		Role *role1 = &roles[select1 - 1];
		Role *role2 = &roles[select2 - 1];
		//ս��ģ��
		int n = 10000;
		for (int i = 1;i <= n;i++) {
			role1->init();
			role2->init();
			if(i%100 == 0)
				cout << ">";
			typeid(int);
			if (BattleSimulate(role1, role2)) winTimes1++;
			else winTimes2++;
		}
		
		//ʤ�������
		cout << "\n			  ģ��ս������" << n << endl;
		cout << "\n		      ��ɫ1��ʤ����Ϊ" << winTimes1 << endl;
		cout << "\n		      ��ɫ2��ʤ����Ϊ" << winTimes2 << endl;
		//ѭ������/����
		cout << "\n�����밴y�������˳�\n";
		isContinue = _getch();
		if (isContinue == 'y' || isContinue == 'Y');
		else break;
		system("cls");
	}
	return 0;
}