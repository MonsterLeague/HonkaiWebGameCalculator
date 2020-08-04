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
vector<Role*> roles;
bool outputFlag;

void Round(Role* x, Role* y) {
	hurtPakge.init();
	hurtPakge.setEnemy(y);
	if (outputFlag)
		cout << "第" << hurtPakge.getRound() << "回合" << endl;
	if (x->getMoveable()) {
		if (outputFlag)
			cout << x->getName() << "跳过了回合！\n";
		x->setMovable(0);
	}
	else {
		hurtPakge = x->myRound(hurtPakge);
		y->enemyRound(hurtPakge);
	}
	x->setSpeed(0);
	y->setSpeed(100);
	x->roundEnd();
}

bool BattleSimulate(Role* x, Role* y) {
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
		"*                     蹦蹦蹦网页活动模拟器                       *\n"
		"*                                                                *\n"
		"******************************************************************\n";
	cout << endl;
}
void RoleMenu() {
	roles.push_back(new Kiana());
	roles.push_back(new Mei());
	roles.push_back(new Bronya());
	roles.push_back(new Himeko());
	roles.push_back(new Rita());
	roles.push_back(new Sakura());
	roles.push_back(new Raven());
	roles.push_back(new Theresa());
	roles.push_back(new Rozaliya());
	roles.push_back(new Seele());
	roles.push_back(new Durandal());
	roles.push_back(new Fuhua());
	cout << "琪亚娜：1		芽衣：2		布洛妮娅：3		姬子：4\n"
			"丽塔：5			樱莲：6		渡鸦：7			德丽莎：8\n"
			"罗萨莉娅：9		希儿：10		幽兰戴尔：11		符华：12\n";
	cout << endl;
}

int main() {
	int winTimes1, winTimes2;
	int select1, select2;
	char isContinue;
	while (true) {
		//初始化
		TitleDisp();RoleMenu();
		winTimes1 = 0; winTimes2 = 0;
		cout << "			选择角色1:";
		cin >> select1;
		cout << "			选择角色2:";
		cin >> select2;
		cout << "作战模拟：1		概率模拟：0" << endl;
		cout << "			选择模式:";
		cin >> outputFlag;
		hurtPakge.setIsOutput(outputFlag);
		Role *role1 = roles[select1 - 1];
		Role *role2 = roles[select2 - 1];
		//战斗模拟
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
			//胜场数输出
			cout << "\n			  模拟战斗次数" << n << endl;
			cout << "\n		      角色1的胜场数为" << winTimes1 << endl;
			cout << "\n		      角色2的胜场数为" << winTimes2 << endl;
		}
		else {
			string winer;
			if (winTimes1)
				winer = role1->getName();
			else
				winer = role2->getName();
			cout << winer << "获得了胜利！" << endl;
		}
		//循环结束/继续
		cout << "\n继续请按y，否则退出\n";
		isContinue = _getch();
		if (isContinue == 'y' || isContinue == 'Y');
		else break;
		system("cls");
	}
	return 0;
}